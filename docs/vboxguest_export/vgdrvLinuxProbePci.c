__int64 __fastcall vgdrvLinuxProbePci(_QWORD *a1)
{
  int v1; // ebp
  __int64 v2; // rax
  __int64 v3; // rdx
  unsigned int v4; // eax
  unsigned int v6; // ebp
  __int64 v7; // rax
  int v8; // r8d
  int v9; // r9d
  __int64 v10; // rax
  __int64 DefaultInstance; // rax
  int v12; // r9d
  __int64 v13; // rax
  int v14; // r8d
  int v15; // r9d

  if ( g_pPciDev )
    return (unsigned int)-22;
  v1 = pci_enable_device();
  if ( v1 < 0 )
  {
    DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(22478864);
    if ( DefaultInstance )
      VBoxGuest_RTLogLoggerEx(
        DefaultInstance,
        16,
        343,
        (unsigned int)"vboxguest: could not enable device: %d\n",
        v1,
        v12);
    return (unsigned int)v1;
  }
  v2 = a1[101];
  g_IOPortBase = v2;
  if ( (_WORD)v2 )
  {
    v3 = a1[109];
    g_MMIOPhysAddr = a1[108];
    if ( g_MMIOPhysAddr || (v4 = 0, v3) )
    {
      v4 = v3 - g_MMIOPhysAddr + 1;
      v3 = v4;
    }
    g_cbMMIO = v4;
    if ( _request_region(&iomem_resource, g_MMIOPhysAddr, v3, "vboxguest", 0) )
    {
      g_pvMMIOBase = ioremap_nocache(g_MMIOPhysAddr, (unsigned int)g_cbMMIO);
      if ( g_pvMMIOBase )
      {
        g_pPciDev = (__int64)a1;
        return 0;
      }
      v10 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22478864);
      if ( v10 )
        VBoxGuest_RTLogLoggerEx(
          v10,
          16,
          343,
          (unsigned int)"vboxguest: ioremap failed; MMIO Addr=%RHp cb=%#x\n",
          g_MMIOPhysAddr,
          g_cbMMIO);
      v6 = -12;
      _release_region(&iomem_resource, g_MMIOPhysAddr, (unsigned int)g_cbMMIO);
    }
    else
    {
      v6 = -16;
      v13 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22478864);
      if ( v13 )
        VBoxGuest_RTLogLoggerEx(v13, 16, 343, (unsigned int)"vboxguest: failed to obtain adapter memory\n", v14, v15);
    }
    g_MMIOPhysAddr = -1;
    g_IOPortBase = 0;
    g_cbMMIO = 0;
    pci_disable_device(a1);
  }
  else
  {
    v6 = -6;
    v7 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22478864);
    if ( v7 )
      VBoxGuest_RTLogLoggerEx(
        v7,
        16,
        343,
        (unsigned int)"vboxguest: did not find expected hardware resources\n",
        v8,
        v9);
    pci_disable_device(a1);
  }
  return v6;
}
