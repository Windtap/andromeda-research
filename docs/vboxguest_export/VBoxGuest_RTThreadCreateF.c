__int64 VBoxGuest_RTThreadCreateF(
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
        ...)
{
  gcc_va_list va; // [rsp+10h] [rbp-48h] BYREF

  va_start(va, a15);
  return VBoxGuest_RTThreadCreateV(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14, a15, (__int64 *)va);
}
