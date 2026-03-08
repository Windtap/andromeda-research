__int64 __fastcall pciDevProbe(__int64 a1)
{
  int v2; // eax
  unsigned int v3; // ebp
  __int64 v4; // rdi
  __int64 v5; // rax
  unsigned int (__fastcall *v6)(__int64, __int64); // rax
  __int64 v7; // rax
  __int64 v8; // rdx
  unsigned int v9; // eax
  __int64 v10; // rdx
  unsigned int v11; // eax

  v2 = pci_enable_device();
  v3 = v2;
  if ( v2 < 0 )
  {
    printk("fastpipe: could not enable device: %d\n", v2);
    return v3;
  }
  v4 = a1 + 144;
  if ( a1 == -144 || (v5 = *(_QWORD *)(a1 + 672)) == 0 )
    v5 = dma_ops;
  v6 = *(unsigned int (__fastcall **)(__int64, __int64))(v5 + 112);
  if ( v6 )
  {
    if ( !v6(v4, -1) )
      goto LABEL_6;
  }
  else if ( *(_QWORD *)(a1 + 608) && (unsigned int)dma_supported(v4, -1) )
  {
    **(_QWORD **)(a1 + 608) = -1;
    goto LABEL_6;
  }
  printk("fastpipe: set dma mask failed");
LABEL_6:
  v7 = *(_QWORD *)(a1 + 808);
  g_IOPortBase = v7;
  if ( (_WORD)v7 )
  {
    printk("fastpipe: port size %d\n", *(_DWORD *)(a1 + 816) + 1 - v7);
    v8 = *(_QWORD *)(a1 + 872);
    g_pipeMemPhysAddr = *(_QWORD *)(a1 + 864);
    if ( g_pipeMemPhysAddr || (v9 = 0, v8) )
    {
      v9 = v8 - g_pipeMemPhysAddr + 1;
      v8 = v9;
    }
    g_pipeMemSize = v9;
    if ( _request_region(&iomem_resource, g_pipeMemPhysAddr, v8, "pipe_share_mem", 0) )
    {
      g_pPipeMem = ioremap_nocache(g_pipeMemPhysAddr, (unsigned int)g_pipeMemSize);
      if ( g_pPipeMem )
      {
        printk("fastpipe: pipePhys=0x%llx, size=%u\n", g_pipeMemPhysAddr, g_pipeMemSize);
        v10 = *(_QWORD *)(a1 + 928);
        g_controlSetPhysAddr = *(_QWORD *)(a1 + 920);
        if ( g_controlSetPhysAddr || (v11 = 0, v10) )
        {
          v11 = v10 - g_controlSetPhysAddr + 1;
          v10 = v11;
        }
        g_controlSetSize = v11;
        if ( _request_region(&iomem_resource, g_controlSetPhysAddr, v10, "host_control_set", 0) )
        {
          g_pControlSet = ioremap_nocache(g_controlSetPhysAddr, (unsigned int)g_controlSetSize);
          if ( !g_pControlSet )
            printk("fastpipe: ioremap failed, g_pControlSet is NULL\n");
          printk("fastpipe: controlSetPhys=0x%llx, size=%u\n", g_controlSetPhysAddr, g_controlSetSize);
        }
        else
        {
          printk("fastpipe: request_mem_region failed, g_pControlSet is NULL\n");
        }
        g_dyncBlobSize = 1610612736;
        g_blobPhysAddr = 0x4000000000LL;
        if ( _request_region(&iomem_resource, 0x4000000000LL, 1610612736, "dync_blob", 0) )
        {
          g_pDyncBlob = ioremap_nocache(g_blobPhysAddr, (unsigned int)g_dyncBlobSize);
          if ( !g_pDyncBlob )
            printk("fastpipe: ioremap failed, g_pDyncBlob is NULL\n");
        }
        else
        {
          printk("fastpipe: request_mem_region failed! blobPhys=0x%llx size=%u\n", g_blobPhysAddr, g_dyncBlobSize);
        }
        g_pPciDev = a1;
        return v3;
      }
      printk("fastpipe: ioremap g_pipeMemPhysAddr failed,  g_pipeMemSize=%d\n", g_pipeMemSize);
      _release_region(&iomem_resource, g_pipeMemPhysAddr, (unsigned int)g_pipeMemSize);
    }
    else
    {
      printk("fastpipe: failed to obtain Share memory\n");
    }
  }
  else
  {
    printk("fastpipe: get port base failed!\n");
  }
  g_controlSetPhysAddr = -1;
  g_pipeMemPhysAddr = -1;
  g_pipeMemSize = 0;
  pci_disable_device(a1);
  return 0xFFFFFFFFLL;
}
