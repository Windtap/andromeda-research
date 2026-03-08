__int64 __fastcall vbsf_stat(__int64 a1, int *a2, unsigned __int16 *a3, __int64 a4)
{
  __int64 v6; // rbx
  bool v7; // zf
  int v8; // r15d
  int v9; // r14d
  unsigned int v10; // r12d
  int PhysAddr; // eax
  int v12; // eax
  int v13; // eax
  int v14; // eax
  int v15; // eax
  __int64 v16; // rdx
  unsigned int v17; // r12d
  int v18; // eax
  int v20; // r14d

  v6 = VbglR0PhysHeapAlloc((unsigned int)*a3 + 260);
  if ( v6 )
  {
    memset((void *)v6, 0, 0x100u);
    *(_DWORD *)(v6 + 256) = 0;
    memcpy((void *)(v6 + 252), a3, *a3 + 4LL);
    v7 = (g_fHostFeatures & 2) == 0;
    *(_QWORD *)(v6 + 144) = -1;
    *(_DWORD *)(v6 + 156) = 257;
    v8 = *a2;
    if ( v7 )
    {
      v9 = 92;
      v10 = 144;
    }
    else
    {
      v20 = *(unsigned __int16 *)(v6 + 252);
      v10 = v20 + 256;
      v9 = v20 + 204;
    }
    *(_DWORD *)v6 = v10;
    *(_DWORD *)(v6 + 4) = (_DWORD)&unk_10001;
    *(_DWORD *)(v6 + 8) = 0;
    *(_DWORD *)(v6 + 12) = -225;
    *(_DWORD *)(v6 + 16) = v10;
    *(_DWORD *)(v6 + 20) = 0;
    PhysAddr = VbglR0PhysHeapGetPhysAddr(v6);
    *(_BYTE *)(v6 + 28) = 0;
    v7 = (g_fHostFeatures & 2) == 0;
    *(_DWORD *)(v6 + 52) = v9;
    *(_DWORD *)(v6 + 24) = PhysAddr + 52;
    v12 = g_SfClient;
    *(_DWORD *)(v6 + 56) = (_DWORD)&unk_10001;
    *(_DWORD *)(v6 + 60) = 63;
    *(_DWORD *)(v6 + 64) = -225;
    *(_DWORD *)(v6 + 68) = 0;
    *(_DWORD *)(v6 + 72) = 2;
    *(_DWORD *)(v6 + 76) = 0;
    *(_DWORD *)(v6 + 80) = -225;
    *(_DWORD *)(v6 + 84) = v12;
    *(_DWORD *)(v6 + 88) = 3;
    *(_DWORD *)(v6 + 92) = 3;
    *(_DWORD *)(v6 + 96) = 1;
    *(_DWORD *)(v6 + 100) = v8;
    v13 = *(unsigned __int16 *)(v6 + 252);
    if ( v7 )
    {
      *(_DWORD *)(v6 + 112) = 5;
      *(_QWORD *)(v6 + 120) = v6 + 252;
      *(_DWORD *)(v6 + 128) = 4;
      *(_DWORD *)(v6 + 132) = 108;
      *(_DWORD *)(v6 + 116) = v13 + 4;
      *(_QWORD *)(v6 + 136) = v6 + 144;
    }
    else
    {
      *(_DWORD *)(v6 + 112) = 11;
      *(_DWORD *)(v6 + 128) = 11;
      *(_DWORD *)(v6 + 136) = 108;
      *(_DWORD *)(v6 + 120) = v13 + 4;
      v14 = *(unsigned __int8 *)(v6 + 116);
      BYTE1(v14) = -56;
      *(_DWORD *)(v6 + 116) = v14;
      v15 = *(unsigned __int8 *)(v6 + 132);
      *(_BYTE *)(v6 + 116) = 1;
      BYTE1(v15) |= 0x5Cu;
      *(_DWORD *)(v6 + 132) = v15;
      *(_BYTE *)(v6 + 132) = 3;
    }
    v16 = v10;
    v17 = -2;
    v18 = VbglR0HGCMFastCall(*(_QWORD *)&algn_FA24[4], v6, v16);
    if ( v18 < 0 || (v18 = *(_DWORD *)(v6 + 80), v18 < 0) )
    {
      if ( v18 != -104 )
        v17 = -71;
    }
    else if ( *(_DWORD *)(v6 + 152) == 3 )
    {
      v17 = 0;
      *(_QWORD *)a4 = *(_QWORD *)(v6 + 160);
      *(_QWORD *)(a4 + 8) = *(_QWORD *)(v6 + 168);
      *(_QWORD *)(a4 + 16) = *(_QWORD *)(v6 + 176);
      *(_QWORD *)(a4 + 24) = *(_QWORD *)(v6 + 184);
      *(_QWORD *)(a4 + 32) = *(_QWORD *)(v6 + 192);
      *(_QWORD *)(a4 + 40) = *(_QWORD *)(v6 + 200);
      *(_QWORD *)(a4 + 48) = *(_QWORD *)(v6 + 208);
      *(_QWORD *)(a4 + 56) = *(_QWORD *)(v6 + 216);
      *(_QWORD *)(a4 + 64) = *(_QWORD *)(v6 + 224);
      *(_QWORD *)(a4 + 72) = *(_QWORD *)(v6 + 232);
      *(_QWORD *)(a4 + 80) = *(_QWORD *)(v6 + 240);
      *(_DWORD *)(a4 + 88) = *(_DWORD *)(v6 + 248);
    }
    VbglR0PhysHeapFree(v6);
  }
  else
  {
    return (unsigned int)-12;
  }
  return v17;
}
