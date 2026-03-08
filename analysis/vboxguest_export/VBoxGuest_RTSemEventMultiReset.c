__int64 __fastcall VBoxGuest_RTSemEventMultiReset(__int64 a1)
{
  if ( !a1
    || (unsigned __int64)(a1 + 0x200000) <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL
    || *(_DWORD *)a1 != 421527810 )
  {
    return 4294967294LL;
  }
  _InterlockedExchangeAdd((volatile signed __int32 *)(a1 + 8), 1u);
  _InterlockedAnd((volatile signed __int32 *)(a1 + 4), 0xFFFFFFFE);
  if ( _InterlockedExchangeAdd((volatile signed __int32 *)(a1 + 8), 0xFFFFFFFF) == 1 )
    VBoxGuest_RTMemFree(a1);
  return 0;
}
