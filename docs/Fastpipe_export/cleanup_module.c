// Alternative name is 'fastpipeExit'
__int64 cleanup_module()
{
  printk("fastpipe: fastpipeExit\n");
  goldfish_sync_uninit();
  printk("fastpipe: miscDevDestruct\n");
  free_irq(*(unsigned int *)(g_pPciDev + 804), &g_MiscDevice);
  misc_deregister(&g_MiscDevice);
  return pci_unregister_driver(&g_PciDriver);
}
