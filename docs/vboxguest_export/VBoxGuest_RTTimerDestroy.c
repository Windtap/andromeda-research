__int64 __fastcall VBoxGuest_RTTimerDestroy(__int64 a1)
{
  unsigned int v1; // ebx
  char v2; // r12
  __int64 v3; // rsi
  unsigned __int32 v4; // edx
  unsigned int v5; // eax
  __int64 v6; // rsi

  if ( !a1 )
    return 0;
  if ( (unsigned __int64)(a1 + 0x200000) <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL
    || *(_DWORD *)a1 != 423037200 )
  {
    return 4294967292LL;
  }
  if ( *(_BYTE *)(a1 + 16) )
  {
    v1 = *(_DWORD *)(a1 + 24);
    if ( v1 > 1 )
      VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a1 + 8));
    v2 = 1;
LABEL_9:
    while ( --v1 != -1 )
    {
LABEL_10:
      v3 = a1 + 112LL * v1;
      while ( 1 )
      {
        v4 = *(_DWORD *)(v3 + 208);
        if ( v4 < 4 )
          break;
        if ( v4 > 6 )
        {
          if ( v4 == 7 )
            v2 = 0;
          if ( --v1 != -1 )
            goto LABEL_10;
          goto LABEL_16;
        }
        if ( v4 == _InterlockedCompareExchange((volatile signed __int32 *)(v3 + 208), 7, v4) )
        {
          v2 = 0;
          goto LABEL_9;
        }
      }
    }
LABEL_16:
    if ( *(_DWORD *)(a1 + 24) > 1u )
      VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 8));
  }
  else
  {
    v2 = rtTimerLnxStop(a1, 1);
  }
  if ( !v2 )
    return 0;
  v5 = __readgsdword((unsigned int)&_preempt_count);
  if ( (v5 & 0x7FFFFFFF) != 0 || (v5 & 0x1FFF00) != 0 )
  {
    v6 = g_prtR0LnxWorkQueue;
    *(_QWORD *)(a1 + 96) = rtTimerLnxDestroyDeferred;
    *(_QWORD *)(a1 + 72) = 0xFFFFFFFE0LL;
    *(_QWORD *)(a1 + 80) = a1 + 80;
    *(_QWORD *)(a1 + 88) = a1 + 80;
    queue_work_on(0x2000, v6, a1 + 72);
    return 0;
  }
  rtTimerLnxDestroyIt(a1);
  return 0;
}
