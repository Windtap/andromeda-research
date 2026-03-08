__int64 __fastcall VBoxGuest_RTSemSpinMutexTryRequest(__int64 a1)
{
  __int64 v1; // rax
  __int64 result; // rax
  signed __int64 v3; // rbp
  unsigned int v4; // ebx
  unsigned __int64 v5; // [rsp+0h] [rbp-28h] BYREF
  __int64 v6; // [rsp+8h] [rbp-20h] BYREF
  __int64 v7; // [rsp+10h] [rbp-18h]

  v1 = VBoxGuest_RTThreadNativeSelf();
  if ( *(_DWORD *)a1 == 409403913 )
  {
    v3 = v1;
    result = rtSemSpinMutexEnter((__int64)&v5, a1);
    if ( (int)result >= 0 )
    {
      if ( _InterlockedCompareExchange64((volatile signed __int64 *)(a1 + 8), v3, -1) == -1 )
      {
        _InterlockedExchangeAdd((volatile signed __int32 *)(a1 + 16), 1u);
        *(_QWORD *)(a1 + 32) = v5;
        *(_QWORD *)(a1 + 40) = v6;
        *(_QWORD *)(a1 + 48) = v7;
        return 0;
      }
      else
      {
        v4 = 4 * (v3 != *(_QWORD *)(a1 + 8)) - 364;
        if ( BYTE1(v7) )
          __writeeflags(v5);
        VBoxGuest_RTThreadPreemptRestore(&v6);
        return v4;
      }
    }
  }
  else
  {
    result = 4294966933LL;
    if ( *(_DWORD *)a1 != 420876809 )
      return 4294967292LL;
  }
  return result;
}
