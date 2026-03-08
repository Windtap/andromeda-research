__int64 __fastcall VBoxGuest_RTLogGetDefaultInstanceEx(unsigned int a1)
{
  __int64 result; // rax
  int v2; // ecx
  int v3; // edx
  unsigned int v4; // edi
  __int64 v5; // rax
  int v6; // edx

  if ( g_cPerThreadLoggers )
  {
    v5 = VBoxGuest_RTThreadNativeSelf();
    v6 = 7;
    while ( v5 != g_aPerThreadLoggers[3 * v6] )
    {
      if ( --v6 == -1 )
        goto LABEL_2;
    }
    result = qword_303D0[3 * v6];
  }
  else
  {
LABEL_2:
    result = g_pLogger;
  }
  if ( result )
  {
    v2 = *(_DWORD *)(result + 49160) & 1;
    if ( v2 )
    {
      return 0;
    }
    else
    {
      v3 = (unsigned __int16)a1;
      v4 = HIWORD(a1);
      if ( (_WORD)v4 != 0xFFFF )
      {
        if ( v4 < *(_DWORD *)(result + 49184) )
          v2 = v4;
        if ( (v3 | 1) != ((v3 | 1) & *(_DWORD *)(result + 4LL * v2 + 49188)) )
          return 0;
      }
    }
  }
  return result;
}
