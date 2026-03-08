__int64 __fastcall rtR0MemObjNativeAllocPhys(
        __int64 *a1,
        unsigned __int64 a2,
        unsigned __int64 a3,
        unsigned __int64 a4)
{
  return rtR0MemObjLinuxAllocPhysSub(a1, 5, a2, a4, a3);
}
