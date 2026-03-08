__int64 __fastcall VBoxGuest_RTStrAAppendNTag(const char **a1, const char *a2, size_t a3)
{
  __int64 result; // rax
  size_t v4; // rbx
  size_t v5; // r15
  const char *v6; // rax
  const char *v7; // rbp

  result = 0;
  v4 = a3;
  if ( a3 )
  {
    if ( a3 == -1 )
      v4 = strlen(a2);
    if ( *a1 )
      v5 = strlen(*a1);
    else
      v5 = 0;
    v6 = (const char *)VBoxGuest_RTMemReallocTag(*a1, v5 + v4 + 1);
    v7 = v6;
    if ( v6 )
    {
      memcpy((void *)&v6[v5], a2, v4);
      v7[v5 + v4] = 0;
      result = 0;
      *a1 = v7;
    }
    else
    {
      return 4294967232LL;
    }
  }
  return result;
}
