__int64 __fastcall rtTimerLnxOmniStart(__int64 a1, _QWORD *a2)
{
  int v3; // esi
  unsigned int v4; // eax
  unsigned int i; // eax
  __int32 v6; // r8d
  volatile signed __int32 *OnlineSet; // rax
  __int64 j; // rcx
  unsigned int v9; // ecx
  __int64 v11; // [rsp+0h] [rbp-120h] BYREF
  __int64 v12; // [rsp+8h] [rbp-118h]
  _QWORD v13[16]; // [rsp+10h] [rbp-110h] BYREF
  signed __int32 v14[36]; // [rsp+90h] [rbp-90h] BYREF

  VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a1 + 8));
  v3 = *(_DWORD *)(a1 + 24);
  if ( v3 )
  {
    if ( *(_DWORD *)(a1 + 208) )
    {
LABEL_18:
      VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 8));
      return 4294967263LL;
    }
    v4 = 0;
    while ( ++v4 != v3 )
    {
      if ( *(_DWORD *)(a1 + 112LL * v4 + 208) )
        goto LABEL_18;
    }
  }
LABEL_6:
  VBoxGuest_RTMpGetOnlineSet((volatile signed __int32 *)v13);
  for ( i = 0; *(_DWORD *)(a1 + 24) > i; ++i )
  {
    v6 = 0;
    if ( i <= 0x3FF && nr_cpu_ids > i )
      v6 = _bittest((const signed __int32 *)v13, i);
    _InterlockedExchange((volatile __int32 *)(a1 + 112LL * i + 208), v6);
  }
  OnlineSet = VBoxGuest_RTMpGetOnlineSet(v14);
  for ( j = 0; j != 16; ++j )
  {
    if ( v13[j] != *(_QWORD *)&OnlineSet[2 * j] )
      goto LABEL_6;
  }
  *(_BYTE *)(a1 + 16) = 0;
  VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 8));
  v11 = 0;
  v12 = 0;
  ktime_get_ts64(&v11);
  *a2 = v12 + 1000000000 * v11;
  VBoxGuest_RTMpOnAll((void (__fastcall *)(_QWORD, __int64, __int64, __int64))rtTimerLnxStartAllOnCpu, a1, (__int64)a2);
  VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a1 + 8));
  if ( *(_DWORD *)(a1 + 24) )
  {
    v9 = 0;
    do
      _InterlockedCompareExchange((volatile signed __int32 *)(a1 + 112LL * v9++ + 208), 0, 1);
    while ( *(_DWORD *)(a1 + 24) > v9 );
  }
  VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 8));
  return 0;
}
