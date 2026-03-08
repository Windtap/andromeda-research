__int64 __fastcall VBoxGuest_RTLogRelPrintfV(
        _BYTE *a1,
        __int64 *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 result; // rax

  result = g_pRelLogger;
  if ( g_pRelLogger )
    return VBoxGuest_RTLogLoggerExV(g_pRelLogger, 0, 0xFFFFFFFF, a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  return result;
}
