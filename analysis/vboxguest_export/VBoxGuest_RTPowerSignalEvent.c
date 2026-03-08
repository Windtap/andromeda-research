__int64 __fastcall VBoxGuest_RTPowerSignalEvent(unsigned int a1)
{
  __int64 v1; // r12
  unsigned int v2; // ebp
  __int64 i; // rax
  int v4; // r13d
  __int64 v5; // rbx
  __int64 v7; // r12
  void (__fastcall *v8)(_QWORD, __int64); // r15

  v1 = g_hRTPowerNotifySpinLock;
  v2 = ((unsigned __int8)_InterlockedExchangeAdd(&g_iRTPowerDoneBit, 1u) + 1) & 0x3F;
  if ( !g_hRTPowerNotifySpinLock )
    return 4294967258LL;
  VBoxGuest_RTSpinlockAcquire(g_hRTPowerNotifySpinLock);
  for ( i = g_pRTPowerCallbackHead; i; i = *(_QWORD *)i )
    _interlockedbittestandreset((volatile signed __int32 *)(i + 24), v2);
LABEL_4:
  v4 = g_iRTPowerGeneration;
  v5 = g_pRTPowerCallbackHead;
  while ( v5 )
  {
    while ( _interlockedbittestandset((volatile signed __int32 *)(v5 + 24), v2) )
    {
      v5 = *(_QWORD *)v5;
      if ( !v5 )
        goto LABEL_8;
    }
    v7 = *(_QWORD *)(v5 + 16);
    v8 = *(void (__fastcall **)(_QWORD, __int64))(v5 + 8);
    v5 = *(_QWORD *)v5;
    VBoxGuest_RTSpinlockRelease(g_hRTPowerNotifySpinLock);
    v8(a1, v7);
    v1 = g_hRTPowerNotifySpinLock;
    if ( !g_hRTPowerNotifySpinLock )
      return 4294967258LL;
    VBoxGuest_RTSpinlockAcquire(g_hRTPowerNotifySpinLock);
    if ( v4 != g_iRTPowerGeneration )
    {
      if ( v5 )
        goto LABEL_4;
      break;
    }
  }
LABEL_8:
  VBoxGuest_RTSpinlockRelease(v1);
  return 0;
}
