__int64 __fastcall fileOpMmap(_QWORD *a1, __int64 *a2)
{
  __int64 v3; // rsi
  int v4; // ebp
  int v5; // ebp
  _DWORD *v6; // rax
  int v7; // r15d
  const char *v8; // rdx
  int v10; // eax
  _DWORD *v11; // r14
  int v12; // eax
  int v13; // r12d
  signed __int64 v14; // rdx
  __int64 v15; // r8
  _DWORD *v16; // rax
  signed __int64 v17; // r12
  int v18; // r13d
  __int64 v19; // r14
  __int64 v20; // rbp
  _DWORD *v21; // rbp
  __int64 v22; // rdx
  unsigned __int64 v23; // rax
  unsigned __int64 v24; // rax
  unsigned __int64 v25; // rax
  _DWORD *v26; // [rsp+28h] [rbp-38h]

  v3 = *a2;
  v4 = *((_DWORD *)a2 + 2);
  a2[10] |= 0x4046400uLL;
  v5 = v4 - v3;
  if ( boot_cpu_data > 3u )
    a2[9] = _cachemode2pte_tbl[2] | (unsigned __int64)a2[9];
  v6 = (_DWORD *)a1[26];
  if ( v6 && *v6 == 3 )
  {
    v11 = (_DWORD *)kmalloc_order_trace(8200, 37781696, 2);
    v26 = v11;
    if ( !v11 )
    {
      printk("fastpipe: fileOpMmap alloc SerialGetBlobPhys_G2H failed\n");
      goto LABEL_37;
    }
    v12 = *((_DWORD *)a2 + 38);
    v11[1] = -1;
    *v11 = v12 << 12;
    sendSerialCallToHost(1001, v11, 8200, v11, 8200, 0);
    v13 = v11[1];
    if ( v13 == -1 )
    {
      v7 = -1;
      v25 = __readgsqword((unsigned int)&current_task);
      printk(
        "fastpipe: fileOpMmap uBlobId=%u not exist! uSize=%lu pFilp=%p pSession=%p pid=%d %s\n",
        *v11,
        a2[1] - *a2,
        a1,
        (const void *)a1[26],
        *(_DWORD *)(v25 + 1936),
        (const char *)(v25 + 2368));
    }
    else
    {
      if ( v5 != ((v13 + 4095) & 0xFFFFF000) )
      {
        printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", "fileOpMmap", "uSizeMap == PAGE_ALIGN(pBlob->uSize)");
        dump_stack();
      }
      v14 = 0;
      v15 = a2[1] - *a2;
      v16 = v11 + 2;
      v17 = (v15 + 4095) & 0xFFFFFFFFFFFFF000LL;
      do
      {
        if ( !*v16 )
          break;
        v14 += 0x20000LL;
        ++v16;
      }
      while ( v14 != 0x10000000 );
      if ( v17 > v14 )
      {
        v7 = -1;
        v24 = __readgsqword((unsigned int)&current_task);
        printk(
          "fastpipe: fileOpMmap error! nReqMapLen=%ld nBlobLen=%ld uBlobId=%u uMapSize=%lu uSize=%u pFilp=%p pSession=%p pid=%d %s\n",
          (v15 + 4095) & 0xFFFFFFFFFFFFF000LL,
          v14,
          *v11,
          v15,
          v11[1],
          a1,
          (const void *)a1[26],
          *(_DWORD *)(v24 + 1936),
          (const char *)(v24 + 2368));
      }
      else
      {
        v18 = 0;
        v19 = 0;
        v7 = -1;
        if ( v17 > 0 )
        {
          do
          {
            v21 = &v26[v18];
            v22 = (unsigned int)v21[2];
            if ( !(_DWORD)v22 )
            {
              printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", "fileOpMmap", "pBlob->arBlockOffset[i] != 0");
              dump_stack();
              v22 = (unsigned int)v21[2];
            }
            v20 = v17 - v19;
            if ( v17 - v19 > 0x20000 )
              v20 = 0x20000;
            v7 = remap_pfn_range(a2, *a2 + v19, (unsigned __int64)(g_blobPhysAddr + v22) >> 12, v20, a2[9]);
            if ( v7 )
              break;
            v19 += v20;
            ++v18;
            if ( v17 <= v19 )
              break;
          }
          while ( v18 <= 2047 );
        }
        if ( v19 != v17 )
        {
          printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", "fileOpMmap", "nMappedLen == nReqMapLen");
          dump_stack();
        }
        if ( v7 )
        {
          v23 = __readgsqword((unsigned int)&current_task);
          printk(
            "fastpipe: fileOpMmap remap error! uBlobId=%u uSize=%lu pFilp=%p pSession=%p pid=%d %s\n",
            *v26,
            a2[1] - *a2,
            a1,
            (const void *)a1[26],
            *(_DWORD *)(v23 + 1936),
            (const char *)(v23 + 2368));
        }
      }
    }
    kfree(v26);
  }
  else
  {
    if ( v5 != 0x2000000 )
    {
      if ( v5 == (_DWORD)&unk_10000 )
      {
        v7 = remap_pfn_range(a2, v3, (unsigned __int64)g_controlSetPhysAddr >> 12, &unk_10000, a2[9]);
        if ( g_controlSetSize == (_DWORD)&unk_10000 )
          goto LABEL_10;
        v8 = "uSizeMap == g_controlSetSize";
        goto LABEL_9;
      }
      printk("fastpipe: fileOpMmap error!!! size = %d\n", v5);
LABEL_37:
      v7 = -1;
      goto LABEL_38;
    }
    v10 = remap_pfn_range(a2, v3, (unsigned __int64)g_pipeMemPhysAddr >> 12, 0x2000000, a2[9]);
    v8 = "uSizeMap == g_pipeMemSize";
    v7 = v10;
    if ( g_pipeMemSize != 0x2000000 )
    {
LABEL_9:
      printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", "fileOpMmap", v8);
      dump_stack();
    }
  }
LABEL_10:
  if ( v7 < 0 )
LABEL_38:
    printk("fastpipe: fileOpMmap error = %d\n", v7);
  return (unsigned int)v7;
}
