__int64 __fastcall pciDevRemove(__int64 a1)
{
  __int64 result; // rax

  result = printk("fastpipe: pciDevRemove\n");
  g_pPciDev = 0;
  if ( a1 )
  {
    iounmap(g_pPipeMem);
    iounmap(g_pControlSet);
    g_pPipeMem = 0;
    g_pControlSet = 0;
    _release_region(&iomem_resource, g_pipeMemPhysAddr, (unsigned int)g_pipeMemSize);
    _release_region(&iomem_resource, g_controlSetPhysAddr, (unsigned int)g_controlSetSize);
    g_pipeMemPhysAddr = -1;
    g_controlSetPhysAddr = -1;
    g_pipeMemSize = 0;
    g_controlSetSize = 0;
    return pci_disable_device(a1);
  }
  return result;
}
