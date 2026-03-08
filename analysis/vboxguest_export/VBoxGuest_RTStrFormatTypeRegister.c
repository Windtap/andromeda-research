__int64 __fastcall VBoxGuest_RTStrFormatTypeRegister(const char *s1, __int64 a2, __int64 a3)
{
  size_t v3; // r15
  int v4; // r12d
  __int64 result; // rax
  char *v6; // rbx
  unsigned int v7; // r14d
  size_t v8; // r13
  size_t v9; // rdx
  int v10; // eax
  unsigned int v11; // r12d
  char *v12; // rsi
  __int64 v13; // rbx
  __int64 v14; // rbx
  char *v15; // [rsp+0h] [rbp-48h]

  v3 = strlen(s1);
  if ( v3 > 0x2E )
    return 4294967294LL;
  v4 = g_cTypes;
  result = 4294967190LL;
  if ( (unsigned int)g_cTypes <= 0x3F )
  {
    if ( !g_cTypes )
    {
      v15 = g_aTypes;
      v13 = 0;
      goto LABEL_15;
    }
    v6 = g_aTypes;
    v7 = 0;
    while ( 1 )
    {
      v8 = (unsigned __int8)*v6;
      v9 = v3;
      v15 = v6;
      if ( v8 <= v3 )
        v9 = (unsigned __int8)*v6;
      v10 = memcmp(s1, v6 + 1, v9);
      if ( v10 )
      {
        if ( v10 < 0 )
          goto LABEL_10;
      }
      else
      {
        if ( v3 == v8 )
          return 4294967191LL;
        if ( v3 < v8 )
        {
LABEL_10:
          v11 = v4 - v7;
          if ( v11 )
          {
            v12 = v6;
            v13 = v7;
            memmove(&g_aTypes[64 * (unsigned __int64)(v7 + 1)], v12, (unsigned __int64)v11 << 6);
          }
          else
          {
            v13 = v7;
          }
LABEL_15:
          v14 = v13 << 6;
          memset(v15, 0, 0x40u);
          memcpy(&g_aTypes[v14 + 1], s1, v3 + 1);
          g_aTypes[v14] = v3;
          *(__int64 *)((char *)&qword_32178 + v14) = a3;
          *(__int64 *)((char *)&qword_32170 + v14) = a2;
          _InterlockedExchangeAdd(&g_cTypes, 1u);
          return 0;
        }
      }
      ++v7;
      v6 += 64;
      if ( v7 == v4 )
      {
        v13 = v7;
        v15 = &g_aTypes[64 * (unsigned __int64)v7];
        goto LABEL_15;
      }
    }
  }
  return result;
}
