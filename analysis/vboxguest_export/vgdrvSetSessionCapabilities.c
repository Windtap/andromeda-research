__int64 __fastcall vgdrvSetSessionCapabilities(__int64 a1, __int64 a2, int a3, int a4, _DWORD *a5, int *a6, char a7)
{
  int v11; // ebx
  int v13; // ecx
  int v14; // r13d
  unsigned int v15; // r13d
  __int64 v16; // rdi
  int v17; // eax
  __int64 DefaultInstance; // rax
  int v19; // r9d
  int v21; // [rsp+4h] [rbp-44h]
  __int64 v22; // [rsp+8h] [rbp-40h]
  _QWORD v23[7]; // [rsp+10h] [rbp-38h] BYREF

  v11 = VbglR0GRAlloc(v23, 32, 56);
  if ( v11 >= 0 )
  {
    if ( !a7 )
      *(_DWORD *)(v23[0] + 20LL) = *(_DWORD *)(a2 + 16);
    goto LABEL_4;
  }
  if ( a7 )
  {
    v23[0] = 0;
LABEL_4:
    VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a1 + 128));
    if ( (*(_DWORD *)(a1 + 492) & a3) != 0 )
    {
      v11 = -138;
    }
    else
    {
      v13 = *(_DWORD *)(a2 + 308);
      v14 = ~a4 & (v13 | a3);
      *(_DWORD *)(a2 + 308) = v14;
      v15 = v13 ^ v14;
      if ( v15 )
      {
        v21 = v13;
        v22 = a1 + 504;
        if ( (unsigned __int8)vgdrvBitUsageTrackerChange_isra_1(a1 + 504, v15, v13) || *(_DWORD *)(a1 + 636) == -1 )
        {
          v16 = v23[0];
          if ( v23[0] )
          {
            v11 = 0;
            v17 = *(_DWORD *)(a1 + 500) | *(_DWORD *)(a1 + 632);
            *(_DWORD *)(v23[0] + 24LL) = v17;
            if ( v17 != *(_DWORD *)(a1 + 636) )
            {
              *(_DWORD *)(a1 + 636) = v17;
              *(_DWORD *)(v16 + 28) = ~*(_DWORD *)(v16 + 24);
              v11 = VbglR0GRPerform(v16);
              if ( v11 < 0 )
              {
                *(_DWORD *)(a1 + 636) = -1;
                if ( !a7 )
                {
                  vgdrvBitUsageTrackerChange_isra_1(v22, v15, *(_DWORD *)(a2 + 308));
                  *(_DWORD *)(a2 + 308) = v21;
                }
              }
            }
          }
        }
      }
    }
    if ( a5 )
      *a5 = *(_DWORD *)(a2 + 308);
    if ( a6 )
      *a6 = *(_DWORD *)(a1 + 500) | *(_DWORD *)(a1 + 632);
    VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 128));
    if ( v23[0] )
      VbglR0GRFree(v23[0]);
    return (unsigned int)v11;
  }
  if ( a5 )
    *a5 = -1;
  if ( a6 )
    *a6 = -1;
  DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
  if ( DefaultInstance )
    VBoxGuest_RTLogLoggerEx(
      DefaultInstance,
      16,
      32,
      (unsigned int)"vgdrvSetSessionCapabilities: VbglR0GRAlloc failure: %Rrc\n",
      v11,
      v19);
  return (unsigned int)v11;
}
