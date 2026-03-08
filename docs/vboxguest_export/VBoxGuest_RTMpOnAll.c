__int64 __fastcall VBoxGuest_RTMpOnAll(
        void (__fastcall *a1)(_QWORD, __int64, __int64, __int64),
        __int64 a2,
        __int64 a3)
{
  unsigned int v3; // eax
  __int64 v4; // rcx
  signed __int32 *v5; // r9
  int v6; // esi
  unsigned int v7; // ebx
  unsigned __int64 v8; // rdx
  volatile signed __int32 *v9; // rdx
  int v10; // ecx
  __int64 i; // rax
  __int64 v13; // rax
  volatile signed __int32 *v14; // rsi
  _DWORD v15[2]; // [rsp+0h] [rbp-148h] BYREF
  void (__fastcall *v16)(_QWORD, __int64, __int64, __int64); // [rsp+8h] [rbp-140h] BYREF
  __int64 v17; // [rsp+10h] [rbp-138h]
  __int64 v18; // [rsp+18h] [rbp-130h]
  int v19; // [rsp+20h] [rbp-128h]
  int v20; // [rsp+28h] [rbp-120h]
  volatile signed __int32 *v21; // [rsp+30h] [rbp-118h]
  signed __int32 v22[32]; // [rsp+38h] [rbp-110h] BYREF
  signed __int32 v23[36]; // [rsp+B8h] [rbp-90h] BYREF

  v16 = a1;
  v17 = a2;
  v18 = a3;
  v15[0] = -1;
  v19 = -1;
  v20 = 0;
  v15[1] = 42;
  preempt_count_add(1);
  VBoxGuest_RTMpGetOnlineSet(v22);
  v21 = v22;
  v3 = debug_smp_processor_id(v22);
  v5 = v22;
  v6 = 0;
  v7 = v3;
  do
  {
    v8 = *(_QWORD *)v5;
    if ( *(_QWORD *)v5 )
    {
      LODWORD(v4) = 64;
      do
      {
        v6 -= ((v8 & 1) == 0) - 1;
        v8 >>= 1;
        v4 = (unsigned int)(v4 - 1);
      }
      while ( (_DWORD)v4 );
    }
    v5 += 2;
  }
  while ( v5 != v23 );
  if ( v6 > 1 )
    smp_call_function(rtmpLinuxAllWrapper, &v16, 0, v4);
  v16(v7, v17, v18, v4);
  v9 = v21;
  if ( v7 <= 0x3FF && v7 < nr_cpu_ids )
  {
    _interlockedbittestandreset(v21, v7);
    v9 = v21;
  }
  v10 = 64000;
LABEL_12:
  for ( i = 0; i != 16; ++i )
  {
    if ( *(_QWORD *)&v9[2 * i] )
    {
      if ( v10 )
      {
        --v10;
      }
      else
      {
        VBoxGuest_RTMpGetOnlineSet(v23);
        v13 = 0;
        v14 = v21;
        do
        {
          _InterlockedAnd64((volatile signed __int64 *)&v14[v13], *(_QWORD *)&v23[v13]);
          v13 += 2;
        }
        while ( v13 != 32 );
        v9 = v21;
        v10 = 64000;
      }
      _mm_pause();
      goto LABEL_12;
    }
  }
  VBoxGuest_RTThreadPreemptRestore((__int64)v15);
  return 0;
}
