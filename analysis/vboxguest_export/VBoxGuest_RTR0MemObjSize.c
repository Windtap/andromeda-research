__int64 __fastcall VBoxGuest_RTR0MemObjSize(__int64 a1)
{
  if ( a1
    && (unsigned __int64)(a1 + 0x200000) > 0x200FFF
    && ((a1 & 0xFF00000000000000LL) == 0 || (a1 & 0xFF00000000000000LL) == 0xFF00000000000000LL)
    && *(_DWORD *)a1 == 425792016
    && (unsigned int)(*(_DWORD *)(a1 + 8) - 1) <= 7 )
  {
    return *(_QWORD *)(a1 + 16);
  }
  else
  {
    return 0;
  }
}
