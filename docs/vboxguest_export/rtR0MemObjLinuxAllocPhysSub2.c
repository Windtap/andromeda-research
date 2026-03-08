__int64 __fastcall rtR0MemObjLinuxAllocPhysSub2(
        __int64 *a1,
        int a2,
        unsigned __int64 a3,
        unsigned __int64 a4,
        unsigned __int64 a5,
        int a6)
{
  bool v7; // r12
  __int64 result; // rax
  __int64 v9; // rsi
  __int64 v10; // rcx
  __int64 v11; // rdx
  __int64 v12[4]; // [rsp+10h] [rbp-20h] BYREF

  v7 = a2 == 5;
  result = rtR0MemObjLinuxAllocPages(v12, a2, a3, a4, a6, a2 == 5, 0, 0xFFFFFFB7);
  if ( (int)result >= 0 )
  {
    v9 = v12[0];
    if ( a5 == -1 )
    {
LABEL_7:
      if ( v7 )
      {
        *(_BYTE *)(v9 + 56) = 1;
        *(_QWORD *)(v9 + 48) = (*(_QWORD *)(v9 + 96) + 0x160000000000LL) >> 6 << 12;
      }
      *a1 = v9;
    }
    else
    {
      v10 = *(_QWORD *)(v12[0] + 88) - 1LL;
      do
      {
        if ( v10 == -1 )
        {
          v9 = v12[0];
          goto LABEL_7;
        }
        v11 = *(_QWORD *)(v12[0] + 8 * v10-- + 96) + 0x160000000000LL;
      }
      while ( a5 >= v11 >> 6 << 12 );
      rtR0MemObjLinuxFreePages(v12[0]);
      rtR0MemObjDelete(v12[0]);
      return 4294967288LL;
    }
  }
  return result;
}
