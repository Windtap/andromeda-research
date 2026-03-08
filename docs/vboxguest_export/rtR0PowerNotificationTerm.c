__int64 rtR0PowerNotificationTerm()
{
  __int64 v0; // r12
  _QWORD *v1; // rbx
  _QWORD *v2; // rbp
  __int64 result; // rax

  v0 = g_hRTPowerNotifySpinLock;
  if ( g_hRTPowerNotifySpinLock )
  {
    VBoxGuest_RTSpinlockAcquire(g_hRTPowerNotifySpinLock);
    _InterlockedExchange64(&g_hRTPowerNotifySpinLock, 0);
    v1 = (_QWORD *)g_pRTPowerCallbackHead;
    g_pRTPowerCallbackHead = 0;
    _InterlockedExchangeAdd(&g_iRTPowerGeneration, 1u);
    VBoxGuest_RTSpinlockRelease(v0);
    if ( v1 )
    {
      while ( 1 )
      {
        v2 = (_QWORD *)*v1;
        v1[1] = 0;
        *v1 = 0;
        VBoxGuest_RTMemFree((__int64)v1);
        if ( !v2 )
          break;
        v1 = v2;
      }
    }
    return VBoxGuest_RTSpinlockDestroy(v0);
  }
  return result;
}
