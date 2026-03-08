# andromeda-research

Reverse-engineering artifacts, notes, and research for the Andromeda project (Linux-native Android emulator).

## Structure

- **docs/**: Research notes, protocols, and architectural findings.
- **tools/**: Scripts, utilities, and automation for analysis.
- **samples/**: Small, safe binary fragments and data samples.
- **logs/**: Execution traces and analysis logs.
- **analysis/**: Decompiled code, IDA databases, and kernel module analysis.

## IDA Pro 9.2 Research

All `.i64` database files in this repository are created and maintained with **IDA Pro 9.2**.

## Fastpipe Interop (Detailed Technical Overview)

Based on the reverse-engineered pseudocode (see `docs/Fastpipe_export/fileOpIOCtl.c`), the `fastpipe` device implements a high-performance communication channel between the Android guest and the Linux host.

### 1. Device Initialization
- **PCI Probe**: The guest driver (`fastpipe.ko`) identifies the device on the PCI bus and maps its I/O regions.
- **I/O Port**: A primary control port (`g_IOPortBase`) is used to signal the host.
- **Shared Memory**: The driver sets up a shared memory region (`g_pPipeMem`) that contains an array of pipe structures (`arPipe[1024]`).

### 2. Communication Protocol
The protocol uses a combination of **MMIO**, **I/O Ports**, and **Shared Memory State**.

#### Connection Lifecycle:
- **Connect (`ioCtlConnect`)**: 
  - Finds two free pipe slots (one for Read, one for Write).
  - Generates a `StateCookie` to track session validity.
  - Signals the host via `outl` to the I/O port with a command word: `((WritePipeId & 0xFFF) << 8) | (ReadPipeId << 20) | 1`.
  - Waits for a host response event (`my_wait_event` with `my_condition_connect`).

#### Data Flow & Synchronization:
- **Ring Buffers**: Each pipe uses a ring buffer in shared memory.
- **Wait Enable (`ioCtrlWaitRecvEnable` / `ioCtrlWaitSendEnable`)**: The guest puts the calling thread to sleep until the host signals that the pipe is ready for more data or has data to read.
- **Host Notification**: Commands are sent to the host by writing to the I/O port, encoding the Pipe ID and the command type in the bitmask.

### 3. IOCTL Command Interface
The `fileOpIOCtl` function handles several critical commands (hex codes based on reverse-engineering):
- `0x80046869`: **Wait Send Enable** - Blocks until the host is ready to receive.
- `0x80046865`: **Wait Recv Enable** - Blocks until data is available from the host.
- `0x8004686B`: **Request Ring Buffer** - Allocates/Syncs the shared memory buffer.
- `0xC00C6872`: **Alloc Blob** - Registers a memory blob with the host for DMA-like transfers.
- `0x80086873`: **Connect** - Establishes a new pipe session.

### 4. Memory Management (FixDMA)
The driver includes sophisticated memory management for persistent buffers (`ioCtrlAllocFixDma` / `ioCtrlFreeFixDma`), allowing the host to directly access specific guest memory blocks for zero-copy operations.

## Credits

- Special thanks to the **LDPlayer** developers for their contribution to the Android emulation ecosystem. Their architectural patterns provided the foundation for the `fastpipe` research.

## Contact

For any questions, collaboration, or feedback:
- **Email**: ssvg056@gmail.com
