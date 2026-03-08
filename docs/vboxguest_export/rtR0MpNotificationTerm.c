__int64 rtR0MpNotificationTerm()
{
  __int64 v0; // r12
  _QWORD *v1; // rbx
  _QWORD *v2; // rbp
  __int64 result; // rax

  v0 = g_hRTMpNotifySpinLock;
  if ( g_hRTMpNotifySpinLock )
  {
    rtR0MpNotificationNativeTerm();
    VBoxGuest_RTSpinlockAcquire(v0);
    _InterlockedExchange64(&g_hRTMpNotifySpinLock, 0);
    v1 = (_QWORD *)g_pRTMpCallbackHead;
    g_pRTMpCallbackHead = 0;
    _InterlockedExchangeAdd(&g_iRTMpGeneration, 1u);
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
