__int64 __fastcall VBoxGuest_RTSemFastMutexDestroy(__int64 a1)
{
  if ( !a1 )
    return 0;
  if ( (unsigned __int64)(a1 + 0x200000) <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL
    || *(_DWORD *)a1 != 412221699 )
  {
    return 4294967292LL;
  }
  _InterlockedExchange((volatile __int32 *)a1, 426969346);
  VBoxGuest_RTMemFree(a1);
  return 0;
}
