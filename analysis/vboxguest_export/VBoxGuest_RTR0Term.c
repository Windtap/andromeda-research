__int64 __fastcall VBoxGuest_RTR0Term(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 result; // rax

  result = (unsigned int)_InterlockedDecrement(&g_crtR0Users);
  if ( (_DWORD)result )
  {
    if ( (int)result < 0 )
      return (unsigned int)_InterlockedExchangeAdd(&g_crtR0Users, 1u);
  }
  else
  {
    rtThreadTerm(a1, a2, a3, a4, a5, a6, a7, a8);
    return rtR0TermNative();
  }
  return result;
}
