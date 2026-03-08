__int64 __fastcall VBoxGuest_RTSemEventDestroy(volatile __int32 *a1)
{
  if ( !a1 )
    return 0;
  if ( *a1 != 425726224 )
    return 4294967292LL;
  _InterlockedExchange(a1, -425726225);
  _InterlockedExchange(a1 + 1, 0);
  _wake_up(a1 + 4, 3, 0, 0);
  if ( _InterlockedExchangeAdd(a1 + 2, 0xFFFFFFFF) != 1 )
    return 0;
  VBoxGuest_RTMemFree((__int64)a1);
  return 0;
}
