__int64 VBoxGuest_RTAssertMsg2Weak(
        __int64 a1,
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
  return rtAssertMsg2Worker(1u, a1, (__int64 *)va);
}
