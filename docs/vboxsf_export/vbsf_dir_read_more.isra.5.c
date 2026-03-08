__int64 __fastcall vbsf_dir_read_more_isra_5(__int64 a1, int *a2, _DWORD *a3, char a4)
{
  __int64 result; // rax
  _DWORD *v7; // rax
  _DWORD *v8; // rbx
  unsigned __int64 v9; // r13
  __int64 v10; // rdx
  int v11; // ecx
  int v12; // r14d
  __int64 v13; // r15
  int PhysAddr; // eax
  bool v15; // zf
  int v16; // eax
  __int64 v17; // rdi
  int v18; // r12d
  __int64 v19; // rax
  __int64 v20; // rax
  __int64 DefaultInstance; // rax
  __int64 v22; // rax
  __int64 v23; // rax
  __int64 v24; // rax
  __int64 v25; // r8
  __int64 v26; // [rsp+0h] [rbp-48h]
  int v28; // [rsp+Ch] [rbp-3Ch]

  if ( *(_BYTE *)(a1 + 96) )
  {
    result = 0;
    if ( !a4 )
      return result;
    *(_BYTE *)(a1 + 96) = 0;
  }
  if ( !*(_QWORD *)(a1 + 64) )
  {
    v20 = _kmalloc((unsigned int)*a3, 37748928);
    *(_QWORD *)(a1 + 64) = v20;
    if ( v20 )
    {
      *(_DWORD *)(a1 + 60) = *a3;
    }
    else
    {
      v22 = kmem_cache_alloc_trace(kmalloc_caches[12], 37748928, 4096);
      *(_QWORD *)(a1 + 64) = v22;
      if ( !v22 )
      {
        DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
        if ( DefaultInstance && (unsigned int)s_LogRelMaxIt_cLogged_44780 <= 9 )
        {
          ++s_LogRelMaxIt_cLogged_44780;
          VBoxGuest_RTLogLoggerEx(DefaultInstance, 16, 337, "vbsf_dir_read_more: Failed to allocate buffer!\n");
        }
        return 4294967284LL;
      }
      *(_DWORD *)(a1 + 60) = 4096;
    }
  }
  v7 = (_DWORD *)VbglR0PhysHeapAlloc(256);
  v8 = v7;
  if ( !v7 )
    return 4294967284LL;
  v9 = *(_QWORD *)(a1 + 64);
  v10 = 0x77FF80000000LL;
  v11 = *(_DWORD *)(a1 + 60);
  v12 = *a2;
  if ( v9 >= 0xFFFFFFFF80000000LL )
    v10 = phys_base;
  v13 = *(_QWORD *)(a1 + 16);
  *v7 = 256;
  v7[1] = (_DWORD)&unk_10001;
  v7[2] = 0;
  v7[3] = -225;
  v7[4] = 256;
  v7[5] = 0;
  v28 = v11;
  v26 = v10;
  PhysAddr = VbglR0PhysHeapGetPhysAddr(v7);
  *((_BYTE *)v8 + 28) = 0;
  v8[13] = 204;
  v8[6] = PhysAddr + 52;
  v15 = (g_fHostFeatures & 4) == 0;
  v16 = g_SfClient;
  v8[14] = (_DWORD)&unk_10001;
  v8[15] = 63;
  v8[16] = -225;
  v8[17] = 0;
  v8[18] = 2;
  v8[19] = 0;
  v8[20] = -225;
  v8[21] = v16;
  v8[22] = 8;
  v8[23] = 8;
  v8[24] = 1;
  v8[25] = v12;
  v8[28] = 2;
  *(_QWORD *)(v8 + 29) = v13;
  v8[32] = 1;
  v8[33] = a4 != 0 ? 2 : 0;
  v8[36] = 1;
  v8[37] = v28;
  if ( v15 )
  {
    v8[40] = 5;
    v8[41] = 0;
    *((_QWORD *)v8 + 21) = 0;
    v8[44] = 6;
    v8[45] = v28;
    *((_QWORD *)v8 + 23) = v9;
  }
  else
  {
    v8[40] = 12;
    v8[42] = 172;
    v8[56] = 1;
    v8[41] = 0;
    *((_WORD *)v8 + 115) = 1;
    v19 = ((_WORD)v26 + (_WORD)v9) & 0xFFF;
    *((_WORD *)v8 + 114) = 0;
    v8[45] = v28;
    *((_QWORD *)v8 + 29) = -1;
    v8[44] = 12;
    v8[46] = 188;
    v8[60] = 2;
    *((_WORD *)v8 + 123) = 1;
    *((_WORD *)v8 + 122) = v19;
    *((_QWORD *)v8 + 31) = v26 + v9 + 0x80000000 - v19;
  }
  v17 = *(_QWORD *)&algn_FA24[4];
  v8[48] = 1;
  v8[49] = 0;
  v8[52] = 1;
  v8[53] = 0;
  v18 = VbglR0HGCMFastCall(v17, v8, 256);
  if ( v18 < 0 || (v18 = v8[20], v18 < 0) )
  {
    v23 = *(_QWORD *)(a1 + 64);
    *(_DWORD *)(a1 + 72) = 0;
    *(_DWORD *)(a1 + 76) = 0;
    *(_QWORD *)(a1 + 88) = v23;
    if ( v18 == -201 )
    {
      *(_BYTE *)(a1 + 96) = 1;
      v18 = 0;
    }
    else
    {
      v24 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
      if ( v24 && (unsigned int)s_LogRelMaxIt_cLogged_44782 <= 0xF )
      {
        v25 = (unsigned int)v18;
        ++s_LogRelMaxIt_cLogged_44782;
        v18 = -71;
        VBoxGuest_RTLogLoggerEx(v24, 16, 337, "vbsf_dir_read_more: VbglR0SfHostReqListDirContig2x -> %Rrc\n", v25);
      }
      else
      {
        v18 = -71;
      }
    }
  }
  else
  {
    *(_QWORD *)(a1 + 88) = *(_QWORD *)(a1 + 64);
    *(_DWORD *)(a1 + 72) = v8[37];
    *(_DWORD *)(a1 + 76) = v8[53];
    *(_BYTE *)(a1 + 96) = v8[49] == 0;
  }
  VbglR0PhysHeapFree(v8);
  return (unsigned int)v18;
}
