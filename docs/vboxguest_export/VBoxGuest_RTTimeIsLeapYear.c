bool __fastcall VBoxGuest_RTTimeIsLeapYear(int a1)
{
  bool result; // al

  result = 0;
  if ( (a1 & 3) == 0 )
  {
    result = 1;
    if ( a1 == 100 * (a1 / 100) )
      return a1 == 400 * (a1 / 400);
  }
  return result;
}
