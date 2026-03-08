# Andromeda Interop: Fastpipe Architecture

This document describes how the communication (interop) works between the Android guest and the Linux host in the Andromeda emulator.

## Overview

The "fastpipe" is a custom virtual PCI device implemented in **AndromedaCore** (QEMU). It provides a high-speed, low-latency communication channel that bypasses standard networking or slow serial interfaces.

## Architecture

```
+--------------------------------+       +----------------------------------+
|        Android Guest           |       |           Linux Host             |
|                                |       |                                  |
|  +--------------------------+  |       |  +----------------------------+  |
|  |   Custom Android App/HAL |  |       |  |   Andromeda-Emu (GUI)      |  |
|  +-------------|------------+  |       |  +-------------|--------------+  |
|                |               |       |                |                |
|  +-------------v------------+  |       |  +-------------v--------------+  |
|  |   fastpipe.ko (Kernel)   |  |       |  |   AndromedaCore (QEMU)     |  |
|  |   (PCI Driver)           |  |       |  |   (Custom PCI Device)      |  |
|  +-------------|------------+  |       |  +-------------|--------------+  |
+----------------|---------------+       +----------------|----------------+
                 |                                        |
                 +----------------- PCI Bus --------------+
```

## How it Works

### 1. The PCI Device (Host Side)
In `AndromedaCore/hw/misc/fastpipe.c`, a virtual PCI device is defined. It exposes:
- **BAR 0**: Memory-mapped I/O (MMIO) for control registers.
- **Interrupts**: Ability to signal the guest kernel.

### 2. The Guest Driver (Android Side)
The `fastpipe.ko` kernel module (found in `analysis/fastpipe.ko`) is responsible for:
- Probing the PCI bus for the `fastpipe` device.
- Mapping the MMIO regions into kernel space.
- Providing a character device (e.g., `/dev/fastpipe`) for user-space Android apps.

### 3. Data Transfer
Communication is typically handled via:
- **Command Registers**: Writing to specific offsets in BAR 0 triggers actions on the host.
- **Shared Memory (Future/Planned)**: For large data transfers like screen buffers or shared folders.
- **Events**: The host can trigger an MSI-X interrupt to notify the guest of new data.

## Reverse Engineering Insights

Our analysis of the `vboxguest.ko` and `fastpipe.ko` (IDA Pro 9.2) shows that the protocol is highly optimized for:
- Mouse/Touch integration (absolute coordinates).
- Clipboard sharing.
- Time synchronization.
- Guest control (shutdown/reboot).

Detailed decompiled structures can be found in `docs/Fastpipe_export/` and `docs/vboxguest_export/`.

## Comparison with LDPlayer
Andromeda's `fastpipe` is inspired by similar mechanisms in LDPlayer but adapted for a native Linux/KVM environment, ensuring better performance and stability on Linux hosts.
