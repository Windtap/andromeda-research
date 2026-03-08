__int64 __fastcall VBoxGuest_RTSemFastMutexRelease(unsigned __int64 a1)
{
  if ( a1 + 0x200000 <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL
    || *(_DWORD *)a1 != 412221699 )
  {
    return 4294967292LL;
  }
  up(a1 + 8);
  return 0;
}
