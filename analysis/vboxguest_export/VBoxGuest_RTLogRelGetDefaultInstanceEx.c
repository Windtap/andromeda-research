__int64 __fastcall VBoxGuest_RTLogRelGetDefaultInstanceEx(unsigned int a1)
{
  __int64 result; // rax
  unsigned int v2; // edx

  result = g_pRelLogger;
  if ( g_pRelLogger )
  {
    if ( (*(_DWORD *)(g_pRelLogger + 49160) & 1) != 0 )
    {
      return 0;
    }
    else
    {
      v2 = HIWORD(a1);
      if ( HIWORD(a1) != 0xFFFF )
      {
        if ( v2 >= *(_DWORD *)(g_pRelLogger + 49184) )
          v2 = 0;
        if ( (((unsigned __int16)a1 | 1) & (unsigned __int16)*(_DWORD *)(g_pRelLogger + 4LL * (int)v2 + 49188)) != ((unsigned __int16)a1 | 1) )
          return 0;
      }
    }
  }
  return result;
}
