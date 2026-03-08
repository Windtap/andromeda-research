__int64 __fastcall VBoxGuest_RTMpCpuIdToSetIndex(unsigned int a1)
{
  __int64 result; // rax

  result = 0xFFFFFFFFLL;
  if ( a1 <= 0x3FF && a1 < nr_cpu_ids )
    return a1;
  return result;
}
