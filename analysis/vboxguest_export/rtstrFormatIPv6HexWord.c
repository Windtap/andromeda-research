__int64 __fastcall rtstrFormatIPv6HexWord(_BYTE *a1, unsigned __int16 a2)
{
  __int64 v2; // rdx
  __int64 v3; // rdx
  __int64 v4; // rax

  if ( (a2 & 0xFF00) != 0 )
  {
    v2 = 0;
    if ( (a2 & 0xF000) != 0 )
    {
      v2 = 1;
      *a1 = g_szHexDigits[(a2 >> 12) & 0xF];
    }
    v4 = v2 + 1;
    a1[v2] = g_szHexDigits[HIBYTE(a2) & 0xF];
    goto LABEL_7;
  }
  v3 = 0;
  if ( (a2 & 0xF0) != 0 )
  {
    v4 = 0;
LABEL_7:
    v3 = v4 + 1;
    a1[v4] = g_szHexDigits[(a2 >> 4) & 0xF];
  }
  a1[v3 + 1] = 0;
  a1[v3] = g_szHexDigits[a2 & 0xF];
  return v3 + 1;
}
