__int64 VBoxGuest_RTStrPrintf(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        ...)
{
  gcc_va_list va; // [rsp+0h] [rbp-48h] BYREF

  va_start(va, a11);
  return VBoxGuest_RTStrPrintfV(a1, a2, a3, (__int64 *)va);
}
