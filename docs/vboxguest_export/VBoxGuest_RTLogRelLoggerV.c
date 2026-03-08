__int64 __fastcall VBoxGuest_RTLogRelLoggerV(
        __int64 a1,
        int a2,
        unsigned int a3,
        _BYTE *a4,
        __int64 *a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 result; // rax

  if ( a1 )
    return VBoxGuest_RTLogLoggerExV(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
  a1 = g_pRelLogger;
  if ( g_pRelLogger )
    return VBoxGuest_RTLogLoggerExV(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13);
  return result;
}
