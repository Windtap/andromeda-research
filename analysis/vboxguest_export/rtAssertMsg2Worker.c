__int64 __fastcall rtAssertMsg2Worker(unsigned __int8 a1, __int64 a2, __int64 *a3)
{
  __int64 result; // rax
  __int64 v5; // [rsp+0h] [rbp-38h] BYREF
  __int64 v6; // [rsp+8h] [rbp-30h]
  __int64 v7; // [rsp+10h] [rbp-28h]

  if ( a1 )
  {
    v5 = *a3;
    v6 = a3[1];
    v7 = a3[2];
    _InterlockedExchange(
      &g_cchRTAssertMsg2,
      VBoxGuest_RTStrPrintfV((__int64)&VBoxGuest_g_szRTAssertMsg2, 4096, a2, &v5));
  }
  else
  {
    _mm_mfence();
    if ( (unsigned int)g_cchRTAssertMsg2 <= 0xFFBuLL )
    {
      v5 = *a3;
      v6 = a3[1];
      v7 = a3[2];
      _InterlockedExchange(
        &g_cchRTAssertMsg2,
        VBoxGuest_RTStrPrintfV(
          (__int64)&VBoxGuest_g_szRTAssertMsg2 + (unsigned int)g_cchRTAssertMsg2,
          4096LL - (unsigned int)g_cchRTAssertMsg2,
          a2,
          &v5)
      + g_cchRTAssertMsg2);
    }
  }
  result = (unsigned __int8)g_fQuiet;
  if ( !g_fQuiet )
  {
    v5 = *a3;
    v6 = a3[1];
    v7 = a3[2];
    VBoxGuest_RTStrFormatV(
      (__int64 (*)(__int64, const char *, ...))rtLogBackdoorOutput,
      0,
      (__int64 (__fastcall *)(__int64, __int64 (*)(__int64, const char *, ...), __int64, char **, __int64 *, _QWORD, _DWORD, unsigned int, int))rtlogFormatStr,
      0,
      a2,
      &v5);
    return rtR0AssertNativeMsg2V(a1, a2, a3);
  }
  return result;
}
