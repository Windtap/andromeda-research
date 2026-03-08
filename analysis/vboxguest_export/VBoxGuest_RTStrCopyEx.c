__int64 __fastcall VBoxGuest_RTStrCopyEx(char *dest, size_t a2, char *a3, size_t a4)
{
  char *v5; // r13
  size_t v6; // rbx
  _BYTE *v7; // rax
  unsigned int v8; // ebx
  size_t n; // [rsp+0h] [rbp-38h]

  v5 = a3;
  v6 = a4;
  for ( n = a4; n > 0x7FFFFFFFFFFFFFF0LL; v5 += 0x7FFFFFFFFFFFFFF0LL )
  {
    v7 = memchr(v5, 0, 0x7FFFFFFFFFFFFFF0uLL);
    if ( v7 )
      goto LABEL_3;
    n -= 0x7FFFFFFFFFFFFFF0LL;
  }
  v7 = memchr(v5, 0, n);
  if ( v7 )
LABEL_3:
    v6 = v7 - a3;
  if ( v6 >= a2 )
  {
    v8 = -41;
    if ( a2 )
    {
      memcpy(dest, a3, a2 - 1);
      dest[a2 - 1] = 0;
    }
  }
  else
  {
    memcpy(dest, a3, v6);
    dest[v6] = 0;
    return 0;
  }
  return v8;
}
