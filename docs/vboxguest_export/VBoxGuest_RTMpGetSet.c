volatile signed __int32 *__fastcall VBoxGuest_RTMpGetSet(volatile signed __int32 *a1)
{
  volatile signed __int32 *result; // rax
  __int64 i; // rdx
  unsigned int v3; // ecx
  const signed __int64 *v4; // rsi
  unsigned int v5; // edx

  result = a1;
  for ( i = 0; i != 16; ++i )
    *(_QWORD *)&a1[2 * i] = 0;
  v3 = nr_cpu_ids;
  v4 = (const signed __int64 *)cpu_possible_mask;
  v5 = nr_cpu_ids - 1;
  while ( 1 )
  {
    if ( v5 < v3 && _bittest64(v4, v5) && v5 <= 0x3FF )
      _interlockedbittestandset(a1, v5);
    if ( --v5 == -1 )
      break;
    v3 = nr_cpu_ids;
  }
  return result;
}
