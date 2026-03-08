__int64 __fastcall vbsf_inode_symlink(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v4; // r12
  __int64 v5; // rax
  int *v6; // r13
  unsigned int v7; // ebx
  __int64 v9; // r14
  __int64 v10; // rbp
  unsigned __int16 *v11; // rsi
  int v12; // r10d
  __int64 v13; // rax
  unsigned __int16 *v14; // rcx
  unsigned __int64 v15; // rsi
  int v16; // r8d
  int v17; // r13d
  int v18; // edx
  int PhysAddr; // eax
  char v20; // di
  int v21; // eax
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // eax
  __int64 inode_isra_6; // rax
  __int64 v28; // rax
  int v29; // r13d
  __int64 v30; // rax
  __int64 v31; // rdx
  unsigned int v32; // [rsp+4h] [rbp-64h]
  unsigned __int16 *v33; // [rsp+8h] [rbp-60h]
  int v34; // [rsp+18h] [rbp-50h]
  int v35; // [rsp+1Ch] [rbp-4Ch]
  unsigned __int16 *v36; // [rsp+28h] [rbp-40h] BYREF
  void *src; // [rsp+30h] [rbp-38h] BYREF

  v4 = a2;
  v5 = *(_QWORD *)(a1 + 40);
  v36 = 0;
  v6 = *(int **)(v5 + 1120);
  v7 = vbsf_nls_to_shflstring(v6, a3, &v36);
  if ( !v7 )
  {
    v9 = *(_QWORD *)(a1 + 552);
    src = 0;
    v7 = vbsf_path_from_dentry(v6, v9, a2, &src, "vbsf_inode_symlink");
    if ( v7 )
    {
LABEL_4:
      kfree(v36);
      return v7;
    }
    v10 = VbglR0PhysHeapAlloc((unsigned int)*(unsigned __int16 *)src + 272);
    if ( !v10 )
    {
      v7 = -12;
LABEL_24:
      if ( src )
        kfree(src);
      goto LABEL_4;
    }
    memset((void *)v10, 0, 0x110u);
    v11 = (unsigned __int16 *)src;
    *(_DWORD *)(v10 + 272) = 0;
    memcpy((void *)(v10 + 268), v11, *v11 + 4LL);
    v12 = *v6;
    v13 = 0x77FF80000000LL;
    v14 = v36;
    if ( (unsigned __int64)v36 >= 0xFFFFFFFF80000000LL )
      v13 = phys_base;
    v15 = (unsigned __int64)v36 + v13 + 0x80000000LL;
    v16 = *v36 + 4;
    if ( (g_fHostFeatures & 2) != 0 )
    {
      v29 = *(unsigned __int16 *)(v10 + 268);
      v18 = v29 + 272;
      v17 = v29 + 220;
    }
    else
    {
      v17 = 124;
      v18 = 176;
    }
    *(_DWORD *)v10 = v18;
    *(_DWORD *)(v10 + 16) = v18;
    *(_DWORD *)(v10 + 4) = (_DWORD)&unk_10001;
    *(_DWORD *)(v10 + 8) = 0;
    *(_DWORD *)(v10 + 12) = -225;
    *(_DWORD *)(v10 + 20) = 0;
    v35 = v16;
    v34 = v12;
    v33 = v14;
    v32 = v18;
    PhysAddr = VbglR0PhysHeapGetPhysAddr(v10);
    v20 = g_fHostFeatures;
    *(_BYTE *)(v10 + 28) = 0;
    *(_DWORD *)(v10 + 52) = v17;
    *(_DWORD *)(v10 + 24) = PhysAddr + 52;
    v21 = g_SfClient;
    *(_DWORD *)(v10 + 56) = (_DWORD)&unk_10001;
    *(_DWORD *)(v10 + 60) = 63;
    *(_DWORD *)(v10 + 100) = v34;
    *(_DWORD *)(v10 + 64) = -225;
    *(_DWORD *)(v10 + 68) = 0;
    *(_DWORD *)(v10 + 72) = 2;
    *(_DWORD *)(v10 + 76) = 0;
    *(_DWORD *)(v10 + 80) = -225;
    *(_DWORD *)(v10 + 84) = v21;
    *(_DWORD *)(v10 + 88) = 19;
    *(_DWORD *)(v10 + 92) = 4;
    *(_DWORD *)(v10 + 96) = 1;
    v22 = *(unsigned __int16 *)(v10 + 268);
    if ( (v20 & 2) != 0 )
    {
      *(_DWORD *)(v10 + 112) = 11;
      *(_DWORD *)(v10 + 120) = v22 + 4;
      v23 = *(unsigned __int8 *)(v10 + 116);
      BYTE1(v23) = -40;
      *(_DWORD *)(v10 + 116) = v23;
      *(_BYTE *)(v10 + 116) = 1;
    }
    else
    {
      *(_DWORD *)(v10 + 112) = 5;
      *(_DWORD *)(v10 + 116) = v22 + 4;
      *(_QWORD *)(v10 + 120) = v10 + 268;
    }
    if ( v35 <= 4096 - (v15 & 0xFFF) )
    {
      v24 = 10;
    }
    else
    {
      if ( (v20 & 4) == 0 )
      {
        *(_DWORD *)(v10 + 128) = 5;
        *(_DWORD *)(v10 + 132) = v35;
        *(_QWORD *)(v10 + 136) = v33;
        goto LABEL_16;
      }
      v24 = 12;
    }
    *(_DWORD *)(v10 + 128) = v24;
    *(_DWORD *)(v10 + 132) = v35;
    *(_WORD *)(v10 + 164) = v15 & 0xFFF;
    *(_DWORD *)(v10 + 136) = 108;
    *(_DWORD *)(v10 + 160) = 1;
    *(_QWORD *)(v10 + 168) = v15 & 0xFFFFFFFFFFFFF000LL;
    *(_WORD *)(v10 + 166) = 1;
LABEL_16:
    if ( (v20 & 2) != 0 )
    {
      v25 = *(unsigned __int8 *)(v10 + 148);
      *(_DWORD *)(v10 + 144) = 11;
      *(_DWORD *)(v10 + 152) = 92;
      BYTE1(v25) |= 0x7Cu;
      *(_DWORD *)(v10 + 148) = v25;
      *(_BYTE *)(v10 + 148) = 2;
    }
    else
    {
      *(_DWORD *)(v10 + 144) = 6;
      *(_DWORD *)(v10 + 148) = 92;
      *(_QWORD *)(v10 + 152) = v10 + 176;
    }
    v26 = VbglR0HGCMFastCall(*(_QWORD *)&algn_FA24[4], v10, v32);
    if ( v26 < 0 || (v26 = *(_DWORD *)(v10 + 80), v26 < 0) )
    {
      v7 = -1;
      if ( v26 != -113 )
        v7 = -(int)VBoxGuest_RTErrConvertToErrno((unsigned int)v26);
    }
    else
    {
      *(_BYTE *)(v9 + 8) = 1;
      inode_isra_6 = vbsf_create_inode_isra_6(
                       (_QWORD *)(a1 + 40),
                       v4,
                       (__int64)src,
                       v10 + 176,
                       *(_QWORD *)(*(_QWORD *)(a1 + 40) + 1120LL),
                       1);
      if ( inode_isra_6 )
      {
        src = 0;
        *(_QWORD *)(*(_QWORD *)(inode_isra_6 + 552) + 48LL) = -1;
        v28 = jiffies;
        do
        {
          *(_QWORD *)(v4 + 120) = v28;
          v4 = *(_QWORD *)(v4 + 24);
        }
        while ( v4 != *(_QWORD *)(v4 + 24) );
      }
      else
      {
        v30 = *(_QWORD *)(v4 + 24);
        if ( v30 )
        {
          v31 = jiffies;
          do
          {
            *(_QWORD *)(v30 + 120) = v31;
            v30 = *(_QWORD *)(v30 + 24);
          }
          while ( v30 != *(_QWORD *)(v30 + 24) );
        }
        v7 = -12;
        *(_QWORD *)(v4 + 120) = jiffies - 0x3FFFFFFFLL;
      }
    }
    VbglR0PhysHeapFree(v10);
    goto LABEL_24;
  }
  return v7;
}
