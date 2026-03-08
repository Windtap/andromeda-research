volatile signed __int32 *__fastcall vbsf_handle_find(__int64 a1, int a2, unsigned int a3)
{
  __int64 v4; // rax
  __int64 v5; // rcx
  volatile signed __int32 *v6; // rbx
  __int64 *v7; // rdi
  __int64 v8; // rdx
  __int64 v9; // rcx

  v4 = raw_spin_lock_irqsave(&g_SfHandleLock);
  v6 = *(volatile signed __int32 **)(a1 + 56);
  v7 = (__int64 *)(a1 + 56);
  v8 = a2 | a3;
  if ( v6 == (volatile signed __int32 *)v7 )
  {
LABEL_7:
    raw_spin_unlock_irqrestore(&g_SfHandleLock, v4, v8, v5, 1);
    return 0;
  }
  else
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v5 = (unsigned int)v8 & v6[6];
        if ( (_DWORD)v5 == a2 )
          break;
        v6 = *(volatile signed __int32 **)v6;
        if ( v6 == (volatile signed __int32 *)v7 )
          goto LABEL_7;
      }
      v9 = (unsigned int)_InterlockedIncrement(v6 + 7);
      if ( (unsigned int)v9 > 1 )
        break;
      v5 = (unsigned int)_InterlockedExchangeAdd(v6 + 7, 0xFFFFFFFF);
      v6 = *(volatile signed __int32 **)v6;
      if ( v6 == (volatile signed __int32 *)v7 )
        goto LABEL_7;
    }
    raw_spin_unlock_irqrestore(&g_SfHandleLock, v4, v8, v9, 1);
    return v6;
  }
}
