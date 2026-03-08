__int64 VBoxGuest_RTThreadPreemptIsPending()
{
  return (*(_QWORD *)(*(_QWORD *)(__readgsqword((unsigned int)&current_task) + 8) + 8LL) >> 3) & 1LL;
}
