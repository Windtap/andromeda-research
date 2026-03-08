unsigned int __fastcall VBoxGuest_RTThreadPreemptRestore(__int64 a1)
{
  unsigned int result; // eax

  preempt_count_sub(1);
  result = __readgsdword((unsigned int)&_preempt_count);
  if ( !result )
    result = __preempt_schedule();
  *(_DWORD *)(a1 + 4) = 0;
  return result;
}
