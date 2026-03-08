__int64 __fastcall rtR0MemObjNativeAllocPage(_QWORD *a1, unsigned __int64 a2, char a3)
{
  __int64 result; // rax
  unsigned int v5; // [rsp+14h] [rbp-1Ch]
  __int64 v6[3]; // [rsp+18h] [rbp-18h] BYREF

  result = rtR0MemObjLinuxAllocPages(v6, 1, a2, 0x1000u, 37880002, 0, a3, 0xFFFFFFF8);
  if ( (int)result >= 0 )
  {
    result = rtR0MemObjLinuxVMap(v6[0], a3);
    if ( (int)result < 0 )
    {
      v5 = result;
      rtR0MemObjLinuxFreePages(v6[0]);
      rtR0MemObjDelete(v6[0]);
      return v5;
    }
    else
    {
      *a1 = v6[0];
    }
  }
  return result;
}
