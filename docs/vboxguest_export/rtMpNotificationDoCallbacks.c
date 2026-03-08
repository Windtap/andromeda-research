void __fastcall rtMpNotificationDoCallbacks(unsigned int a1, unsigned int a2)
{
  __int64 v2; // r15
  unsigned int v3; // ebp
  __int64 i; // rax
  int v5; // r12d
  __int64 v6; // rbx
  __int64 v7; // r15
  void (__fastcall *v8)(_QWORD, _QWORD, __int64); // r13

  v2 = g_hRTMpNotifySpinLock;
  v3 = ((unsigned __int8)_InterlockedExchangeAdd(&g_iRTMpDoneBit, 1u) + 1) & 0x3F;
  if ( g_hRTMpNotifySpinLock )
  {
    VBoxGuest_RTSpinlockAcquire(g_hRTMpNotifySpinLock);
    for ( i = g_pRTMpCallbackHead; i; i = *(_QWORD *)i )
      _interlockedbittestandreset((volatile signed __int32 *)(i + 24), v3);
LABEL_4:
    v5 = g_iRTMpGeneration;
    v6 = g_pRTMpCallbackHead;
    while ( v6 )
    {
      while ( _interlockedbittestandset((volatile signed __int32 *)(v6 + 24), v3) )
      {
        v6 = *(_QWORD *)v6;
        if ( !v6 )
          goto LABEL_8;
      }
      v7 = *(_QWORD *)(v6 + 16);
      v8 = *(void (__fastcall **)(_QWORD, _QWORD, __int64))(v6 + 8);
      v6 = *(_QWORD *)v6;
      VBoxGuest_RTSpinlockRelease(g_hRTMpNotifySpinLock);
      v8(a1, a2, v7);
      v2 = g_hRTMpNotifySpinLock;
      if ( !g_hRTMpNotifySpinLock )
        return;
      VBoxGuest_RTSpinlockAcquire(g_hRTMpNotifySpinLock);
      if ( v5 != g_iRTMpGeneration )
      {
        if ( v6 )
          goto LABEL_4;
        break;
      }
    }
LABEL_8:
    VBoxGuest_RTSpinlockRelease(v2);
  }
}
