__int64 __fastcall VBoxGuest_RTSemMutexRelease(__int64 a1)
{
  unsigned __int64 v2; // r13
  unsigned int v3; // r12d
  __int64 v4; // rsi
  bool v6; // zf
  __int64 v7; // rax
  __int64 v8; // rdi

  v2 = __readgsqword((unsigned int)&current_task);
  if ( (unsigned __int64)(a1 + 0x200000) <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL
    || *(_DWORD *)a1 != 424805137 )
  {
    return 4294967292LL;
  }
  v3 = -355;
  v4 = raw_spin_lock_irqsave(a1 + 36);
  if ( v2 == *(_QWORD *)(a1 + 24) )
  {
    v6 = (*(_DWORD *)(a1 + 4))-- == 1;
    if ( !v6 || (*(_QWORD *)(a1 + 24) = 0, *(_QWORD *)(a1 + 16) == a1 + 8) )
    {
      v3 = 0;
    }
    else
    {
      v7 = *(_QWORD *)(a1 + 8);
      v3 = 0;
      v8 = *(_QWORD *)(v7 + 16);
      *(_DWORD *)(v7 + 24) = 0;
      wake_up_process(v8);
    }
  }
  raw_spin_unlock_irqrestore(a1 + 36, v4);
  return v3;
}
