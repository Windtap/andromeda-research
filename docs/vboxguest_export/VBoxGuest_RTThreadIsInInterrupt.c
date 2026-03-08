bool VBoxGuest_RTThreadIsInInterrupt()
{
  return (__readgsdword((unsigned int)&_preempt_count) & 0x1FFF00) != 0;
}
