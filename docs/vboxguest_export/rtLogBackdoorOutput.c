unsigned __int64 __fastcall rtLogBackdoorOutput(__int64 a1, unsigned __int8 *a2, unsigned __int64 a3)
{
  unsigned __int64 result; // rax

  result = a3;
  if ( a3 <= 1 )
  {
    VBoxGuest_RTLogWriteUser_part_6(a2, a3);
    return a3;
  }
  else
  {
    __outbytestring(0x504u, a2, a3);
  }
  return result;
}
