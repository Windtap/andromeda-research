__int64 __fastcall VBoxGuest_RTLogSetBuffering(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // rbx
  __int64 v11; // rax
  __int64 v12; // rdi
  unsigned int v13; // edx
  __int64 v14; // rdi
  unsigned int v15; // ebx

  v10 = a1;
  if ( a1 || (v10 = VBoxGuest_RTLogDefaultInstance()) != 0 )
  {
    v11 = *(_QWORD *)(v10 + 49168);
    if ( *(_DWORD *)v11 == 11 && *(_DWORD *)(v11 + 4) == 120 )
    {
      v12 = *(_QWORD *)(v11 + 8);
      if ( v12 )
      {
        VBoxGuest_RTSemSpinMutexRequest(v12);
        v11 = *(_QWORD *)(v10 + 49168);
      }
    }
    v13 = *(_DWORD *)(v10 + 49160);
    if ( a2 )
      *(_DWORD *)(v10 + 49160) = v13 | 2;
    else
      *(_DWORD *)(v10 + 49160) = v13 & 0xFFFFFFFD;
    v14 = *(_QWORD *)(v11 + 8);
    v15 = (v13 >> 1) & 1;
    if ( v14 )
      VBoxGuest_RTSemSpinMutexRelease(v14, a3, a4, a5, a6, a7, a8, a9, a10);
  }
  else
  {
    return 0;
  }
  return v15;
}
