__int64 __fastcall rtThreadRemove(__int64 a1)
{
  VBoxGuest_RTSpinlockAcquire(g_ThreadSpinlock);
  if ( _interlockedbittestandreset((volatile signed __int32 *)(a1 + 72), 2u) )
    rtThreadRemoveLocked(a1);
  return VBoxGuest_RTSpinlockRelease(g_ThreadSpinlock);
}
