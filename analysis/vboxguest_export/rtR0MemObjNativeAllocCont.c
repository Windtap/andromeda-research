__int64 __fastcall rtR0MemObjNativeAllocCont(__int64 *a1, unsigned __int64 a2, char a3)
{
  __int64 result; // rax
  __int64 v5; // rcx
  unsigned int v6; // [rsp+14h] [rbp-24h]
  __int64 v7[4]; // [rsp+18h] [rbp-20h] BYREF

  if ( (int)rtR0MemObjLinuxAllocPages(v7, 3, a2, 0x1000u, 4, 1, a3, 0xFFFFFFE6) >= 0
    || (result = rtR0MemObjLinuxAllocPages(v7, 3, a2, 0x1000u, 1, 1, a3, 0xFFFFFFE6), (int)result >= 0) )
  {
    result = rtR0MemObjLinuxVMap(v7[0], a3);
    if ( (int)result < 0 )
    {
      v6 = result;
      rtR0MemObjLinuxFreePages(v7[0]);
      rtR0MemObjDelete(v7[0]);
      return v6;
    }
    else
    {
      v5 = v7[0];
      *(_QWORD *)(v7[0] + 48) = (*(_QWORD *)(v7[0] + 96) + 0x160000000000LL) >> 6 << 12;
      *a1 = v5;
    }
  }
  return result;
}
