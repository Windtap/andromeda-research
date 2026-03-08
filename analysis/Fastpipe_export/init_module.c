// Alternative name is 'fastpipeInit'
__int64 init_module()
{
  int v0; // ebx

  printk("fastpipe: fastpipeInit\n");
  v0 = _pci_register_driver(&g_PciDriver, &_this_module, "fastpipe_x64");
  if ( v0 < 0 )
  {
    printk("fastpipe: pci_register_driver failed\n");
    return (unsigned int)v0;
  }
  else
  {
    printk("fastpipe: miscDevConstruct\n");
    if ( (int)misc_register(&g_MiscDevice) < 0 )
      printk("fastpipe: misc_register failed\n");
    g_waitHostRetQueue = 0;
    qword_15C98 = (__int64)&qword_15C98;
    qword_15CA0 = (__int64)&qword_15C98;
    _mutex_init(&g_lockSendSerialCall, "&g_lockSendSerialCall", &g_u64GuestFDBase);
    _init_waitqueue_head(&g_waitSerialCallQueue, "&g_waitSerialCallQueue", &g_u64GuestFDBase);
    if ( (int)request_threaded_irq(
                *(unsigned int *)(g_pPciDev + 804),
                pciDevIrqHandler,
                0,
                8193,
                "fastpipe",
                &g_MiscDevice) < 0 )
      printk("fastpipe: request_threaded_irq failed\n");
    return goldfish_sync_init();
  }
}
