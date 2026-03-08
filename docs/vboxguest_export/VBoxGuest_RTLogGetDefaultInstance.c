__int64 VBoxGuest_RTLogGetDefaultInstance()
{
  __int64 v1; // rax
  int v2; // edx

  if ( !g_cPerThreadLoggers )
    return g_pLogger;
  v1 = VBoxGuest_RTThreadNativeSelf();
  v2 = 7;
  while ( v1 != g_aPerThreadLoggers[3 * v2] )
  {
    if ( --v2 == -1 )
      return g_pLogger;
  }
  return qword_303D0[3 * v2];
}
