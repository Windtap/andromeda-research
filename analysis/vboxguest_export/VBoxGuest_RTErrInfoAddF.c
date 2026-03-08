__int64 VBoxGuest_RTErrInfoAddF(
        __int64 a1,
        unsigned int a2,
        _BYTE *a3,
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
  gcc_va_list va; // [rsp+0h] [rbp-50h] BYREF

  va_start(va, a11);
  VBoxGuest_RTErrInfoAddV(a1, a2, a3, (__int64 *)va);
  return a2;
}
