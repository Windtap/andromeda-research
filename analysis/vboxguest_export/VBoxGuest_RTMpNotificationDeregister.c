__int64 __fastcall VBoxGuest_RTMpNotificationDeregister(__int64 a1, __int64 a2)
{
  _QWORD *v2; // rbx
  _QWORD *v3; // rdx

  if ( (unsigned __int64)(a1 + 0x200000) <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 4294967290LL;
  }
  if ( !g_hRTMpNotifySpinLock )
    return 4294967274LL;
  VBoxGuest_RTSpinlockAcquire(g_hRTMpNotifySpinLock);
  v2 = (_QWORD *)g_pRTMpCallbackHead;
  if ( g_pRTMpCallbackHead )
  {
    v3 = 0;
    while ( v2[2] != a2 || v2[1] != a1 )
    {
      if ( !*v2 )
        goto LABEL_13;
      v3 = v2;
      v2 = (_QWORD *)*v2;
    }
    if ( v3 )
      *v3 = *v2;
    else
      g_pRTMpCallbackHead = *v2;
    _InterlockedExchangeAdd(&g_iRTMpGeneration, 1u);
    VBoxGuest_RTSpinlockRelease(g_hRTMpNotifySpinLock);
    *v2 = 0;
    v2[1] = 0;
    VBoxGuest_RTMemFree((__int64)v2);
    return 0;
  }
  else
  {
LABEL_13:
    VBoxGuest_RTSpinlockRelease(g_hRTMpNotifySpinLock);
    return 4294967218LL;
  }
}
