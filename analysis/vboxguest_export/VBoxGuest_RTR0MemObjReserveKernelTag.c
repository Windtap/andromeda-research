__int64 __fastcall VBoxGuest_RTR0MemObjReserveKernelTag(
        unsigned __int64 a1,
        __int64 a2,
        unsigned __int64 a3,
        __int64 a4)
{
  unsigned __int64 v4; // rax

  v4 = (a3 + 4095) & 0xFFFFFFFFFFFFF000LL;
  if ( a1 + 0x200000 > 0x200FFF
    && ((a1 & 0xFF00000000000000LL) == 0 || (a1 & 0xFF00000000000000LL) == 0xFF00000000000000LL) )
  {
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
    if ( a3 && a3 <= v4 && (a2 == -1 || ((a4 - 1) & a2) == 0) )
      return rtR0MemObjNativeReserveKernel(a1, a2, v4);
    return 4294967294LL;
  }
  return 4294967290LL;
}
