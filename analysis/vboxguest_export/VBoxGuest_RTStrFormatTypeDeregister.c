__int64 __fastcall VBoxGuest_RTStrFormatTypeDeregister(const char *a1)
{
  int v1; // ebx
  size_t v2; // r12
  int v3; // r15d
  int i; // r14d
  __int64 v5; // rdx
  size_t v6; // rbp
  char *v7; // r13
  char *v8; // rsi
  size_t v9; // rdx
  int v10; // eax
  unsigned int v12; // [rsp+Ch] [rbp-34h]

  v1 = 0;
  v2 = strlen(a1);
  v12 = g_cTypes - 1;
  v3 = g_cTypes - 1;
  for ( i = (g_cTypes - 1) / 2; ; i = v1 + (v3 - v1) / 2 )
  {
    v5 = (__int64)i << 6;
    v6 = (unsigned __int8)g_aTypes[v5];
    v7 = &g_aTypes[v5];
    v8 = &g_aTypes[v5 + 1];
    v9 = v6;
    if ( v2 <= v6 )
      v9 = v2;
    v10 = memcmp(a1, v8, v9);
    if ( v10 )
    {
      if ( v3 == v1 )
        return 4294967194LL;
      if ( v10 < 0 )
        goto LABEL_8;
      goto LABEL_12;
    }
    if ( v2 == v6 )
      break;
    if ( v2 < v6 )
    {
      if ( v3 == v1 )
        return 4294967194LL;
LABEL_8:
      v3 = i - 1;
      if ( i - 1 < v1 )
        return 4294967194LL;
      continue;
    }
    if ( v3 == v1 )
      return 4294967194LL;
LABEL_12:
    v1 = i + 1;
    if ( v3 < i + 1 )
      return 4294967194LL;
  }
  if ( i < 0 )
    return 4294967194LL;
  if ( (int)(v12 - i) > 0 )
    memmove(v7, &g_aTypes[64 * (__int64)(i + 1)], (__int64)(int)(v12 - i) << 6);
  memset(&g_aTypes[64 * (unsigned __int64)v12], 0, 0x40u);
  _InterlockedExchangeAdd(&g_cTypes, 0xFFFFFFFF);
  return 0;
}
