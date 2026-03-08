_BYTE *__fastcall VBoxGuest_RTStrPutCpInternal(_BYTE *a1, unsigned int a2)
{
  if ( a2 <= 0x7F )
  {
    *a1 = a2;
    return a1 + 1;
  }
  else if ( a2 <= 0x7FF )
  {
    a1[1] = a2 & 0x3F | 0x80;
    *a1 = (a2 >> 6) | 0xC0;
    return a1 + 2;
  }
  else if ( a2 <= 0xFFFF )
  {
    *a1 = (a2 >> 12) | 0xE0;
    a1[2] = a2 & 0x3F | 0x80;
    a1[1] = (a2 >> 6) & 0x3F | 0x80;
    return a1 + 3;
  }
  else if ( a2 <= 0x1FFFFF )
  {
    *a1 = (a2 >> 18) | 0xF0;
    a1[1] = (a2 >> 12) & 0x3F | 0x80;
    a1[3] = a2 & 0x3F | 0x80;
    a1[2] = (a2 >> 6) & 0x3F | 0x80;
    return a1 + 4;
  }
  else if ( a2 <= 0x3FFFFFF )
  {
    *a1 = HIBYTE(a2) | 0xF8;
    a1[1] = (a2 >> 18) & 0x3F | 0x80;
    a1[2] = (a2 >> 12) & 0x3F | 0x80;
    a1[4] = a2 & 0x3F | 0x80;
    a1[3] = (a2 >> 6) & 0x3F | 0x80;
    return a1 + 5;
  }
  else if ( (a2 & 0x80000000) != 0 )
  {
    *a1 = 127;
    return a1 + 1;
  }
  else
  {
    *a1 = (a2 >> 30) | 0xFC;
    a1[1] = HIBYTE(a2) & 0x3F | 0x80;
    a1[2] = (a2 >> 18) & 0x3F | 0x80;
    a1[3] = (a2 >> 12) & 0x3F | 0x80;
    a1[5] = a2 & 0x3F | 0x80;
    a1[4] = (a2 >> 6) & 0x3F | 0x80;
    return a1 + 6;
  }
}
