void *__fastcall VBoxGuest_RTMemDupTag(void *src, size_t n)
{
  void *v2; // rax
  void *v3; // rcx

  v2 = (void *)VBoxGuest_RTMemAllocTag(n);
  v3 = v2;
  if ( v2 )
    return memcpy(v2, src, n);
  return v3;
}
