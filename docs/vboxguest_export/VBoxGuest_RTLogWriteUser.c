__int64 __fastcall VBoxGuest_RTLogWriteUser(unsigned __int8 *a1, unsigned __int64 a2)
{
  __int64 result; // rax

  if ( a2 <= 1 )
    return VBoxGuest_RTLogWriteUser_part_6(a1, a2);
  __outbytestring(0x504u, a1, a2);
  return result;
}
