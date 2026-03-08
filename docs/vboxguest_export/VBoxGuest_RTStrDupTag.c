void *__fastcall VBoxGuest_RTStrDupTag(const char *src)
{
  size_t v1; // rbp
  void *v2; // rax
  void *v3; // rcx

  v1 = strlen(src) + 1;
  v2 = (void *)VBoxGuest_RTMemAllocTag(v1);
  v3 = v2;
  if ( v2 )
    return memcpy(v2, src, v1);
  return v3;
}
