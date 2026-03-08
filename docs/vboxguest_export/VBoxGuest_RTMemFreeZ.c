__int64 __fastcall VBoxGuest_RTMemFreeZ(unsigned int *a1)
{
  __int64 result; // rax

  if ( a1 )
  {
    if ( *(a1 - 4) == 403243289 )
    {
      memset(a1, 0, *(a1 - 1));
      return rtR0MemFree(a1 - 4);
    }
  }
  return result;
}
