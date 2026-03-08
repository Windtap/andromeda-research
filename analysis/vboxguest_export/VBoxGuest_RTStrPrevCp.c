_BYTE *__fastcall VBoxGuest_RTStrPrevCp(unsigned __int64 a1, unsigned __int64 a2)
{
  _BYTE *result; // rax
  int v3; // ecx
  _BYTE *v4; // rsi
  unsigned int v5; // edx
  unsigned int v6; // esi
  int v7; // esi

  result = (_BYTE *)a1;
  if ( a1 < a2 )
  {
    result = (_BYTE *)(a2 - 1);
    if ( *(char *)(a2 - 1) < 0 )
    {
      result = (_BYTE *)a1;
      if ( (*(_BYTE *)(a2 - 1) & 0x40) == 0 && a1 < a2 - 1 )
      {
        v3 = *(unsigned __int8 *)(a2 - 2);
        result = (_BYTE *)(a2 - 2);
        v4 = (_BYTE *)(a2 - 7);
        v5 = -64;
        if ( (v3 & 0xC0) == 0x80 )
        {
          do
          {
            v5 >>= 1;
            if ( a1 >= (unsigned __int64)result || result == v4 )
              return (_BYTE *)a1;
            v3 = (unsigned __int8)*--result;
          }
          while ( (*result & 0xC0) == 0x80 );
          v6 = v5;
          v5 = (unsigned __int8)v5;
          v7 = v6 >> 1;
        }
        else
        {
          v5 = 192;
          v7 = 2147483616;
        }
        if ( v5 != (v7 & v3) )
          return (_BYTE *)a1;
      }
    }
  }
  return result;
}
