__int64 __fastcall vbsf_reg_read_locking_isra_22(
        unsigned __int64 a1,
        unsigned __int64 a2,
        __int64 *a3,
        int *a4,
        unsigned int a5,
        __int64 a6)
{
  __int64 v6; // rcx
  unsigned __int64 v7; // rdx
  unsigned __int64 v8; // rax
  unsigned __int64 v9; // rbp
  __int64 v10; // rax
  __int64 v11; // rbx
  __int64 v12; // rax
  char *v13; // r15
  unsigned __int64 v14; // rbp
  unsigned __int64 v15; // rax
  unsigned __int64 v16; // r12
  __int64 user_pages_unlocked; // rax
  int v18; // r13d
  int v19; // r8d
  unsigned __int64 v20; // rdx
  __int64 v21; // r13
  int v22; // esi
  int PhysAddr; // eax
  int v24; // eax
  int v25; // eax
  int v26; // r13d
  unsigned __int64 v27; // rax
  unsigned __int64 v28; // rdx
  int v29; // eax
  bool v31; // bp
  unsigned __int64 v32; // [rsp+8h] [rbp-128h]
  unsigned __int64 v33; // [rsp+10h] [rbp-120h]
  __int64 v34; // [rsp+18h] [rbp-118h]
  unsigned __int64 v35; // [rsp+20h] [rbp-110h]
  int v36; // [rsp+28h] [rbp-108h]
  char v37; // [rsp+34h] [rbp-FCh]
  unsigned __int64 v38; // [rsp+38h] [rbp-F8h]
  __int64 v39; // [rsp+40h] [rbp-F0h]
  unsigned __int64 v40; // [rsp+48h] [rbp-E8h]
  unsigned __int64 v43; // [rsp+60h] [rbp-D0h]
  char *v44; // [rsp+70h] [rbp-C0h]
  char v46; // [rsp+80h] [rbp-B0h] BYREF

  v6 = *a3;
  v7 = 1;
  v32 = a1;
  v33 = a2;
  v34 = v6;
  v35 = a2 + 4095;
  v8 = (a2 + 4095 + (a1 & 0xFFF)) >> 12;
  if ( a5 )
    v7 = a5;
  if ( v7 <= v8 )
    v8 = v7;
  v9 = v8;
  v38 = v8;
  v10 = VbglR0PhysHeapAlloc(8 * v8 + 184);
  v11 = v10;
  if ( v9 > 4 && !v10 )
  {
    do
    {
      v9 >>= 1;
      v12 = VbglR0PhysHeapAlloc(8 * v9 + 184);
    }
    while ( !v12 && v9 > 4 );
    v38 = v9;
    v11 = v12;
  }
  if ( v38 > 0x10 && v11 )
  {
    v13 = (char *)_kmalloc(8 * v38, 37748928);
    v44 = v13;
    if ( !v13 )
      goto LABEL_36;
  }
  else
  {
    v44 = 0;
    v13 = &v46;
  }
  if ( !v11 )
  {
LABEL_36:
    v39 = -12;
    goto LABEL_40;
  }
  v40 = __readgsqword((unsigned int)&current_task);
  v39 = 0;
  v43 = __readgsqword((unsigned int)&cpu_tss + 4);
  while ( 1 )
  {
    while ( 1 )
    {
      v14 = v33;
      v15 = v32 & 0xFFF;
      *(_WORD *)(v11 + 180) = v15;
      v16 = (v35 + v15) >> 12;
      if ( v16 > v38 )
      {
        v16 = v38;
        v14 = (v38 << 12) - v15;
      }
      user_pages_unlocked = get_user_pages_unlocked(v40, *(_QWORD *)(v40 + 1768), v32, v16, 1, 1, v13);
      v18 = user_pages_unlocked;
      if ( v16 == user_pages_unlocked )
        goto LABEL_24;
      if ( user_pages_unlocked >= 0 )
      {
        vbsf_unlock_user_pages((__int64)v13, user_pages_unlocked, 0, 0);
        v39 = -14;
        goto LABEL_40;
      }
      v19 = user_pages_unlocked;
      if ( __CFADD__(v32, v16 << 12)
        || *(_QWORD *)(v43 - 16360) < v32 + (v16 << 12)
        || v32 <= 0x7FFFFFFFEFFFLL
        || (v29 = vbsf_lock_kernel_pages(v32, 1, v16, (__int64)v13), v19 = v18, v29) )
      {
        if ( v18 )
        {
          v39 = v19;
          goto LABEL_40;
        }
LABEL_24:
        v37 = 0;
        goto LABEL_25;
      }
      v37 = 1;
LABEL_25:
      v20 = v16 - 1;
      if ( v16 )
      {
        do
        {
          *(_QWORD *)(v11 + 8 * v20 + 184) = (*(_QWORD *)&v13[8 * v20] + 0x160000000000LL) >> 6 << 12;
          --v20;
        }
        while ( v20 != -1 );
      }
      v36 = 8 * v16 + 184;
      v21 = *(_QWORD *)(a6 + 16);
      v22 = *a4;
      *(_DWORD *)v11 = v36;
      *(_DWORD *)(v11 + 16) = v36;
      *(_DWORD *)(v11 + 4) = (_DWORD)&unk_10001;
      *(_DWORD *)(v11 + 8) = 0;
      *(_DWORD *)(v11 + 12) = -225;
      *(_DWORD *)(v11 + 20) = 0;
      PhysAddr = VbglR0PhysHeapGetPhysAddr(v11);
      *(_BYTE *)(v11 + 28) = 0;
      *(_DWORD *)(v11 + 56) = (_DWORD)&unk_10001;
      *(_DWORD *)(v11 + 24) = PhysAddr + 52;
      *(_DWORD *)(v11 + 60) = 63;
      *(_DWORD *)(v11 + 64) = -225;
      *(_DWORD *)(v11 + 68) = 0;
      *(_DWORD *)(v11 + 52) = 8 * v16 + 132;
      v24 = g_SfClient;
      *(_DWORD *)(v11 + 72) = 2;
      *(_DWORD *)(v11 + 76) = 0;
      *(_DWORD *)(v11 + 80) = -225;
      *(_DWORD *)(v11 + 84) = v24;
      *(_DWORD *)(v11 + 88) = 5;
      *(_DWORD *)(v11 + 92) = 5;
      *(_DWORD *)(v11 + 96) = 1;
      *(_QWORD *)(v11 + 132) = v34;
      LOBYTE(v24) = g_fHostFeatures;
      *(_DWORD *)(v11 + 100) = v22;
      *(_DWORD *)(v11 + 112) = 2;
      *(_QWORD *)(v11 + 116) = v21;
      *(_DWORD *)(v11 + 148) = v14;
      *(_DWORD *)(v11 + 164) = v14;
      *(_DWORD *)(v11 + 128) = 2;
      *(_DWORD *)(v11 + 144) = 1;
      *(_DWORD *)(v11 + 168) = 124;
      *(_DWORD *)(v11 + 160) = (v24 & 8) == 0 ? 10 : 13;
      *(_DWORD *)(v11 + 176) = 2;
      *(_WORD *)(v11 + 182) = v16;
      if ( (unsigned int)v16 > 0xFFFF )
      {
        v31 = 0;
        goto LABEL_52;
      }
      v25 = VbglR0HGCMFastCall(*(_QWORD *)&algn_FA24[4], v11, 8 * v16 + 184);
      if ( v25 < 0 )
        break;
      v26 = *(_DWORD *)(v11 + 80);
      vbsf_unlock_user_pages((__int64)v13, v16, 1, v37);
      if ( v26 < 0 )
      {
        v31 = v26 == -8 && v38 > 4;
        goto LABEL_49;
      }
      v27 = *(unsigned int *)(v11 + 148);
      if ( v14 < v27 )
      {
        v28 = (unsigned int)v14;
        v27 = (unsigned int)v14;
      }
      else
      {
        v28 = *(unsigned int *)(v11 + 148);
      }
      v39 += v27;
      v34 += v27;
      v32 += v28;
      v33 -= v28;
      if ( !v33 || v28 < v14 )
        goto LABEL_45;
      v35 = v33 + 4095;
    }
    v31 = v38 > 4 && v25 == -8;
LABEL_52:
    vbsf_unlock_user_pages((__int64)v13, v16, 1, v37);
LABEL_49:
    if ( !v31 )
      break;
    v38 >>= 2;
  }
  if ( v39 )
  {
LABEL_45:
    *a3 = v34;
    goto LABEL_40;
  }
  v39 = -71;
LABEL_40:
  if ( v44 )
    kfree(v13);
  if ( v11 )
    VbglR0PhysHeapFree(v11);
  return v39;
}
