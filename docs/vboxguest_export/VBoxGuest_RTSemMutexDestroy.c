__int64 __fastcall VBoxGuest_RTSemMutexDestroy(__int64 a1)
{
  __int64 v2; // r12
  __int64 v3; // rax
  __int64 *v4; // rbx
  __int64 v5; // r14
  __int64 v6; // rdi

  if ( !a1 )
    return 0;
  if ( (unsigned __int64)(a1 + 0x200000) <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL
    || *(_DWORD *)a1 != 424805137
    || _InterlockedCompareExchange((volatile signed __int32 *)a1, 536937745, 424805137) != 424805137 )
  {
    return 4294967292LL;
  }
  v2 = a1 + 8;
  v3 = raw_spin_lock_irqsave(a1 + 36);
  v4 = *(__int64 **)(a1 + 8);
  v5 = v3;
  if ( (__int64 *)(a1 + 8) != v4 )
  {
    do
    {
      v6 = v4[2];
      *((_DWORD *)v4 + 6) = 1;
      wake_up_process(v6);
      v4 = (__int64 *)*v4;
    }
    while ( (__int64 *)v2 != v4 );
  }
  if ( _InterlockedExchangeAdd((volatile signed __int32 *)(a1 + 32), 0xFFFFFFFF) == 1 )
  {
    raw_spin_unlock_irqrestore(a1 + 36, v5);
    VBoxGuest_RTMemFree(a1);
  }
  else
  {
    raw_spin_unlock_irqrestore(a1 + 36, v5);
  }
  return 0;
}
