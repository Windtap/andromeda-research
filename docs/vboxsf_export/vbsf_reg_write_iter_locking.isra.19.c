__int64 __fastcall vbsf_reg_write_iter_locking_isra_19(
        __int64 *a1,
        int *a2,
        unsigned __int64 a3,
        __int64 a4,
        int *a5,
        unsigned int a6,
        __int64 a7,
        __int64 a8,
        __int64 a9,
        __int64 a10,
        char a11)
{
  unsigned __int64 v13; // rax
  unsigned __int64 v14; // rdx
  unsigned __int64 v15; // rbx
  __int64 v16; // rax
  __int64 v17; // r13
  __int64 v18; // rax
  char *v19; // r14
  __int64 v20; // r15
  int v21; // eax
  unsigned int v22; // r12d
  __int64 v23; // rdx
  int v24; // edx
  bool v25; // cc
  int v26; // esi
  unsigned int v27; // r13d
  int PhysAddr; // eax
  int v29; // eax
  int v30; // eax
  unsigned int v31; // edx
  __int64 v32; // r12
  unsigned __int64 j; // r13
  __int64 v34; // rdi
  unsigned __int64 i; // rbx
  __int64 v37; // rax
  unsigned __int64 v39; // [rsp+18h] [rbp-160h]
  __int64 v40; // [rsp+20h] [rbp-158h]
  int v41; // [rsp+28h] [rbp-150h]
  unsigned __int64 v42; // [rsp+30h] [rbp-148h]
  __int64 v43; // [rsp+38h] [rbp-140h]
  bool v46; // [rsp+5Fh] [rbp-119h]
  char *v47; // [rsp+60h] [rbp-118h]
  unsigned __int64 v48; // [rsp+68h] [rbp-110h] BYREF
  unsigned __int64 v49; // [rsp+70h] [rbp-108h] BYREF
  __int64 v50; // [rsp+78h] [rbp-100h] BYREF
  _QWORD v51[9]; // [rsp+80h] [rbp-F8h] BYREF
  char v52; // [rsp+C8h] [rbp-B0h] BYREF

  v13 = vbsf_iter_max_span_of_pages(a2);
  v14 = 2;
  if ( a6 >= 2 )
    v14 = a6;
  if ( v14 <= v13 )
    v13 = v14;
  v15 = v13;
  v42 = v13;
  v16 = VbglR0PhysHeapAlloc(8 * v13 + 184);
  v17 = v16;
  if ( v15 > 4 && !v16 )
  {
    do
    {
      v15 >>= 1;
      v18 = VbglR0PhysHeapAlloc(8 * v15 + 184);
    }
    while ( !v18 && v15 > 4 );
    v42 = v15;
    v17 = v18;
  }
  v46 = v17 != 0;
  if ( v42 > 0x10 && v17 )
  {
    v19 = (char *)_kmalloc(8 * v42, 37748928);
    v47 = v19;
    if ( !v19 )
      goto LABEL_46;
  }
  else
  {
    v47 = 0;
    v19 = &v52;
  }
  if ( !v17 )
  {
LABEL_46:
    v43 = -12;
    goto LABEL_40;
  }
  v20 = v17;
  v43 = 0;
  memset(v51, 0, sizeof(v51));
  v51[2] = -1;
  while ( 1 )
  {
    v48 = 0;
    v49 = 0;
    v50 = 0;
    v21 = vbsf_iter_lock_pages_constprop_23(a2, 0, v51, v42, v19, &v48, &v50, (__int64 *)&v49);
    if ( v21 )
      break;
    v22 = v48;
    v23 = v48 - 1;
    if ( v48 )
    {
      do
      {
        *(_QWORD *)(v20 + 8 * v23 + 184) = (*(_QWORD *)&v19[8 * v23] + 0x160000000000LL) >> 6 << 12;
        --v23;
      }
      while ( v23 != -1 );
    }
    v24 = v49;
    v25 = v49 <= a3;
    *(_WORD *)(v20 + 180) = v50;
    if ( !v25 )
    {
      v49 = a3;
      v24 = a3;
    }
    v41 = v24;
    v40 = *(_QWORD *)(a7 + 16);
    v26 = *a5;
    *(_DWORD *)(v20 + 4) = (_DWORD)&unk_10001;
    v27 = 8 * v22 + 184;
    *(_DWORD *)(v20 + 8) = 0;
    *(_DWORD *)v20 = v27;
    *(_DWORD *)(v20 + 12) = -225;
    *(_QWORD *)(v20 + 16) = v27;
    PhysAddr = VbglR0PhysHeapGetPhysAddr(v20);
    *(_BYTE *)(v20 + 28) = 0;
    *(_DWORD *)(v20 + 56) = (_DWORD)&unk_10001;
    *(_DWORD *)(v20 + 24) = PhysAddr + 52;
    *(_DWORD *)(v20 + 52) = 8 * v22 + 132;
    v29 = g_SfClient;
    *(_DWORD *)(v20 + 60) = 63;
    *(_DWORD *)(v20 + 64) = -225;
    *(_DWORD *)(v20 + 68) = 0;
    *(_DWORD *)(v20 + 84) = v29;
    LOBYTE(v29) = g_fHostFeatures;
    *(_DWORD *)(v20 + 72) = 2;
    *(_DWORD *)(v20 + 76) = 0;
    *(_DWORD *)(v20 + 80) = -225;
    *(_DWORD *)(v20 + 88) = 6;
    *(_DWORD *)(v20 + 92) = 5;
    *(_DWORD *)(v20 + 96) = 1;
    *(_DWORD *)(v20 + 100) = v26;
    *(_QWORD *)(v20 + 116) = v40;
    *(_DWORD *)(v20 + 112) = 2;
    *(_DWORD *)(v20 + 128) = 2;
    *(_QWORD *)(v20 + 132) = a4;
    *(_DWORD *)(v20 + 144) = 1;
    *(_DWORD *)(v20 + 148) = v41;
    *(_DWORD *)(v20 + 160) = (v29 & 8) == 0 ? 10 : 13;
    *(_DWORD *)(v20 + 164) = v41;
    *(_DWORD *)(v20 + 168) = 124;
    *(_DWORD *)(v20 + 176) = 1;
    *(_WORD *)(v20 + 182) = v22;
    if ( v22 > 0xFFFF || (int)VbglR0HGCMFastCall(*(_QWORD *)&algn_FA24[4], v20, v27) < 0 )
    {
      v17 = v20;
      *(_QWORD *)(a9 + 40) = *(_QWORD *)(a9 + 32);
LABEL_52:
      for ( i = v48; i; --i )
        put_page(*(_QWORD *)&v19[8 * i - 8]);
      if ( v51[0] )
        put_page(v51[0]);
      v37 = -71;
      if ( v43 )
        v37 = v43;
      v43 = v37;
      goto LABEL_40;
    }
    v30 = *(_DWORD *)(v20 + 80);
    *(_QWORD *)(a9 + 40) = *(_QWORD *)(a9 + 32);
    if ( v30 < 0 )
    {
      v17 = v20;
      goto LABEL_52;
    }
    v31 = *(_DWORD *)(v20 + 148);
    v32 = v31;
    v39 = v31;
    if ( v31 > v49 )
    {
      v31 = v49;
      v39 = (unsigned int)v49;
      v32 = (unsigned int)v49;
    }
    if ( a10 && *(_QWORD *)(a10 + 80) )
      vbsf_reg_write_sync_page_cache_isra_15_part_16(a10, a4, v31, 0, v19, v50);
    for ( j = v48; j; --j )
      put_page(*(_QWORD *)&v19[8 * j - 8]);
    a4 += v32;
    v43 += v32;
    a3 -= v39;
    if ( a11 && (g_fSfFeatures & 1) != 0 )
      a4 = *(_QWORD *)(v20 + 132);
    *a1 = a4;
    if ( a4 > *(_QWORD *)(a8 + 80) )
      *(_QWORD *)(a8 + 80) = a4;
    *(_BYTE *)(a9 + 8) = 1;
    if ( !a3 )
    {
      v34 = v51[0];
      v17 = v20;
      goto LABEL_48;
    }
    if ( v49 > v39 )
    {
      v34 = v51[0];
      v17 = v20;
      if ( !v51[0] )
        goto LABEL_40;
      goto LABEL_39;
    }
  }
  v17 = v20;
  v34 = v51[0];
  v43 = v21;
LABEL_48:
  if ( v34 )
LABEL_39:
    put_page(v34);
LABEL_40:
  if ( v47 )
    kfree(v19);
  if ( v46 )
    VbglR0PhysHeapFree(v17);
  return v43;
}
