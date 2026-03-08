__int64 __fastcall rtThreadTerm(double a1, double a2, double a3, double a4, double a5, double a6, double a7, double a8)
{
  __int64 result; // rax
  double v9; // xmm4_8
  double v10; // xmm5_8

  result = VBoxGuest_RTSpinlockDestroy(g_ThreadSpinlock);
  g_ThreadSpinlock = 0;
  if ( g_ThreadTree )
    return VBoxGuest_RTAssertMsg2Weak((__int64)"WARNING: g_ThreadTree=%p\n", a1, a2, a3, a4, v9, v10, a7, a8);
  return result;
}
