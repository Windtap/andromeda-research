__int64 __fastcall vbsf_statfs(__int64 a1, __int64 a2)
{
  __int64 v2; // r12
  __int64 v3; // rax
  __int64 v4; // rbx
  __int64 v5; // rdi
  int v6; // r14d
  char v7; // al
  int v8; // eax
  int v9; // r13d
  unsigned int v10; // r12d
  int PhysAddr; // eax
  bool v12; // zf
  int v13; // eax
  int v14; // eax
  __int64 v15; // rax
  __int64 v16; // rcx
  unsigned int v17; // ebp
  int v19; // eax

  v2 = *(_QWORD *)(*(_QWORD *)(a1 + 48) + 40LL);
  v3 = VbglR0PhysHeapAlloc(216);
  v4 = v3;
  if ( v3 )
  {
    v5 = v3;
    v6 = **(_DWORD **)(v2 + 1120);
    *(_DWORD *)(v3 + 4) = (_DWORD)&unk_10001;
    v7 = g_fHostFeatures;
    *(_DWORD *)(v4 + 8) = 0;
    *(_DWORD *)(v4 + 12) = -225;
    *(_DWORD *)(v4 + 20) = 0;
    v8 = v7 & 2;
    v9 = v8 == 0 ? 124 : 164;
    v10 = v8 == 0 ? 176 : 216;
    *(_DWORD *)v4 = v10;
    *(_DWORD *)(v4 + 16) = v10;
    PhysAddr = VbglR0PhysHeapGetPhysAddr(v5);
    *(_BYTE *)(v4 + 28) = 0;
    v12 = (g_fHostFeatures & 2) == 0;
    *(_DWORD *)(v4 + 52) = v9;
    *(_DWORD *)(v4 + 24) = PhysAddr + 52;
    v13 = g_SfClient;
    *(_DWORD *)(v4 + 56) = (_DWORD)&unk_10001;
    *(_DWORD *)(v4 + 60) = 63;
    *(_DWORD *)(v4 + 64) = -225;
    *(_DWORD *)(v4 + 68) = 0;
    *(_DWORD *)(v4 + 72) = 2;
    *(_DWORD *)(v4 + 76) = 0;
    *(_DWORD *)(v4 + 80) = -225;
    *(_DWORD *)(v4 + 84) = v13;
    *(_DWORD *)(v4 + 88) = 9;
    *(_DWORD *)(v4 + 92) = 5;
    *(_DWORD *)(v4 + 96) = 1;
    *(_DWORD *)(v4 + 100) = v6;
    *(_DWORD *)(v4 + 112) = 2;
    *(_QWORD *)(v4 + 116) = 0;
    *(_DWORD *)(v4 + 128) = 1;
    *(_DWORD *)(v4 + 132) = 16;
    *(_DWORD *)(v4 + 144) = 1;
    *(_DWORD *)(v4 + 148) = 40;
    if ( v12 )
    {
      *(_DWORD *)(v4 + 160) = 6;
      *(_DWORD *)(v4 + 164) = 40;
      *(_QWORD *)(v4 + 168) = v4 + 176;
    }
    else
    {
      v19 = *(unsigned __int8 *)(v4 + 164);
      *(_DWORD *)(v4 + 160) = 11;
      *(_DWORD *)(v4 + 168) = 40;
      BYTE1(v19) |= 0x7Cu;
      *(_DWORD *)(v4 + 164) = v19;
      *(_BYTE *)(v4 + 164) = 2;
    }
    v14 = VbglR0HGCMFastCall(*(_QWORD *)&algn_FA24[4], v4, v10);
    if ( v14 < 0 || (v14 = *(_DWORD *)(v4 + 80), v14 < 0) )
    {
      v17 = -(int)VBoxGuest_RTErrConvertToErrno((unsigned int)v14);
    }
    else
    {
      *(_QWORD *)a2 = 2020557398;
      *(_QWORD *)(a2 + 8) = *(unsigned int *)(v4 + 192);
      *(_QWORD *)(a2 + 72) = *(unsigned int *)(v4 + 192);
      *(_QWORD *)(a2 + 16) = *(_QWORD *)(v4 + 176) / (__int64)*(unsigned int *)(v4 + 192);
      *(_QWORD *)(a2 + 24) = *(_QWORD *)(v4 + 184) / (__int64)*(unsigned int *)(v4 + 192);
      v15 = *(_QWORD *)(v4 + 184);
      v16 = *(unsigned int *)(v4 + 192);
      *(_QWORD *)(a2 + 40) = 1000;
      *(_QWORD *)(a2 + 48) = 1000000;
      *(_DWORD *)(a2 + 56) = 0;
      *(_DWORD *)(a2 + 60) = 0;
      *(_QWORD *)(a2 + 64) = 255;
      *(_QWORD *)(a2 + 32) = v15 / v16;
      *(_QWORD *)(a2 + 80) = 0;
      *(_QWORD *)(a2 + 88) = 0;
      *(_QWORD *)(a2 + 96) = 0;
      *(_QWORD *)(a2 + 104) = 0;
      *(_QWORD *)(a2 + 112) = 0;
      v17 = 0;
    }
    VbglR0PhysHeapFree(v4);
  }
  else
  {
    return (unsigned int)-12;
  }
  return v17;
}
