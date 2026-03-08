__int64 __fastcall VBoxGuest_RTSpinlockRelease(__int64 a1)
{
  __int64 v2; // rsi

  if ( (*(_BYTE *)(a1 + 4) & 2) == 0 )
    return raw_spin_unlock(a1 + 16);
  v2 = *(_QWORD *)(a1 + 8);
  *(_QWORD *)(a1 + 8) = 0;
  return raw_spin_unlock_irqrestore(a1 + 16, v2);
}
