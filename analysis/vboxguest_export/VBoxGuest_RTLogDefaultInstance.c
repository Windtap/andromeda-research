__int64 VBoxGuest_RTLogDefaultInstance()
{
  __int64 result; // rax
  __int64 v1; // rax
  int v2; // edx

  if ( g_cPerThreadLoggers )
  {
    v1 = VBoxGuest_RTThreadNativeSelf();
    v2 = 7;
    while ( v1 != g_aPerThreadLoggers[3 * v2] )
    {
      if ( --v2 == -1 )
        goto LABEL_2;
    }
    return qword_303D0[3 * v2];
  }
  else
  {
LABEL_2:
    result = g_pLogger;
    if ( !g_pLogger )
    {
      result = VBoxGuest_RTLogDefaultInit();
      g_pLogger = result;
    }
  }
  return result;
}
