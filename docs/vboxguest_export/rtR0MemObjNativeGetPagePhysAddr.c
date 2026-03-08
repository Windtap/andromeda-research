__int64 __fastcall rtR0MemObjNativeGetPagePhysAddr(__int64 a1, __int64 a2)
{
  int v2; // eax

  if ( *(_QWORD *)(a1 + 88) )
    return (*(_QWORD *)(a1 + 8 * a2 + 96) + 0x160000000000LL) >> 6 << 12;
  while ( 1 )
  {
    v2 = *(_DWORD *)(a1 + 8);
    if ( v2 == 5 )
      break;
    if ( v2 != 8 )
    {
      if ( v2 != 3 )
        return -1;
      return *(_QWORD *)(a1 + 48) + (a2 << 12);
    }
    a1 = *(_QWORD *)(a1 + 32);
    if ( *(_QWORD *)(a1 + 88) )
      return (*(_QWORD *)(a1 + 8 * a2 + 96) + 0x160000000000LL) >> 6 << 12;
  }
  return *(_QWORD *)(a1 + 48) + (a2 << 12);
}
