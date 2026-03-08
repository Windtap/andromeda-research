__int64 __fastcall vbsf_dir_open(__int64 a1, __int64 a2)
{
  const void **v2; // rbp
  __int64 v3; // rbx
  unsigned int v4; // r15d
  __int64 v5; // rax
  __int64 v6; // r14
  __int64 v7; // rax
  __int64 v8; // r13
  bool v9; // zf
  int v10; // ecx
  int v11; // r15d
  int v12; // edx
  int PhysAddr; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // ebx
  int v20; // r15d
  __int64 DefaultInstance; // rax
  __int64 v22; // rax
  __int64 v23; // rax
  int *v24; // [rsp+10h] [rbp-58h]
  unsigned int v25; // [rsp+20h] [rbp-48h]
  int v26; // [rsp+24h] [rbp-44h]
  __int64 v27; // [rsp+30h] [rbp-38h]

  v2 = *(const void ***)(a1 + 552);
  v3 = *(_QWORD *)(a2 + 24);
  v24 = *(int **)(*(_QWORD *)(a1 + 40) + 1120LL);
  if ( !v24 || !v2 )
    return (unsigned int)-22;
  if ( *(_QWORD *)(a2 + 208) )
    return 0;
  v4 = -12;
  v5 = kmem_cache_alloc_trace(kmalloc_caches[7], 37748928, 104);
  v6 = v5;
  if ( v5 )
  {
    memset((void *)v5, 0, 0x68u);
    *(_DWORD *)(v5 + 56) = 419890951;
    *(_DWORD *)(v5 + 36) = 1;
    *(_QWORD *)(v5 + 40) = v5 + 40;
    *(_QWORD *)(v5 + 48) = v5 + 40;
    v7 = VbglR0PhysHeapAlloc((unsigned int)*(unsigned __int16 *)*v2 + 256);
    v8 = v7;
    if ( !v7 )
    {
      v18 = -12;
      DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
      if ( DefaultInstance && (unsigned int)s_LogRelMaxIt_cLogged_44753 <= 0x3F )
      {
        ++s_LogRelMaxIt_cLogged_44753;
        VBoxGuest_RTLogLoggerEx(
          DefaultInstance,
          16,
          337,
          "%Rfn: %M",
          "vbsf_dir_open",
          "failed to allocate %zu bytes for '%s'\n",
          *(unsigned __int16 *)*v2 + 256LL,
          (char *)*v2 + 4);
      }
      goto LABEL_15;
    }
    v27 = v7 + 252;
    memcpy((void *)(v7 + 252), *v2, *(unsigned __int16 *)*v2 + 4LL);
    memset((void *)(v8 + 144), 0, 0x68u);
    v9 = (g_fHostFeatures & 2) == 0;
    *(_DWORD *)(v8 + 248) = 0;
    *(_QWORD *)(v8 + 144) = -1;
    *(_DWORD *)(v8 + 156) = 4356;
    v10 = *v24;
    if ( v9 )
    {
      v11 = 92;
      v12 = 144;
    }
    else
    {
      v20 = *(unsigned __int16 *)(v8 + 252);
      v12 = v20 + 256;
      v11 = v20 + 204;
    }
    *(_DWORD *)v8 = v12;
    *(_DWORD *)(v8 + 16) = v12;
    *(_DWORD *)(v8 + 4) = (_DWORD)&unk_10001;
    *(_DWORD *)(v8 + 8) = 0;
    *(_DWORD *)(v8 + 12) = -225;
    *(_DWORD *)(v8 + 20) = 0;
    v26 = v10;
    v25 = v12;
    PhysAddr = VbglR0PhysHeapGetPhysAddr(v8);
    *(_BYTE *)(v8 + 28) = 0;
    *(_DWORD *)(v8 + 52) = v11;
    *(_DWORD *)(v8 + 24) = PhysAddr + 52;
    v9 = (g_fHostFeatures & 2) == 0;
    v14 = g_SfClient;
    *(_DWORD *)(v8 + 56) = (_DWORD)&unk_10001;
    *(_DWORD *)(v8 + 60) = 63;
    *(_DWORD *)(v8 + 64) = -225;
    *(_DWORD *)(v8 + 68) = 0;
    *(_DWORD *)(v8 + 72) = 2;
    *(_DWORD *)(v8 + 76) = 0;
    *(_DWORD *)(v8 + 80) = -225;
    *(_DWORD *)(v8 + 84) = v14;
    *(_DWORD *)(v8 + 88) = 3;
    *(_DWORD *)(v8 + 92) = 3;
    *(_DWORD *)(v8 + 96) = 1;
    *(_DWORD *)(v8 + 100) = v26;
    v15 = *(unsigned __int16 *)(v8 + 252);
    if ( v9 )
    {
      *(_DWORD *)(v8 + 112) = 5;
      *(_DWORD *)(v8 + 128) = 4;
      *(_DWORD *)(v8 + 132) = 108;
      *(_QWORD *)(v8 + 136) = v8 + 144;
      *(_DWORD *)(v8 + 116) = v15 + 4;
      *(_QWORD *)(v8 + 120) = v27;
    }
    else
    {
      *(_DWORD *)(v8 + 112) = 11;
      *(_DWORD *)(v8 + 128) = 11;
      *(_DWORD *)(v8 + 136) = 108;
      *(_DWORD *)(v8 + 120) = v15 + 4;
      v16 = *(unsigned __int8 *)(v8 + 116);
      BYTE1(v16) = -56;
      *(_DWORD *)(v8 + 116) = v16;
      v17 = *(unsigned __int8 *)(v8 + 132);
      *(_BYTE *)(v8 + 116) = 1;
      BYTE1(v17) |= 0x5Cu;
      *(_DWORD *)(v8 + 132) = v17;
      *(_BYTE *)(v8 + 132) = 3;
    }
    if ( (int)VbglR0HGCMFastCall(*(_QWORD *)&algn_FA24[4], v8, v25) < 0 || *(int *)(v8 + 80) < 0 )
    {
      v18 = -1;
      goto LABEL_14;
    }
    if ( *(_DWORD *)(v8 + 152) != 3 )
    {
      *(_QWORD *)(v3 + 120) = jiffies - 0x3FFFFFFFLL;
      v18 = -2;
      *((_BYTE *)v2 + 8) = 1;
LABEL_14:
      VbglR0PhysHeapFree(v8);
LABEL_15:
      *(_DWORD *)(v6 + 56) = 428344584;
      v4 = v18;
      kfree(v6);
      return v4;
    }
    vbsf_update_inode(a1, v2, v8 + 160, v24, 1, 0);
    v22 = jiffies;
    do
    {
      *(_QWORD *)(v3 + 120) = v22;
      v3 = *(_QWORD *)(v3 + 24);
    }
    while ( v3 != *(_QWORD *)(v3 + 24) );
    v23 = *(_QWORD *)(v8 + 144);
    *(_DWORD *)(v6 + 28) = 1;
    v4 = 0;
    *(_DWORD *)(v6 + 24) = 1963132705;
    *(_QWORD *)(v6 + 16) = v23;
    vbsf_handle_append(v2, v6);
    *(_QWORD *)(a2 + 208) = v6;
    VbglR0PhysHeapFree(v8);
  }
  return v4;
}
