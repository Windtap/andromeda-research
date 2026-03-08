__int64 __fastcall VBoxGuest_RTLogDestroy(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v10; // rax
  __int64 v11; // rdi
  __int64 result; // rax
  int v13; // edx
  unsigned int v14; // eax
  __int64 v15; // rdx
  unsigned int v16; // ebp
  double v17; // xmm4_8
  double v18; // xmm5_8
  __int64 v19; // rax
  __int64 v20; // r12
  int v21; // eax
  __int64 v22; // rax

  if ( !a1 )
    return 0;
  if ( (unsigned __int64)(a1 + 0x200000) <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 4294967290LL;
  }
  if ( *(_DWORD *)(a1 + 49156) != 422056455 )
    return 4294967293LL;
  v10 = *(_QWORD *)(a1 + 49168);
  if ( (unsigned __int64)(v10 + 0x200000) <= 0x200FFF
    || (v10 & 0xFF00000000000000LL) != 0 && (v10 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 4294967290LL;
  }
  if ( *(_DWORD *)v10 != 11 || *(_DWORD *)(v10 + 4) != 120 )
    return 4294944996LL;
  v11 = *(_QWORD *)(v10 + 8);
  if ( !v11 || (result = VBoxGuest_RTSemSpinMutexRequest(v11), (int)result >= 0) )
  {
    v13 = *(_DWORD *)(a1 + 49184);
    *(_DWORD *)(a1 + 49160) |= 1u;
    v14 = v13 - 1;
    if ( v13 )
    {
      do
      {
        v15 = v14--;
        *(_DWORD *)(a1 + 4 * v15 + 49188) = 0;
      }
      while ( v14 != -1 );
    }
    v16 = 0;
    rtlogFlush_isra_12(a1);
    v19 = *(_QWORD *)(a1 + 49168);
    v20 = *(_QWORD *)(v19 + 8);
    *(_QWORD *)(v19 + 8) = 0;
    if ( v20 )
    {
      VBoxGuest_RTSemSpinMutexRelease(v20, a2, a3, a4, a5, v17, v18, a8, a9);
      v21 = VBoxGuest_RTSemSpinMutexDestroy(v20);
      if ( v21 <= 0 )
        v16 = v21;
    }
    v22 = *(_QWORD *)(a1 + 49176);
    if ( v22 )
    {
      if ( *(_DWORD *)(v22 - 16) == 403243289 )
        rtR0MemFree(v22 - 16);
      *(_QWORD *)(a1 + 49176) = 0;
    }
    VBoxGuest_RTMemFree(a1);
    return v16;
  }
  return result;
}
