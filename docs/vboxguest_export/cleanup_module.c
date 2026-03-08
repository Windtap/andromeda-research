// Alternative name is 'vgdrvLinuxModExit'
__int64 __fastcall cleanup_module(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 v8; // rax
  double v9; // xmm4_8
  double v10; // xmm5_8
  __int64 v11; // rax
  double v12; // xmm4_8
  double v13; // xmm5_8
  double v14; // xmm4_8
  double v15; // xmm5_8

  misc_deregister(&g_MiscDevice);
  misc_deregister(&g_MiscDeviceUser);
  free_irq(*(unsigned int *)(g_pPciDev + 804), &g_DevExt);
  VGDrvCommonDeleteDevExt((__int64)&g_DevExt, (__int64)&g_DevExt);
  pci_unregister_driver(&g_PciDriver);
  v8 = VBoxGuest_RTLogRelSetDefaultInstance(0);
  VBoxGuest_RTLogDestroy(v8, a1, a2, a3, a4, v9, v10, a7, a8);
  v11 = VBoxGuest_RTLogSetDefaultInstance(0);
  VBoxGuest_RTLogDestroy(v11, a1, a2, a3, a4, v12, v13, a7, a8);
  return VBoxGuest_RTR0Term(a1, a2, a3, a4, v14, v15, a7, a8);
}
