__int64 __fastcall vbsf_reg_write_locking_isra_21(
        _DWORD *a1,
        unsigned __int64 a2,
        unsigned __int64 a3,
        __int64 *a4,
        __int64 a5,
        __int64 a6,
        __int64 a7,
        int *a8,
        unsigned int a9,
        __int64 a10)
{
  unsigned __int64 v10; // rdi
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // rdx
  unsigned __int64 v13; // rax
  unsigned __int64 v14; // rbp
  __int64 v15; // rax
  __int64 v16; // rbx
  __int64 v17; // rax
  char *v18; // r15
  unsigned __int64 v19; // r13
  unsigned __int64 v20; // rax
  unsigned __int64 v21; // rbp
  __int64 user_pages_unlocked; // rax
  int v23; // r14d
  int v24; // r8d
  unsigned __int64 v25; // rdx
  __int64 v26; // r14
  int v27; // esi
  int PhysAddr; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  unsigned int v32; // edx
  __int64 v33; // r14
  unsigned __int64 v34; // rax
  __int64 v35; // rdi
  int v36; // eax
  bool v38; // r13
  unsigned __int64 v39; // [rsp+8h] [rbp-128h]
  unsigned __int64 v41; // [rsp+18h] [rbp-118h]
  unsigned __int64 v43; // [rsp+28h] [rbp-108h]
  unsigned __int64 v44; // [rsp+28h] [rbp-108h]
  unsigned __int64 v45; // [rsp+28h] [rbp-108h]
  int v46; // [rsp+30h] [rbp-100h]
  unsigned __int64 v47; // [rsp+40h] [rbp-F0h]
  __int64 v48; // [rsp+48h] [rbp-E8h]
  unsigned __int64 v49; // [rsp+50h] [rbp-E0h]
  unsigned __int64 v51; // [rsp+60h] [rbp-D0h]
  char v52; // [rsp+68h] [rbp-C8h]
  char *v53; // [rsp+70h] [rbp-C0h]
  char v55; // [rsp+80h] [rbp-B0h] BYREF

  v10 = a3 + 4095;
  v39 = a2;
  v11 = a3 + 4095 + (a2 & 0xFFF);
  v41 = a3;
  v12 = 1;
  v13 = v11 >> 12;
  if ( a9 )
    v12 = a9;
  v43 = v10;
  if ( v12 <= v13 )
    v13 = v12;
  v14 = v13;
  v47 = v13;
  v15 = VbglR0PhysHeapAlloc(8 * v13 + 184);
  v16 = v15;
  if ( v14 > 4 && !v15 )
  {
    do
    {
      v14 >>= 1;
      v17 = VbglR0PhysHeapAlloc(8 * v14 + 184);
    }
    while ( !v17 && v14 > 4 );
    v47 = v14;
    v16 = v17;
  }
  if ( v47 > 0x10 && v16 )
  {
    v18 = (char *)_kmalloc(8 * v47, 37748928);
    v53 = v18;
    if ( !v18 )
      goto LABEL_44;
  }
  else
  {
    v53 = 0;
    v18 = &v55;
  }
  if ( !v16 )
  {
LABEL_44:
    v48 = -12;
    goto LABEL_48;
  }
  v49 = __readgsqword((unsigned int)&current_task);
  v48 = 0;
  v51 = __readgsqword((unsigned int)&cpu_tss + 4);
  while ( 1 )
  {
    while ( 1 )
    {
      v19 = v41;
      v20 = v39 & 0xFFF;
      *(_WORD *)(v16 + 180) = v20;
      v21 = (v43 + v20) >> 12;
      if ( v21 > v47 )
      {
        v21 = v47;
        v19 = (v47 << 12) - v20;
      }
      user_pages_unlocked = get_user_pages_unlocked(v49, *(_QWORD *)(v49 + 1768), v39, v21, 0, 1, v18);
      v23 = user_pages_unlocked;
      if ( v21 == user_pages_unlocked )
        goto LABEL_24;
      if ( user_pages_unlocked >= 0 )
      {
        vbsf_unlock_user_pages((__int64)v18, user_pages_unlocked, 0, 0);
        v48 = -14;
        goto LABEL_48;
      }
      v24 = user_pages_unlocked;
      if ( __CFADD__(v39, v21 << 12)
        || *(_QWORD *)(v51 - 16360) < v39 + (v21 << 12)
        || v39 <= 0x7FFFFFFFEFFFLL
        || (v36 = vbsf_lock_kernel_pages(v39, 0, v21, (__int64)v18), v24 = v23, v36) )
      {
        if ( v23 )
        {
          v48 = v24;
          goto LABEL_48;
        }
LABEL_24:
        v52 = 0;
        goto LABEL_25;
      }
      v52 = 1;
LABEL_25:
      v25 = v21 - 1;
      if ( v21 )
      {
        do
        {
          *(_QWORD *)(v16 + 8 * v25 + 184) = (*(_QWORD *)&v18[8 * v25] + 0x160000000000LL) >> 6 << 12;
          --v25;
        }
        while ( v25 != -1 );
      }
      v46 = 8 * v21 + 184;
      v26 = *(_QWORD *)(a10 + 16);
      v27 = *a8;
      *(_DWORD *)v16 = v46;
      *(_DWORD *)(v16 + 16) = v46;
      *(_DWORD *)(v16 + 4) = (_DWORD)&unk_10001;
      *(_DWORD *)(v16 + 8) = 0;
      *(_DWORD *)(v16 + 12) = -225;
      *(_DWORD *)(v16 + 20) = 0;
      PhysAddr = VbglR0PhysHeapGetPhysAddr(v16);
      *(_BYTE *)(v16 + 28) = 0;
      *(_DWORD *)(v16 + 56) = (_DWORD)&unk_10001;
      *(_DWORD *)(v16 + 24) = PhysAddr + 52;
      *(_DWORD *)(v16 + 60) = 63;
      *(_DWORD *)(v16 + 64) = -225;
      *(_DWORD *)(v16 + 68) = 0;
      *(_DWORD *)(v16 + 52) = 8 * v21 + 132;
      v29 = g_SfClient;
      *(_DWORD *)(v16 + 72) = 2;
      *(_DWORD *)(v16 + 76) = 0;
      *(_DWORD *)(v16 + 80) = -225;
      *(_DWORD *)(v16 + 84) = v29;
      *(_DWORD *)(v16 + 88) = 6;
      *(_DWORD *)(v16 + 92) = 5;
      *(_DWORD *)(v16 + 96) = 1;
      *(_QWORD *)(v16 + 132) = a5;
      LOBYTE(v29) = g_fHostFeatures;
      *(_DWORD *)(v16 + 100) = v27;
      *(_DWORD *)(v16 + 112) = 2;
      *(_QWORD *)(v16 + 116) = v26;
      *(_DWORD *)(v16 + 128) = 2;
      *(_DWORD *)(v16 + 148) = v19;
      *(_DWORD *)(v16 + 164) = v19;
      *(_DWORD *)(v16 + 144) = 1;
      *(_DWORD *)(v16 + 168) = 124;
      *(_DWORD *)(v16 + 160) = (v29 & 8) == 0 ? 10 : 13;
      *(_DWORD *)(v16 + 176) = 1;
      *(_WORD *)(v16 + 182) = v21;
      if ( (unsigned int)v21 > 0xFFFF )
      {
        v38 = 0;
        goto LABEL_60;
      }
      v30 = VbglR0HGCMFastCall(*(_QWORD *)&algn_FA24[4], v16, 8 * v21 + 184);
      if ( v30 < 0 )
        break;
      v31 = *(_DWORD *)(v16 + 80);
      *(_QWORD *)(a7 + 40) = *(_QWORD *)(a7 + 32);
      if ( v31 < 0 )
      {
        v38 = v31 == -8 && v47 > 4;
        goto LABEL_57;
      }
      v32 = *(_DWORD *)(v16 + 148);
      v33 = v32;
      if ( v19 < v32 )
      {
        v34 = (unsigned int)v19;
        v32 = v19;
        v33 = (unsigned int)v19;
      }
      else
      {
        v34 = *(unsigned int *)(v16 + 148);
      }
      v35 = *(_QWORD *)(a6 + 48);
      if ( v35 && *(_QWORD *)(v35 + 80) )
      {
        v45 = v34;
        vbsf_reg_write_sync_page_cache_isra_15_part_16(v35, a5, v32, 0, v18, v39 & 0xFFF);
        v34 = v45;
      }
      v44 = v34;
      vbsf_unlock_user_pages((__int64)v18, v21, 0, v52);
      v48 += v33;
      a5 += v33;
      v39 += v44;
      v41 -= v44;
      if ( (*a1 & 0x400) != 0 && (g_fSfFeatures & 1) != 0 )
        a5 = *(_QWORD *)(v16 + 132);
      if ( *(_QWORD *)(a6 + 80) < a5 )
        *(_QWORD *)(a6 + 80) = a5;
      *(_BYTE *)(a7 + 8) = 1;
      if ( !v41 || v44 < v19 )
        goto LABEL_53;
      v43 = v41 + 4095;
    }
    v38 = v47 > 4 && v30 == -8;
LABEL_60:
    *(_QWORD *)(a7 + 40) = *(_QWORD *)(a7 + 32);
LABEL_57:
    vbsf_unlock_user_pages((__int64)v18, v21, 0, v52);
    if ( !v38 )
      break;
    v47 >>= 2;
  }
  if ( v48 )
  {
LABEL_53:
    *a4 = a5;
    goto LABEL_48;
  }
  v48 = -71;
LABEL_48:
  if ( v53 )
    kfree(v18);
  if ( v16 )
    VbglR0PhysHeapFree(v16);
  return v48;
}
