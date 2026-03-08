__int64 __fastcall VBoxGuest_RTMpOnPair(unsigned int a1, unsigned int a2, char a3, __int64 a4, __int64 a5, __int64 a6)
{
  unsigned int v6; // ebx
  char v9; // dl
  __int64 result; // rax
  unsigned int v11; // ebx
  int v12; // eax
  bool v13; // r12
  bool v14; // r15
  __int16 i; // ax
  const signed __int64 *v17; // [rsp+8h] [rbp-78h]
  volatile signed __int32 *v18; // [rsp+10h] [rbp-70h] BYREF
  int v19; // [rsp+18h] [rbp-68h] BYREF
  int v20; // [rsp+1Ch] [rbp-64h]
  _QWORD v21[3]; // [rsp+20h] [rbp-60h] BYREF
  unsigned int v22; // [rsp+38h] [rbp-48h]
  unsigned int v23; // [rsp+3Ch] [rbp-44h]
  unsigned int v24; // [rsp+40h] [rbp-40h]

  v6 = a1;
  v19 = -1;
  v20 = 0;
  if ( a1 == a2 )
    return 4294967294LL;
  if ( (a3 & 1) != 0 )
    return 4294967283LL;
  v9 = zalloc_cpumask_var(&v18, 37748928);
  result = 4294967288LL;
  if ( v9 )
  {
    _interlockedbittestandset64(v18, a1);
    _interlockedbittestandset64(v18, a2);
    v20 = 42;
    preempt_count_add(1);
    if ( a1 < nr_cpu_ids && _bittest64(cpu_online_mask, a1) && a2 < nr_cpu_ids && _bittest64(cpu_online_mask, a2) )
    {
      v17 = (const signed __int64 *)cpu_online_mask;
      v12 = debug_smp_processor_id(1);
      v21[0] = a4;
      v13 = a1 == v12;
      v21[1] = a5;
      v14 = a1 == v12 || a2 == v12;
      v22 = a1;
      v23 = a2;
      v24 = 0;
      v21[2] = a6;
      smp_call_function_many(v18, rtmpLinuxWrapperPostInc, v21, !v14);
      if ( v14 )
      {
        rtmpLinuxWrapper((__int64)v21);
        _mm_mfence();
        if ( v24 <= 1 )
        {
          if ( v13 )
            v6 = a2;
          for ( i = 0; (i & 0x1FF) != 0 || v6 < nr_cpu_ids && _bittest64(v17, v6); ++i )
          {
            _mm_pause();
            _mm_mfence();
          }
        }
      }
      v11 = 0;
      if ( v24 != 2 )
      {
        v11 = -802;
        if ( v24 != 1 )
          v11 = v24 == 0 ? -800 : -803;
      }
    }
    else
    {
      v11 = -801;
      if ( (unsigned __int8)VBoxGuest_RTMpIsCpuPresent(a1) )
        v11 = -((unsigned __int8)VBoxGuest_RTMpIsCpuPresent(a2) == 0) - 800;
    }
    VBoxGuest_RTThreadPreemptRestore((__int64)&v19);
    free_cpumask_var(v18);
    return v11;
  }
  return result;
}
