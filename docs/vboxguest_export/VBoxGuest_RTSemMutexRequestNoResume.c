__int64 __fastcall VBoxGuest_RTSemMutexRequestNoResume(__int64 a1, unsigned int a2)
{
  unsigned __int64 v3; // rbx
  __int64 v4; // rax
  unsigned int v5; // ebx
  __int64 v6; // rsi
  __int64 v7; // rdi
  unsigned __int64 v9; // r14
  __int64 v10; // r12
  __int64 **v11; // rdx
  volatile __int64 *v12; // rbx
  __int64 *v13; // rdx
  __int64 *v14; // rdx
  __int64 v15; // rax
  __int64 v16; // [rsp+8h] [rbp-60h]
  __int64 v17; // [rsp+20h] [rbp-48h] BYREF
  __int64 *v18; // [rsp+28h] [rbp-40h]
  unsigned __int64 v19; // [rsp+30h] [rbp-38h]
  int v20; // [rsp+38h] [rbp-30h]

  v3 = __readgsqword((unsigned int)&current_task);
  if ( (unsigned __int64)(a1 + 0x200000) > 0x200FFF
    && ((a1 & 0xFF00000000000000LL) == 0 || (a1 & 0xFF00000000000000LL) == 0xFF00000000000000LL)
    && *(_DWORD *)a1 == 424805137 )
  {
    v16 = raw_spin_lock_irqsave(a1 + 36);
    v4 = *(_QWORD *)(a1 + 24);
    if ( v3 == v4 )
    {
      ++*(_DWORD *)(a1 + 4);
      v5 = 0;
    }
    else if ( v4 || *(_QWORD *)(a1 + 16) != a1 + 8 )
    {
      v5 = -40;
      if ( a2 )
      {
        v9 = __readgsqword((unsigned int)&current_task);
        v10 = 0x7FFFFFFFFFFFFFFFLL;
        if ( a2 != -1 )
          v10 = _msecs_to_jiffies(a2);
        _InterlockedExchangeAdd((volatile signed __int32 *)(a1 + 32), 1u);
        v11 = *(__int64 ***)(a1 + 16);
        v19 = v9;
        v20 = 2;
        v12 = (volatile __int64 *)__readgsqword((unsigned int)&current_task);
        *v11 = &v17;
        v13 = *(__int64 **)(a1 + 16);
        *(_QWORD *)(a1 + 16) = &v17;
        v18 = v13;
        v17 = a1 + 8;
        while ( (*(_QWORD *)(*(_QWORD *)(v9 + 8) + 8LL) & 4) == 0 )
        {
          if ( !v10 )
          {
            v5 = -40;
            goto LABEL_19;
          }
          _InterlockedExchange64(v12, 1);
          raw_spin_unlock_irq(a1 + 36);
          v10 = schedule_timeout(v10);
          raw_spin_lock_irq(a1 + 36);
          _InterlockedExchange64(v12, 0);
          if ( !v20 )
          {
            *(_DWORD *)(a1 + 4) = 1;
            v5 = 0;
            *(_QWORD *)(a1 + 24) = v9;
            goto LABEL_19;
          }
          if ( v20 == 1 || *(_DWORD *)a1 != 424805137 )
          {
            v5 = -363;
            goto LABEL_19;
          }
        }
        v5 = -39;
LABEL_19:
        v14 = v18;
        v15 = v17;
        *v18 = v17;
        *(_QWORD *)(v15 + 8) = v14;
        v17 = 0;
        v18 = 0;
        v6 = v16;
        v7 = a1 + 36;
        if ( _InterlockedExchangeAdd((volatile signed __int32 *)(a1 + 32), 0xFFFFFFFF) == 1 )
        {
          raw_spin_unlock_irqrestore(v7, v16);
          VBoxGuest_RTMemFree(a1);
          return v5;
        }
LABEL_8:
        raw_spin_unlock_irqrestore(v7, v6);
        return v5;
      }
    }
    else
    {
      *(_QWORD *)(a1 + 24) = v3;
      v5 = 0;
      *(_DWORD *)(a1 + 4) = 1;
    }
    v6 = v16;
    v7 = a1 + 36;
    goto LABEL_8;
  }
  return 4294967292LL;
}
