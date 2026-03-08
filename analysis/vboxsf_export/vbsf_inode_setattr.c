__int64 __fastcall vbsf_inode_setattr(__int64 a1, __int64 a2)
{
  __int64 v2; // r13
  __int64 v3; // rbp
  const void **v4; // r14
  unsigned int v5; // r12d
  unsigned int v6; // r15d
  volatile signed __int32 *v7; // r11
  __int64 v8; // r12
  volatile signed __int32 *v9; // r11
  unsigned int v10; // r13d
  unsigned __int64 v12; // rdi
  _DWORD *v13; // rax
  int v14; // ecx
  int v15; // eax
  int v16; // edx
  int PhysAddr; // eax
  bool v18; // zf
  int v19; // eax
  int v20; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  unsigned __int16 v24; // ax
  __int16 v25; // dx
  int v26; // ecx
  char v27; // al
  int v28; // eax
  unsigned int v29; // r13d
  int v30; // eax
  int v31; // eax
  int v32; // eax
  int v33; // eax
  int v34; // ebx
  int v35; // eax
  __int64 v36; // rdi
  int v37; // eax
  __int64 v38; // rax
  int v39; // eax
  int v40; // eax
  int v41; // edx
  char v42; // al
  int v43; // eax
  int v44; // r13d
  unsigned int v45; // ebx
  int v46; // eax
  int v47; // eax
  int v48; // eax
  int v49; // eax
  int v50; // eax
  int *v51; // [rsp+0h] [rbp-70h]
  volatile signed __int32 *v52; // [rsp+8h] [rbp-68h]
  volatile signed __int32 *v53; // [rsp+8h] [rbp-68h]
  int v54; // [rsp+8h] [rbp-68h]
  _DWORD *v55; // [rsp+8h] [rbp-68h]
  __int64 v56; // [rsp+10h] [rbp-60h]
  unsigned int v57; // [rsp+10h] [rbp-60h]
  int v58; // [rsp+18h] [rbp-58h]
  int v59; // [rsp+20h] [rbp-50h]
  volatile signed __int32 *v60; // [rsp+20h] [rbp-50h]
  int v61; // [rsp+2Ch] [rbp-44h]
  int v62; // [rsp+2Ch] [rbp-44h]
  _DWORD *v63; // [rsp+30h] [rbp-40h]
  volatile signed __int32 *v64; // [rsp+30h] [rbp-40h]
  _DWORD *v65; // [rsp+38h] [rbp-38h]

  v2 = a1;
  v3 = *(_QWORD *)(a1 + 48);
  v4 = *(const void ***)(v3 + 552);
  v51 = *(int **)(*(_QWORD *)(v3 + 40) + 1120LL);
  if ( !v4 )
    return (unsigned int)-22;
  *(_DWORD *)a2 |= 0x200u;
  v5 = inode_change_ok(v3);
  if ( !v5 )
  {
    v6 = *(_DWORD *)a2 & 0xFFFFDFFF;
    if ( v6 == 104 || (*(_DWORD *)a2 & 0x8008) == 0x8008 )
      LOBYTE(v6) = *(_DWORD *)a2 & 0x9F;
    v5 = 0;
    if ( (v6 & 0x79) != 0 )
    {
      if ( (v6 & 8) != 0 )
        v7 = vbsf_handle_find((__int64)v4, 2, 0);
      else
        v7 = vbsf_handle_find((__int64)v4, 0, 0);
      if ( v7 )
      {
        v52 = v7;
        v56 = *((_QWORD *)v7 + 2);
        v8 = VbglR0PhysHeapAlloc(268);
        v9 = v52;
        if ( v8 )
          goto LABEL_10;
      }
      else
      {
        v12 = *(unsigned __int16 *)*v4 + 264LL;
        if ( v12 < 0x10C )
          v12 = 268;
        v13 = (_DWORD *)VbglR0PhysHeapAlloc(v12);
        v8 = (__int64)v13;
        v9 = 0;
        if ( v13 )
        {
          v63 = v13 + 36;
          memset(v13 + 36, 0, 0x68u);
          v13[62] = 0;
          v13[39] = (v6 & 8) == 0 ? 131328 : 139520;
          *((_QWORD *)v13 + 18) = -1;
          v65 = v13 + 63;
          memcpy(v13 + 63, *v4, *(unsigned __int16 *)*v4 + 4LL);
          v14 = *v51;
          if ( (g_fHostFeatures & 2) != 0 )
          {
            v15 = *(unsigned __int16 *)(v8 + 252);
            v16 = v15 + 256;
            v54 = v15 + 204;
          }
          else
          {
            v54 = 92;
            v16 = 144;
          }
          *(_DWORD *)v8 = v16;
          *(_DWORD *)(v8 + 16) = v16;
          *(_DWORD *)(v8 + 4) = (_DWORD)&unk_10001;
          *(_DWORD *)(v8 + 8) = 0;
          *(_DWORD *)(v8 + 12) = -225;
          *(_DWORD *)(v8 + 20) = 0;
          v61 = v14;
          v57 = v16;
          PhysAddr = VbglR0PhysHeapGetPhysAddr(v8);
          *(_BYTE *)(v8 + 28) = 0;
          *(_DWORD *)(v8 + 56) = (_DWORD)&unk_10001;
          *(_DWORD *)(v8 + 24) = PhysAddr + 52;
          *(_DWORD *)(v8 + 60) = 63;
          v18 = (g_fHostFeatures & 2) == 0;
          *(_DWORD *)(v8 + 64) = -225;
          *(_DWORD *)(v8 + 68) = 0;
          *(_DWORD *)(v8 + 52) = v54;
          v19 = g_SfClient;
          *(_DWORD *)(v8 + 72) = 2;
          *(_DWORD *)(v8 + 76) = 0;
          *(_DWORD *)(v8 + 80) = -225;
          *(_DWORD *)(v8 + 84) = v19;
          *(_DWORD *)(v8 + 88) = 3;
          *(_DWORD *)(v8 + 92) = 3;
          *(_DWORD *)(v8 + 96) = 1;
          *(_DWORD *)(v8 + 100) = v61;
          v20 = *(unsigned __int16 *)(v8 + 252);
          if ( v18 )
          {
            *(_DWORD *)(v8 + 112) = 5;
            *(_DWORD *)(v8 + 128) = 4;
            *(_DWORD *)(v8 + 132) = 108;
            *(_DWORD *)(v8 + 116) = v20 + 4;
            *(_QWORD *)(v8 + 120) = v65;
            *(_QWORD *)(v8 + 136) = v63;
          }
          else
          {
            *(_DWORD *)(v8 + 112) = 11;
            *(_DWORD *)(v8 + 128) = 11;
            *(_DWORD *)(v8 + 136) = 108;
            *(_DWORD *)(v8 + 120) = v20 + 4;
            v21 = *(unsigned __int8 *)(v8 + 116);
            BYTE1(v21) = -56;
            *(_DWORD *)(v8 + 116) = v21;
            v22 = *(unsigned __int8 *)(v8 + 132);
            *(_BYTE *)(v8 + 116) = 1;
            BYTE1(v22) |= 0x5Cu;
            *(_DWORD *)(v8 + 132) = v22;
            *(_BYTE *)(v8 + 132) = 3;
          }
          v23 = VbglR0HGCMFastCall(*(_QWORD *)&algn_FA24[4], v8, v57);
          v9 = 0;
          if ( v23 < 0 || (v23 = *(_DWORD *)(v8 + 80), v23 < 0) )
          {
            v39 = VBoxGuest_RTErrConvertToErrno((unsigned int)v23);
            v9 = 0;
            v10 = -v39;
            if ( v39 )
            {
LABEL_14:
              v53 = v9;
              VbglR0PhysHeapFree(v8);
              v9 = v53;
              goto LABEL_15;
            }
            v56 = -1;
          }
          else
          {
            if ( *(_DWORD *)(v8 + 152) != 3 )
            {
              *(_QWORD *)(v2 + 120) = jiffies - 0x3FFFFFFFLL;
              v10 = -2;
              *((_BYTE *)v4 + 8) = 1;
              if ( !v8 )
                return v10;
              goto LABEL_14;
            }
            v56 = *(_QWORD *)(v8 + 144);
            v38 = jiffies;
            do
            {
              *(_QWORD *)(v2 + 120) = v38;
              v2 = *(_QWORD *)(v2 + 24);
            }
            while ( v2 != *(_QWORD *)(v2 + 24) );
          }
LABEL_10:
          if ( (v6 & 0x71) != 0 )
          {
            v55 = (_DWORD *)(v8 + 176);
            memset((void *)(v8 + 176), 0, 0x58u);
            *(_DWORD *)(v8 + 264) = 0;
            if ( (v6 & 1) != 0 )
            {
              v24 = *(_WORD *)(a2 + 4) & 0x1FF;
              *(_DWORD *)(v8 + 224) = v24;
              v25 = *(_WORD *)(a2 + 4);
              if ( (v25 & 0x4000) != 0 )
              {
                HIBYTE(v24) |= 0x40u;
                *(_DWORD *)(v8 + 224) = v24;
              }
              else if ( (v25 & 0xA000) != 0 )
              {
                *(_DWORD *)(v8 + 224) = v24 | 0xA000;
              }
              else
              {
                *(_DWORD *)(v8 + 224) = v24 | 0x8000;
              }
            }
            if ( (v6 & 0x10) != 0 )
              *(_QWORD *)(v8 + 192) = *(_QWORD *)(a2 + 32) + 1000000000LL * *(_QWORD *)(a2 + 24);
            if ( (v6 & 0x20) != 0 )
              *(_QWORD *)(v8 + 200) = *(_QWORD *)(a2 + 48) + 1000000000LL * *(_QWORD *)(a2 + 40);
            if ( (v6 & 0x40) != 0 )
              *(_QWORD *)(v8 + 208) = *(_QWORD *)(a2 + 64) + 1000000000LL * *(_QWORD *)(a2 + 56);
            v64 = v9;
            v26 = *v51;
            *(_DWORD *)(v8 + 4) = (_DWORD)&unk_10001;
            *(_DWORD *)(v8 + 8) = 0;
            v27 = g_fHostFeatures;
            *(_DWORD *)(v8 + 12) = -225;
            *(_DWORD *)(v8 + 20) = 0;
            v62 = v26;
            v28 = v27 & 2;
            v59 = v28 == 0 ? 124 : 216;
            v29 = v28 == 0 ? 176 : 268;
            *(_DWORD *)v8 = v29;
            *(_DWORD *)(v8 + 16) = v29;
            v30 = VbglR0PhysHeapGetPhysAddr(v8);
            *(_BYTE *)(v8 + 28) = 0;
            *(_DWORD *)(v8 + 56) = (_DWORD)&unk_10001;
            *(_DWORD *)(v8 + 24) = v30 + 52;
            v31 = g_SfClient;
            *(_DWORD *)(v8 + 60) = 63;
            *(_DWORD *)(v8 + 64) = -225;
            v18 = (g_fHostFeatures & 2) == 0;
            *(_DWORD *)(v8 + 52) = v59;
            *(_DWORD *)(v8 + 84) = v31;
            *(_DWORD *)(v8 + 68) = 0;
            *(_DWORD *)(v8 + 72) = 2;
            *(_DWORD *)(v8 + 76) = 0;
            *(_DWORD *)(v8 + 80) = -225;
            *(_DWORD *)(v8 + 88) = 9;
            *(_DWORD *)(v8 + 92) = 5;
            *(_DWORD *)(v8 + 96) = 1;
            *(_DWORD *)(v8 + 100) = v62;
            *(_DWORD *)(v8 + 112) = 2;
            *(_QWORD *)(v8 + 116) = v56;
            *(_DWORD *)(v8 + 128) = 1;
            *(_DWORD *)(v8 + 132) = 9;
            *(_DWORD *)(v8 + 144) = 1;
            *(_DWORD *)(v8 + 148) = 92;
            if ( v18 )
            {
              *(_DWORD *)(v8 + 160) = 4;
              *(_DWORD *)(v8 + 164) = 92;
              *(_QWORD *)(v8 + 168) = v55;
            }
            else
            {
              v32 = *(unsigned __int8 *)(v8 + 164);
              *(_DWORD *)(v8 + 160) = 11;
              *(_DWORD *)(v8 + 168) = 92;
              BYTE1(v32) |= 0x7Cu;
              *(_DWORD *)(v8 + 164) = v32;
              *(_BYTE *)(v8 + 164) = 3;
            }
            v33 = VbglR0HGCMFastCall(*(_QWORD *)&algn_FA24[4], v8, v29);
            if ( v33 < 0 || (v33 = *(_DWORD *)(v8 + 80), v33 < 0) )
            {
              v40 = VBoxGuest_RTErrConvertToErrno((unsigned int)v33);
              v9 = v64;
              v10 = -v40;
              if ( (v6 & 8) == 0 || v40 )
                goto LABEL_12;
              goto LABEL_62;
            }
            vbsf_update_inode((unsigned __int16 *)v3, (__int64)v4, (__int64)v55, v51, 1, v6);
            v9 = v64;
          }
          v10 = 0;
          if ( (v6 & 8) == 0 )
            goto LABEL_12;
          v55 = (_DWORD *)(v8 + 176);
LABEL_62:
          v60 = v9;
          memset(v55, 0, 0x58u);
          v55[22] = 0;
          *(_QWORD *)(v8 + 176) = *(_QWORD *)(a2 + 16);
          v41 = *v51;
          *(_DWORD *)(v8 + 4) = (_DWORD)&unk_10001;
          *(_DWORD *)(v8 + 8) = 0;
          v42 = g_fHostFeatures;
          *(_DWORD *)(v8 + 12) = -225;
          *(_DWORD *)(v8 + 20) = 0;
          v58 = v41;
          v43 = v42 & 2;
          v44 = v43 == 0 ? 124 : 216;
          v45 = v43 == 0 ? 176 : 268;
          *(_DWORD *)v8 = v45;
          *(_DWORD *)(v8 + 16) = v45;
          v46 = VbglR0PhysHeapGetPhysAddr(v8);
          *(_BYTE *)(v8 + 28) = 0;
          *(_DWORD *)(v8 + 52) = v44;
          *(_DWORD *)(v8 + 24) = v46 + 52;
          v47 = g_SfClient;
          *(_DWORD *)(v8 + 56) = (_DWORD)&unk_10001;
          v18 = (g_fHostFeatures & 2) == 0;
          *(_DWORD *)(v8 + 60) = 63;
          *(_DWORD *)(v8 + 64) = -225;
          *(_DWORD *)(v8 + 84) = v47;
          *(_DWORD *)(v8 + 68) = 0;
          *(_DWORD *)(v8 + 72) = 2;
          *(_DWORD *)(v8 + 76) = 0;
          *(_DWORD *)(v8 + 80) = -225;
          *(_DWORD *)(v8 + 88) = 9;
          *(_DWORD *)(v8 + 92) = 5;
          *(_DWORD *)(v8 + 96) = 1;
          *(_DWORD *)(v8 + 100) = v58;
          *(_DWORD *)(v8 + 112) = 2;
          *(_QWORD *)(v8 + 116) = v56;
          *(_DWORD *)(v8 + 128) = 1;
          *(_DWORD *)(v8 + 132) = 5;
          *(_DWORD *)(v8 + 144) = 1;
          *(_DWORD *)(v8 + 148) = 92;
          if ( v18 )
          {
            *(_DWORD *)(v8 + 160) = 4;
            *(_DWORD *)(v8 + 164) = 92;
            *(_QWORD *)(v8 + 168) = v55;
          }
          else
          {
            v48 = *(unsigned __int8 *)(v8 + 164);
            *(_DWORD *)(v8 + 160) = 11;
            *(_DWORD *)(v8 + 168) = 92;
            BYTE1(v48) |= 0x7Cu;
            *(_DWORD *)(v8 + 164) = v48;
            *(_BYTE *)(v8 + 164) = 3;
          }
          v49 = VbglR0HGCMFastCall(*(_QWORD *)&algn_FA24[4], v8, v45);
          if ( v49 < 0 || (v49 = *(_DWORD *)(v8 + 80), v49 < 0) )
          {
            v50 = VBoxGuest_RTErrConvertToErrno((unsigned int)v49);
            v9 = v60;
            v10 = -v50;
          }
          else
          {
            v10 = 0;
            vbsf_update_inode((unsigned __int16 *)v3, (__int64)v4, (__int64)v55, v51, 1, v6);
            v9 = v60;
          }
LABEL_12:
          if ( !v9 )
          {
            v34 = *v51;
            *(_DWORD *)v8 = 128;
            *(_DWORD *)(v8 + 4) = (_DWORD)&unk_10001;
            *(_DWORD *)(v8 + 8) = 0;
            *(_DWORD *)(v8 + 12) = -225;
            *(_DWORD *)(v8 + 16) = 128;
            *(_DWORD *)(v8 + 20) = 0;
            v35 = VbglR0PhysHeapGetPhysAddr(v8);
            v36 = *(_QWORD *)&algn_FA24[4];
            *(_BYTE *)(v8 + 28) = 0;
            *(_DWORD *)(v8 + 24) = v35 + 52;
            v37 = g_SfClient;
            *(_DWORD *)(v8 + 52) = 76;
            *(_DWORD *)(v8 + 56) = (_DWORD)&unk_10001;
            *(_DWORD *)(v8 + 60) = 63;
            *(_DWORD *)(v8 + 84) = v37;
            *(_DWORD *)(v8 + 64) = -225;
            *(_DWORD *)(v8 + 68) = 0;
            *(_DWORD *)(v8 + 72) = 2;
            *(_DWORD *)(v8 + 76) = 0;
            *(_DWORD *)(v8 + 80) = -225;
            *(_DWORD *)(v8 + 88) = 4;
            *(_DWORD *)(v8 + 92) = 2;
            *(_DWORD *)(v8 + 96) = 1;
            *(_DWORD *)(v8 + 100) = v34;
            *(_DWORD *)(v8 + 112) = 2;
            *(_QWORD *)(v8 + 116) = v56;
            VbglR0HGCMFastCall(v36, v8, 128);
            v9 = 0;
          }
          goto LABEL_14;
        }
      }
      v10 = -12;
LABEL_15:
      if ( v9 )
      {
        v5 = v10;
        if ( _InterlockedExchangeAdd(v9 + 7, 0xFFFFFFFF) == 1 )
          vbsf_handle_release_slow((__int64 *)v9, v51);
        return v5;
      }
      return v10;
    }
  }
  return v5;
}
