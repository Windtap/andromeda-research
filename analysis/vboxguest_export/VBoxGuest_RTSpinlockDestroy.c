__int64 __fastcall VBoxGuest_RTSpinlockDestroy(volatile signed __int32 *a1)
{
  __int64 result; // rax

  if ( !a1 )
    return 4294967294LL;
  result = 4294967294LL;
  if ( *a1 == 424150056 )
  {
    _InterlockedExchangeAdd(a1, 1u);
    VBoxGuest_RTMemFree((__int64)a1);
    return 0;
  }
  return result;
}
