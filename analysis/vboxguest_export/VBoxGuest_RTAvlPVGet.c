unsigned __int64 *__fastcall VBoxGuest_RTAvlPVGet(unsigned __int64 **a1, unsigned __int64 a2)
{
  unsigned __int64 *result; // rax

  result = *a1;
  if ( !*a1 )
    return 0;
  while ( *result != a2 )
  {
    if ( *result <= a2 )
    {
      result = (unsigned __int64 *)result[2];
      if ( !result )
        return 0;
    }
    else
    {
      result = (unsigned __int64 *)result[1];
      if ( !result )
        return result;
    }
  }
  return result;
}
