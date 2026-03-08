__int64 __fastcall vbsf_reg_write(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, __int64 *a4)
{
  __int64 v5; // r8
  __int64 v6; // rbx
  __int64 v7; // r15
  int *v8; // rcx
  unsigned __int64 v9; // r11
  __int64 v11; // r14
  __int64 result; // rax
  __int64 v13; // rax
  unsigned __int64 v14; // rsi
  __int64 v15; // rax
  __int64 v16; // r11
  _DWORD *v17; // r10
  __int64 v18; // rsi
  int v19; // r8d
  int v20; // edx
  int v21; // ecx
  bool v22; // zf
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  signed __int64 v27; // rax
  __int64 v28; // r14
  __int64 v29; // [rsp+20h] [rbp-68h]
  __int64 v30; // [rsp+20h] [rbp-68h]
  int *v31; // [rsp+28h] [rbp-60h]
  _DWORD *v32; // [rsp+28h] [rbp-60h]
  __int64 v33; // [rsp+28h] [rbp-60h]
  __int64 v34; // [rsp+30h] [rbp-58h]
  int *v35; // [rsp+30h] [rbp-58h]
  _DWORD *v36; // [rsp+30h] [rbp-58h]
  unsigned int v37; // [rsp+30h] [rbp-58h]
  _DWORD *v38; // [rsp+30h] [rbp-58h]
  __int64 v39; // [rsp+38h] [rbp-50h]
  int *v40; // [rsp+38h] [rbp-50h]
  int v41; // [rsp+38h] [rbp-50h]
  unsigned __int64 v42; // [rsp+40h] [rbp-48h]
  __int64 v43; // [rsp+40h] [rbp-48h]
  char *v44; // [rsp+48h] [rbp-40h]
  int v45; // [rsp+54h] [rbp-34h]

  v5 = *(_QWORD *)(a1 + 208);
  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 48LL);
  v7 = *(_QWORD *)(v6 + 48);
  v29 = *(_QWORD *)(v6 + 552);
  v8 = *(int **)(*(_QWORD *)(v6 + 40) + 1120LL);
  if ( (*(_WORD *)v6 & 0xF000) != 0x8000 )
    return -22;
  v9 = a2;
  v11 = *a4;
  if ( (*(_BYTE *)(a1 + 65) & 4) != 0 )
  {
    v11 = *(_QWORD *)(v6 + 80);
    if ( !a3 )
    {
      *a4 = v11;
      return 0;
    }
  }
  else
  {
    result = 0;
    if ( !a3 )
      return result;
  }
  if ( v7 )
  {
    if ( *(_QWORD *)(v7 + 80) )
    {
      if ( *(int *)(v7 + 28) > 0 )
      {
        v34 = *(_QWORD *)(a1 + 208);
        v31 = *(int **)(*(_QWORD *)(v6 + 40) + 1120LL);
        LODWORD(result) = filemap_fdatawait_range(v7, v11, v11 + a3 - 1);
        v8 = v31;
        v5 = v34;
        v9 = a2;
        if ( (_DWORD)result )
          return (int)result;
      }
    }
  }
  if ( a3 > 0xB50 )
    return vbsf_reg_write_locking_isra_21((_DWORD *)(a1 + 64), v9, a3, a4, v11, v6, v29, v8, v8[11], v5);
  v42 = v9;
  v39 = v5;
  v35 = v8;
  v13 = VbglR0PhysHeapAlloc((unsigned int)(a3 + 176));
  v8 = v35;
  v5 = v39;
  v9 = v42;
  if ( !v13 )
    return vbsf_reg_write_locking_isra_21((_DWORD *)(a1 + 64), v9, a3, a4, v11, v6, v29, v8, v8[11], v5);
  if ( 4096 - (unsigned __int64)(v13 & 0xFFF) < (unsigned int)(a3 + 176) )
  {
    VbglR0PhysHeapFree(v13);
    v9 = v42;
    v5 = v39;
    v8 = v35;
    return vbsf_reg_write_locking_isra_21((_DWORD *)(a1 + 64), v9, a3, a4, v11, v6, v29, v8, v8[11], v5);
  }
  v14 = v42;
  v43 = v39;
  v40 = v35;
  v36 = (_DWORD *)v13;
  v44 = (char *)(v13 + 176);
  v15 = copy_from_user(v13 + 176, v14, (unsigned int)a3);
  v16 = -14;
  v17 = v36;
  if ( !v15 )
  {
    v18 = *(_QWORD *)(v43 + 16);
    v19 = *v40;
    if ( (g_fHostFeatures & 2) != 0 )
    {
      v20 = a3 + 176;
      v21 = a3 + 124;
    }
    else
    {
      v21 = 124;
      v20 = 176;
    }
    *v36 = v20;
    v36[4] = v20;
    v36[1] = (_DWORD)&unk_10001;
    v36[2] = 0;
    v36[3] = -225;
    v36[5] = 0;
    v45 = v19;
    v41 = v21;
    v37 = v20;
    v32 = v17;
    v17[6] = VbglR0PhysHeapGetPhysAddr(v17) + 52;
    v22 = (g_fHostFeatures & 2) == 0;
    v23 = g_SfClient;
    *((_BYTE *)v32 + 28) = 0;
    v32[13] = v41;
    v32[14] = (_DWORD)&unk_10001;
    v32[15] = 63;
    v32[16] = -225;
    v32[17] = 0;
    v32[18] = 2;
    v32[19] = 0;
    v32[20] = -225;
    v32[21] = v23;
    v32[22] = 6;
    v32[23] = 5;
    v32[24] = 1;
    v32[25] = v45;
    v32[28] = 2;
    *(_QWORD *)(v32 + 29) = v18;
    v32[32] = 2;
    *(_QWORD *)(v32 + 33) = v11;
    v32[36] = 1;
    v32[37] = a3;
    if ( v22 )
    {
      v32[41] = a3;
      v32[40] = 5;
      *((_QWORD *)v32 + 21) = v44;
    }
    else
    {
      v24 = *((unsigned __int8 *)v32 + 164);
      v32[42] = a3;
      v32[40] = 11;
      BYTE1(v24) |= 0x7Cu;
      v32[41] = v24;
      *((_BYTE *)v32 + 164) = 1;
    }
    v25 = VbglR0HGCMFastCall(*(_QWORD *)&algn_FA24[4], v32, v37);
    v17 = v32;
    if ( v25 < 0 )
    {
      v16 = -71;
      *(_QWORD *)(v29 + 40) = *(_QWORD *)(v29 + 32);
    }
    else
    {
      v26 = v32[20];
      *(_QWORD *)(v29 + 40) = *(_QWORD *)(v29 + 32);
      if ( v26 < 0 )
      {
        v16 = -71;
      }
      else
      {
        v27 = (unsigned int)v32[37];
        if ( (__int64)a3 <= v27 )
          v27 = a3;
        v16 = v27;
        if ( v7 && *(_QWORD *)(v7 + 80) )
        {
          v38 = v32;
          v33 = v27;
          vbsf_reg_write_sync_page_cache_isra_15_part_16(v7, v11, v27, v44, 0, 0);
          v17 = v38;
          v16 = v33;
        }
        v28 = v16 + v11;
        if ( (*(_BYTE *)(a1 + 65) & 4) != 0 && (g_fSfFeatures & 1) != 0 )
          v28 = *(_QWORD *)(v17 + 33);
        *a4 = v28;
        if ( v28 > *(_QWORD *)(v6 + 80) )
          *(_QWORD *)(v6 + 80) = v28;
      }
    }
    *(_BYTE *)(v29 + 8) = 1;
  }
  v30 = v16;
  VbglR0PhysHeapFree(v17);
  return v30;
}
