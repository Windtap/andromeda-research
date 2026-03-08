__int64 __fastcall fileOpRelease(__int64 a1, _QWORD *a2)
{
  int *v3; // rbx
  int v4; // esi
  unsigned __int64 v5; // rdx
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // r12
  _QWORD *v10; // rsi
  const char *v11; // rdi
  __int64 v12; // r8
  int v13; // r13d
  int v14; // r14d
  __int64 v15; // rax
  __int64 v16; // rcx
  __int64 v17; // r15
  __int64 v18; // rdx
  unsigned __int64 v19; // r9
  unsigned __int64 v20; // r15
  int i; // r12d
  unsigned __int64 v22; // rax
  __int64 v23; // rax
  unsigned __int64 v24; // rax
  _QWORD v25[7]; // [rsp+8h] [rbp-38h] BYREF

  v3 = (int *)a2[26];
  if ( v3 )
  {
    v4 = *v3;
    if ( *v3 == 1 )
    {
      v9 = __readgsqword((unsigned int)&current_task);
      v10 = a2;
      v11 = "fastpipe: fileOpRelease: pFilp=%p pSession=%p pid=%d %s\n";
      printk(
        "fastpipe: fileOpRelease: pFilp=%p pSession=%p pid=%d %s\n",
        a2,
        v3,
        *(_DWORD *)(v9 + 1936),
        (const char *)(v9 + 2368));
      v13 = v3[2];
      v14 = v3[3];
      if ( (unsigned int)(v13 - 1) > 0x3FE || (unsigned int)(v14 - 1) > 0x3FE )
      {
        v24 = __readgsqword((unsigned int)&current_task);
        printk(
          "fastpipe: fileOpRelease: private_data invalid! pFilp=%p pSession=%p pid=%d %s\n",
          a2,
          (const void *)a2[26],
          *(_DWORD *)(v24 + 1936),
          (const char *)(v24 + 2368));
      }
      else
      {
        v15 = g_pPipeMem;
        v16 = 48LL * v13;
        v17 = 48LL * v14;
        *(_DWORD *)(g_pPipeMem + v16 + 40) = 2;
        v18 = v15 + v17;
        *(_DWORD *)(v15 + v17 + 40) = 2;
        _InterlockedIncrement((volatile signed __int32 *)(v15 + v16 + 44));
        _InterlockedIncrement((volatile signed __int32 *)(v15 + v17 + 44));
        v19 = v9 + 2368;
        if ( (*(_BYTE *)(v9 + 20) & 4) != 0 )
        {
          v10 = (_QWORD *)*(unsigned int *)(v9 + 1936);
          v11 = "fastpipe: fileOpRelease, because process terminite! pid=%d %s\n";
          printk(
            "fastpipe: fileOpRelease, because process terminite! pid=%d %s\n",
            (_DWORD)v10,
            (const char *)(v9 + 2368));
          v16 = g_pPipeMem + 48LL * v13;
          v23 = v17 + g_pPipeMem;
          *(_DWORD *)(v16 + 48) = 1;
          *(_DWORD *)(v23 + 48) = 1;
        }
        my_wake_up_constprop_5(v11, v10, v18, v16, v12, v19);
        __outdword(g_IOPortBase, (v13 << 20) | (v14 << 8) | 2);
      }
      v20 = __readgsqword((unsigned int)&current_task);
      for ( i = 0; i != 8; ++i )
      {
        if ( *(_DWORD *)(g_pPipeMem + 8 * (i + 22572LL) + 8) == v13 )
          printk(
            "fastpipe: fileOpRelease: fix-dma index=%d will unlock by host. pFilp=%p pSession=%p pid=%d %s\n",
            i,
            a2,
            v3,
            *(_DWORD *)(v20 + 1936),
            (const char *)(v20 + 2368));
      }
    }
    else if ( v4 == 2 )
    {
      v8 = __readgsqword((unsigned int)&current_task);
      printk(
        "fastpipe: fileOpRelease: host-handle=%u pFilp=%p pSession=%p pid=%d %s\n",
        v3[2],
        a2,
        v3,
        *(_DWORD *)(v8 + 1936),
        (const char *)(v8 + 2368));
      sendSerialCallToHost(2, v3 + 2, 4, 0, 0, 0);
    }
    else if ( v4 == 3 )
    {
      v7 = __readgsqword((unsigned int)&current_task);
      printk(
        "fastpipe: fileOpRelease: guestFD=%llu pFilp=%p pSession=%p pid=%d %s\n",
        *((_QWORD *)v3 + 1),
        a2,
        v3,
        *(_DWORD *)(v7 + 1936),
        (const char *)(v7 + 2368));
      v25[0] = *((_QWORD *)v3 + 1);
      sendSerialCallToHost(1003, v25, 8, 0, 0, 0);
    }
    else
    {
      v5 = __readgsqword((unsigned int)&current_task);
      printk(
        "fastpipe: fileOpRelease: error! eType invalid! eType=%d pFilp=%p pSession=%p pid=%d %s\n",
        v4,
        a2,
        v3,
        *(_DWORD *)(v5 + 1936),
        (const char *)(v5 + 2368));
    }
    a2[26] = 0;
    kfree(v3);
  }
  else
  {
    v22 = __readgsqword((unsigned int)&current_task);
    printk(
      "fastpipe: fileOpRelease: private_data invalid! pFilp=%p pSession=%p pid=%d %s\n",
      a2,
      0,
      *(_DWORD *)(v22 + 1936),
      (const char *)(v22 + 2368));
  }
  return 0;
}
