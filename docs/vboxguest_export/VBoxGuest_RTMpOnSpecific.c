__int64 __fastcall VBoxGuest_RTMpOnSpecific(unsigned int a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // rax
  __int64 v5; // r8
  __int64 v6; // r9
  unsigned int v7; // ebp
  __int64 v8; // [rsp+0h] [rbp-50h] BYREF
  _QWORD v9[3]; // [rsp+8h] [rbp-48h] BYREF
  unsigned int v10; // [rsp+20h] [rbp-30h]
  int v11; // [rsp+28h] [rbp-28h]

  result = 4294966495LL;
  v8 = 0xFFFFFFFFLL;
  v9[0] = a2;
  v9[1] = a3;
  v9[2] = a4;
  v10 = a1;
  v11 = 0;
  if ( a1 < nr_cpu_ids && _bittest64(cpu_possible_mask, a1) )
  {
    HIDWORD(v8) = 42;
    preempt_count_add(1);
    if ( a1 == (unsigned int)debug_smp_processor_id(1) )
    {
      rtmpLinuxWrapper((__int64)v9);
      VBoxGuest_RTThreadPreemptRestore((__int64)&v8);
      return 0;
    }
    else
    {
      v7 = -800;
      if ( a1 < nr_cpu_ids )
      {
        if ( _bittest64(cpu_online_mask, a1) )
        {
          ((void (__fastcall *)(_QWORD, __int64 (__fastcall *)(__int64), _QWORD *, __int64, __int64, __int64, __int64))smp_call_function_single)(
            a1,
            rtmpLinuxWrapper,
            v9,
            1,
            v5,
            v6,
            v8);
          v7 = v11 == 0 ? 0xFFFFFCE0 : 0;
        }
      }
      VBoxGuest_RTThreadPreemptRestore((__int64)&v8);
      return v7;
    }
  }
  return result;
}
