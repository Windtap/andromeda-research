__int64 __fastcall VBoxGuest_RTThreadPreemptDisable(__int64 a1)
{
  *(_DWORD *)(a1 + 4) = 42;
  return preempt_count_add(1);
}
