__int64 __fastcall rtTimerLinuxMpEvent(int a1, unsigned int a2, unsigned int *a3)
{
  __int64 result; // rax
  __int64 v4; // rbp
  __int64 v5; // rax
  __int64 v6; // r14
  __int64 v7; // rbx
  signed __int32 v8; // eax
  __int64 v9; // rax
  __int64 v11; // [rsp+8h] [rbp-38h] BYREF
  unsigned __int64 v12; // [rsp+10h] [rbp-30h]

  result = *a3;
  if ( (_DWORD)result == 423037200 )
  {
    v4 = *((_QWORD *)a3 + 1);
    if ( v4 )
    {
      VBoxGuest_RTSpinlockAcquire(v4);
      if ( !*((_BYTE *)a3 + 16) && *a3 == 423037200 )
      {
        v5 = 28LL * a2;
        v6 = (__int64)&a3[v5 + 24];
        v7 = (__int64)&a3[v5 + 26];
        if ( a1 == 1 )
        {
          if ( !_InterlockedCompareExchange((volatile signed __int32 *)&a3[v5 + 52], 2, 0) )
          {
            v11 = 0;
            v12 = 0;
            ktime_get_ts64(&v11);
            v9 = v12 + 1000000000 * v11;
            v12 = 0;
            v11 = v9;
            if ( a2 != (unsigned int)debug_smp_processor_id(&v11) )
            {
              _InterlockedExchange((volatile __int32 *)(v6 + 112), 0);
              VBoxGuest_RTSpinlockRelease(v4);
              return VBoxGuest_RTMpOnSpecific(a2, (__int64)rtTimerLinuxMpStartOnCpu, (__int64)a3, (__int64)&v11);
            }
            rtTimerLnxStartSubTimer(v7, v11, v12, 1, *((_BYTE *)a3 + 19));
          }
        }
        else if ( a1 == 2 )
        {
          while ( 1 )
          {
            v8 = *(_DWORD *)(v7 + 104);
            if ( v8 == 3 )
            {
              if ( _InterlockedCompareExchange((volatile signed __int32 *)(v7 + 104), 9, 3) == 3 )
              {
                VBoxGuest_RTSpinlockRelease(v4);
                return rtTimerLnxStopSubTimer(v7, *((_BYTE *)a3 + 19));
              }
            }
            else if ( (v8 & 0xFFFFFFFD) != 4
                   || v8 == _InterlockedCompareExchange((volatile signed __int32 *)(v7 + 104), 5, v8) )
            {
              return VBoxGuest_RTSpinlockRelease(v4);
            }
            _mm_pause();
          }
        }
      }
      return VBoxGuest_RTSpinlockRelease(v4);
    }
  }
  return result;
}
