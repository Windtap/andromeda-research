__int64 __fastcall vbsf_handle_drop_chain(__int64 a1)
{
  __int64 v1; // rax
  _QWORD *v2; // r8
  _QWORD *v3; // rdx
  _QWORD *v4; // rdi
  _QWORD *v5; // rcx
  _QWORD *v6; // r8

  v1 = raw_spin_lock_irqsave(&g_SfHandleLock);
  v3 = *(_QWORD **)(a1 + 56);
  v4 = (_QWORD *)(a1 + 56);
  v5 = (_QWORD *)*v3;
  if ( v3 != v4 )
  {
    while ( 1 )
    {
      v6 = (_QWORD *)v3[1];
      *((_DWORD *)v3 + 6) |= 0x80u;
      *v6 = v5;
      v5[1] = v6;
      *v3 = 0;
      v3[1] = 0;
      v2 = (_QWORD *)*v5;
      if ( v4 == v5 )
        break;
      v3 = v5;
      v5 = (_QWORD *)*v5;
    }
  }
  return raw_spin_unlock_irqrestore(&g_SfHandleLock, v1, v3, v5, v2);
}
