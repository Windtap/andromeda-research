__int64 __fastcall vbsf_inode_revalidate_worker(__int64 a1, char a2, unsigned __int8 a3)
{
  unsigned int v3; // ebx
  __int64 v4; // r13
  unsigned __int16 **v5; // r12
  int *v6; // r14
  volatile signed __int32 *v7; // rbp
  int v8; // r15d
  unsigned int *v9; // rbx
  char v10; // al
  __int64 v11; // rsi
  int v12; // r8d
  int v13; // eax
  unsigned int v14; // r15d
  int PhysAddr; // eax
  int v16; // eax
  bool v17; // zf
  unsigned int v18; // eax
  _DWORD *v20; // rax
  _DWORD *v21; // rbx
  int *v22; // r10
  int v23; // ecx
  int v24; // ebp
  int v25; // edx
  int v26; // eax
  int v27; // eax
  int v28; // eax
  int v29; // eax
  int v30; // eax
  int v31; // eax
  int *v32; // r10
  int v33; // ebp
  int srcb; // [rsp+8h] [rbp-48h]
  unsigned __int16 *src; // [rsp+8h] [rbp-48h]
  int *srca; // [rsp+8h] [rbp-48h]
  int v38; // [rsp+10h] [rbp-40h]
  int *v39; // [rsp+10h] [rbp-40h]
  unsigned int v40; // [rsp+10h] [rbp-40h]
  int v41; // [rsp+18h] [rbp-38h]

  v3 = -22;
  if ( a1 )
  {
    v4 = *(_QWORD *)(a1 + 48);
    if ( v4 )
    {
      v5 = *(unsigned __int16 ***)(v4 + 552);
      v6 = *(int **)(*(_QWORD *)(v4 + 40) + 1120LL);
      if ( v5 )
      {
        if ( v6 )
        {
          if ( a2 || *((_BYTE *)v5 + 8) || (v3 = 0, jiffies - (_QWORD)v5[2] >= (unsigned __int64)(unsigned int)v6[14]) )
          {
            v7 = vbsf_handle_find(*(_QWORD *)(v4 + 552), 0, 0);
            if ( v7 )
            {
              v8 = -12;
              v9 = (unsigned int *)VbglR0PhysHeapAlloc(268);
              if ( v9 )
              {
                memset(v9, 0, 0x108u);
                v10 = g_fHostFeatures;
                v9[66] = 0;
                v11 = *((_QWORD *)v7 + 2);
                v12 = *v6;
                v9[1] = (unsigned int)&unk_10001;
                v9[2] = 0;
                v13 = v10 & 2;
                v9[3] = -225;
                v9[5] = 0;
                v38 = v12;
                srcb = v13 == 0 ? 124 : 216;
                v14 = v13 == 0 ? 176 : 268;
                *v9 = v14;
                v9[4] = v14;
                PhysAddr = VbglR0PhysHeapGetPhysAddr(v9);
                *((_BYTE *)v9 + 28) = 0;
                v9[14] = (unsigned int)&unk_10001;
                v9[6] = PhysAddr + 52;
                v16 = g_SfClient;
                v9[15] = 63;
                v9[16] = -225;
                v17 = (g_fHostFeatures & 2) == 0;
                v9[13] = srcb;
                v9[17] = 0;
                v9[18] = 2;
                v9[19] = 0;
                v9[20] = -225;
                v9[21] = v16;
                v9[22] = 9;
                v9[23] = 5;
                v9[24] = 1;
                v9[25] = v38;
                v9[28] = 2;
                *(_QWORD *)(v9 + 29) = v11;
                v9[32] = 1;
                v9[33] = 8;
                v9[36] = 1;
                v9[37] = 92;
                if ( v17 )
                {
                  v9[40] = 6;
                  v9[41] = 92;
                  *((_QWORD *)v9 + 21) = v9 + 44;
                }
                else
                {
                  v18 = *((unsigned __int8 *)v9 + 164);
                  v9[40] = 11;
                  v9[42] = 92;
                  BYTE1(v18) |= 0x7Cu;
                  v9[41] = v18;
                  *((_BYTE *)v9 + 164) = 2;
                }
                v8 = VbglR0HGCMFastCall(*(_QWORD *)&algn_FA24[4], v9, v14);
                if ( v8 < 0 || (v8 = v9[20], v8 < 0) )
                {
                  if ( v8 == -4 )
                    v8 = -2;
                  else
                    v8 = -(int)VBoxGuest_RTErrConvertToErrno((unsigned int)v8);
                }
                else
                {
                  vbsf_update_inode((unsigned __int16 *)v4, (__int64)v5, (__int64)(v9 + 44), v6, a3, 0);
                }
                VbglR0PhysHeapFree(v9);
              }
              v3 = v8;
              if ( _InterlockedExchangeAdd(v7 + 7, 0xFFFFFFFF) == 1 )
                vbsf_handle_release_slow((__int64 *)v7, v6);
            }
            else
            {
              v3 = -12;
              src = *v5;
              v20 = (_DWORD *)VbglR0PhysHeapAlloc((unsigned int)**v5 + 260);
              if ( v20 )
              {
                memset(v20, 0, 0x100u);
                v21 = v20 + 63;
                v39 = v20;
                v20[64] = 0;
                memcpy(v20 + 63, src, *src + 4LL);
                v17 = (g_fHostFeatures & 2) == 0;
                v22 = v39;
                *((_QWORD *)v39 + 18) = -1;
                v39[39] = 257;
                v23 = *v6;
                if ( v17 )
                {
                  v24 = 92;
                  v25 = 144;
                }
                else
                {
                  v33 = *((unsigned __int16 *)v39 + 126);
                  v25 = v33 + 256;
                  v24 = v33 + 204;
                }
                *v39 = v25;
                v39[4] = v25;
                v39[1] = (int)&unk_10001;
                v39[2] = 0;
                v39[3] = -225;
                v39[5] = 0;
                v41 = v23;
                v40 = v25;
                srca = v22;
                v26 = VbglR0PhysHeapGetPhysAddr(v22);
                v17 = (g_fHostFeatures & 2) == 0;
                srca[6] = v26 + 52;
                v27 = g_SfClient;
                *((_BYTE *)srca + 28) = 0;
                srca[13] = v24;
                srca[14] = (int)&unk_10001;
                srca[15] = 63;
                srca[16] = -225;
                srca[17] = 0;
                srca[18] = 2;
                srca[19] = 0;
                srca[20] = -225;
                srca[21] = v27;
                srca[22] = 3;
                srca[23] = 3;
                srca[24] = 1;
                srca[25] = v41;
                v28 = *((unsigned __int16 *)srca + 126);
                if ( v17 )
                {
                  srca[28] = 5;
                  *((_QWORD *)srca + 15) = v21;
                  srca[32] = 4;
                  srca[33] = 108;
                  srca[29] = v28 + 4;
                  *((_QWORD *)srca + 17) = srca + 36;
                }
                else
                {
                  srca[28] = 11;
                  srca[32] = 11;
                  srca[34] = 108;
                  srca[30] = v28 + 4;
                  v29 = *((unsigned __int8 *)srca + 116);
                  BYTE1(v29) = -56;
                  srca[29] = v29;
                  v30 = *((unsigned __int8 *)srca + 132);
                  *((_BYTE *)srca + 116) = 1;
                  BYTE1(v30) |= 0x5Cu;
                  srca[33] = v30;
                  *((_BYTE *)srca + 132) = 3;
                }
                v3 = -2;
                v31 = VbglR0HGCMFastCall(*(_QWORD *)&algn_FA24[4], srca, v40);
                v32 = srca;
                if ( v31 < 0 || (v31 = srca[20], v31 < 0) )
                {
                  if ( v31 != -104 )
                    v3 = -71;
                }
                else if ( srca[38] == 3 )
                {
                  v3 = 0;
                  vbsf_update_inode((unsigned __int16 *)v4, (__int64)v5, (__int64)(srca + 40), v6, a3, 0);
                  v32 = srca;
                }
                VbglR0PhysHeapFree(v32);
              }
            }
          }
        }
      }
    }
  }
  return v3;
}
