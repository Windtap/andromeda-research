__int64 __fastcall VBoxGuest_RTStrCopy(char *dest, size_t a2, const char *a3)
{
  size_t v4; // rax
  unsigned int v5; // r13d

  v4 = strlen(a3);
  if ( v4 >= a2 )
  {
    v5 = -41;
    if ( a2 )
    {
      memcpy(dest, a3, a2 - 1);
      dest[a2 - 1] = 0;
    }
  }
  else
  {
    memcpy(dest, a3, v4 + 1);
    return 0;
  }
  return v5;
}
