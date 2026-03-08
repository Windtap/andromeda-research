__int64 __fastcall VbglR0QueryHostFeatures(_DWORD *a1)
{
  __int64 result; // rax

  if ( g_vbgldata == 2 || (result = vbglR0QueryDriverInfo(), g_vbgldata == 2) )
  {
    *a1 = *(_DWORD *)&algn_10484[80];
    return 0;
  }
  return result;
}
