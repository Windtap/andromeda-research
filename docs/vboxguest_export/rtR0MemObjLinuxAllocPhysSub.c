__int64 __fastcall rtR0MemObjLinuxAllocPhysSub(
        __int64 *a1,
        int a2,
        unsigned __int64 a3,
        unsigned __int64 a4,
        unsigned __int64 a5)
{
  int v6; // r9d
  __int64 result; // rax

  v6 = 37880002;
  if ( a5 == -1 )
    return rtR0MemObjLinuxAllocPhysSub2(a1, a2, a3, a4, a5, v6);
  if ( a5 <= 0x1000000
    || (result = rtR0MemObjLinuxAllocPhysSub2(a1, a2, a3, a4, a5, 37880002), (int)result < 0)
    && (result = rtR0MemObjLinuxAllocPhysSub2(a1, a2, a3, a4, a5, 37880000), (int)result < 0)
    && (result = rtR0MemObjLinuxAllocPhysSub2(a1, a2, a3, a4, a5, 4), (int)result < 0) )
  {
    v6 = 1;
    return rtR0MemObjLinuxAllocPhysSub2(a1, a2, a3, a4, a5, v6);
  }
  return result;
}
