__int64 __fastcall rtTimerLnxDestroyIt(__int64 a1)
{
  volatile signed __int32 *v2; // r12
  unsigned int i; // ebx
  __int64 v4; // rdi
  __int64 result; // rax

  v2 = *(volatile signed __int32 **)(a1 + 8);
  if ( *(_DWORD *)(a1 + 24) > 1u && v2 )
    VBoxGuest_RTMpNotificationDeregister((__int64)rtTimerLinuxMpEvent, a1);
  _InterlockedExchange((volatile __int32 *)a1, -423037201);
  for ( i = *(_DWORD *)(a1 + 24) - 1; i != -1; --i )
  {
    v4 = a1 + 112LL * i + 104;
    if ( *(_BYTE *)(a1 + 19) )
      hrtimer_cancel(v4);
    else
      del_timer_sync(v4);
  }
  result = VBoxGuest_RTMemFreeEx(a1);
  if ( v2 )
    return VBoxGuest_RTSpinlockDestroy(v2);
  return result;
}
