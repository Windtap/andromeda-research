bool __fastcall VBoxGuest_RTR0MemObjIsMapping(unsigned __int64 a1)
{
  int v1; // eax
  bool result; // al

  result = a1 + 0x200000 > 0x200FFF
        && ((a1 & 0xFF00000000000000LL) == 0 || (a1 & 0xFF00000000000000LL) == 0xFF00000000000000LL)
        && *(_DWORD *)a1 == 425792016
        && (v1 = *(_DWORD *)(a1 + 8), (unsigned int)(v1 - 1) <= 7)
        && v1 == 8;
  return result;
}
