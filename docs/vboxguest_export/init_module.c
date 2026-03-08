// Alternative name is 'vgdrvLinuxModInit'
__int64 __fastcall init_module(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
  int v8; // eax
  double v9; // xmm4_8
  double v10; // xmm5_8
  double v12; // xmm4_8
  double v13; // xmm5_8
  signed int inited; // ebx
  __int64 (*v15)(); // rsi
  unsigned int v16; // ebx
  __int64 v17; // rax
  double v18; // xmm4_8
  double v19; // xmm5_8
  __int64 v20; // rax
  double v21; // xmm4_8
  double v22; // xmm5_8
  __int64 v23; // rax
  double v24; // xmm4_8
  double v25; // xmm5_8
  __int64 v26; // rax
  double v27; // xmm4_8
  double v28; // xmm5_8
  __int64 v29; // rax
  double v30; // xmm4_8
  double v31; // xmm5_8
  __int64 v32; // rax
  double v33; // xmm4_8
  double v34; // xmm5_8
  __int64 DefaultInstance; // rax
  double v36; // xmm4_8
  double v37; // xmm5_8
  __int64 v38; // rax
  double v39; // xmm4_8
  double v40; // xmm5_8
  __int64 v41; // rax
  double v42; // xmm4_8
  double v43; // xmm5_8
  double v44; // xmm4_8
  double v45; // xmm5_8
  __int64 v46; // [rsp+0h] [rbp-28h]
  int v47; // [rsp+10h] [rbp-18h]
  __int64 v48; // [rsp+18h] [rbp-10h] BYREF

  v8 = VBoxGuest_RTR0Init(0);
  if ( v8 < 0 )
  {
    printk(byte_287C0, (unsigned int)v8);
    return 4294967274LL;
  }
  if ( (int)VBoxGuest_RTLogCreate(
              (unsigned __int64)&v48,
              0,
              "all",
              (__int64)"VBOX_RELEASE_LOG",
              0x176u,
              (__int64)s_apszGroups_41358,
              a1,
              a2,
              a3,
              a4,
              v9,
              v10,
              a7,
              a8,
              1073741834) >= 0 )
  {
    VBoxGuest_RTLogGroupSettings(v48, g_szLogGrp);
    VBoxGuest_RTLogFlags(v48, g_szLogFlags);
    VBoxGuest_RTLogDestinations(v48, g_szLogDst, a1, a2, a3, a4, v12, v13, a7, a8);
    VBoxGuest_RTLogRelSetDefaultInstance(v48);
  }
  g_fLoggerCreated = 1;
  if ( (int)_pci_register_driver(&g_PciDriver, &_this_module, "vboxguest") < 0 || !g_pPciDev )
  {
    v16 = -19;
    DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(0x1570010u);
    if ( DefaultInstance )
      VBoxGuest_RTLogLoggerEx(
        DefaultInstance,
        16,
        0x157u,
        "vboxguest: PCI device not found, probably running on physical hardware.\n",
        a1,
        a2,
        a3,
        a4,
        v36,
        v37,
        a7,
        a8);
    goto LABEL_34;
  }
  inited = VGDrvCommonInitDevExt((__int64)&g_DevExt, g_IOPortBase, (unsigned int *)g_pvMMIOBase, g_cbMMIO, 340224, 512);
  if ( inited < 0 )
  {
    v32 = VBoxGuest_RTLogRelGetDefaultInstanceEx(0x1570010u);
    if ( v32 )
      VBoxGuest_RTLogLoggerEx(
        v32,
        16,
        0x157u,
        "vboxguest: VGDrvCommonInitDevExt failed with rc=%Rrc\n",
        a1,
        a2,
        a3,
        a4,
        v33,
        v34,
        a7,
        a8,
        (unsigned int)inited);
    v16 = VBoxGuest_RTErrConvertFromErrno(inited, a1, a2, a3, a4, v33, v34, a7, a8);
    goto LABEL_34;
  }
  _init_waitqueue_head(&g_PollEventQueue, "&g_PollEventQueue", g_szLogDst);
  v15 = vgdrvLinuxISR;
  v16 = request_threaded_irq(*(unsigned int *)(g_pPciDev + 804), vgdrvLinuxISR, 0, 128, "vboxguest", &g_DevExt);
  if ( v16 )
  {
    v17 = VBoxGuest_RTLogRelGetDefaultInstanceEx(0x1570010u);
    if ( v17 )
    {
      v15 = (__int64 (*)())(&loc_C + 4);
      VBoxGuest_RTLogLoggerEx(
        v17,
        16,
        0x157u,
        "vboxguest: could not request IRQ %d: err=%d\n",
        a1,
        a2,
        a3,
        a4,
        v18,
        v19,
        a7,
        a8,
        *(unsigned int *)(g_pPciDev + 804),
        v16);
    }
    if ( (v16 & 0x80000000) != 0 )
    {
LABEL_28:
      VGDrvCommonDeleteDevExt((__int64)&g_DevExt, (__int64)v15);
LABEL_34:
      pci_unregister_driver(&g_PciDriver);
      v38 = VBoxGuest_RTLogRelSetDefaultInstance(0);
      VBoxGuest_RTLogDestroy(v38, a1, a2, a3, a4, v39, v40, a7, a8);
      v41 = VBoxGuest_RTLogSetDefaultInstance(0);
      VBoxGuest_RTLogDestroy(v41, a1, a2, a3, a4, v42, v43, a7, a8);
      VBoxGuest_RTR0Term(a1, a2, a3, a4, v44, v45, a7, a8);
      return v16;
    }
  }
  VGDrvCommonProcessOptionsFromHost(&g_DevExt);
  v16 = misc_register(&g_MiscDevice);
  if ( v16 )
  {
    v23 = VBoxGuest_RTLogRelGetDefaultInstanceEx(0x1570010u);
    if ( v23 )
      VBoxGuest_RTLogLoggerEx(
        v23,
        16,
        0x157u,
        "vboxguest: misc_register failed for %s (rc=%d)\n",
        a1,
        a2,
        a3,
        a4,
        v24,
        v25,
        a7,
        a8,
        "vboxguest",
        v16);
LABEL_21:
    if ( (v16 & 0x80000000) == 0 )
      goto LABEL_22;
    v15 = (__int64 (*)())&g_DevExt;
    free_irq(*(unsigned int *)(g_pPciDev + 804), &g_DevExt);
    goto LABEL_28;
  }
  v16 = misc_register(&g_MiscDeviceUser);
  if ( v16 )
  {
    v20 = VBoxGuest_RTLogRelGetDefaultInstanceEx(0x1570010u);
    if ( v20 )
      VBoxGuest_RTLogLoggerEx(
        v20,
        16,
        0x157u,
        "vboxguest: misc_register failed for %s (rc=%d)\n",
        a1,
        a2,
        a3,
        a4,
        v21,
        v22,
        a7,
        a8,
        "vboxuser",
        v16);
    misc_deregister(&g_MiscDevice);
    goto LABEL_21;
  }
LABEL_22:
  v26 = VBoxGuest_RTLogRelGetDefaultInstanceEx(0x1570010u);
  if ( v26 )
    VBoxGuest_RTLogLoggerEx(
      v26,
      16,
      0x157u,
      "vboxguest: Successfully loaded version 6.1.36 r152435\n",
      a1,
      a2,
      a3,
      a4,
      v27,
      v28,
      a7,
      a8);
  v29 = VBoxGuest_RTLogRelGetDefaultInstanceEx(0x1570010u);
  if ( v29 )
  {
    v47 = g_cbMMIO;
    LODWORD(v46) = (unsigned __int16)g_IOPortBase;
    VBoxGuest_RTLogLoggerEx(
      v29,
      16,
      0x157u,
      "vboxguest: misc device minor %d, IRQ %d, I/O port %RTiop, MMIO at %RHp (size 0x%x)\n",
      a1,
      a2,
      a3,
      a4,
      v30,
      v31,
      a7,
      a8,
      (unsigned int)g_MiscDevice,
      *(unsigned int *)(g_pPciDev + 804),
      v46,
      g_MMIOPhysAddr,
      v47);
  }
  printk(byte_288D8);
  return v16;
}
