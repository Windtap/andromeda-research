__int64 __fastcall VBoxGuest_RTTimerStop(__int64 a1)
{
  __int64 result; // rax

  if ( (unsigned __int64)(a1 + 0x200000) <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL
    || *(_DWORD *)a1 != 423037200 )
  {
    return 4294967292LL;
  }
  result = 4294967227LL;
  if ( !*(_BYTE *)(a1 + 16) )
  {
    rtTimerLnxStop(a1, 0);
    return 0;
  }
  return result;
}
