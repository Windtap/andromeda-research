__int64 __fastcall VBoxGuest_RTPowerNotificationRegister(__int64 a1, __int64 a2)
{
  _QWORD *v3; // rax
  __int64 result; // rax
  _QWORD *v5; // rax
  __int64 v6; // r13
  __int64 v7; // rdi
  __int64 *i; // rbx

  if ( (unsigned __int64)(a1 + 0x200000) <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 4294967290LL;
  }
  if ( !g_hRTPowerNotifySpinLock )
    return 4294967274LL;
  VBoxGuest_RTSpinlockAcquire(g_hRTPowerNotifySpinLock);
  v3 = (_QWORD *)g_pRTPowerCallbackHead;
  if ( g_pRTPowerCallbackHead )
  {
    while ( v3[2] != a2 || v3[1] != a1 )
    {
      v3 = (_QWORD *)*v3;
      if ( !v3 )
        goto LABEL_10;
    }
    VBoxGuest_RTSpinlockRelease(g_hRTPowerNotifySpinLock);
    return 4294967191LL;
  }
  else
  {
LABEL_10:
    VBoxGuest_RTSpinlockRelease(g_hRTPowerNotifySpinLock);
    v5 = (_QWORD *)VBoxGuest_RTMemAllocTag(32);
    v6 = (__int64)v5;
    if ( v5 )
    {
      *v5 = 0;
      v7 = g_hRTPowerNotifySpinLock;
      v5[1] = a1;
      v5[2] = a2;
      v5[3] = -1;
      VBoxGuest_RTSpinlockAcquire(v7);
      i = (__int64 *)g_pRTPowerCallbackHead;
      if ( g_pRTPowerCallbackHead )
      {
        for ( i = (__int64 *)g_pRTPowerCallbackHead; i[2] != a2 || i[1] != a1; i = (__int64 *)*i )
        {
          if ( !*i )
          {
            *i = v6;
            i = 0;
            break;
          }
        }
      }
      else
      {
        g_pRTPowerCallbackHead = v6;
      }
      _InterlockedExchangeAdd(&g_iRTPowerGeneration, 1u);
      VBoxGuest_RTSpinlockRelease(g_hRTPowerNotifySpinLock);
      result = 0;
      if ( i )
      {
        VBoxGuest_RTMemFree((__int64)i);
        return 4294967191LL;
      }
    }
    else
    {
      return 4294967288LL;
    }
  }
  return result;
}
