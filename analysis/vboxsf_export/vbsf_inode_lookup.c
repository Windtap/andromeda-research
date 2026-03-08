__int64 __fastcall vbsf_inode_lookup(__int64 a1, __int64 a2)
{
  int *v3; // r14
  int v4; // eax
  __int64 v5; // rbp
  __int64 v7; // rbx
  unsigned __int16 *v8; // rsi
  bool v9; // zf
  int v10; // ecx
  int v11; // r15d
  int v12; // edx
  int PhysAddr; // eax
  int v14; // eax
  int v15; // eax
  int v16; // eax
  int v17; // eax
  int v18; // r15d
  int v19; // eax
  __int64 inode_isra_6; // r12
  int v21; // r15d
  __int64 v22; // rdx
  __int64 v23; // rax
  unsigned int v24; // [rsp+0h] [rbp-40h]
  int v25; // [rsp+4h] [rbp-3Ch]
  void *src; // [rsp+8h] [rbp-38h] BYREF

  v3 = *(int **)(*(_QWORD *)(a1 + 40) + 1120LL);
  v4 = vbsf_path_from_dentry(v3, *(_QWORD *)(a1 + 552), a2, &src, "vbsf_inode_lookup");
  v5 = v4;
  if ( v4 )
    return v5;
  v5 = -12;
  v7 = VbglR0PhysHeapAlloc((unsigned int)*(unsigned __int16 *)src + 260);
  if ( v7 )
  {
    memset((void *)v7, 0, 0x100u);
    v8 = (unsigned __int16 *)src;
    *(_DWORD *)(v7 + 256) = 0;
    memcpy((void *)(v7 + 252), v8, *v8 + 4LL);
    v9 = (g_fHostFeatures & 2) == 0;
    *(_QWORD *)(v7 + 144) = -1;
    *(_DWORD *)(v7 + 156) = 257;
    v10 = *v3;
    if ( v9 )
    {
      v11 = 92;
      v12 = 144;
    }
    else
    {
      v21 = *(unsigned __int16 *)(v7 + 252);
      v12 = v21 + 256;
      v11 = v21 + 204;
    }
    *(_DWORD *)v7 = v12;
    *(_DWORD *)(v7 + 16) = v12;
    *(_DWORD *)(v7 + 4) = (_DWORD)&unk_10001;
    *(_DWORD *)(v7 + 8) = 0;
    *(_DWORD *)(v7 + 12) = -225;
    *(_DWORD *)(v7 + 20) = 0;
    v25 = v10;
    v24 = v12;
    PhysAddr = VbglR0PhysHeapGetPhysAddr(v7);
    *(_BYTE *)(v7 + 28) = 0;
    *(_DWORD *)(v7 + 52) = v11;
    *(_DWORD *)(v7 + 24) = PhysAddr + 52;
    v9 = (g_fHostFeatures & 2) == 0;
    v14 = g_SfClient;
    *(_DWORD *)(v7 + 56) = (_DWORD)&unk_10001;
    *(_DWORD *)(v7 + 60) = 63;
    *(_DWORD *)(v7 + 64) = -225;
    *(_DWORD *)(v7 + 68) = 0;
    *(_DWORD *)(v7 + 72) = 2;
    *(_DWORD *)(v7 + 76) = 0;
    *(_DWORD *)(v7 + 80) = -225;
    *(_DWORD *)(v7 + 84) = v14;
    *(_DWORD *)(v7 + 88) = 3;
    *(_DWORD *)(v7 + 92) = 3;
    *(_DWORD *)(v7 + 96) = 1;
    *(_DWORD *)(v7 + 100) = v25;
    v15 = *(unsigned __int16 *)(v7 + 252);
    if ( v9 )
    {
      *(_DWORD *)(v7 + 112) = 5;
      *(_QWORD *)(v7 + 120) = v7 + 252;
      *(_DWORD *)(v7 + 128) = 4;
      *(_DWORD *)(v7 + 132) = 108;
      *(_DWORD *)(v7 + 116) = v15 + 4;
      *(_QWORD *)(v7 + 136) = v7 + 144;
    }
    else
    {
      *(_DWORD *)(v7 + 112) = 11;
      *(_DWORD *)(v7 + 128) = 11;
      *(_DWORD *)(v7 + 136) = 108;
      *(_DWORD *)(v7 + 120) = v15 + 4;
      v16 = *(unsigned __int8 *)(v7 + 116);
      BYTE1(v16) = -56;
      *(_DWORD *)(v7 + 116) = v16;
      v17 = *(unsigned __int8 *)(v7 + 132);
      *(_BYTE *)(v7 + 116) = 1;
      BYTE1(v17) |= 0x5Cu;
      *(_DWORD *)(v7 + 132) = v17;
      *(_BYTE *)(v7 + 132) = 3;
    }
    v18 = VbglR0HGCMFastCall(*(_QWORD *)&algn_FA24[4], v7, v24);
    if ( v18 < 0 || (v18 = *(_DWORD *)(v7 + 80), v18 < 0) )
    {
      if ( v18 == -104 )
        goto LABEL_18;
      inode_isra_6 = 0;
      v5 = -36;
      if ( v18 != -120 )
        v5 = -71;
    }
    else
    {
      v19 = *(_DWORD *)(v7 + 152);
      if ( v19 != 3 )
      {
        if ( (unsigned int)(v19 - 1) > 1 )
        {
          inode_isra_6 = 0;
          v5 = -71;
          goto LABEL_13;
        }
LABEL_18:
        inode_isra_6 = 0;
        VbglR0PhysHeapFree(v7);
LABEL_19:
        v5 = 0;
        *(_QWORD *)(a2 + 120) = jiffies;
        d_instantiate(a2, inode_isra_6);
        d_rehash(a2);
        goto LABEL_14;
      }
      v5 = -12;
      inode_isra_6 = vbsf_create_inode_isra_6((_QWORD *)(a1 + 40), a2, (__int64)src, v7 + 160, (__int64)v3, 0);
      if ( !v18 )
      {
        src = 0;
        v5 = a2;
      }
      v22 = *(_QWORD *)(a2 + 24);
      if ( v22 )
      {
        v23 = jiffies;
        do
        {
          *(_QWORD *)(v22 + 120) = v23;
          v22 = *(_QWORD *)(v22 + 24);
        }
        while ( v22 != *(_QWORD *)(v22 + 24) );
      }
    }
LABEL_13:
    VbglR0PhysHeapFree(v7);
    if ( v5 != a2 )
      goto LABEL_14;
    goto LABEL_19;
  }
LABEL_14:
  if ( src )
    kfree(src);
  return v5;
}
