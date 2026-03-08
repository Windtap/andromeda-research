__int64 __fastcall VBoxGuest_RTLogRelSetBuffering(
        char a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  if ( g_pRelLogger )
    return VBoxGuest_RTLogSetBuffering(g_pRelLogger, a1, a2, a3, a4, a5, a6, a7, a8, a9);
  else
    return 0;
}
