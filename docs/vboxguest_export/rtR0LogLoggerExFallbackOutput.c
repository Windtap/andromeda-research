__int64 __fastcall rtR0LogLoggerExFallbackOutput(unsigned int *a1, char *a2, size_t a3)
{
  size_t v3; // r12
  __int64 v5; // r14
  __int64 v6; // rax
  int v7; // r15d
  size_t v8; // rbx
  __int64 v9; // rcx

  v3 = a3;
  if ( a3 )
  {
    v5 = 0;
    while ( 1 )
    {
      v6 = *a1;
      v7 = 79 - v6;
      v8 = (unsigned int)(79 - v6);
      if ( v3 < v8 )
      {
        v7 = v3;
        v8 = v3;
      }
      memcpy((char *)a1 + v6 + 16, a2, v8);
      v5 += v8;
      v9 = *a1 + v7;
      v3 -= v8;
      *a1 = v9;
      if ( !v3 )
        break;
      *((_BYTE *)a1 + v9 + 16) = 0;
      a2 += v8;
      rtR0LogLoggerExFallbackFlush(a1);
    }
    return v5;
  }
  else
  {
    *((_BYTE *)a1 + *a1 + 16) = 0;
    rtR0LogLoggerExFallbackFlush(a1);
    return 0;
  }
}
