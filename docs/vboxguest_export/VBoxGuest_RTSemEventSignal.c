__int64 __fastcall VBoxGuest_RTSemEventSignal(__int64 a1)
{
  if ( (unsigned __int64)(a1 + 0x200000) <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL
    || *(_DWORD *)a1 != 425726224 )
  {
    return 4294967292LL;
  }
  _InterlockedExchangeAdd((volatile signed __int32 *)(a1 + 8), 1u);
  _InterlockedExchange((volatile __int32 *)(a1 + 4), 1);
  _wake_up(a1 + 16, 3, 1, 0);
  if ( _InterlockedExchangeAdd((volatile signed __int32 *)(a1 + 8), 0xFFFFFFFF) == 1 )
    VBoxGuest_RTMemFree(a1);
  return 0;
}
