__int64 __fastcall rtmpLinuxAllWrapper(__int64 a1)
{
  signed __int32 *v1; // r12
  __int64 result; // rax
  unsigned int v3; // ebx

  v1 = *(signed __int32 **)(a1 + 40);
  result = debug_smp_processor_id();
  v3 = result;
  if ( (unsigned int)result <= 0x3FF && (unsigned int)result < nr_cpu_ids )
  {
    result = _bittest(v1, result);
    if ( (_BYTE)result )
    {
      result = (*(__int64 (__fastcall **)(_QWORD, _QWORD, _QWORD))a1)(v3, *(_QWORD *)(a1 + 8), *(_QWORD *)(a1 + 16));
      if ( v3 < nr_cpu_ids )
        _interlockedbittestandreset(v1, v3);
    }
  }
  return result;
}
