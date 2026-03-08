__int64 __fastcall VBoxGuest_RTR0MemObjAllocPhysTag(unsigned __int64 a1, unsigned __int64 a2, unsigned __int64 a3)
{
  if ( a1 + 0x200000 <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 4294967290LL;
  }
  *(_QWORD *)a1 = 0;
  if ( a2 && a2 <= ((a2 + 4095) & 0xFFFFFFFFFFFFF000LL) && a2 <= a3 )
    return rtR0MemObjNativeAllocPhys(a1, (a2 + 4095) & 0xFFFFFFFFFFFFF000LL, a3, 4096);
  else
    return 4294967294LL;
}
