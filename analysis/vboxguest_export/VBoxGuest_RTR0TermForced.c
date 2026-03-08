__int64 __fastcall VBoxGuest_RTR0TermForced(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  _InterlockedExchange(&g_crtR0Users, 0);
  rtThreadTerm(a1, a2, a3, a4, a5, a6, a7, a8);
  return rtR0TermNative();
}
