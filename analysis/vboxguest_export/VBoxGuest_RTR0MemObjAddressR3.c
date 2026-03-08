__int64 __fastcall VBoxGuest_RTR0MemObjAddressR3(__int64 a1)
{
  int v1; // edx
  __int64 result; // rax

  if ( !a1
    || (unsigned __int64)(a1 + 0x200000) <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 0;
  }
  if ( *(_DWORD *)a1 != 425792016 )
    return 0;
  v1 = *(_DWORD *)(a1 + 8);
  if ( (unsigned int)(v1 - 1) > 7 )
    return 0;
  if ( v1 == 8 || v1 == 4 || v1 == 6 )
  {
    if ( *(_QWORD *)(a1 + 48) != -1 )
      return *(_QWORD *)(a1 + 24);
    return 0;
  }
  result = 0;
  if ( v1 == 7 && *(_QWORD *)(a1 + 48) != -1 )
    return *(_QWORD *)(a1 + 24);
  return result;
}
