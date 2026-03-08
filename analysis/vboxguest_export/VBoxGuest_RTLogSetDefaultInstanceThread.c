__int64 __fastcall VBoxGuest_RTLogSetDefaultInstanceThread(__int64 a1, __int64 a2)
{
  signed __int64 v3; // r10
  int i; // edx
  int v5; // esi
  volatile signed __int64 *v6; // rcx
  int j; // edx
  __int64 v8; // r9
  volatile __int64 *v10; // rax
  int k; // edx

  v3 = VBoxGuest_RTThreadNativeSelf();
  if ( a1 )
  {
    if ( *(_DWORD *)(a1 + 49156) == 422056455 )
    {
      for ( i = 7; i != -1; --i )
      {
        if ( g_aPerThreadLoggers[3 * i] == v3 )
        {
          _InterlockedExchange64(&qword_303C8[3 * i], a2);
          qword_303D0[3 * i] = a1;
          return 0;
        }
      }
      if ( _InterlockedIncrement(&g_cPerThreadLoggers) > 8 )
      {
        _InterlockedExchangeAdd(&g_cPerThreadLoggers, 0xFFFFFFFF);
        return 4294967255LL;
      }
      else
      {
        v5 = 10;
        do
        {
          v6 = (volatile signed __int64 *)&unk_30468;
          for ( j = 7; j != -1; --j )
          {
            v8 = 3LL * j;
            if ( g_aPerThreadLoggers[v8] == -1 && _InterlockedCompareExchange64(v6, v3, -1) == -1 )
            {
              _InterlockedExchange64(&qword_303C8[v8], a2);
              _InterlockedExchange64(&g_aPerThreadLoggers[v8 + 2], a1);
              return 0;
            }
            v6 -= 3;
          }
          --v5;
        }
        while ( v5 );
        _InterlockedExchangeAdd(&g_cPerThreadLoggers, 0xFFFFFFFF);
        return 4294967071LL;
      }
    }
    else
    {
      return 4294967293LL;
    }
  }
  else
  {
    v10 = (volatile __int64 *)&unk_30470;
    for ( k = 7; k != -1; --k )
    {
      while ( g_aPerThreadLoggers[3 * k] != v3 && qword_303C8[3 * k] != a2 )
      {
        --k;
        v10 -= 3;
        if ( k == -1 )
          return 0;
      }
      _InterlockedExchange64(v10, 0);
      _InterlockedExchange64(v10 + 1, 0);
      _InterlockedExchange64(v10 - 1, -1);
      _InterlockedExchangeAdd(&g_cPerThreadLoggers, 0xFFFFFFFF);
      v10 -= 3;
    }
    return 0;
  }
}
