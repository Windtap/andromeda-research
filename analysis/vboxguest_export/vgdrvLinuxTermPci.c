__int64 __fastcall vgdrvLinuxTermPci(__int64 a1)
{
  __int64 result; // rax

  g_pPciDev = 0;
  if ( a1 )
  {
    iounmap(g_pvMMIOBase);
    g_pvMMIOBase = 0;
    _release_region(&iomem_resource, g_MMIOPhysAddr, (unsigned int)g_cbMMIO);
    g_MMIOPhysAddr = -1;
    g_cbMMIO = 0;
    return pci_disable_device(a1);
  }
  return result;
}
