__int64 __fastcall rtR0MemObjFallbackAllocLarge(__int64 a1, __int64 a2, __int64 a3)
{
  if ( a2 == a3 )
    return rtR0MemObjNativeAllocPhys(a1, a2, -1, a2);
  else
    return 4294967259LL;
}
