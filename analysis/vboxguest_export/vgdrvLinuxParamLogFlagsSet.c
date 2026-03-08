__int64 __fastcall vgdrvLinuxParamLogFlagsSet(__int64 a1, _BYTE **a2)
{
  _BYTE *v2; // rax
  __int64 DefaultInstance; // rax

  v2 = *a2;
  if ( g_fLoggerCreated )
  {
    if ( *v2 == 100 )
      DefaultInstance = VBoxGuest_RTLogDefaultInstance();
    else
      DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstance();
    if ( DefaultInstance )
      VBoxGuest_RTLogFlags(DefaultInstance, a1);
    return 0;
  }
  if ( *v2 == 100 )
    return 0;
  strlcpy(&g_szLogFlags, a1, 128);
  return 0;
}
