__int64 rtR0PowerNotificationInit()
{
  return VBoxGuest_RTSpinlockCreate(&g_hRTPowerNotifySpinLock, 2, "RTR0Power");
}
