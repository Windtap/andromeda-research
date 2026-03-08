char *__fastcall VBoxGuest_RTMemDupExTag(void *src, size_t n, size_t a3)
{
  char *v4; // rax
  char *v5; // rbx

  v4 = (char *)VBoxGuest_RTMemAllocTag(n + a3);
  v5 = v4;
  if ( v4 )
  {
    memcpy(v4, src, n);
    memset(&v5[n], 0, a3);
  }
  return v5;
}
