__int64 __fastcall rtTimerLinuxHrCallback(__int64 a1)
{
  volatile signed __int32 *v1; // r12
  __int64 v2; // rbp
  int v3; // eax
  void (__fastcall *v5)(__int64, _QWORD); // rax
  __int64 v6; // rax
  void (__fastcall *v8)(__int64, _QWORD); // rax
  int v9; // eax
  signed __int32 v10; // eax
  unsigned __int64 v11; // rax
  signed __int64 v12; // rax
  unsigned __int64 v13; // rdx
  unsigned __int64 v14; // rtt
  __int64 v15; // rax

  v1 = (volatile signed __int32 *)(a1 + 104);
  v2 = *(_QWORD *)(a1 + 96);
  if ( _InterlockedCompareExchange((volatile signed __int32 *)(a1 + 104), 4, 3) != 3 )
  {
    while ( 1 )
    {
      v10 = *(_DWORD *)(a1 + 104);
      if ( (unsigned int)(v10 - 1) > 2 )
        return 0;
      if ( v10 == _InterlockedCompareExchange(v1, 4, v10) )
        break;
      _mm_pause();
    }
  }
  if ( *(_BYTE *)(v2 + 18) || *(_BYTE *)(v2 + 17) )
  {
    v3 = debug_smp_processor_id(a1);
    if ( *(_BYTE *)(v2 + 18) ? -1227133513 * (unsigned int)((a1 - (v2 + 104)) >> 4) != v3 : *(_DWORD *)(v2 + 20) != v3 )
    {
      rtTimerLnxCallbackHandleMigration(v2, a1);
      return 0;
    }
  }
  if ( !*(_QWORD *)(v2 + 48) )
  {
    *(_BYTE *)(v2 + 16) = 1;
    v8 = *(void (__fastcall **)(__int64, _QWORD))(v2 + 32);
    ++*(_QWORD *)(a1 + 80);
    v8(v2, *(_QWORD *)(v2 + 40));
    if ( _InterlockedCompareExchange((volatile signed __int32 *)(a1 + 104), 0, 4) == 4 )
      return 0;
    while ( 1 )
    {
LABEL_14:
      v9 = *(_DWORD *)(a1 + 104);
      if ( v9 == 6 )
      {
        if ( _InterlockedCompareExchange(v1, 3, 6) == 6 )
        {
          v11 = *(_QWORD *)(a1 + 88);
          *(_QWORD *)(a1 + 80) = 0;
          v14 = v11;
          v12 = v11 / 0x3B9ACA00;
          v13 = v14 % 0x3B9ACA00;
          if ( v12 > 0x225C17D03LL )
            v15 = 0x7FFFFFFFFFFFFFFFLL;
          else
            v15 = v13 + 1000000000 * v12;
          *(_QWORD *)(a1 + 24) = v15;
          *(_QWORD *)(a1 + 32) = v15;
          return 1;
        }
      }
      else
      {
        if ( v9 == 7 )
        {
          rtTimerLnxCallbackDestroy(v2, a1, 0, 3);
          return 0;
        }
        if ( v9 != 5 || _InterlockedCompareExchange(v1, 0, 5) == 5 )
          return 0;
      }
      _mm_pause();
    }
  }
  v5 = *(void (__fastcall **)(__int64, _QWORD))(v2 + 32);
  ++*(_QWORD *)(a1 + 80);
  v5(v2, *(_QWORD *)(v2 + 40));
  _mm_mfence();
  v6 = *(_QWORD *)(v2 + 48);
  *(_QWORD *)(a1 + 24) += v6;
  *(_QWORD *)(a1 + 32) += v6;
  if ( _InterlockedCompareExchange((volatile signed __int32 *)(a1 + 104), 3, 4) != 4 )
    goto LABEL_14;
  return 1;
}
