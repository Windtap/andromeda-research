__int64 VbglR0HGCMTerminate()
{
  VBoxGuest_RTSemFastMutexDestroy(g_hMtxHGCMHandleData);
  g_hMtxHGCMHandleData = 0;
  return 0;
}
