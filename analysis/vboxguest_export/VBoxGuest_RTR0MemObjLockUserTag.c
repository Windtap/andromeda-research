__int64 __fastcall VBoxGuest_RTR0MemObjLockUserTag(
        unsigned __int64 a1,
        __int64 a2,
        unsigned __int64 a3,
        int a4,
        __int64 a5)
{
  __int16 v5; // ax
  unsigned __int64 v6; // rsi
  unsigned __int64 v7; // rbx
  int v9; // [rsp+14h] [rbp-Ch]

  v5 = a2;
  v6 = a2 & 0xFFFFFFFFFFFFF000LL;
  v7 = (a3 + (v5 & 0xFFF) + 4095) & 0xFFFFFFFFFFFFF000LL;
  if ( a1 + 0x200000 <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 4294967290LL;
  }
  *(_QWORD *)a1 = 0;
  if ( !a3 || a3 > v7 )
    return 4294967294LL;
  if ( a5 == -1 )
  {
    v9 = a4;
    VBoxGuest_RTR0ProcHandleSelf();
    a4 = v9;
  }
  if ( (a4 & 0xFFFFFFFC) == 0 && a4 )
    return rtR0MemObjNativeLockUser(a1, v6, v7);
  else
    return 4294967294LL;
}
