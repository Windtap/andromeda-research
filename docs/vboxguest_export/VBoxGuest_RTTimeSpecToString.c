__int64 __fastcall VBoxGuest_RTTimeSpecToString(
        __int64 *a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int *v12; // rax
  double v13; // xmm4_8
  double v14; // xmm5_8
  __int64 v16; // [rsp+0h] [rbp-28h] BYREF

  v12 = (unsigned int *)VBoxGuest_RTTimeExplode((__int64)&v16, a1);
  return VBoxGuest_RTTimeToString(v12, a2, a3, a4, a5, a6, a7, v13, v14, a10, a11);
}
