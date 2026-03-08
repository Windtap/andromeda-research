unsigned __int64 VBoxGuest_RTThreadPreemptIsEnabled()
{
  unsigned __int64 result; // rax

  result = 0;
  if ( (__readgsdword((unsigned int)&_preempt_count) & 0x7FFFFFFF) == 0 )
    return ((unsigned __int64)pv_irq_ops() >> 9) & 1;
  return result;
}
