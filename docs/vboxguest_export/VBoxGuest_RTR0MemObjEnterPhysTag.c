__int64 __fastcall VBoxGuest_RTR0MemObjEnterPhysTag(
        unsigned __int64 a1,
        __int64 a2,
        unsigned __int64 a3,
        unsigned int a4)
{
  __int64 v5; // rax
  unsigned __int64 v6; // rsi
  unsigned __int64 v7; // rax

  v5 = a2 & 0xFFF;
  v6 = a2 & 0xFFFFFFFFFFFFF000LL;
  v7 = (a3 + v5 + 4095) & 0xFFFFFFFFFFFFF000LL;
  if ( a1 + 0x200000 <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 4294967290LL;
  }
  *(_QWORD *)a1 = 0;
  if ( !a3 || a3 > v7 || a2 == -1 || a4 > 1 )
    return 4294967294LL;
  else
    return rtR0MemObjNativeEnterPhys(a1, v6, v7);
}
