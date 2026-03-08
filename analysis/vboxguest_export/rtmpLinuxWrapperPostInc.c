__int64 __fastcall rtmpLinuxWrapperPostInc(__int64 a1)
{
  __int64 v1; // r12
  __int64 v2; // rbp
  void (__fastcall *v3)(_QWORD, __int64, __int64); // r13
  unsigned int v4; // eax

  v1 = *(_QWORD *)(a1 + 16);
  v2 = *(_QWORD *)(a1 + 8);
  v3 = *(void (__fastcall **)(_QWORD, __int64, __int64))a1;
  v4 = debug_smp_processor_id();
  v3(v4, v2, v1);
  return (unsigned int)_InterlockedExchangeAdd((volatile signed __int32 *)(a1 + 32), 1u);
}
