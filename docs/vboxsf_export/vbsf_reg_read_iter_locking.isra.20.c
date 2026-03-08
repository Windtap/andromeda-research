__int64 __fastcall vbsf_reg_read_iter_locking_isra_20(
        __int64 *a1,
        int *a2,
        unsigned __int64 a3,
        int *a4,
        unsigned int a5,
        __int64 a6)
{
  unsigned __int64 v7; // rax
  unsigned __int64 v8; // rdx
  unsigned __int64 v9; // r13
  __int64 v10; // rax
  __int64 v11; // r14
  __int64 v12; // rax
  char *v13; // rbx
  __int64 v14; // r13
  int v15; // eax
  unsigned int v16; // ebp
  __int64 v17; // rax
  int v18; // edx
  bool v19; // cc
  int v20; // r8d
  unsigned int v21; // r14d
  int PhysAddr; // eax
  int v23; // eax
  int v24; // eax
  unsigned __int64 v25; // r14
  int v26; // ebp
  _QWORD *v27; // r13
  unsigned __int64 v28; // rax
  unsigned __int64 v29; // rcx
  unsigned __int64 v30; // rdx
  __int64 v31; // rdi
  __int64 v33; // rax
  __int64 v35; // [rsp+20h] [rbp-158h]
  __int64 v36; // [rsp+20h] [rbp-158h]
  __int64 v37; // [rsp+28h] [rbp-150h]
  int v38; // [rsp+30h] [rbp-148h]
  __int64 v39; // [rsp+38h] [rbp-140h]
  unsigned __int64 v40; // [rsp+40h] [rbp-138h]
  int v43; // [rsp+58h] [rbp-120h]
  int v44; // [rsp+58h] [rbp-120h]
  bool v45; // [rsp+5Fh] [rbp-119h]
  char *v46; // [rsp+60h] [rbp-118h]
  unsigned __int64 v47; // [rsp+68h] [rbp-110h] BYREF
  unsigned __int64 v48; // [rsp+70h] [rbp-108h] BYREF
  __int64 v49; // [rsp+78h] [rbp-100h] BYREF
  _QWORD v50[9]; // [rsp+80h] [rbp-F8h] BYREF
  char v51; // [rsp+C8h] [rbp-B0h] BYREF

  v7 = vbsf_iter_max_span_of_pages(a2);
  v8 = 2;
  if ( a5 >= 2 )
    v8 = a5;
  if ( v8 <= v7 )
    v7 = v8;
  v9 = v7;
  v10 = VbglR0PhysHeapAlloc(8 * v7 + 184);
  v11 = v10;
  if ( v9 > 4 && !v10 )
  {
    do
    {
      v9 >>= 1;
      v12 = VbglR0PhysHeapAlloc(8 * v9 + 184);
    }
    while ( !v12 && v9 > 4 );
    v11 = v12;
  }
  v45 = v11 != 0;
  if ( v9 > 0x10 && v11 )
  {
    v13 = (char *)_kmalloc(8 * v9, 37748928);
    v46 = v13;
    if ( !v13 )
      goto LABEL_44;
  }
  else
  {
    v46 = 0;
    v13 = &v51;
  }
  if ( !v11 )
  {
LABEL_44:
    v39 = -12;
    goto LABEL_38;
  }
  v40 = v9;
  v14 = v11;
  v39 = 0;
  memset(v50, 0, sizeof(v50));
  v50[2] = -1;
  while ( 1 )
  {
    v47 = 0;
    v48 = 0;
    v49 = 0;
    v15 = vbsf_iter_lock_pages_constprop_23(a2, 1u, v50, v40, v13, &v47, &v49, (__int64 *)&v48);
    if ( v15 )
    {
      v31 = v50[0];
      v11 = v14;
      v39 = v15;
      goto LABEL_46;
    }
    v16 = v47;
    v17 = v47 - 1;
    if ( v47 )
    {
      do
      {
        *(_QWORD *)(v14 + 8 * v17 + 184) = (*(_QWORD *)&v13[8 * v17] + 0x160000000000LL) >> 6 << 12;
        --v17;
      }
      while ( v17 != -1 );
    }
    v18 = v48;
    v19 = v48 <= a3;
    *(_WORD *)(v14 + 180) = v49;
    if ( !v19 )
    {
      v48 = a3;
      v18 = a3;
    }
    v38 = v18;
    v37 = *a1;
    v35 = *(_QWORD *)(a6 + 16);
    v20 = *a4;
    *(_DWORD *)(v14 + 4) = (_DWORD)&unk_10001;
    v21 = 8 * v16 + 184;
    *(_DWORD *)(v14 + 8) = 0;
    *(_DWORD *)v14 = v21;
    *(_DWORD *)(v14 + 12) = -225;
    *(_QWORD *)(v14 + 16) = v21;
    v43 = v20;
    PhysAddr = VbglR0PhysHeapGetPhysAddr(v14);
    *(_BYTE *)(v14 + 28) = 0;
    *(_DWORD *)(v14 + 56) = (_DWORD)&unk_10001;
    *(_DWORD *)(v14 + 24) = PhysAddr + 52;
    *(_DWORD *)(v14 + 52) = 8 * v16 + 132;
    v23 = g_SfClient;
    *(_DWORD *)(v14 + 60) = 63;
    *(_DWORD *)(v14 + 64) = -225;
    *(_DWORD *)(v14 + 68) = 0;
    *(_DWORD *)(v14 + 84) = v23;
    LOBYTE(v23) = g_fHostFeatures;
    *(_DWORD *)(v14 + 72) = 2;
    *(_DWORD *)(v14 + 76) = 0;
    *(_DWORD *)(v14 + 80) = -225;
    *(_DWORD *)(v14 + 88) = 5;
    *(_DWORD *)(v14 + 92) = 5;
    *(_DWORD *)(v14 + 96) = 1;
    *(_DWORD *)(v14 + 100) = v43;
    *(_QWORD *)(v14 + 116) = v35;
    *(_DWORD *)(v14 + 112) = 2;
    *(_DWORD *)(v14 + 128) = 2;
    *(_QWORD *)(v14 + 132) = v37;
    *(_DWORD *)(v14 + 144) = 1;
    *(_DWORD *)(v14 + 148) = v38;
    *(_DWORD *)(v14 + 160) = (v23 & 8) == 0 ? 10 : 13;
    *(_DWORD *)(v14 + 164) = v38;
    *(_DWORD *)(v14 + 168) = 124;
    *(_DWORD *)(v14 + 176) = 2;
    *(_WORD *)(v14 + 182) = v16;
    if ( v16 > 0xFFFF )
    {
      v44 = -54;
    }
    else
    {
      v24 = VbglR0HGCMFastCall(*(_QWORD *)&algn_FA24[4], v14, v21);
      if ( v24 < 0 )
        v44 = v24;
      else
        v44 = *(_DWORD *)(v14 + 80);
    }
    v25 = v47;
    v26 = *a2 & 6;
    if ( v47 )
    {
      v36 = v14;
      do
      {
        while ( 1 )
        {
          v27 = *(_QWORD **)&v13[8 * v25 - 8];
          if ( !v26 && (*v27 & 0x400LL) == 0 )
            break;
          put_page(*(_QWORD *)&v13[8 * v25-- - 8]);
          if ( !v25 )
            goto LABEL_30;
        }
        set_page_dirty(*(_QWORD *)&v13[8 * v25 - 8]);
        put_page(v27);
        --v25;
      }
      while ( v25 );
LABEL_30:
      v14 = v36;
    }
    if ( v44 < 0 )
      break;
    v28 = *(unsigned int *)(v14 + 148);
    v29 = v48;
    v30 = v28;
    if ( v28 > v48 )
    {
      v30 = (unsigned int)v48;
      v28 = (unsigned int)v48;
    }
    v39 += v28;
    *a1 += v28;
    a3 -= v30;
    if ( !a3 )
    {
      v11 = v14;
      v31 = v50[0];
LABEL_46:
      if ( !v31 )
        goto LABEL_38;
LABEL_37:
      put_page(v31);
      goto LABEL_38;
    }
    if ( v30 < v29 )
    {
      v31 = v50[0];
      v11 = v14;
      if ( !v50[0] )
        goto LABEL_38;
      goto LABEL_37;
    }
  }
  v11 = v14;
  if ( v50[0] )
    put_page(v50[0]);
  v33 = -71;
  if ( v39 )
    v33 = v39;
  v39 = v33;
LABEL_38:
  if ( v46 )
    kfree(v13);
  if ( v45 )
    VbglR0PhysHeapFree(v11);
  return v39;
}
