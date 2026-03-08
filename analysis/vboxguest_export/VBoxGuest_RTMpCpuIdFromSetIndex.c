__int64 __fastcall VBoxGuest_RTMpCpuIdFromSetIndex(unsigned int a1)
{
  __int64 result; // rax

  result = 0xFFFFFFFFLL;
  if ( a1 < nr_cpu_ids )
    return a1;
  return result;
}
