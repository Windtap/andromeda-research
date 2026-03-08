__int64 __fastcall rtR0ThreadLnxSleepCommon(__int64 a1)
{
  __int64 v1; // rax

  v1 = _msecs_to_jiffies(a1);
  _InterlockedExchange64((volatile __int64 *)__readgsqword((unsigned int)&current_task), 1);
  return schedule_timeout(v1) != 0 ? 0xFFFFFFD9 : 0;
}
