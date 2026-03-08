__int64 __fastcall VBoxGuest_RTTimeConvertToZulu(__int64 a1)
{
  __int64 v1; // rax

  if ( (unsigned __int64)(a1 + 0x200000) <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL
    || (*(_DWORD *)(a1 + 16) & 0xFFFFFF00) != 0 )
  {
    return 0;
  }
  v1 = rtTimeNormalizeInternal(a1);
  return rtTimeConvertToZulu(v1);
}
