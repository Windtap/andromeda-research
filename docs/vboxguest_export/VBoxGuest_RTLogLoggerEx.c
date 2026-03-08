__int64 VBoxGuest_RTLogLoggerEx(
        __int64 a1,
        int a2,
        unsigned int a3,
        _BYTE *a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        ...)
{
  gcc_va_list va; // [rsp+0h] [rbp-48h] BYREF

  va_start(va, a12);
  return VBoxGuest_RTLogLoggerExV(a1, a2, a3, a4, (__int64 *)va, a5, a6, a7, a8, a9, a10, a11, a12);
}
