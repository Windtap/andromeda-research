__int64 __fastcall VBoxGuest_RTLogClearFileDelayFlag(
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
  __int64 v9; // rbx
  __int64 v10; // rax
  __int64 v11; // rdi
  int v12; // edx
  __int64 v13; // rdi

  v9 = a1;
  if ( a1 || (v9 = VBoxGuest_RTLogDefaultInstance()) != 0 )
  {
    v10 = *(_QWORD *)(v9 + 49168);
    if ( *(_DWORD *)v10 == 11 && *(_DWORD *)(v10 + 4) == 120 )
    {
      v11 = *(_QWORD *)(v10 + 8);
      if ( v11 )
      {
        if ( (int)VBoxGuest_RTSemSpinMutexRequest(v11) < 0 )
          return 0;
        v10 = *(_QWORD *)(v9 + 49168);
      }
      v12 = *(_DWORD *)(v9 + 49164);
      if ( (v12 & 0x20000) != 0 )
        *(_DWORD *)(v9 + 49164) = v12 & 0xFFFDFFFF;
      v13 = *(_QWORD *)(v10 + 8);
      if ( v13 )
        VBoxGuest_RTSemSpinMutexRelease(v13, a2, a3, a4, a5, a6, a7, a8, a9);
    }
  }
  return 0;
}
