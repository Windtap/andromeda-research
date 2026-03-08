_BYTE *__fastcall VBoxGuest_RTStrDupNTag(char *s, size_t n)
{
  size_t v2; // r14
  char *v3; // r12
  size_t i; // rbx
  _BYTE *v5; // rax
  _BYTE *v6; // rax
  _BYTE *v7; // rcx

  v2 = n;
  v3 = s;
  for ( i = n; v2 > 0x7FFFFFFFFFFFFFF0LL; v3 += 0x7FFFFFFFFFFFFFF0LL )
  {
    v5 = memchr(v3, 0, 0x7FFFFFFFFFFFFFF0uLL);
    if ( v5 )
      goto LABEL_3;
    v2 -= 0x7FFFFFFFFFFFFFF0LL;
  }
  v5 = memchr(v3, 0, v2);
  if ( v5 )
LABEL_3:
    i = v5 - s;
  v6 = (_BYTE *)VBoxGuest_RTMemAllocTag(i + 1);
  v7 = v6;
  if ( v6 )
  {
    v7 = memcpy(v6, s, i);
    v7[i] = 0;
  }
  return v7;
}
