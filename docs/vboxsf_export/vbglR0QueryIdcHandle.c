__int64 __fastcall vbglR0QueryIdcHandle(_QWORD *a1)
{
  if ( g_vbgldata == 2 || (vbglR0QueryDriverInfo(), g_vbgldata == 2) )
  {
    *a1 = &algn_10484[84];
    return 0;
  }
  else
  {
    *a1 = 0;
    return 4294967244LL;
  }
}
