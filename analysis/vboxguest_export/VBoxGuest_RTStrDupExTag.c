__int64 __fastcall VBoxGuest_RTStrDupExTag(void **a1, const char *a2)
{
  size_t v2; // rbp
  void *v3; // rax

  v2 = strlen(a2) + 1;
  v3 = (void *)VBoxGuest_RTMemAllocTag(v2);
  if ( !v3 )
    return 4294967288LL;
  *a1 = memcpy(v3, a2, v2);
  return 0;
}
