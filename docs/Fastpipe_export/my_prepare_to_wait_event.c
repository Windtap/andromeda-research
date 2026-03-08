__int64 __fastcall my_prepare_to_wait_event(__int64 a1, __int64 a2)
{
  __int64 v2; // rax
  __int64 v3; // rdx
  __int64 v5; // rcx

  v2 = raw_spin_lock_irqsave(a1);
  v3 = *(_QWORD *)(a2 + 24);
  if ( v3 == a2 + 24 )
  {
    v5 = *(_QWORD *)(a1 + 8);
    *(_QWORD *)(v5 + 8) = v3;
    *(_QWORD *)(a2 + 24) = v5;
    *(_QWORD *)(a2 + 32) = a1 + 8;
    *(_QWORD *)(a1 + 8) = v3;
  }
  return raw_spin_unlock_irqrestore(
           a1,
           v2,
           _InterlockedExchange64((volatile __int64 *)__readgsqword((unsigned int)&current_task), 2));
}
