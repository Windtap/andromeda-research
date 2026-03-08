__int64 __fastcall vgdrvSetSessionEventFilter(__int64 a1, __int64 a2, int a3, int a4, char a5)
{
  int v8; // ebp
  int v9; // ebx
  int v10; // edx
  unsigned int v11; // r15d
  __int64 v13; // rdi
  int v14; // eax
  __int64 DefaultInstance; // rax
  int v16; // r9d
  _QWORD v18[7]; // [rsp+8h] [rbp-38h] BYREF

  v8 = VbglR0GRAlloc(v18, 32, 42);
  if ( v8 >= 0 )
    goto LABEL_2;
  if ( a5 )
  {
    v18[0] = 0;
LABEL_2:
    VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a1 + 128));
    v9 = *(_DWORD *)(a2 + 300);
    v10 = ~a4 & (v9 | a3);
    *(_DWORD *)(a2 + 300) = v10;
    v11 = v9 ^ v10;
    if ( v9 != v10
      && ((unsigned __int8)vgdrvBitUsageTrackerChange_isra_1(a1 + 220, v11, v9) || *(_DWORD *)(a1 + 352) == -1) )
    {
      v13 = v18[0];
      if ( !v18[0]
        || (v14 = *(_DWORD *)(a1 + 216) | *(_DWORD *)(a1 + 348),
            *(_DWORD *)(v18[0] + 24LL) = v14,
            v14 == *(_DWORD *)(a1 + 352)) )
      {
        v8 = 0;
      }
      else
      {
        *(_DWORD *)(a1 + 352) = v14;
        *(_DWORD *)(v13 + 28) = ~*(_DWORD *)(v13 + 24);
        v8 = VbglR0GRPerform(v13);
        if ( v8 < 0 )
        {
          *(_DWORD *)(a1 + 352) = -1;
          if ( !a5 )
          {
            vgdrvBitUsageTrackerChange_isra_1(a1 + 220, v11, *(_DWORD *)(a2 + 300));
            *(_DWORD *)(a2 + 300) = v9;
          }
        }
      }
    }
    VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 128));
    if ( v18[0] )
      VbglR0GRFree(v18[0]);
    return (unsigned int)v8;
  }
  DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
  if ( DefaultInstance )
    VBoxGuest_RTLogLoggerEx(
      DefaultInstance,
      16,
      32,
      (unsigned int)"vgdrvSetSessionFilterMask: VbglR0GRAlloc failure: %Rrc\n",
      v8,
      v16);
  return (unsigned int)v8;
}
