__int64 VbglR0HGCMInit()
{
  if ( g_hMtxHGCMHandleData )
    return 28;
  else
    return VBoxGuest_RTSemFastMutexCreate(&g_hMtxHGCMHandleData);
}
