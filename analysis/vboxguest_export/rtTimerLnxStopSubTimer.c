__int64 __fastcall rtTimerLnxStopSubTimer(__int64 a1, char a2)
{
  if ( a2 )
  {
    if ( (int)((__int64 (*)(void))hrtimer_try_to_cancel)() < 0 )
    {
      hrtimer_start_range_ns(a1, 0x7FFFFFFFFFFFFFFFLL, 0, 0);
      hrtimer_try_to_cancel(a1);
    }
  }
  else
  {
    del_timer();
  }
  return (unsigned int)_InterlockedExchange((volatile __int32 *)(a1 + 104), 0);
}
