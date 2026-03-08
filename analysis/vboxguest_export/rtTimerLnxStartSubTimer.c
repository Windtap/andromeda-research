__int64 __fastcall rtTimerLnxStartSubTimer(__int64 a1, __int64 a2, unsigned __int64 a3, char a4, char a5)
{
  unsigned __int64 v5; // rsi
  unsigned __int64 v6; // rsi
  __int64 v7; // rax
  __int64 v8; // rcx
  signed __int64 v9; // rdx
  unsigned __int64 v10; // rsi
  __int64 v11; // rsi
  __int64 result; // rax

  v5 = a3 + a2;
  if ( a5 )
  {
    *(_QWORD *)(a1 + 80) = 0;
    v8 = a4 != 0 ? 2 : 0;
    v9 = v5 / 0x3B9ACA00;
    v10 = v5 % 0x3B9ACA00;
    if ( v9 > 0x225C17D03LL )
      v11 = 0x7FFFFFFFFFFFFFFFLL;
    else
      v11 = 1000000000 * v9 + v10;
    hrtimer_start_range_ns(a1, v11, 0, v8);
  }
  else
  {
    *(_QWORD *)(a1 + 48) = v5;
    *(_QWORD *)(a1 + 56) = v5;
    v6 = 0;
    *(_QWORD *)(a1 + 80) = 0;
    if ( a3 )
    {
      v6 = 0x3FFFFFFFFFFFFFFELL;
      if ( a3 <= 0x3FFFFFFFFF9A4656LL )
        v6 = (a3 + 3333332) / 0x32DCD5;
    }
    v7 = jiffies;
    *(_BYTE *)(a1 + 72) = 1;
    *(_QWORD *)(a1 + 64) = v7 + v6;
    if ( a4 )
      mod_timer_pinned();
    else
      mod_timer();
  }
  result = (unsigned int)_InterlockedCompareExchange((volatile signed __int32 *)(a1 + 104), 3, 1);
  if ( (_DWORD)result != 1 )
    return (unsigned int)_InterlockedCompareExchange((volatile signed __int32 *)(a1 + 104), 3, 2);
  return result;
}
