__int64 __fastcall VBoxGuest_RTMpOnOthers(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 v3; // rcx
  _DWORD v5[2]; // [rsp+0h] [rbp-38h] BYREF
  _QWORD v6[3]; // [rsp+8h] [rbp-30h] BYREF
  int v7; // [rsp+20h] [rbp-18h]
  int v8; // [rsp+28h] [rbp-10h]

  v6[0] = a1;
  v6[1] = a2;
  v6[2] = a3;
  v5[0] = -1;
  v7 = -1;
  v8 = 0;
  v5[1] = 42;
  preempt_count_add(1);
  smp_call_function(rtmpLinuxWrapper, v6, 1, v3);
  VBoxGuest_RTThreadPreemptRestore((__int64)v5);
  return 0;
}
