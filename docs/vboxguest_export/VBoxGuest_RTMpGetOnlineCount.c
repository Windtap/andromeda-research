__int64 VBoxGuest_RTMpGetOnlineCount()
{
  return _bitmap_weight(cpu_online_mask, nr_cpu_ids);
}
