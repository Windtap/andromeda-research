__int64 __fastcall VBoxGuest_RTSemEventMultiDestroy(volatile __int32 *a1)
{
  if ( !a1 )
    return 0;
  if ( (unsigned __int64)(a1 + 0x80000) <= 0x200FFF
    || ((unsigned __int64)a1 & 0xFF00000000000000LL) != 0
    && ((unsigned __int64)a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL
    || *a1 != 421527810 )
  {
    return 4294967294LL;
  }
  _InterlockedExchange(a1, -421527811);
  _InterlockedAnd(a1 + 1, 0xFFFFFFFE);
  _wake_up(a1 + 4, 3, 0, 0);
  if ( _InterlockedExchangeAdd(a1 + 2, 0xFFFFFFFF) != 1 )
    return 0;
  VBoxGuest_RTMemFree((__int64)a1);
  return 0;
}
