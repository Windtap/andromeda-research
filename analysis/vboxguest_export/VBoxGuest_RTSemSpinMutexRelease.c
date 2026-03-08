__int64 __fastcall VBoxGuest_RTSemSpinMutexRelease(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  signed __int64 v9; // rax
  __int64 result; // rax
  signed __int32 v11; // ebp
  int v12; // eax
  double v13; // xmm4_8
  double v14; // xmm5_8
  double v15; // xmm4_8
  double v16; // xmm5_8
  unsigned int v17; // [rsp+4h] [rbp-2Ch]
  unsigned __int64 v18; // [rsp+8h] [rbp-28h]
  __int64 v19; // [rsp+10h] [rbp-20h] BYREF
  __int64 v20; // [rsp+18h] [rbp-18h]

  v9 = VBoxGuest_RTThreadNativeSelf();
  if ( *(_DWORD *)a1 == 409403913 )
  {
    v18 = *(_QWORD *)(a1 + 32);
    v19 = *(_QWORD *)(a1 + 40);
    v20 = *(_QWORD *)(a1 + 48);
    if ( v9 == _InterlockedCompareExchange64((volatile signed __int64 *)(a1 + 8), -1, v9) )
    {
      v11 = _InterlockedExchangeAdd((volatile signed __int32 *)(a1 + 16), 0xFFFFFFFF);
      if ( BYTE1(v20) )
        __writeeflags(v18);
      VBoxGuest_RTThreadPreemptRestore(&v19);
      if ( v11 == 1 )
        return 0;
      v12 = VBoxGuest_RTSemEventSignal(*(_QWORD *)(a1 + 24));
      if ( v12 >= 0 )
      {
        return 0;
      }
      else
      {
        v17 = v12;
        VBoxGuest_RTAssertMsg1(
          (__int64)"RT_SUCCESS(rc)",
          0x1D4u,
          (__int64)"/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/r0drv/generic/semspinmutex-r0drv-generic.c",
          (__int64)"VBoxGuest_RTSemSpinMutexRelease",
          a2,
          a3,
          a4,
          a5,
          v13,
          v14,
          a8,
          a9);
        VBoxGuest_RTAssertMsg2Weak((__int64)"RTSemEventSignal -> %Rrc\n", a2, a3, a4, a5, v15, v16, a8, a9, v17);
        __debugbreak();
        return 0;
      }
    }
    else
    {
      return 4294966941LL;
    }
  }
  else
  {
    result = 4294966933LL;
    if ( *(_DWORD *)a1 != 420876809 )
      return 4294967292LL;
  }
  return result;
}
