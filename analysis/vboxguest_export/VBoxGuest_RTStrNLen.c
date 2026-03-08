size_t __fastcall VBoxGuest_RTStrNLen(char *s, size_t n)
{
  size_t v2; // r13
  char *i; // r12
  _BYTE *v4; // rax

  v2 = n;
  for ( i = s; v2 > 0x7FFFFFFFFFFFFFF0LL; i += 0x7FFFFFFFFFFFFFF0LL )
  {
    v4 = memchr(i, 0, 0x7FFFFFFFFFFFFFF0uLL);
    if ( v4 )
      return v4 - s;
    v2 -= 0x7FFFFFFFFFFFFFF0LL;
  }
  v4 = memchr(i, 0, v2);
  if ( v4 )
    return v4 - s;
  return n;
}
