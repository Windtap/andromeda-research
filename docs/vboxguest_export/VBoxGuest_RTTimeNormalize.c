__int64 __fastcall VBoxGuest_RTTimeNormalize(__int64 a1)
{
  __int64 result; // rax

  if ( (unsigned __int64)(a1 + 0x200000) <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 0;
  }
  if ( (*(_DWORD *)(a1 + 16) & 0xFFFFFF00) != 0 )
    return 0;
  if ( (*(_DWORD *)(a1 + 16) & 3) == 3 )
    return 0;
  if ( *(_DWORD *)(a1 + 20) )
    return 0;
  result = rtTimeNormalizeInternal(a1);
  if ( !result )
    return 0;
  *(_DWORD *)(result + 16) |= 2u;
  return result;
}
