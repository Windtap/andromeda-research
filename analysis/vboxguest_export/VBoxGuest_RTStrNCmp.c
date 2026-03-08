int __fastcall VBoxGuest_RTStrNCmp(const char *a1, const char *a2, size_t a3)
{
  if ( a1 == a2 )
    return 0;
  if ( !a1 )
    return -1;
  if ( a2 )
    return strncmp(a1, a2, a3);
  return 1;
}
