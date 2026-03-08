__int64 __fastcall VBoxGuest_RTLogWriteUser_part_6(unsigned __int8 *a1, __int64 a2)
{
  __int64 result; // rax

  if ( a2 )
  {
    result = *a1;
    __outbyte(0x504u, result);
  }
  return result;
}
