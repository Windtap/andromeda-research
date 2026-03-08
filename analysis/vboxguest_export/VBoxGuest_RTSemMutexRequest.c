__int64 __fastcall VBoxGuest_RTSemMutexRequest(__int64 a1, unsigned int a2)
{
  unsigned __int64 v3; // rbx
  __int64 v4; // r14
  __int64 v5; // rax
  unsigned int v6; // ebx
  __int64 v7; // rsi
  __int64 v8; // rdi
  __int64 v10; // r12
  __int64 v11; // rcx
  __int64 *v12; // rax
  volatile __int64 *v13; // rbx
  unsigned __int64 v14; // [rsp+0h] [rbp-60h]
  __int64 v15; // [rsp+18h] [rbp-48h] BYREF
  __int64 *v16; // [rsp+20h] [rbp-40h]
  unsigned __int64 v17; // [rsp+28h] [rbp-38h]
  int v18; // [rsp+30h] [rbp-30h]

  v3 = __readgsqword((unsigned int)&current_task);
  if ( (unsigned __int64)(a1 + 0x200000) > 0x200FFF
    && ((a1 & 0xFF00000000000000LL) == 0 || (a1 & 0xFF00000000000000LL) == 0xFF00000000000000LL)
    && *(_DWORD *)a1 == 424805137 )
  {
    v4 = raw_spin_lock_irqsave(a1 + 36);
    v5 = *(_QWORD *)(a1 + 24);
    if ( v3 == v5 )
    {
      ++*(_DWORD *)(a1 + 4);
      v6 = 0;
    }
    else if ( v5 || *(_QWORD *)(a1 + 16) != a1 + 8 )
    {
      v6 = -40;
      if ( a2 )
      {
        v14 = __readgsqword((unsigned int)&current_task);
        v10 = 0x7FFFFFFFFFFFFFFFLL;
        if ( a2 != -1 )
          v10 = _msecs_to_jiffies(a2);
        _InterlockedExchangeAdd((volatile signed __int32 *)(a1 + 32), 1u);
        v18 = 2;
        v11 = a1 + 8;
        v17 = v14;
        **(_QWORD **)(a1 + 16) = &v15;
        v12 = *(__int64 **)(a1 + 16);
        v15 = a1 + 8;
        *(_QWORD *)(a1 + 16) = &v15;
        v16 = v12;
        if ( v10 )
        {
          v13 = (volatile __int64 *)__readgsqword((unsigned int)&current_task);
          while ( 1 )
          {
            _InterlockedExchange64(v13, 2);
            raw_spin_unlock_irq(a1 + 36);
            v10 = schedule_timeout(v10);
            raw_spin_lock_irq(a1 + 36);
            _InterlockedExchange64(v13, 0);
            if ( !v18 )
            {
              *(_DWORD *)(a1 + 4) = 1;
              v6 = 0;
              v11 = v15;
              *(_QWORD *)(a1 + 24) = v14;
              v12 = v16;
              goto LABEL_19;
            }
            if ( v18 == 1 || *(_DWORD *)a1 != 424805137 )
              break;
            if ( !v10 )
            {
              v12 = v16;
              v6 = -40;
              v11 = v15;
              goto LABEL_19;
            }
          }
          v12 = v16;
          v6 = -363;
          v11 = v15;
        }
        else
        {
          v6 = -40;
        }
LABEL_19:
        *v12 = v11;
        *(_QWORD *)(v11 + 8) = v12;
        v15 = 0;
        v16 = 0;
        v7 = v4;
        v8 = a1 + 36;
        if ( _InterlockedExchangeAdd((volatile signed __int32 *)(a1 + 32), 0xFFFFFFFF) == 1 )
        {
          raw_spin_unlock_irqrestore(v8, v4);
          VBoxGuest_RTMemFree(a1);
          return v6;
        }
LABEL_8:
        raw_spin_unlock_irqrestore(v8, v7);
        return v6;
      }
    }
    else
    {
      *(_QWORD *)(a1 + 24) = v3;
      v6 = 0;
      *(_DWORD *)(a1 + 4) = 1;
    }
    v7 = v4;
    v8 = a1 + 36;
    goto LABEL_8;
  }
  return 4294967292LL;
}
