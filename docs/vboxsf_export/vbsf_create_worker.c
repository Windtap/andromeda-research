__int64 __fastcall vbsf_create_worker(
        __int64 a1,
        __int64 a2,
        __int16 a3,
        int a4,
        char a5,
        char a6,
        _QWORD *a7,
        bool *a8)
{
  __int64 v9; // r12
  int *v10; // rbp
  __int64 result; // rax
  __int64 v12; // rax
  unsigned int v13; // r11d
  __int64 v14; // rbx
  int v15; // eax
  bool v16; // zf
  int v17; // ecx
  int v18; // r14d
  int v19; // edx
  int PhysAddr; // eax
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // r11d
  int v26; // eax
  __int64 v27; // rax
  int v28; // r11d
  __int64 v29; // r12
  int v30; // ebp
  int v31; // eax
  __int64 v32; // rdi
  int v33; // eax
  int v34; // eax
  int v35; // eax
  __int64 v36; // rax
  __int64 v37; // rdx
  __int64 v38; // rax
  __int64 v39; // rdx
  __int64 inode_isra_6; // rax
  int v42; // [rsp+0h] [rbp-58h]
  unsigned int v43; // [rsp+0h] [rbp-58h]
  unsigned int v44; // [rsp+0h] [rbp-58h]
  unsigned int v46; // [rsp+4h] [rbp-54h]
  int v47; // [rsp+4h] [rbp-54h]
  int v49; // [rsp+14h] [rbp-44h]
  __int64 v50; // [rsp+18h] [rbp-40h]
  void *src; // [rsp+20h] [rbp-38h] BYREF

  v9 = *(_QWORD *)(a1 + 552);
  v10 = *(int **)(*(_QWORD *)(a1 + 40) + 1120LL);
  if ( a8 )
    *a8 = 0;
  if ( !v9 || !v10 )
    return 4294967274LL;
  result = vbsf_path_from_dentry(v10, v9, a2, &src, "vbsf_create_worker");
  if ( !(_DWORD)result )
  {
    v12 = VbglR0PhysHeapAlloc((unsigned int)*(unsigned __int16 *)src + 256);
    v13 = -12;
    v14 = v12;
    if ( !v12 )
      goto LABEL_30;
    v50 = v12 + 252;
    memcpy((void *)(v12 + 252), src, *(unsigned __int16 *)src + 4LL);
    memset((void *)(v14 + 144), 0, 0x68u);
    *(_DWORD *)(v14 + 248) = 0;
    *(_DWORD *)(v14 + 156) = a4;
    v15 = 0x4000;
    if ( (a3 & 0xF000) != 0x4000 )
      v15 = 0x8000;
    *(_QWORD *)(v14 + 144) = -1;
    *(_DWORD *)(v14 + 212) = 1;
    v16 = (g_fHostFeatures & 2) == 0;
    *(_DWORD *)(v14 + 208) = a3 & 0x1FF | v15;
    v17 = *v10;
    if ( v16 )
    {
      v18 = 92;
      v19 = 144;
    }
    else
    {
      v34 = *(unsigned __int16 *)(v14 + 252);
      v19 = v34 + 256;
      v18 = v34 + 204;
    }
    *(_DWORD *)v14 = v19;
    *(_DWORD *)(v14 + 16) = v19;
    *(_DWORD *)(v14 + 4) = (_DWORD)&unk_10001;
    *(_DWORD *)(v14 + 8) = 0;
    *(_DWORD *)(v14 + 12) = -225;
    *(_DWORD *)(v14 + 20) = 0;
    v49 = v17;
    v46 = v19;
    PhysAddr = VbglR0PhysHeapGetPhysAddr(v14);
    *(_BYTE *)(v14 + 28) = 0;
    *(_DWORD *)(v14 + 52) = v18;
    *(_DWORD *)(v14 + 24) = PhysAddr + 52;
    v16 = (g_fHostFeatures & 2) == 0;
    v21 = g_SfClient;
    *(_DWORD *)(v14 + 56) = (_DWORD)&unk_10001;
    *(_DWORD *)(v14 + 60) = 63;
    *(_DWORD *)(v14 + 64) = -225;
    *(_DWORD *)(v14 + 68) = 0;
    *(_DWORD *)(v14 + 72) = 2;
    *(_DWORD *)(v14 + 76) = 0;
    *(_DWORD *)(v14 + 80) = -225;
    *(_DWORD *)(v14 + 84) = v21;
    *(_DWORD *)(v14 + 88) = 3;
    *(_DWORD *)(v14 + 92) = 3;
    *(_DWORD *)(v14 + 96) = 1;
    *(_DWORD *)(v14 + 100) = v49;
    v22 = *(unsigned __int16 *)(v14 + 252);
    if ( v16 )
    {
      *(_DWORD *)(v14 + 112) = 5;
      *(_DWORD *)(v14 + 128) = 4;
      *(_DWORD *)(v14 + 132) = 108;
      *(_QWORD *)(v14 + 136) = v14 + 144;
      *(_DWORD *)(v14 + 116) = v22 + 4;
      *(_QWORD *)(v14 + 120) = v50;
    }
    else
    {
      *(_DWORD *)(v14 + 112) = 11;
      *(_DWORD *)(v14 + 128) = 11;
      *(_DWORD *)(v14 + 136) = 108;
      *(_DWORD *)(v14 + 120) = v22 + 4;
      v23 = *(unsigned __int8 *)(v14 + 116);
      BYTE1(v23) = -56;
      *(_DWORD *)(v14 + 116) = v23;
      v24 = *(unsigned __int8 *)(v14 + 132);
      *(_BYTE *)(v14 + 116) = 1;
      BYTE1(v24) |= 0x5Cu;
      *(_DWORD *)(v14 + 132) = v24;
      *(_BYTE *)(v14 + 132) = 3;
    }
    v25 = VbglR0HGCMFastCall(*(_QWORD *)&algn_FA24[4], v14, v46);
    if ( v25 < 0 || (v25 = *(_DWORD *)(v14 + 80), v25 < 0) )
    {
      v28 = -(int)VBoxGuest_RTErrConvertToErrno((unsigned int)v25);
    }
    else
    {
      v26 = *(_DWORD *)(v14 + 152);
      if ( (unsigned int)(v26 - 4) <= 1 )
      {
        v36 = *(_QWORD *)(a2 + 24);
        if ( v36 )
        {
          v37 = jiffies;
          do
          {
            *(_QWORD *)(v36 + 120) = v37;
            v36 = *(_QWORD *)(v36 + 24);
          }
          while ( v36 != *(_QWORD *)(v36 + 24) );
        }
        *(_BYTE *)(v9 + 8) = 1;
      }
      else if ( (unsigned int)(v26 - 2) <= 1 )
      {
        v38 = *(_QWORD *)(a2 + 24);
        if ( v38 )
        {
          v39 = jiffies;
          do
          {
            *(_QWORD *)(v38 + 120) = v39;
            v38 = *(_QWORD *)(v38 + 24);
          }
          while ( v38 != *(_QWORD *)(v38 + 24) );
        }
      }
      v47 = v25;
      if ( *(_QWORD *)(v14 + 144) == -1 )
      {
        v35 = *(_DWORD *)(v14 + 152);
        if ( v35 == 3 )
        {
          v28 = -17;
          if ( a6 )
          {
            inode_isra_6 = vbsf_create_inode_isra_6((_QWORD *)(a1 + 40), a2, (__int64)src, v14 + 160, (__int64)v10, 0);
            if ( inode_isra_6 )
            {
              d_instantiate(a2, inode_isra_6);
              d_rehash(a2);
            }
            src = 0;
            v28 = -17;
            goto LABEL_27;
          }
        }
        else
        {
          v28 = -((unsigned int)(v35 - 1) < 2) - 1;
        }
LABEL_29:
        v43 = v28;
        VbglR0PhysHeapFree(v14);
        v13 = v43;
LABEL_30:
        result = v13;
        if ( src )
        {
          v44 = v13;
          kfree(src);
          return v44;
        }
        return result;
      }
      v27 = vbsf_create_inode_isra_6((_QWORD *)(a1 + 40), a2, (__int64)src, v14 + 160, (__int64)v10, a6 ^ 1u);
      v28 = -12;
      if ( v27 )
      {
        v28 = v47;
        if ( a7 )
        {
          *a7 = *(_QWORD *)(v14 + 144);
          *(_QWORD *)(v14 + 144) = -1;
        }
        else if ( a5 )
        {
          *(_QWORD *)(*(_QWORD *)(v27 + 552) + 48LL) = *(_QWORD *)(v14 + 144);
          *(_QWORD *)(v14 + 144) = -1;
        }
        if ( a8 )
          *a8 = *(_DWORD *)(v14 + 152) == 4;
        if ( a6 )
        {
          d_instantiate(a2, v27);
          d_rehash(a2);
          v28 = v47;
        }
        src = 0;
      }
    }
LABEL_27:
    v29 = *(_QWORD *)(v14 + 144);
    if ( v29 != -1 )
    {
      v30 = *v10;
      *(_DWORD *)v14 = 128;
      *(_DWORD *)(v14 + 4) = (_DWORD)&unk_10001;
      *(_DWORD *)(v14 + 8) = 0;
      *(_DWORD *)(v14 + 12) = -225;
      *(_DWORD *)(v14 + 16) = 128;
      *(_DWORD *)(v14 + 20) = 0;
      v42 = v28;
      v31 = VbglR0PhysHeapGetPhysAddr(v14);
      v32 = *(_QWORD *)&algn_FA24[4];
      *(_BYTE *)(v14 + 28) = 0;
      *(_DWORD *)(v14 + 52) = 76;
      *(_DWORD *)(v14 + 24) = v31 + 52;
      v33 = g_SfClient;
      *(_DWORD *)(v14 + 56) = (_DWORD)&unk_10001;
      *(_DWORD *)(v14 + 60) = 63;
      *(_DWORD *)(v14 + 64) = -225;
      *(_DWORD *)(v14 + 68) = 0;
      *(_DWORD *)(v14 + 72) = 2;
      *(_DWORD *)(v14 + 76) = 0;
      *(_DWORD *)(v14 + 80) = -225;
      *(_DWORD *)(v14 + 84) = v33;
      *(_DWORD *)(v14 + 88) = 4;
      *(_DWORD *)(v14 + 92) = 2;
      *(_DWORD *)(v14 + 96) = 1;
      *(_DWORD *)(v14 + 100) = v30;
      *(_DWORD *)(v14 + 112) = 2;
      *(_QWORD *)(v14 + 116) = v29;
      VbglR0HGCMFastCall(v32, v14, 128);
      v28 = v42;
    }
    goto LABEL_29;
  }
  return result;
}
