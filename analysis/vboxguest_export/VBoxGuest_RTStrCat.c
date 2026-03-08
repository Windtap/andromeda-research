__int64 __fastcall VBoxGuest_RTStrCat(char *s, size_t n, char *a3)
{
  size_t v3; // r15
  char *v4; // r14
  _BYTE *v6; // rax
  _BYTE *v7; // rbp
  size_t v8; // rax
  char *v9; // rbx
  unsigned int v10; // r13d

  v3 = n;
  v4 = s;
  if ( n <= 0x7FFFFFFFFFFFFFF0LL )
  {
LABEL_8:
    v7 = memchr(v4, 0, v3);
    if ( !v7 )
      return (unsigned int)-2;
  }
  else
  {
    while ( 1 )
    {
      v6 = memchr(v4, 0, 0x7FFFFFFFFFFFFFF0uLL);
      if ( v6 )
        break;
      v3 -= 0x7FFFFFFFFFFFFFF0LL;
      v4 += 0x7FFFFFFFFFFFFFF0LL;
      if ( v3 <= 0x7FFFFFFFFFFFFFF0LL )
        goto LABEL_8;
    }
    v7 = v6;
  }
  v8 = strlen(a3);
  v9 = (char *)(s - v7 + n);
  if ( (unsigned __int64)v9 <= v8 )
  {
    v10 = -41;
    if ( v9 )
    {
      memcpy(v7, a3, (size_t)(v9 - 1));
      s[n - 1] = 0;
    }
  }
  else
  {
    memcpy(v7, a3, v8 + 1);
    return 0;
  }
  return v10;
}
