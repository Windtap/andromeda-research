__int64 __fastcall VBoxGuest_RTR0MemObjProtect(__int64 a1, unsigned __int64 a2, unsigned __int64 a3, unsigned int a4)
{
  unsigned int v6; // ecx
  unsigned __int64 v7; // rax
  __int64 result; // rax

  if ( (unsigned __int64)(a1 + 0x200000) <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 4294967292LL;
  }
  if ( *(_DWORD *)a1 != 425792016 )
    return 4294967292LL;
  v6 = *(_DWORD *)(a1 + 8) - 1;
  if ( v6 > 7 )
    return 4294967292LL;
  if ( ((1LL << v6) & 0x87) == 0 )
    return 4294967294LL;
  if ( (a2 & 0xFFF) != 0 )
    return 4294967294LL;
  v7 = *(_QWORD *)(a1 + 16);
  if ( a2 >= v7 || (a3 & 0xFFF) != 0 || v7 < a3 || v7 < a2 + a3 || (a4 & 0xFFFFFFF8) != 0 )
    return 4294967294LL;
  result = rtR0MemObjNativeProtect(a1, a2, a3, a4);
  if ( (int)result >= 0 )
    *(_DWORD *)(a1 + 12) |= 1u;
  return result;
}
