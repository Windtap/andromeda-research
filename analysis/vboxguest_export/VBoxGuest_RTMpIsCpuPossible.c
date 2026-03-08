bool __fastcall VBoxGuest_RTMpIsCpuPossible(unsigned int a1)
{
  bool result; // al

  result = 0;
  if ( nr_cpu_ids > a1 )
    return _bittest64(cpu_possible_mask, a1) != 0;
  return result;
}
