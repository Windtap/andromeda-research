__int64 __fastcall VBoxGuest_RTThreadCreateV(
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
        __int64 a15,
        __int64 *a16)
{
  double v18; // xmm4_8
  double v19; // xmm5_8
  char s[72]; // [rsp+10h] [rbp-48h] BYREF

  VBoxGuest_RTStrPrintfV((__int64)s, 32, a15, a16);
  return VBoxGuest_RTThreadCreate(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, v18, v19, a13, a14, s);
}
