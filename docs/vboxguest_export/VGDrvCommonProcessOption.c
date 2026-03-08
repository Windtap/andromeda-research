char __fastcall VGDrvCommonProcessOption(__int64 a1, _BYTE *a2, char *a3)
{
  __int64 DefaultInstance; // rax
  bool v5; // r14
  unsigned __int64 v6; // rax
  _BYTE *v7; // r13
  __int64 v8; // rbx

  if ( (unsigned int)VBoxGuest_RTStrICmpAscii(a2, "r3_log_to_host")
    && (unsigned int)VBoxGuest_RTStrICmpAscii(a2, "LoggingEnabled") )
  {
    if ( (unsigned int)VBoxGuest_RTStrNICmpAscii(a2, "log", 3)
      && (unsigned int)VBoxGuest_RTStrNICmpAscii(a2, "dbg_log", 7)
      || (v5 = (*a2 & 0xDF) == 68, v6 = -(__int64)((*a2 & 0xDF) != 68) & 0xFFFFFFFFFFFFFFFCLL, v7 = &a2[v6 + 7], *v7)
      && (unsigned int)VBoxGuest_RTStrICmpAscii(&a2[v6 + 7], "_flags")
      && (unsigned int)VBoxGuest_RTStrICmpAscii(v7, "_dest") )
    {
      LOBYTE(DefaultInstance) = VGDrvNativeProcessOption(a1, a2, a3);
      if ( !(_BYTE)DefaultInstance )
      {
        DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
        if ( DefaultInstance )
          LOBYTE(DefaultInstance) = VBoxGuest_RTLogLoggerEx(
                                      DefaultInstance,
                                      16,
                                      32,
                                      (unsigned int)"VBoxGuest: Ignoring unknown option '%s' (value '%s')\n",
                                      (_DWORD)a2,
                                      (_DWORD)a3);
      }
    }
    else
    {
      if ( v5 )
        DefaultInstance = VBoxGuest_RTLogDefaultInstance();
      else
        DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstance();
      v8 = DefaultInstance;
      if ( DefaultInstance )
      {
        if ( *v7 )
        {
          if ( (unsigned int)VBoxGuest_RTStrICmpAscii(v7, "_flags") )
            LOBYTE(DefaultInstance) = VBoxGuest_RTLogFlags(v8, a3);
          else
            LOBYTE(DefaultInstance) = VBoxGuest_RTLogDestinations(v8, a3);
        }
        else
        {
          LOBYTE(DefaultInstance) = VBoxGuest_RTLogGroupSettings(DefaultInstance, a3);
        }
      }
    }
  }
  else
  {
    LOBYTE(DefaultInstance) = VBDrvCommonIsOptionValueTrue(a3);
    *(_BYTE *)(a1 + 156) = DefaultInstance;
  }
  return DefaultInstance;
}
