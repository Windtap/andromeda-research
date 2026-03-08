__int64 __fastcall VBoxGuest_RTThreadSetType(__int64 a1, unsigned __int32 a2)
{
  int v2; // ebp
  __int64 v3; // rax
  __int64 v4; // rbx

  v2 = -2;
  if ( a2 - 1 <= 0xA )
  {
    v3 = rtThreadGet(a1);
    v4 = v3;
    if ( v3 )
    {
      LOBYTE(v2) = -29;
      if ( (*(_BYTE *)(v3 + 72) & 2) == 0 )
      {
        VBoxGuest_RTSpinlockAcquire(g_ThreadSpinlock);
        v2 = rtThreadNativeSetPriority(v4, a2);
        if ( v2 >= 0 )
          _InterlockedExchange((volatile __int32 *)(v4 + 64), a2);
        VBoxGuest_RTSpinlockRelease(g_ThreadSpinlock);
      }
      if ( *(_DWORD *)(v4 + 36) )
        rtThreadRelease_part_26(v4);
    }
    else
    {
      return (unsigned int)-4;
    }
  }
  return (unsigned int)v2;
}
