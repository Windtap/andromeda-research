__int64 __fastcall VBoxGuest_RTSpinlockAcquire(__int64 a1)
{
  bool v2; // zf
  __int64 v3; // rdi
  __int64 result; // rax

  v2 = (*(_BYTE *)(a1 + 4) & 2) == 0;
  v3 = a1 + 16;
  if ( v2 )
    return raw_spin_lock(v3);
  result = raw_spin_lock_irqsave(v3);
  *(_QWORD *)(a1 + 8) = result;
  return result;
}
