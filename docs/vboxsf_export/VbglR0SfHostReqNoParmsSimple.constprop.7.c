__int64 __fastcall VbglR0SfHostReqNoParmsSimple_constprop_7(int a1, unsigned __int64 a2)
{
  _DWORD *v3; // rax
  __int64 v4; // rbx
  int PhysAddr; // eax
  __int64 v6; // rdi
  int v7; // eax
  int v8; // ebp

  v3 = (_DWORD *)VbglR0PhysHeapAlloc(96, a2);
  v4 = (__int64)v3;
  if ( !v3 )
    return 4294967288LL;
  *v3 = 96;
  v3[1] = (_DWORD)&unk_10001;
  v3[2] = 0;
  v3[3] = -225;
  v3[4] = 96;
  v3[5] = 0;
  PhysAddr = VbglR0PhysHeapGetPhysAddr((__int64)v3);
  v6 = *(_QWORD *)&algn_FA24[4];
  *(_DWORD *)(v4 + 88) = a1;
  *(_BYTE *)(v4 + 28) = 0;
  *(_DWORD *)(v4 + 24) = PhysAddr + 52;
  v7 = g_SfClient;
  *(_DWORD *)(v4 + 52) = 44;
  *(_DWORD *)(v4 + 56) = (_DWORD)&unk_10001;
  *(_DWORD *)(v4 + 60) = 63;
  *(_DWORD *)(v4 + 64) = -225;
  *(_DWORD *)(v4 + 68) = 0;
  *(_DWORD *)(v4 + 72) = 2;
  *(_DWORD *)(v4 + 76) = 0;
  *(_DWORD *)(v4 + 80) = -225;
  *(_DWORD *)(v4 + 84) = v7;
  *(_DWORD *)(v4 + 92) = 0;
  v8 = VbglR0HGCMFastCall(v6, v4, 0x60u);
  if ( v8 >= 0 )
    v8 = *(_DWORD *)(v4 + 80);
  VbglR0PhysHeapFree(v4, v4);
  return (unsigned int)v8;
}
