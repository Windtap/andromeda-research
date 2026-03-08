__int64 __fastcall rtmpLinuxWrapper(__int64 a1)
{
  __int64 v1; // rbx
  __int64 (__fastcall *v2)(_QWORD, __int64, __int64); // r12
  __int64 v3; // rbp
  unsigned int v4; // eax

  _InterlockedExchangeAdd((volatile signed __int32 *)(a1 + 32), 1u);
  v1 = *(_QWORD *)(a1 + 8);
  v2 = *(__int64 (__fastcall **)(_QWORD, __int64, __int64))a1;
  v3 = *(_QWORD *)(a1 + 16);
  v4 = debug_smp_processor_id();
  return v2(v4, v1, v3);
}
