__int64 __fastcall vbsf_handle_append(__int64 a1, __int64 a2)
{
  __int64 v2; // rax
  __int64 v3; // rcx
  __int64 v4; // r8

  v2 = raw_spin_lock_irqsave(&g_SfHandleLock);
  *(_DWORD *)(a2 + 24) |= 0x80u;
  **(_QWORD **)(a1 + 64) = a2;
  *(_QWORD *)(a2 + 8) = *(_QWORD *)(a1 + 64);
  *(_QWORD *)a2 = a1 + 56;
  *(_QWORD *)(a1 + 64) = a2;
  return raw_spin_unlock_irqrestore(&g_SfHandleLock, v2, a1 + 56, v3, v4);
}
