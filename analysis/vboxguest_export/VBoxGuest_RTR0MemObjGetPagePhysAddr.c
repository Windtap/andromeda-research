__int64 __fastcall VBoxGuest_RTR0MemObjGetPagePhysAddr(__int64 a1, unsigned __int64 a2)
{
  int v2; // ecx

  if ( (unsigned __int64)(a1 + 0x200000) <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return -1;
  }
  if ( *(_DWORD *)a1 != 425792016 )
    return -1;
  v2 = *(_DWORD *)(a1 + 8);
  if ( (unsigned int)(v2 - 1) > 7 || *(_QWORD *)(a1 + 16) >> 12 <= a2 )
    return -1;
  if ( v2 == 3 || v2 == 5 )
    return *(_QWORD *)(a1 + 48) + (a2 << 12);
  return rtR0MemObjNativeGetPagePhysAddr();
}
