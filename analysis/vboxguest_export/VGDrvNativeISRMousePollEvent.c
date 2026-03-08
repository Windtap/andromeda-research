__int64 VGDrvNativeISRMousePollEvent()
{
  _wake_up(&g_PollEventQueue, 3, 0, 0);
  return kill_fasync(&g_pFAsyncQueue, 29, (char *)&_ksymtab_VBoxGuest_RTR0MemObjAllocContTag + 1);
}
