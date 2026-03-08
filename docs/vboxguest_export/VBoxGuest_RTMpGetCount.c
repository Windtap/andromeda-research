__int64 VBoxGuest_RTMpGetCount()
{
  return _bitmap_weight(cpu_possible_mask, nr_cpu_ids);
}
