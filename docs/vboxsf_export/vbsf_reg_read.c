__int64 __fastcall vbsf_reg_read(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, __int64 *a4)
{
  __int64 v5; // r15
  __int64 v6; // r10
  __int64 v7; // rdx
  int *v8; // r14
  __int64 result; // rax
  unsigned int v10; // eax
  int v13; // ecx
  __int64 v14; // rax
  __int64 v15; // rax
  __int64 v16; // rbp
  __int64 v17; // rcx
  __int64 v18; // rsi
  int v19; // r14d
  unsigned int v20; // r15d
  int PhysAddr; // eax
  bool v22; // zf
  int v23; // eax
  int v24; // eax
  __int64 v25; // [rsp+0h] [rbp-A8h]
  int v26; // [rsp+14h] [rbp-94h]
  _QWORD v27[2]; // [rsp+18h] [rbp-90h] BYREF
  _BYTE v28[40]; // [rsp+28h] [rbp-80h] BYREF
  __int64 v29; // [rsp+50h] [rbp-58h] BYREF
  __int64 v30; // [rsp+58h] [rbp-50h]
  __int64 v31; // [rsp+60h] [rbp-48h]
  __int64 v32; // [rsp+68h] [rbp-40h]
  __int64 v33; // [rsp+70h] [rbp-38h]

  v5 = *(_QWORD *)(a1 + 208);
  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 48LL);
  v7 = *(_QWORD *)(v6 + 48);
  v8 = *(int **)(*(_QWORD *)(v6 + 40) + 1120LL);
  result = -22;
  if ( (*(_WORD *)v6 & 0xF000) != 0x8000 )
    return result;
  result = 0;
  if ( !a3 )
    return result;
  v10 = *(_DWORD *)(a1 + 64);
  if ( (v10 & 0x4000) == 0 )
  {
    v13 = v8[15];
    if ( v13 != 1 && ((unsigned int)(v13 - 3) <= 1 || v7 && *(_QWORD *)(v7 + 80) && *(int *)(v7 + 28) > 0) )
    {
      v29 = a1;
      v33 = (v10 >> 9) & 2LL;
      v14 = *a4;
      v27[0] = a2;
      v27[1] = a3;
      v31 = 0;
      v30 = v14;
      v32 = 0;
      iov_iter_init(v28, 0, v27, 1, a3);
      result = generic_file_read_iter(&v29, v28);
      *a4 = v30;
      return result;
    }
  }
  if ( a3 > 0xB50 )
    return vbsf_reg_read_locking_isra_22(a2, a3, a4, v8, v8[11], v5);
  v15 = VbglR0PhysHeapAlloc((unsigned int)(a3 + 176));
  v16 = v15;
  if ( !v15 )
    return vbsf_reg_read_locking_isra_22(a2, a3, a4, v8, v8[11], v5);
  if ( 4096 - (unsigned __int64)(v15 & 0xFFF) < (unsigned int)(a3 + 176) )
  {
    VbglR0PhysHeapFree(v15);
    return vbsf_reg_read_locking_isra_22(a2, a3, a4, v8, v8[11], v5);
  }
  v17 = *a4;
  v18 = *(_QWORD *)(v5 + 16);
  v19 = *v8;
  if ( (g_fHostFeatures & 2) != 0 )
  {
    v20 = a3 + 176;
    v26 = a3 + 124;
  }
  else
  {
    v26 = 124;
    v20 = 176;
  }
  *(_DWORD *)v15 = v20;
  *(_DWORD *)(v15 + 4) = (_DWORD)&unk_10001;
  *(_DWORD *)(v15 + 8) = 0;
  *(_DWORD *)(v15 + 12) = -225;
  *(_DWORD *)(v15 + 16) = v20;
  *(_DWORD *)(v15 + 20) = 0;
  v25 = v17;
  PhysAddr = VbglR0PhysHeapGetPhysAddr(v15);
  *(_BYTE *)(v16 + 28) = 0;
  *(_DWORD *)(v16 + 56) = (_DWORD)&unk_10001;
  *(_DWORD *)(v16 + 24) = PhysAddr + 52;
  *(_DWORD *)(v16 + 60) = 63;
  v22 = (g_fHostFeatures & 2) == 0;
  *(_DWORD *)(v16 + 64) = -225;
  *(_DWORD *)(v16 + 68) = 0;
  *(_DWORD *)(v16 + 52) = v26;
  v23 = g_SfClient;
  *(_DWORD *)(v16 + 72) = 2;
  *(_DWORD *)(v16 + 76) = 0;
  *(_DWORD *)(v16 + 80) = -225;
  *(_DWORD *)(v16 + 84) = v23;
  *(_DWORD *)(v16 + 88) = 5;
  *(_DWORD *)(v16 + 92) = 5;
  *(_DWORD *)(v16 + 96) = 1;
  *(_DWORD *)(v16 + 100) = v19;
  *(_DWORD *)(v16 + 112) = 2;
  *(_QWORD *)(v16 + 116) = v18;
  *(_DWORD *)(v16 + 128) = 2;
  *(_QWORD *)(v16 + 132) = v25;
  *(_DWORD *)(v16 + 144) = 1;
  *(_DWORD *)(v16 + 148) = a3;
  if ( v22 )
  {
    *(_DWORD *)(v16 + 164) = a3;
    *(_DWORD *)(v16 + 160) = 6;
    *(_QWORD *)(v16 + 168) = v16 + 176;
  }
  else
  {
    v24 = *(unsigned __int8 *)(v16 + 164);
    *(_DWORD *)(v16 + 168) = a3;
    *(_DWORD *)(v16 + 160) = 11;
    BYTE1(v24) |= 0x7Cu;
    *(_DWORD *)(v16 + 164) = v24;
    *(_BYTE *)(v16 + 164) = 2;
  }
  if ( (int)VbglR0HGCMFastCall(*(_QWORD *)&algn_FA24[4], v16, v20) < 0 || *(int *)(v16 + 80) < 0 )
  {
    a3 = -71;
  }
  else
  {
    if ( (__int64)a3 > *(unsigned int *)(v16 + 148) )
      a3 = *(unsigned int *)(v16 + 148);
    if ( copy_to_user(a2, v16 + 176, (unsigned int)a3) )
      a3 = -14;
    else
      *a4 += a3;
  }
  VbglR0PhysHeapFree(v16);
  return a3;
}
