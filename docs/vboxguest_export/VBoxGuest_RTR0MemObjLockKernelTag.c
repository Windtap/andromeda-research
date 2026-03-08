__int64 __fastcall VBoxGuest_RTR0MemObjLockKernelTag(unsigned __int64 a1, __int64 a2, unsigned __int64 a3, int a4)
{
  unsigned __int64 v5; // r8
  unsigned __int64 v6; // rsi
  unsigned __int64 v7; // rax

  v5 = (a3 + (a2 & 0xFFF) + 4095) & 0xFFFFFFFFFFFFF000LL;
  v6 = a2 & 0xFFFFFFFFFFFFF000LL;
  if ( a1 + 0x200000 <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 4294967290LL;
  }
  *(_QWORD *)a1 = 0;
  if ( a3 && a3 <= v5 )
  {
    if ( v6 + 0x200000 <= 0x200FFF )
      return 4294967290LL;
    v7 = a2 & 0xFF00000000000000LL;
    if ( v7 )
    {
      if ( v7 != 0xFF00000000000000LL )
        return 4294967290LL;
    }
    if ( (a4 & 0xFFFFFFFC) == 0 && a4 )
      return rtR0MemObjNativeLockKernel(a1, v6, v5);
  }
  return 4294967294LL;
}
