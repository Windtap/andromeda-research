__int64 __fastcall rtThreadGet(__int64 a1)
{
  __int64 result; // rax

  if ( !a1
    || (unsigned __int64)(a1 + 0x200000) <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 0;
  }
  result = 0;
  if ( *(_DWORD *)(a1 + 32) == 410256681 )
  {
    if ( *(_DWORD *)(a1 + 36) )
    {
      LOBYTE(result) = 1;
      _InterlockedExchangeAdd((volatile signed __int32 *)(a1 + 36), result);
      return a1;
    }
  }
  return result;
}
