__int64 VBoxGuest_RTLogDefaultInit()
{
  __int64 v1; // rdx
  __int64 v2; // [rsp+10h] [rbp-8h] BYREF

  if ( g_pLogger || _InterlockedCompareExchange(&fInitializing_30240, 1, 0) )
    return g_pLogger;
  if ( (int)VBoxGuest_RTLogCreate(
              (unsigned int)&v2,
              0,
              0,
              (unsigned int)"VBOX_LOG",
              374,
              (unsigned int)g_apszGroups,
              0x40000000,
              (__int64)"VBox-ring0.log",
              v2) < 0 )
    v1 = 0;
  else
    v1 = v2;
  g_pLogger = v1;
  return v1;
}
