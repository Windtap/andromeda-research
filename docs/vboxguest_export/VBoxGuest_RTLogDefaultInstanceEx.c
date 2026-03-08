__int64 __fastcall VBoxGuest_RTLogDefaultInstanceEx(unsigned int a1)
{
  __int64 result; // rax
  unsigned int v2; // edx
  __int64 v3; // rax
  int v4; // edx

  if ( g_cPerThreadLoggers )
  {
    v3 = VBoxGuest_RTThreadNativeSelf();
    v4 = 7;
    while ( v3 != g_aPerThreadLoggers[3 * v4] )
    {
      if ( --v4 == -1 )
        goto LABEL_2;
    }
    result = qword_303D0[3 * v4];
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
  if ( result )
  {
    if ( (*(_DWORD *)(result + 49160) & 1) != 0 )
    {
      return 0;
    }
    else
    {
      v2 = HIWORD(a1);
      if ( HIWORD(a1) != 0xFFFF )
      {
        if ( v2 >= *(_DWORD *)(result + 49184) )
          v2 = 0;
        if ( (((unsigned __int16)a1 | 1) & (unsigned __int16)*(_DWORD *)(result + 4LL * (int)v2 + 49188)) != ((unsigned __int16)a1 | 1) )
          return 0;
      }
    }
  }
  return result;
}
