__int64 __fastcall rtTimerLinuxStdCallback(__int64 a1)
{
  __int64 v2; // r14
  int v3; // eax
  __int64 v5; // r15
  __int64 v6; // r12
  __int64 v7; // rbp
  __int64 v8; // rax
  unsigned __int64 v9; // r13
  __int64 v10; // rsi
  unsigned __int64 v11; // r8
  __int64 v12; // rdx
  unsigned __int64 v13; // r15
  volatile signed __int32 *v14; // rcx
  unsigned __int64 v15; // rsi
  __int64 v16; // rdi
  __int64 result; // rax
  void (__fastcall *v18)(__int64, _QWORD); // rax
  __int64 v19; // rax
  __int64 v20; // rsi
  unsigned __int64 v21; // rdi
  unsigned __int64 v22; // r13
  unsigned __int64 v23; // r15
  unsigned __int64 v24; // rax
  __int64 v25; // rdx
  unsigned __int64 v26; // rax
  unsigned __int64 v27; // r15
  __int64 SystemNanoTS; // rax
  __int64 v29; // rax
  unsigned __int64 v30; // rbp
  __int64 v31; // r13
  __int64 v32; // rdx
  unsigned __int64 v33; // rax
  unsigned __int64 v34; // rbp
  unsigned __int64 v35; // rdi
  unsigned __int64 v36; // rdi
  volatile signed __int32 *v37; // [rsp+0h] [rbp-60h]
  unsigned __int64 v38; // [rsp+8h] [rbp-58h]
  unsigned __int64 v39; // [rsp+18h] [rbp-48h]
  __int64 v40; // [rsp+20h] [rbp-40h] BYREF
  __int64 v41; // [rsp+28h] [rbp-38h]

  v37 = (volatile signed __int32 *)(a1 + 104);
  v2 = *(_QWORD *)(a1 + 96);
  if ( _InterlockedCompareExchange((volatile signed __int32 *)(a1 + 104), 4, 3) != 3 )
  {
    while ( 1 )
    {
      result = *(unsigned int *)(a1 + 104);
      if ( (unsigned int)(result - 1) > 2 )
        return result;
      if ( (_DWORD)result == _InterlockedCompareExchange(v37, 4, result) )
        break;
      _mm_pause();
    }
  }
  if ( *(_BYTE *)(v2 + 18) || *(_BYTE *)(v2 + 17) )
  {
    v3 = debug_smp_processor_id(a1);
    if ( *(_BYTE *)(v2 + 18) ? -1227133513 * (unsigned int)((a1 - (v2 + 104)) >> 4) != v3 : *(_DWORD *)(v2 + 20) != v3 )
      return rtTimerLnxCallbackHandleMigration(v2, a1);
  }
  if ( *(_QWORD *)(v2 + 48) )
  {
    v5 = *(_QWORD *)(a1 + 80);
    v6 = jiffies;
    v7 = v5 + 1;
    *(_QWORD *)(a1 + 80) = v5 + 1;
    v8 = raw_spin_lock_irqsave(v2 + 64);
    v9 = *(_QWORD *)(v2 + 48);
    v10 = v8;
    v11 = *(_QWORD *)(v2 + 56);
    v12 = v2 + 64;
    if ( *(_BYTE *)(a1 + 72) )
    {
      *(_BYTE *)(a1 + 72) = 0;
      v39 = v11;
      SystemNanoTS = rtTimeGetSystemNanoTS(v2 + 64, v8, v12);
      v6 = jiffies;
      *(_QWORD *)(a1 + 48) = SystemNanoTS;
      v11 = v39;
      *(_QWORD *)(a1 + 56) = SystemNanoTS - v9 * v5;
      v12 = v2 + 64;
      *(_QWORD *)(a1 + 64) = v6;
    }
    v38 = v11;
    raw_spin_unlock_irqrestore(v12, v10);
    *(_QWORD *)(a1 + 48) += v9;
    if ( v38 )
    {
      v13 = *(_QWORD *)(a1 + 64) + v38;
      *(_QWORD *)(a1 + 64) = v13;
      if ( (__int64)(v13 - v6) >= 0 )
        goto LABEL_12;
      v24 = v6 - v13;
      v13 = v6 + (v38 >> 1);
      if ( v24 <= 0x4A )
        goto LABEL_12;
    }
    else
    {
      v40 = 0;
      v41 = 0;
      ktime_get_ts64(&v40);
      v19 = *(_QWORD *)(a1 + 48);
      v20 = v41 + 1000000000 * v40;
      v21 = v20 - v19;
      if ( v20 - v19 <= 0 )
      {
        v26 = v19 - v20;
        v27 = 0x3FFFFFFFFFFFFFFELL;
        if ( v26 <= 0x3FFFFFFFFF9A4656LL )
          v27 = (v26 + 3333332) / 0x32DCD5;
        v13 = v6 + v27;
      }
      else if ( v9 <= 0x65B9A9 )
      {
        v13 = v6 + 1;
        if ( v21 > 0xCB734 )
          *(_QWORD *)(a1 + 48) = v20 + 3333333;
      }
      else
      {
        v22 = v9 >> 1;
        v23 = 0x3FFFFFFFFFFFFFFELL;
        if ( v22 <= 0x3FFFFFFFFF9A4656LL )
        {
          v25 = (0x421F615D46CF8DE9LL * (unsigned __int128)(v22 + 3333332)) >> 64;
          v23 = (v25 + ((v22 + 3333332 - v25) >> 1)) >> 21;
        }
        v13 = v6 + v23;
        if ( v21 > 0xCB734 )
          *(_QWORD *)(a1 + 48) = v20 + v22;
      }
    }
    *(_QWORD *)(a1 + 64) = v13;
LABEL_12:
    (*(void (__fastcall **)(__int64, _QWORD, __int64))(v2 + 32))(v2, *(_QWORD *)(v2 + 40), v7);
    if ( _InterlockedCompareExchange((volatile signed __int32 *)(a1 + 104), 3, 4) != 4 )
      goto LABEL_41;
    v15 = v13;
    v16 = a1;
    if ( *(_BYTE *)(v2 + 17) || *(_BYTE *)(v2 + 18) )
      return mod_timer_pinned(v16, v15);
    return mod_timer(v16, v15);
  }
  *(_BYTE *)(v2 + 16) = 1;
  v18 = *(void (__fastcall **)(__int64, _QWORD))(v2 + 32);
  ++*(_QWORD *)(a1 + 80);
  v18(v2, *(_QWORD *)(v2 + 40));
  result = (unsigned int)_InterlockedCompareExchange((volatile signed __int32 *)(a1 + 104), 0, 4);
  if ( (_DWORD)result == 4 )
    return result;
LABEL_41:
  while ( 1 )
  {
    result = *(unsigned int *)(a1 + 104);
    if ( (_DWORD)result == 6 )
      break;
    if ( (_DWORD)result == 7 )
      return rtTimerLnxCallbackDestroy(v2, a1, 0, v14);
    if ( (_DWORD)result != 5 )
      return result;
    v14 = v37;
    result = (unsigned int)_InterlockedCompareExchange(v37, 0, 5);
    if ( (_DWORD)result == 5 )
      return result;
LABEL_45:
    _mm_pause();
  }
  v14 = v37;
  if ( _InterlockedCompareExchange(v37, 3, 6) != 6 )
    goto LABEL_45;
  v29 = raw_spin_lock_irqsave(v2 + 64);
  v30 = *(_QWORD *)(a1 + 88);
  v31 = v29;
  v33 = rtTimeGetSystemNanoTS(v2 + 64, 3, v32);
  *(_QWORD *)(a1 + 80) = 0;
  *(_BYTE *)(a1 + 72) = 1;
  *(_QWORD *)(a1 + 48) = v30;
  if ( v30 <= v33 )
  {
    v36 = jiffies;
  }
  else
  {
    v34 = v30 - v33;
    v35 = 0x3FFFFFFFFFFFFFFELL;
    if ( v34 <= 0x3FFFFFFFFF9A4656LL )
      v35 = (v34 + 3333332) / 0x32DCD5;
    v36 = jiffies + v35;
  }
  *(_QWORD *)(a1 + 64) = v36;
  raw_spin_unlock_irqrestore(v2 + 64, v31);
  if ( !*(_BYTE *)(v2 + 17) && !*(_BYTE *)(v2 + 18) )
  {
    v15 = *(_QWORD *)(a1 + 64);
    v16 = a1;
    return mod_timer(v16, v15);
  }
  v15 = *(_QWORD *)(a1 + 64);
  v16 = a1;
  return mod_timer_pinned(v16, v15);
}
