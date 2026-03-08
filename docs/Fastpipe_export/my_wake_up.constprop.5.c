__int64 my_wake_up_constprop_5()
{
  __int64 v0; // rax
  __int64 v1; // rdx
  __int64 v2; // r12
  __int64 v3; // r13
  __int64 v4; // rbp
  __int64 v5; // rbx
  __int64 v6; // rax
  __int64 v7; // rdx
  _QWORD *v8; // rax

  v0 = raw_spin_lock_irqsave(&g_waitHostRetQueue);
  v2 = qword_15C98;
  v3 = v0;
  v4 = qword_15C98 - 24;
  v5 = *(_QWORD *)qword_15C98 - 24LL;
  if ( (__int64 *)qword_15C98 != &qword_15C98 )
  {
    while ( 1 )
    {
      if ( (*(unsigned __int8 (__fastcall **)(__int64))(v4 + 16))(v4)
        && (unsigned int)wake_up_process(*(_QWORD *)(v4 + 8)) )
      {
        v7 = *(_QWORD *)(v4 + 24);
        v8 = *(_QWORD **)(v4 + 32);
        *(_QWORD *)(v7 + 8) = v8;
        *v8 = v7;
        *(_QWORD *)(v4 + 24) = v2;
        *(_QWORD *)(v4 + 32) = v2;
      }
      v6 = *(_QWORD *)(v5 + 24);
      v2 = v5 + 24;
      v1 = v6 - 24;
      if ( (__int64 *)(v5 + 24) == &qword_15C98 )
        break;
      v4 = v5;
      v5 = v6 - 24;
    }
  }
  return raw_spin_unlock_irqrestore(&g_waitHostRetQueue, v3, v1);
}
