__int64 __fastcall VBoxGuest_RTLogSetCustomPrefixCallback(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v12; // rbx
  __int64 v13; // rax
  __int64 v14; // rdi
  __int64 v15; // rdi

  v12 = a1;
  if ( !a1 )
  {
    v12 = VBoxGuest_RTLogDefaultInstance();
    if ( !v12 )
      return 0;
  }
  if ( *(_DWORD *)(v12 + 49156) == 422056455 )
  {
    v13 = *(_QWORD *)(v12 + 49168);
    if ( *(_DWORD *)v13 == 11 && *(_DWORD *)(v13 + 4) == 120 )
    {
      v14 = *(_QWORD *)(v13 + 8);
      if ( v14 )
      {
        VBoxGuest_RTSemSpinMutexRequest(v14);
        v13 = *(_QWORD *)(v12 + 49168);
      }
    }
    *(_QWORD *)(v13 + 32) = a3;
    *(_QWORD *)(*(_QWORD *)(v12 + 49168) + 24LL) = a2;
    v15 = *(_QWORD *)(*(_QWORD *)(v12 + 49168) + 8LL);
    if ( v15 )
      VBoxGuest_RTSemSpinMutexRelease(v15, a4, a5, a6, a7, a8, a9, a10, a11);
    return 0;
  }
  return 4294967293LL;
}
