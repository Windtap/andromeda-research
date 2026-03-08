__int64 __fastcall rtTimerLnxStop(__int64 a1, char a2)
{
  unsigned __int32 i; // edx
  __int64 result; // rax
  unsigned int v5; // ebx
  unsigned int v6; // esi
  __int64 v7; // rdx
  __int64 v8; // r9
  signed __int32 v9; // eax
  __int64 v10; // rdx
  unsigned int v11; // r12d
  __int64 v12; // rax

  if ( !*(_BYTE *)(a1 + 18) )
  {
    *(_BYTE *)(a1 + 16) = 1;
    for ( i = *(_DWORD *)(a1 + 208); i <= 6; i = *(_DWORD *)(a1 + 208) )
    {
      if ( i >= 4 )
      {
        if ( i == _InterlockedCompareExchange((volatile signed __int32 *)(a1 + 208), a2 == 0 ? 5 : 7, i) )
          return 1;
      }
      else
      {
        if ( i != 3 )
          return 0;
        if ( _InterlockedCompareExchange((volatile signed __int32 *)(a1 + 208), 8, 3) == 3 )
        {
          rtTimerLnxStopSubTimer(a1 + 104, *(_BYTE *)(a1 + 19));
          return 0;
        }
      }
      _mm_pause();
    }
    result = 1;
    if ( i != 7 )
      return 0;
    return result;
  }
  VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a1 + 8));
  *(_BYTE *)(a1 + 16) = 1;
  v5 = 0;
  if ( !*(_DWORD *)(a1 + 24) )
    goto LABEL_24;
  v6 = 0;
  do
  {
    while ( 1 )
    {
      v7 = 112LL * v6;
      v8 = a1 + v7;
      v9 = *(_DWORD *)(a1 + v7 + 208);
      if ( v9 != 9 )
      {
        if ( v9 )
          break;
      }
LABEL_23:
      if ( ++v6 >= *(_DWORD *)(a1 + 24) )
        goto LABEL_24;
    }
    v10 = a1 + v7 + 192;
    while ( 1 )
    {
      if ( (unsigned int)(v9 - 4) > 2 )
      {
        if ( v9 == _InterlockedCompareExchange((volatile signed __int32 *)(v10 + 16), 8, v9) )
          goto LABEL_23;
        goto LABEL_19;
      }
      if ( v9 == _InterlockedCompareExchange((volatile signed __int32 *)(v10 + 16), a2 == 0 ? 5 : 7, v9) )
        break;
LABEL_19:
      _mm_pause();
      v9 = *(_DWORD *)(v8 + 208);
      if ( v9 == 9 || !v9 )
        goto LABEL_23;
    }
    ++v6;
    v5 = 1;
  }
  while ( v6 < *(_DWORD *)(a1 + 24) );
LABEL_24:
  VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 8));
  if ( *(_DWORD *)(a1 + 24) )
  {
    v11 = 0;
    do
    {
      while ( 1 )
      {
        v12 = 112LL * v11;
        if ( *(_DWORD *)(a1 + v12 + 208) == 8 )
          break;
        if ( ++v11 >= *(_DWORD *)(a1 + 24) )
          return v5;
      }
      ++v11;
      rtTimerLnxStopSubTimer(a1 + v12 + 104, *(_BYTE *)(a1 + 19));
    }
    while ( v11 < *(_DWORD *)(a1 + 24) );
  }
  return v5;
}
