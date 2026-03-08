__int64 __fastcall VBoxGuest_RTStrFormatTypeSetUser(const char *a1, __int64 a2)
{
  int v2; // ebp
  size_t v3; // r13
  int v4; // r15d
  int i; // r14d
  __int64 v6; // rbx
  size_t v7; // r12
  size_t v8; // rdx
  int v9; // eax

  v2 = 0;
  v3 = strlen(a1);
  v4 = g_cTypes - 1;
  for ( i = (g_cTypes - 1) / 2; ; i = v2 + (v4 - v2) / 2 )
  {
    v6 = (__int64)i << 6;
    v7 = (unsigned __int8)g_aTypes[v6];
    v8 = v7;
    if ( v3 <= v7 )
      v8 = v3;
    v9 = memcmp(a1, (char *)&unk_32141 + v6, v8);
    if ( v9 )
    {
      if ( v4 == v2 )
        return 4294967194LL;
      if ( v9 < 0 )
        goto LABEL_8;
      goto LABEL_12;
    }
    if ( v3 == v7 )
      break;
    if ( v3 < v7 )
    {
      if ( v4 == v2 )
        return 4294967194LL;
LABEL_8:
      v4 = i - 1;
      if ( i - 1 < v2 )
        return 4294967194LL;
      continue;
    }
    if ( v4 == v2 )
      return 4294967194LL;
LABEL_12:
    v2 = i + 1;
    if ( v4 < i + 1 )
      return 4294967194LL;
  }
  if ( i < 0 )
    return 4294967194LL;
  _InterlockedExchange64((__int64 *)((char *)&qword_32148 + v6 + 48), a2);
  return 0;
}
