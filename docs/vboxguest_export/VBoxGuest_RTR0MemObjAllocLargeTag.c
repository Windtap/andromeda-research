__int64 __fastcall VBoxGuest_RTR0MemObjAllocLargeTag(unsigned __int64 a1, unsigned __int64 a2, __int64 a3, int a4)
{
  if ( a1 + 0x200000 <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 4294967290LL;
  }
  *(_QWORD *)a1 = 0;
  if ( a3 != 0x40000000 && a3 != 0x200000 )
    return 4294967242LL;
  if ( !a2 || a2 > ((a2 + a3 - 1) & -a3) || (a4 & 0xFFFFFFFE) != 0 )
    return 4294967294LL;
  return rtR0MemObjNativeAllocLarge(a1, (a2 + a3 - 1) & -a3);
}
