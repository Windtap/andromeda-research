#include "qemu/osdep.h"
#include "hw/pci/pci.h"
#include "hw/qdev-properties.h"
#include "hw/pci/msi.h"
#include "qemu/timer.h"
#include "qom/object.h"
#include "qemu/log.h"
#include "qapi/error.h"

#define TYPE_FASTPIPE "fastpipe"
OBJECT_DECLARE_SIMPLE_TYPE(FastpipeState, FASTPIPE)

#define FASTPIPE_VENDOR_ID 0x80EE
#define FASTPIPE_DEVICE_ID 0xDBDB

struct FastpipeState {
    PCIDevice parent_obj;

    MemoryRegion bar0_io;      /* I/O ports for commands */
    MemoryRegion bar1_mem;     /* Pipe shared memory (32MB) */
    MemoryRegion bar2_control;  /* Control set (64KB) */
    
    uint32_t ioport_base;
    uint8_t *pipe_mem;
    uint8_t *control_mem;
};

static uint64_t fastpipe_io_read(void *opaque, hwaddr addr, unsigned size)
{
    /* LDPlayer driver reads from I/O to check status/interrupts */
    return 0; 
}

static void fastpipe_io_write(void *opaque, hwaddr addr, uint64_t val, unsigned size)
{
    uint32_t cmd = val & 0xFF;
    uint32_t pipe_id = (val >> 8) & 0xFFF;

    switch (cmd) {
        case 1: /* Connect */
            qemu_log_mask(LOG_GUEST_ERROR, "fastpipe: Connect pipe %d\n", pipe_id);
            break;
        case 7: /* Serial Call */
            qemu_log_mask(LOG_GUEST_ERROR, "fastpipe: Serial Call to host\n");
            break;
        default:
            qemu_log_mask(LOG_GUEST_ERROR, "fastpipe: Unknown command %ld for pipe %d\n", val & 0xF, pipe_id);
            break;
    }
}

static const MemoryRegionOps fastpipe_io_ops = {
    .read = fastpipe_io_read,
    .write = fastpipe_io_write,
    .endianness = DEVICE_LITTLE_ENDIAN,
    .impl = {
        .min_access_size = 4,
        .max_access_size = 4,
    },
};

static void fastpipe_realize(PCIDevice *pci_dev, Error **errp)
{
    FastpipeState *s = FASTPIPE(pci_dev);

    /* BAR 0: I/O (8 bytes or more) */
    memory_region_init_io(&s->bar0_io, OBJECT(s), &fastpipe_io_ops, s, "fastpipe-io", 16);
    pci_register_bar(pci_dev, 0, PCI_BASE_ADDRESS_SPACE_IO, &s->bar0_io);

    /* BAR 1: Shared Memory (32MB) */
    memory_region_init_ram(&s->bar1_mem, OBJECT(s), "fastpipe-mem", 32 * 1024 * 1024, errp);
    pci_register_bar(pci_dev, 1, PCI_BASE_ADDRESS_SPACE_MEMORY, &s->bar1_mem);

    /* BAR 2: Control Set (64KB) */
    memory_region_init_ram(&s->bar2_control, OBJECT(s), "fastpipe-control", 64 * 1024, errp);
    pci_register_bar(pci_dev, 2, PCI_BASE_ADDRESS_SPACE_MEMORY, &s->bar2_control);
}

static void fastpipe_class_init(ObjectClass *klass, void *data)
{
    DeviceClass *dc = DEVICE_CLASS(klass);
    PCIDeviceClass *k = PCI_DEVICE_CLASS(klass);

    k->realize = fastpipe_realize;
    k->vendor_id = FASTPIPE_VENDOR_ID;
    k->device_id = FASTPIPE_DEVICE_ID;
    k->class_id = PCI_CLASS_OTHERS;
    set_bit(DEVICE_CATEGORY_MISC, dc->categories);
}

static const TypeInfo fastpipe_info = {
    .name          = TYPE_FASTPIPE,
    .parent        = TYPE_PCI_DEVICE,
    .instance_size = sizeof(FastpipeState),
    .class_init    = fastpipe_class_init,
    .interfaces = (InterfaceInfo[]) {
        { INTERFACE_CONVENTIONAL_PCI_DEVICE },
        { },
    },
};

static void fastpipe_register_types(void)
{
    type_register_static(&fastpipe_info);
}

type_init(fastpipe_register_types)
