__int64 __fastcall VBoxGuest_RTTimerChangeInterval(__int64 a1, unsigned __int64 a2)
{
  __int64 result; // rax
  __int64 v4; // rdi
  unsigned __int64 v5; // r12
  __int64 v6; // rax

  if ( (unsigned __int64)(a1 + 0x200000) <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL
    || *(_DWORD *)a1 != 423037200 )
  {
    return 4294967292LL;
  }
  if ( a2 - 1 > 0x1FFFFFFFFFFFFFFDLL )
    return 4294967294LL;
  if ( !*(_QWORD *)(a1 + 48) )
    return 4294967217LL;
  if ( *(_BYTE *)(a1 + 19) )
  {
    _InterlockedExchange64((volatile __int64 *)(a1 + 48), a2);
    return 0;
  }
  else
  {
    result = 4294967259LL;
    if ( *(_DWORD *)(a1 + 24) <= 1u )
    {
      v4 = a1 + 64;
      v5 = a2 / 0x32DCD5;
      if ( a2 != 3333333 * (a2 / 0x32DCD5) )
        v5 = 0;
      v6 = raw_spin_lock_irqsave(v4);
      *(_BYTE *)(a1 + 176) = 1;
      *(_QWORD *)(a1 + 56) = v5;
      _InterlockedExchange64((volatile __int64 *)(a1 + 48), a2);
      raw_spin_unlock_irqrestore(a1 + 64, v6);
      return 0;
    }
  }
  return result;
}
