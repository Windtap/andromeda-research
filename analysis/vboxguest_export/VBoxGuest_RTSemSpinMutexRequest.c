__int64 __fastcall VBoxGuest_RTSemSpinMutexRequest(__int64 a1)
{
  __int64 v1; // rax
  __int64 result; // rax
  signed __int64 v3; // rbp
  volatile signed __int64 *v4; // rbx
  char v5; // r14
  char v6; // r15
  unsigned __int64 v7; // [rsp+0h] [rbp-48h] BYREF
  __int64 v8; // [rsp+8h] [rbp-40h] BYREF
  __int64 v9; // [rsp+10h] [rbp-38h]

  v1 = VBoxGuest_RTThreadNativeSelf();
  if ( *(_DWORD *)a1 != 409403913 )
  {
    result = 4294967292LL;
    if ( *(_DWORD *)a1 != 420876809 )
      return result;
    return 4294966933LL;
  }
  v3 = v1;
  result = rtSemSpinMutexEnter((__int64)&v7, a1);
  if ( (int)result >= 0 )
  {
    _InterlockedExchangeAdd((volatile signed __int32 *)(a1 + 16), 1u);
    v4 = (volatile signed __int64 *)(a1 + 8);
    if ( _InterlockedCompareExchange64((volatile signed __int64 *)(a1 + 8), v3, -1) == -1 )
      goto LABEL_22;
    if ( v3 == *(_QWORD *)(a1 + 8) )
    {
      if ( BYTE1(v9) )
        __writeeflags(v7);
      VBoxGuest_RTThreadPreemptRestore(&v8);
      return 4294966932LL;
    }
    else
    {
      if ( (_DWORD)result != 367 )
      {
        if ( (_BYTE)v9 )
        {
          if ( _InterlockedCompareExchange64((volatile signed __int64 *)(a1 + 8), v3, -1) != -1 )
          {
            _mm_pause();
            if ( *(_DWORD *)a1 == 409403913 )
            {
              v5 = 0;
              while ( 1 )
              {
                ++v5;
                if ( _InterlockedCompareExchange64(v4, v3, -1) == -1 )
                  goto LABEL_22;
                _mm_pause();
                if ( *(_DWORD *)a1 != 409403913 )
                  break;
                if ( (v5 & 0x7F) == 0x1F )
                {
                  if ( BYTE1(v9) )
                    __writeeflags(v7);
                  VBoxGuest_RTThreadPreemptRestore(&v8);
                  rtSemSpinMutexEnter((__int64)&v7, a1);
                }
              }
            }
LABEL_4:
            if ( BYTE1(v9) )
              __writeeflags(v7);
            VBoxGuest_RTThreadPreemptRestore(&v8);
            return 4294966933LL;
          }
        }
        else if ( _InterlockedCompareExchange64((volatile signed __int64 *)(a1 + 8), v3, -1) != -1 )
        {
          _mm_pause();
          if ( *(_DWORD *)a1 == 409403913 )
          {
            v6 = 0;
            while ( 1 )
            {
              ++v6;
              if ( _InterlockedCompareExchange64(v4, v3, -1) == -1 )
                goto LABEL_22;
              _mm_pause();
              if ( *(_DWORD *)a1 != 409403913 )
                goto LABEL_4;
              if ( (v6 & 0xF) == 0xF )
              {
                if ( BYTE1(v9) )
                  __writeeflags(v7);
                VBoxGuest_RTThreadPreemptRestore(&v8);
                result = VBoxGuest_RTSemEventWaitEx(*(_QWORD *)(a1 + 24), 80, 0);
                if ( (int)result < 0 )
                {
                  if ( (_DWORD)result != -39 )
                    return result;
                }
                else if ( *(_DWORD *)a1 != 409403913 )
                {
                  return 4294966933LL;
                }
                result = rtSemSpinMutexEnter((__int64)&v7, a1);
                if ( (int)result < 0 )
                  return result;
              }
            }
          }
          goto LABEL_4;
        }
LABEL_22:
        *(_QWORD *)(a1 + 32) = v7;
        *(_QWORD *)(a1 + 40) = v8;
        *(_QWORD *)(a1 + 48) = v9;
        return 0;
      }
      if ( BYTE1(v9) )
        __writeeflags(v7);
      VBoxGuest_RTThreadPreemptRestore(&v8);
      return 4294966929LL;
    }
  }
  return result;
}
