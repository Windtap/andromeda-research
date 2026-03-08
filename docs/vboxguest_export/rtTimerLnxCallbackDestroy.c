__int64 __fastcall rtTimerLnxCallbackDestroy(__int64 a1, __int64 a2)
{
  unsigned int v2; // r12d
  unsigned int v3; // eax
  __int64 v4; // rdx
  __int64 v6; // rsi

  v2 = *(_DWORD *)(a1 + 24);
  if ( v2 > 1 )
  {
    VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a1 + 8));
    _InterlockedExchange((volatile __int32 *)(a2 + 104), 0);
    v3 = v2 - 1;
    while ( v3 != -1 )
    {
      v4 = v3--;
      if ( *(_DWORD *)(a1 + 112 * v4 + 208) )
        return VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 8));
    }
    VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 8));
  }
  v6 = g_prtR0LnxWorkQueue;
  *(_QWORD *)(a1 + 96) = rtTimerLnxDestroyDeferred;
  *(_QWORD *)(a1 + 72) = 0xFFFFFFFE0LL;
  *(_QWORD *)(a1 + 80) = a1 + 80;
  *(_QWORD *)(a1 + 88) = a1 + 80;
  return queue_work_on(0x2000, v6, a1 + 72);
}
