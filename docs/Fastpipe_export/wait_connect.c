bool __fastcall wait_connect(int a1, int a2)
{
  my_wait_event_constprop_6(a1, a2, (__int64 (__fastcall *)(_QWORD))my_condition_connect);
  return *(_DWORD *)(g_pPipeMem + 48LL * a1 + 44) == a2;
}
