bool __fastcall wait_recv_enable(int a1, int a2)
{
  my_wait_event_constprop_6(a1, a2, (__int64 (__fastcall *)(_QWORD))my_condition_recv_enable);
  return *(_DWORD *)(g_pPipeMem + 48LL * a1 + 44) == a2;
}
