__int64 __fastcall VBoxGuest_RTR0MemObjReserveUserTag(
        unsigned __int64 a1,
        __int64 a2,
        unsigned __int64 a3,
        __int64 a4,
        __int64 a5)
{
  unsigned __int64 v5; // rbx
  __int64 v7; // rax
  __int64 v8; // [rsp+10h] [rbp-10h]

  v5 = (a3 + 4095) & 0xFFFFFFFFFFFFF000LL;
  if ( a1 + 0x200000 <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 4294967290LL;
  }
  *(_QWORD *)a1 = 0;
  if ( a4 )
  {
    if ( a4 != 4096 && a4 != 0x200000 && a4 != 0x400000 )
      return 4294967294LL;
  }
  else
  {
    a4 = 4096;
  }
  if ( !a3 || a3 > v5 || a2 != -1 && (a2 & (a4 - 1)) != 0 )
    return 4294967294LL;
  if ( a5 != -1 )
    return rtR0MemObjNativeReserveUser(a1, a2, (a3 + 4095) & 0xFFFFFFFFFFFFF000LL, a4, a5);
  v8 = a4;
  v7 = VBoxGuest_RTR0ProcHandleSelf();
  return rtR0MemObjNativeReserveUser(a1, a2, v5, v8, v7);
}
