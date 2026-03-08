__int64 VBoxGuest_RTLogPrintf(
        _BYTE *a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        ...)
{
  gcc_va_list va; // [rsp+0h] [rbp-48h] BYREF

  va_start(va, a9);
  return VBoxGuest_RTLogLoggerExV(0, 0, 0xFFFFFFFF, a1, (__int64 *)va, a2, a3, a4, a5, a6, a7, a8, a9);
}
