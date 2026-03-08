__int64 __fastcall vgdrvSetSessionMouseStatus(__int64 a1, __int64 a2, int a3, int a4, char a5)
{
  int v9; // r12d
  int v10; // ebx
  int v11; // edx
  unsigned int v12; // r15d
  __int64 v14; // rdi
  int v15; // eax
  __int64 DefaultInstance; // rax
  int v17; // r9d
  _QWORD v19[7]; // [rsp+8h] [rbp-38h] BYREF

  v9 = VbglR0GRAlloc(v19, 36, 2);
  if ( v9 >= 0 )
  {
    if ( !a5 )
      *(_DWORD *)(v19[0] + 20LL) = *(_DWORD *)(a2 + 16);
    goto LABEL_4;
  }
  if ( a5 )
  {
    v19[0] = 0;
LABEL_4:
    VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a1 + 128));
    v10 = *(_DWORD *)(a2 + 312);
    v11 = ~a4 & (v10 | a3);
    *(_DWORD *)(a2 + 312) = v11;
    v12 = v10 ^ v11;
    if ( v10 != v11
      && ((unsigned __int8)vgdrvBitUsageTrackerChange_isra_1(a1 + 356, v12, v10) || *(_DWORD *)(a1 + 488) == -1) )
    {
      v14 = v19[0];
      if ( !v19[0] || (v15 = *(_DWORD *)(a1 + 484), *(_DWORD *)(v19[0] + 24LL) = v15, v15 == *(_DWORD *)(a1 + 488)) )
      {
        v9 = 0;
      }
      else
      {
        *(_DWORD *)(a1 + 488) = v15;
        *(_DWORD *)(v14 + 28) = 0;
        *(_DWORD *)(v14 + 32) = 0;
        v9 = VbglR0GRPerform(v14);
        if ( v9 < 0 )
        {
          *(_DWORD *)(a1 + 488) = -1;
          if ( !a5 )
          {
            vgdrvBitUsageTrackerChange_isra_1(a1 + 356, v12, *(_DWORD *)(a2 + 312));
            *(_DWORD *)(a2 + 312) = v10;
          }
        }
      }
    }
    VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 128));
    if ( v19[0] )
      VbglR0GRFree(v19[0]);
    return (unsigned int)v9;
  }
  DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
  if ( DefaultInstance )
    VBoxGuest_RTLogLoggerEx(
      DefaultInstance,
      16,
      32,
      (unsigned int)"vgdrvSetSessionMouseStatus: VbglR0GRAlloc failure: %Rrc\n",
      v9,
      v17);
  return (unsigned int)v9;
}
