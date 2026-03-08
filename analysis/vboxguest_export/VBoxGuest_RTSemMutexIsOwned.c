__int64 __fastcall VBoxGuest_RTSemMutexIsOwned(__int64 a1)
{
  unsigned int v1; // ebx
  __int64 v2; // rax

  v1 = a1;
  if ( (unsigned __int64)(a1 + 0x200000) <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL
    || *(_DWORD *)a1 != 424805137 )
  {
    return 0;
  }
  v2 = raw_spin_lock_irqsave(a1 + 36);
  LOBYTE(v1) = *(_QWORD *)(a1 + 24) != 0;
  raw_spin_unlock_irqrestore(a1 + 36, v2);
  return v1;
}
