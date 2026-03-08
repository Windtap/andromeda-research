__int64 __fastcall VBoxGuest_RTStrATruncateTag(unsigned __int64 *a1, unsigned __int64 a2)
{
  unsigned __int64 v2; // rbx
  size_t v4; // r13
  _BYTE *v5; // rax
  _DWORD *v6; // rax
  _DWORD *s; // [rsp+0h] [rbp-38h]

  v2 = *a1;
  if ( !a2 )
  {
    if ( v2 )
    {
      if ( *(_BYTE *)v2 )
      {
        *(_BYTE *)v2 = 0;
        v6 = VBoxGuest_RTMemReallocTag((_DWORD *)v2, 1u);
        if ( v6 )
          goto LABEL_13;
      }
    }
    return 0;
  }
  if ( v2 + 0x200000 > 0x200FFF
    && ((v2 & 0xFF00000000000000LL) == 0 || (v2 & 0xFF00000000000000LL) == 0xFF00000000000000LL)
    && a2 <= 0xFFFFFFFFFFFFFFBELL )
  {
    v4 = a2 + 63;
    s = (_DWORD *)*a1;
    if ( a2 + 63 <= 0x7FFFFFFFFFFFFFF0LL )
    {
LABEL_17:
      v5 = memchr(s, 0, v4);
      if ( !v5 )
      {
        *(_BYTE *)(v2 + a2) = 0;
        v6 = VBoxGuest_RTMemReallocTag((_DWORD *)v2, a2 + 1);
        if ( v6 )
        {
LABEL_13:
          *a1 = (unsigned __int64)v6;
          return 0;
        }
        return 0;
      }
    }
    else
    {
      while ( 1 )
      {
        v5 = memchr(s, 0, 0x7FFFFFFFFFFFFFF0uLL);
        if ( v5 )
          break;
        s += 0x1FFFFFFFFFFFFFFCLL;
        v4 -= 0x7FFFFFFFFFFFFFF0LL;
        if ( v4 <= 0x7FFFFFFFFFFFFFF0LL )
          goto LABEL_17;
      }
    }
    if ( a2 <= (unsigned __int64)&v5[-v2] )
    {
      *(_BYTE *)(v2 + a2) = 0;
      return 0;
    }
  }
  return 4294967242LL;
}
