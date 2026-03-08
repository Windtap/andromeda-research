__int64 __fastcall rtTimerLinuxMpStartOnCpu(unsigned int a1, unsigned int *a2, __int64 a3)
{
  __int64 v3; // rbx
  __int64 result; // rax
  __int64 v6; // rbp

  v3 = *((_QWORD *)a2 + 1);
  if ( v3 )
  {
    result = *a2;
    if ( (_DWORD)result == 423037200 )
    {
      VBoxGuest_RTSpinlockAcquire(*((_QWORD *)a2 + 1));
      if ( !*((_BYTE *)a2 + 16) && *a2 == 423037200 )
      {
        v6 = 28LL * a1;
        if ( !_InterlockedCompareExchange((volatile signed __int32 *)&a2[v6 + 52], 2, 0) )
          rtTimerLnxStartSubTimer((__int64)&a2[v6 + 26], *(_QWORD *)a3, *(_QWORD *)(a3 + 8), 1, *((_BYTE *)a2 + 19));
      }
      return VBoxGuest_RTSpinlockRelease(v3);
    }
  }
  return result;
}
