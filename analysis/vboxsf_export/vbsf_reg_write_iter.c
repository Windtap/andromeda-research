__int64 __fastcall vbsf_reg_write_iter(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // r12
  __int64 v3; // r14
  __int64 v4; // rcx
  int v5; // r10d
  __int64 v6; // rbx
  __int64 v7; // r13
  _DWORD *v8; // r8
  __int64 result; // rax
  __int64 v10; // rax
  __int64 v11; // r15
  __int64 v12; // rax
  _DWORD *v13; // r11
  char v14; // r10
  __int64 v15; // r15
  int v16; // esi
  int v17; // edx
  int PhysAddr; // eax
  bool v19; // zf
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  char v24; // r10
  __int64 v25; // r14
  __int64 v26; // [rsp+28h] [rbp-68h]
  __int64 v27; // [rsp+30h] [rbp-60h]
  _DWORD *v28; // [rsp+30h] [rbp-60h]
  _DWORD *v29; // [rsp+38h] [rbp-58h]
  __int64 v30; // [rsp+38h] [rbp-58h]
  _DWORD *v31; // [rsp+38h] [rbp-58h]
  unsigned int v32; // [rsp+38h] [rbp-58h]
  char v33; // [rsp+40h] [rbp-50h]
  _DWORD *v34; // [rsp+40h] [rbp-50h]
  __int64 v35; // [rsp+40h] [rbp-50h]
  char v36; // [rsp+40h] [rbp-50h]
  char v37; // [rsp+48h] [rbp-48h]
  int *v38; // [rsp+48h] [rbp-48h]
  char v39; // [rsp+54h] [rbp-3Ch]
  int v40; // [rsp+54h] [rbp-3Ch]
  char *v41; // [rsp+58h] [rbp-38h]

  v2 = *(_QWORD *)(a2 + 16);
  v3 = *(_QWORD *)(a1 + 8);
  v4 = *(_QWORD *)(*(_QWORD *)a1 + 208LL);
  v5 = (*(_DWORD *)(a1 + 32) >> 1) & 1;
  v6 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)a1 + 24LL) + 48LL);
  v7 = *(_QWORD *)(v6 + 48);
  v8 = *(_DWORD **)(*(_QWORD *)(v6 + 40) + 1120LL);
  v26 = *(_QWORD *)(v6 + 552);
  if ( (*(_WORD *)v6 & 0xF000) != 0x8000 )
    return -22;
  if ( (*(_DWORD *)(a1 + 32) & 2) != 0 )
  {
    v3 = *(_QWORD *)(v6 + 80);
    *(_QWORD *)(a1 + 8) = v3;
  }
  result = 0;
  if ( v2 )
  {
    result = -95;
    if ( !*(_QWORD *)(a1 + 16) )
    {
      if ( v7 )
      {
        if ( *(_QWORD *)(v7 + 80) )
        {
          if ( *(int *)(v7 + 28) > 0 )
          {
            v33 = v5;
            v29 = v8;
            v27 = v4;
            LODWORD(result) = filemap_fdatawait_range(v7, v3, v3 + v2 - 1);
            v4 = v27;
            v8 = v29;
            LOBYTE(v5) = v33;
            if ( (_DWORD)result )
              return (int)result;
          }
        }
      }
      if ( v2 <= 0xB50 )
      {
        v37 = v5;
        v34 = v8;
        v30 = v4;
        v10 = VbglR0PhysHeapAlloc((unsigned int)(v2 + 176));
        v4 = v30;
        v8 = v34;
        LOBYTE(v5) = v37;
        if ( v10 )
        {
          if ( 4096 - (unsigned __int64)(v10 & 0xFFF) >= (unsigned int)(v2 + 176) )
          {
            v39 = v37;
            v11 = -14;
            v38 = v34;
            v35 = v30;
            v31 = (_DWORD *)v10;
            v41 = (char *)(v10 + 176);
            v12 = copy_from_iter(v10 + 176, v2, a2);
            v13 = v31;
            v14 = v39;
            if ( v2 == v12 )
            {
              v15 = *(_QWORD *)(v35 + 16);
              v16 = *v38;
              if ( (g_fHostFeatures & 2) != 0 )
              {
                v17 = v2 + 176;
                v40 = v2 + 124;
              }
              else
              {
                v40 = 124;
                v17 = 176;
              }
              *v31 = v17;
              v31[4] = v17;
              v31[1] = (_DWORD)&unk_10001;
              v31[2] = 0;
              v31[3] = -225;
              v31[5] = 0;
              v36 = v14;
              v32 = v17;
              v28 = v13;
              PhysAddr = VbglR0PhysHeapGetPhysAddr(v13);
              v19 = (g_fHostFeatures & 2) == 0;
              v28[6] = PhysAddr + 52;
              *((_BYTE *)v28 + 28) = 0;
              v28[14] = (_DWORD)&unk_10001;
              v28[15] = 63;
              v28[13] = v40;
              v20 = g_SfClient;
              v28[16] = -225;
              v28[17] = 0;
              v28[18] = 2;
              v28[19] = 0;
              v28[20] = -225;
              v28[21] = v20;
              v28[22] = 6;
              v28[23] = 5;
              v28[24] = 1;
              v28[25] = v16;
              v28[28] = 2;
              *(_QWORD *)(v28 + 29) = v15;
              v28[32] = 2;
              *(_QWORD *)(v28 + 33) = v3;
              v28[36] = 1;
              v28[37] = v2;
              if ( v19 )
              {
                v28[41] = v2;
                v28[40] = 5;
                *((_QWORD *)v28 + 21) = v41;
              }
              else
              {
                v21 = *((unsigned __int8 *)v28 + 164);
                v28[42] = v2;
                v28[40] = 11;
                BYTE1(v21) |= 0x7Cu;
                v28[41] = v21;
                *((_BYTE *)v28 + 164) = 1;
              }
              v22 = VbglR0HGCMFastCall(*(_QWORD *)&algn_FA24[4], v28, v32);
              v13 = v28;
              if ( v22 < 0 )
              {
                v11 = -71;
                *(_QWORD *)(v26 + 40) = *(_QWORD *)(v26 + 32);
              }
              else
              {
                v23 = v28[20];
                *(_QWORD *)(v26 + 40) = *(_QWORD *)(v26 + 32);
                if ( v23 < 0 )
                {
                  v11 = -71;
                }
                else
                {
                  v11 = (unsigned int)v28[37];
                  v24 = v36;
                  if ( (__int64)v2 <= v11 )
                    v11 = v2;
                  if ( v7 && *(_QWORD *)(v7 + 80) )
                  {
                    vbsf_reg_write_sync_page_cache_isra_15_part_16(v7, v3, v11, v41, 0, 0);
                    v13 = v28;
                    v24 = v36;
                  }
                  v25 = v11 + v3;
                  if ( v24 && (g_fSfFeatures & 1) != 0 )
                    v25 = *(_QWORD *)(v13 + 33);
                  *(_QWORD *)(a1 + 8) = v25;
                  if ( v25 > *(_QWORD *)(v6 + 80) )
                    *(_QWORD *)(v6 + 80) = v25;
                }
              }
              *(_BYTE *)(v26 + 8) = 1;
            }
            VbglR0PhysHeapFree(v13);
            return v11;
          }
          VbglR0PhysHeapFree(v10);
          LOBYTE(v5) = v37;
          v8 = v34;
          v4 = v30;
        }
      }
      return vbsf_reg_write_iter_locking_isra_19(
               (__int64 *)(a1 + 8),
               (int *)a2,
               v2,
               v3,
               v8,
               v8[11],
               v4,
               v6,
               v26,
               v7,
               v5);
    }
  }
  return result;
}
