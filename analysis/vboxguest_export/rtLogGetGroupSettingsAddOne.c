__int64 __fastcall rtLogGetGroupSettingsAddOne(
        const char *src,
        unsigned int a2,
        void **a3,
        unsigned __int64 *a4,
        _BYTE *a5)
{
  size_t v8; // r12
  unsigned __int64 v9; // rax
  int v10; // eax
  _WORD *v12; // rax

  v8 = strlen(src);
  if ( v8 + (unsigned __int8)*a5 + 1 > *a4 )
    return 4294967255LL;
  if ( *a5 )
  {
    *(_BYTE *)*a3 = 32;
    *a3 = (char *)*a3 + 1;
    --*a4;
  }
  else
  {
    *a5 = 1;
  }
  memcpy(*a3, src, v8);
  *a3 = (char *)*a3 + v8;
  v9 = *a4 - v8;
  *a4 = v9;
  if ( a2 == 17 )
    return 0;
  if ( a2 != 51 )
  {
    if ( a2 != 19 )
    {
      if ( v9 > 0xB )
      {
        *(_BYTE *)*a3 = 61;
        *a3 = (char *)*a3 + 1;
        --*a4;
        v10 = VBoxGuest_RTStrFormatNumber((char *)*a3, a2, 0x10u, 0, 0, 8200);
        *a3 = (char *)*a3 + v10;
        *a4 -= v10;
        return 0;
      }
      return 4294967255LL;
    }
    if ( v9 > 4 )
    {
      *(_DWORD *)*a3 = 1714316590;
      *a3 = (char *)*a3 + 4;
      *a4 -= 4LL;
      return 0;
    }
    return 4294967255LL;
  }
  if ( v9 <= 6 )
    return 4294967255LL;
  v12 = *a3;
  *(_DWORD *)v12 = 1814979886;
  v12[2] = 26158;
  *a3 = (char *)*a3 + 6;
  *a4 -= 6LL;
  return 0;
}
