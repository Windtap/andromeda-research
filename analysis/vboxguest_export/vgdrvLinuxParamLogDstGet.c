size_t __fastcall vgdrvLinuxParamLogDstGet(char *s, _BYTE **a2)
{
  __int64 DefaultInstance; // rax

  if ( **a2 == 100 )
    DefaultInstance = VBoxGuest_RTLogDefaultInstance();
  else
    DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstance();
  *s = 0;
  if ( DefaultInstance )
    VBoxGuest_RTLogGetDestinations(DefaultInstance, s, 4096);
  return strlen(s);
}
