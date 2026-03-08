__int64 __fastcall VBoxGuest_RTThreadCreate(
        __int64 *a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        int a5,
        int a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        char *s)
{
  bool v17; // cc
  __int64 result; // rax
  _DWORD *v19; // rax
  double v20; // xmm4_8
  double v21; // xmm5_8
  __int64 v22; // r14
  size_t v23; // rax
  size_t v24; // r8
  int v25; // ebp
  double v26; // xmm4_8
  double v27; // xmm5_8
  size_t v30; // [rsp+10h] [rbp-40h]
  unsigned __int64 v31[7]; // [rsp+18h] [rbp-38h] BYREF

  if ( (unsigned __int64)(a1 + 0x40000) > 0x200FFF
    && (((unsigned __int64)a1 & 0xFF00000000000000LL) == 0
     || ((unsigned __int64)a1 & 0xFF00000000000000LL) == 0xFF00000000000000LL)
    || (result = 4294967294LL, !a1) )
  {
    if ( (unsigned __int64)(a2 + 0x200000) <= 0x200FFF
      || (a2 & 0xFF00000000000000LL) != 0 && (a2 & 0xFF00000000000000LL) != 0xFF00000000000000LL
      || !s
      || !*s )
    {
      return 4294967294LL;
    }
    v17 = strlen(s) <= 0xF;
    result = 4294967294LL;
    if ( v17 && (a6 & 0xFFFFFFF8) == 0 )
    {
      v19 = VBoxGuest_RTMemAllocZTag(120);
      v22 = (__int64)v19;
      if ( v19 )
      {
        *(_QWORD *)v19 = 0;
        v19[8] = 410256681;
        v23 = strlen(s);
        v24 = 15;
        if ( v23 <= 0xF )
          v24 = v23;
        v30 = v24;
        memcpy((void *)(v22 + 104), s, v24);
        *(_BYTE *)(v22 + v30 + 104) = 0;
        *(_DWORD *)(v22 + 36) = 3 - ((a6 & 1) == 0);
        *(_DWORD *)(v22 + 76) = -51;
        *(_DWORD *)(v22 + 40) = 1;
        *(_DWORD *)(v22 + 64) = a5;
        *(_DWORD *)(v22 + 68) = a6;
        *(_DWORD *)(v22 + 72) = 0;
        *(_BYTE *)(v22 + 44) = 0;
        if ( (int)VBoxGuest_RTSemEventMultiCreate(v22 + 48) >= 0 )
        {
          if ( (int)VBoxGuest_RTSemEventMultiCreate(v22 + 56) >= 0 )
          {
            *(_QWORD *)(v22 + 80) = a2;
            *(_QWORD *)(v22 + 88) = a3;
            *(_QWORD *)(v22 + 96) = a4;
            v25 = rtThreadNativeCreate(v22, v31);
            if ( v25 >= 0 )
            {
              rtThreadInsert(v22, v31[0], a7, a8, a9, a10, v20, v21, a13, a14);
              if ( *(_DWORD *)(v22 + 36) )
                rtThreadRelease_part_26(v22);
              if ( a1 )
                *a1 = v22;
              return 0;
            }
            *(_DWORD *)(v22 + 36) = 1;
            if ( *(_DWORD *)(v22 + 36) )
              rtThreadRelease_part_26(v22);
LABEL_29:
            VBoxGuest_RTAssertMsg1(
              (__int64)"RT_SUCCESS_NP(rc)",
              0x336u,
              (__int64)"/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/common/misc/thread.c",
              (__int64)"VBoxGuest_RTThreadCreate",
              a7,
              a8,
              a9,
              a10,
              v20,
              v21,
              a13,
              a14);
            VBoxGuest_RTAssertMsg2Weak((__int64)"%Rra\n", a7, a8, a9, a10, v26, v27, a13, a14, (unsigned int)v25);
            __debugbreak();
            return (unsigned int)v25;
          }
          VBoxGuest_RTSemEventMultiDestroy(*(_QWORD *)(v22 + 48));
        }
        VBoxGuest_RTMemFree(v22);
      }
      v25 = -20;
      goto LABEL_29;
    }
  }
  return result;
}
