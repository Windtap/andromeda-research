__int64 rtR0MpNotificationInit()
{
  int v0; // ebx

  v0 = VBoxGuest_RTSpinlockCreate(&g_hRTMpNotifySpinLock, 2, "RTR0Mp");
  if ( v0 >= 0 )
  {
    v0 = rtR0MpNotificationNativeInit();
    if ( v0 < 0 )
    {
      VBoxGuest_RTSpinlockDestroy(g_hRTMpNotifySpinLock);
      g_hRTMpNotifySpinLock = 0;
    }
  }
  return (unsigned int)v0;
}
