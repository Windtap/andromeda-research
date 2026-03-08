__int64 __fastcall vbsf_reg_read_iter(__int64 *a1, __int64 a2)
{
  unsigned __int64 v3; // rbx
  __int64 v4; // r15
  __int64 v5; // rax
  __int64 v6; // rcx
  int *v7; // r14
  __int64 result; // rax
  int v9; // eax
  __int64 v10; // rax
  __int64 v11; // r12
  __int64 v12; // rcx
  __int64 v13; // rsi
  int v14; // r14d
  unsigned int v15; // r15d
  int PhysAddr; // eax
  bool v17; // zf
  int v18; // eax
  int v19; // eax
  __int64 v20; // r14
  __int64 v21; // [rsp+0h] [rbp-48h]
  int v22; // [rsp+14h] [rbp-34h]

  v3 = *(_QWORD *)(a2 + 16);
  v4 = *(_QWORD *)(*a1 + 208);
  v5 = *(_QWORD *)(*(_QWORD *)(*a1 + 24) + 48LL);
  v6 = *(_QWORD *)(v5 + 48);
  v7 = *(int **)(*(_QWORD *)(v5 + 40) + 1120LL);
  if ( (*(_WORD *)v5 & 0xF000) != 0x8000 )
    return -22;
  result = 0;
  if ( !v3 )
    return result;
  if ( (*(_BYTE *)(*a1 + 65) & 0x40) == 0 )
  {
    v9 = v7[15];
    if ( v9 != 1 && ((unsigned int)(v9 - 3) <= 1 || v6 && *(_QWORD *)(v6 + 80) && *(int *)(v6 + 28) > 0) )
      return generic_file_read_iter(a1, a2);
  }
  if ( a1[2] )
    return -95;
  if ( v3 > 0xB50 )
    return vbsf_reg_read_iter_locking_isra_20(a1 + 1, (int *)a2, v3, v7, v7[11], v4);
  v10 = VbglR0PhysHeapAlloc((unsigned int)(v3 + 176));
  v11 = v10;
  if ( !v10 )
    return vbsf_reg_read_iter_locking_isra_20(a1 + 1, (int *)a2, v3, v7, v7[11], v4);
  if ( 4096 - (unsigned __int64)(v10 & 0xFFF) < (unsigned int)(v3 + 176) )
  {
    VbglR0PhysHeapFree(v10);
    return vbsf_reg_read_iter_locking_isra_20(a1 + 1, (int *)a2, v3, v7, v7[11], v4);
  }
  v12 = a1[1];
  v13 = *(_QWORD *)(v4 + 16);
  v14 = *v7;
  if ( (g_fHostFeatures & 2) != 0 )
  {
    v15 = v3 + 176;
    v22 = v3 + 124;
  }
  else
  {
    v22 = 124;
    v15 = 176;
  }
  *(_DWORD *)v10 = v15;
  *(_DWORD *)(v10 + 4) = (_DWORD)&unk_10001;
  *(_DWORD *)(v10 + 8) = 0;
  *(_DWORD *)(v10 + 12) = -225;
  *(_DWORD *)(v10 + 16) = v15;
  *(_DWORD *)(v10 + 20) = 0;
  v21 = v12;
  PhysAddr = VbglR0PhysHeapGetPhysAddr(v10);
  *(_BYTE *)(v11 + 28) = 0;
  *(_DWORD *)(v11 + 100) = v14;
  *(_DWORD *)(v11 + 24) = PhysAddr + 52;
  *(_DWORD *)(v11 + 56) = (_DWORD)&unk_10001;
  v17 = (g_fHostFeatures & 2) == 0;
  *(_DWORD *)(v11 + 60) = 63;
  *(_DWORD *)(v11 + 64) = -225;
  *(_DWORD *)(v11 + 52) = v22;
  v18 = g_SfClient;
  *(_DWORD *)(v11 + 68) = 0;
  *(_DWORD *)(v11 + 72) = 2;
  *(_DWORD *)(v11 + 76) = 0;
  *(_DWORD *)(v11 + 80) = -225;
  *(_DWORD *)(v11 + 84) = v18;
  *(_DWORD *)(v11 + 88) = 5;
  *(_DWORD *)(v11 + 92) = 5;
  *(_DWORD *)(v11 + 96) = 1;
  *(_DWORD *)(v11 + 112) = 2;
  *(_QWORD *)(v11 + 116) = v13;
  *(_DWORD *)(v11 + 128) = 2;
  *(_QWORD *)(v11 + 132) = v21;
  *(_DWORD *)(v11 + 144) = 1;
  *(_DWORD *)(v11 + 148) = v3;
  if ( v17 )
  {
    *(_DWORD *)(v11 + 164) = v3;
    *(_DWORD *)(v11 + 160) = 6;
    *(_QWORD *)(v11 + 168) = v11 + 176;
  }
  else
  {
    v19 = *(unsigned __int8 *)(v11 + 164);
    *(_DWORD *)(v11 + 168) = v3;
    *(_DWORD *)(v11 + 160) = 11;
    BYTE1(v19) |= 0x7Cu;
    *(_DWORD *)(v11 + 164) = v19;
    *(_BYTE *)(v11 + 164) = 2;
  }
  if ( (int)VbglR0HGCMFastCall(*(_QWORD *)&algn_FA24[4], v11, v15) < 0 || *(int *)(v11 + 80) < 0 )
  {
    v20 = -71;
  }
  else
  {
    v20 = *(unsigned int *)(v11 + 148);
    if ( (__int64)v3 <= v20 )
      v20 = v3;
    if ( v20 == copy_to_iter(v11 + 176, v20, a2) )
    {
      a1[1] += v20;
      if ( v3 > v20 )
      {
        if ( *(_QWORD *)(a2 + 16) )
          *(_QWORD *)(a2 + 16) = 0;
      }
    }
    else
    {
      v20 = -14;
    }
  }
  VbglR0PhysHeapFree(v11);
  return v20;
}
