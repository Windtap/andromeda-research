_QWORD **__fastcall my_wait_event_constprop_6(int a1, int a2, __int64 (__fastcall *a3)(_QWORD))
{
  volatile __int64 *v4; // rbx
  _QWORD **result; // rax
  __int64 v6; // rdx
  __int64 v7; // rax
  __int64 v8; // rax
  __int64 *v9; // rdx
  _QWORD *v10; // rcx
  int v11; // [rsp+8h] [rbp-50h] BYREF
  int v12; // [rsp+Ch] [rbp-4Ch]
  volatile __int64 *v13; // [rsp+10h] [rbp-48h]
  __int64 (__fastcall *v14)(_QWORD); // [rsp+18h] [rbp-40h]
  _QWORD *v15; // [rsp+20h] [rbp-38h] BYREF
  __int64 *v16; // [rsp+28h] [rbp-30h]

  v11 = a1;
  v14 = a3;
  v4 = (volatile __int64 *)__readgsqword((unsigned int)&current_task);
  v12 = a2;
  v13 = v4;
  v15 = &v15;
  v16 = (__int64 *)&v15;
  result = (_QWORD **)a3(&v11);
  if ( !(_BYTE)result )
  {
    while ( 1 )
    {
      v7 = raw_spin_lock_irqsave(&g_waitHostRetQueue);
      if ( v15 == &v15 )
      {
        v6 = qword_15C98;
        *(_QWORD *)(qword_15C98 + 8) = &v15;
        v15 = (_QWORD *)v6;
        v16 = &qword_15C98;
        qword_15C98 = (__int64)&v15;
      }
      raw_spin_unlock_irqrestore(&g_waitHostRetQueue, v7, _InterlockedExchange64(v4, 2));
      if ( (unsigned __int8)a3(&v11) )
        break;
      schedule();
      v13 = v4;
      v14 = a3;
      v11 = a1;
      v12 = a2;
    }
    *v4 = 0;
    result = &v15;
    if ( v15 != &v15 || v16 != (__int64 *)&v15 )
    {
      v8 = raw_spin_lock_irqsave(&g_waitHostRetQueue);
      v9 = v16;
      v10 = v15;
      v15[1] = v16;
      *v9 = (__int64)v10;
      v15 = &v15;
      v16 = (__int64 *)&v15;
      return (_QWORD **)raw_spin_unlock_irqrestore(&g_waitHostRetQueue, v8, &v15);
    }
  }
  return result;
}
