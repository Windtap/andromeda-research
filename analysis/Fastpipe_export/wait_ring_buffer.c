bool __fastcall wait_ring_buffer(int a1, int a2)
{
  my_wait_event_constprop_6(a1, a2, (__int64 (__fastcall *)(_QWORD))my_condition_ring_buffer);
  return *(_DWORD *)(g_pPipeMem + 48LL * a1 + 44) == a2;
}
