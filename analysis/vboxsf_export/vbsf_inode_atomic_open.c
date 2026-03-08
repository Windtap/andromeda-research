__int64 __fastcall vbsf_inode_atomic_open(__int64 a1, __int64 a2, __int64 a3, unsigned int a4, __int16 a5, _DWORD *a6)
{
  unsigned int v7; // ebx
  unsigned __int64 v8; // rax
  __int64 v11; // rax
  __int64 v12; // rbp
  __int16 v13; // bx
  int v14; // eax
  __int64 v15; // r14
  int v16; // r13d
  _DWORD *v17; // rax
  _DWORD *v18; // r12
  int PhysAddr; // eax
  __int64 v20; // rdi
  int v21; // eax
  __int64 DefaultInstance; // rax
  __int64 v24; // [rsp+10h] [rbp-48h]
  bool v26; // [rsp+27h] [rbp-31h] BYREF

  if ( (a4 & 0x40) != 0 )
  {
    v11 = kmem_cache_alloc_trace(kmalloc_caches[5], 37748928, 32);
    v12 = v11;
    if ( v11 )
    {
      v26 = 0;
      *(_QWORD *)(v11 + 8) = v11;
      *(_QWORD *)v11 = v11;
      *(_DWORD *)(v11 + 28) = 1;
      if ( (a4 & 0x10000) != 0 )
      {
        *(_DWORD *)(v11 + 24) = 1963132704;
        v13 = a5 & 0xFFF | 0x4000;
        *(_QWORD *)(v11 + 16) = -1;
      }
      else
      {
        *(_DWORD *)(v11 + 24) = 1963132688;
        *(_QWORD *)(v11 + 16) = -1;
        v13 = a5 & 0xFFF | 0x8000;
      }
      v14 = vbsf_linux_oflags_to_vbox(a4, v11 + 24, "vbsf_inode_atomic_open");
      v7 = vbsf_create_worker(a1, a2, v13, v14, 0, 1, (_QWORD *)(v12 + 16), &v26);
      if ( !v7 )
      {
        v24 = *(_QWORD *)(*(_QWORD *)(a2 + 48) + 552LL);
        if ( v26 )
          *a6 |= 1u;
        v7 = finish_open(a3, a2, &generic_file_open, a6);
        if ( !v7 )
        {
          vbsf_handle_append(v24, v12);
          *(_QWORD *)(a3 + 208) = v12;
          return v7;
        }
        v15 = *(_QWORD *)(v12 + 16);
        v16 = **(_DWORD **)(*(_QWORD *)(a1 + 40) + 1120LL);
        v17 = (_DWORD *)VbglR0PhysHeapAlloc(128);
        v18 = v17;
        if ( v17 )
        {
          *v17 = 128;
          v17[1] = (_DWORD)&unk_10001;
          v17[2] = 0;
          v17[3] = -225;
          v17[4] = 128;
          v17[5] = 0;
          PhysAddr = VbglR0PhysHeapGetPhysAddr(v17);
          v20 = *(_QWORD *)&algn_FA24[4];
          *((_BYTE *)v18 + 28) = 0;
          v18[6] = PhysAddr + 52;
          v21 = g_SfClient;
          v18[13] = 76;
          v18[14] = (_DWORD)&unk_10001;
          v18[15] = 63;
          v18[16] = -225;
          v18[17] = 0;
          v18[18] = 2;
          v18[19] = 0;
          v18[20] = -225;
          v18[21] = v21;
          v18[22] = 4;
          v18[23] = 2;
          v18[24] = 1;
          v18[25] = v16;
          v18[28] = 2;
          *(_QWORD *)(v18 + 29) = v15;
          VbglR0HGCMFastCall(v20, v18, 128);
          VbglR0PhysHeapFree(v18);
        }
        *(_QWORD *)(v12 + 16) = -1;
      }
      kfree(v12);
      return v7;
    }
    DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
    if ( DefaultInstance )
    {
      v7 = -12;
      if ( (unsigned int)s_LogRelMaxIt_cLogged_44914 <= 0x3F )
      {
        ++s_LogRelMaxIt_cLogged_44914;
        VBoxGuest_RTLogLoggerEx(
          DefaultInstance,
          16,
          337,
          "%Rfn: %M",
          "vbsf_inode_atomic_open",
          "could not allocate reg info\n");
      }
    }
    else
    {
      return (unsigned int)-12;
    }
  }
  else
  {
    v7 = -2;
    if ( !*(_QWORD *)(a2 + 16) )
    {
      v8 = vbsf_inode_lookup(a1, a2);
      if ( v8 > 0xFFFFFFFFFFFFF000LL )
        return (unsigned int)v8;
      else
        return (unsigned int)finish_no_open(a3, v8);
    }
  }
  return v7;
}
