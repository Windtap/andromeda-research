__int64 __fastcall VBoxGuest_RTAssertMsg1(
        __int64 a1,
        unsigned int a2,
        __int64 a3,
        __int64 a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  double v14; // xmm4_8
  double v15; // xmm5_8
  __int64 result; // rax

  VBoxGuest_g_pszRTAssertExpr = a1;
  VBoxGuest_g_pszRTAssertFile = a3;
  VBoxGuest_g_pszRTAssertFunction = a4;
  VBoxGuest_g_u32RTAssertLine = a2;
  VBoxGuest_RTStrPrintf(
    (__int64)&VBoxGuest_g_szRTAssertMsg1,
    1024,
    (__int64)"\n!!Assertion Failed!!\nExpression: %s\nLocation  : %s(%d) %s\n",
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    a11,
    a12,
    a1,
    a3,
    a2,
    a4,
    a1,
    a3,
    a4);
  result = (unsigned __int8)g_fQuiet;
  if ( !g_fQuiet )
  {
    VBoxGuest_RTLogBackdoorPrintf(
      (__int64)"\n!!Assertion Failed!!\nExpression: %s\nLocation  : %s(%d) %s\n",
      a5,
      a6,
      a7,
      a8,
      v14,
      v15,
      a11,
      a12,
      a1,
      a3,
      a2,
      a4);
    return rtR0AssertNativeMsg1(a1, a2, a3, a4);
  }
  return result;
}
