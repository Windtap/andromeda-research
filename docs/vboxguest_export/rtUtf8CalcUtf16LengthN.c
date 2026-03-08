__int64 __fastcall rtUtf8CalcUtf16LengthN(unsigned __int8 *a1, unsigned __int64 a2, _QWORD *a3)
{
  __int64 i; // rcx
  __int16 v4; // ax
  __int64 v6; // r11
  unsigned int v7; // r9d
  unsigned __int8 v8; // r8
  int v9; // r8d
  unsigned int v10; // r9d

  for ( i = 0; ; ++i )
  {
    if ( !a2 )
    {
LABEL_6:
      *a3 = i;
      return 0;
    }
    while ( 1 )
    {
      v4 = *a1;
      if ( (v4 & 0x80u) != 0 )
        break;
      if ( (_BYTE)v4 )
      {
        --a2;
        ++i;
        ++a1;
        if ( a2 )
          continue;
      }
      goto LABEL_6;
    }
    if ( (v4 & 0xE0) == 0xC0 )
    {
      if ( a2 <= 1 )
        return 4294967235LL;
      v6 = 2;
      v7 = 2;
    }
    else
    {
      if ( (v4 & 0xF0) == 0xE0 )
      {
        if ( a2 <= 2 )
          return 4294967235LL;
        v6 = 3;
        v7 = 3;
      }
      else
      {
        if ( (v4 & 0xF8) == 0xF0 )
        {
          if ( a2 <= 3 )
            return 4294967235LL;
          v6 = 4;
          v7 = 4;
        }
        else
        {
          if ( (v4 & 0xFC) == 0xF8 )
          {
            if ( a2 <= 4 )
              return 4294967235LL;
            v6 = 5;
            v7 = 5;
          }
          else
          {
            if ( (v4 & 0xFE) != 0xFC || a2 <= 5 || (a1[5] & 0xC0) != 0x80 )
              return 4294967235LL;
            v6 = 6;
            v7 = 6;
          }
          if ( (a1[4] & 0xC0) != 0x80 )
            return 4294967235LL;
        }
        if ( (a1[3] & 0xC0) != 0x80 )
          return 4294967235LL;
      }
      if ( (a1[2] & 0xC0) != 0x80 )
        return 4294967235LL;
    }
    v8 = a1[1];
    if ( (v8 & 0xC0) != 0x80 )
      return 4294967235LL;
    if ( v7 == 4 )
    {
      v10 = ((v4 & 7) << 18) | a1[3] & 0x3F | ((v8 & 0x3F) << 12) | ((a1[2] & 0x3F) << 6);
      if ( v10 - 0x10000 > 0x1EFFFF )
        return 4294967235LL;
      if ( v10 > 0x10FFFF )
        return 4294967233LL;
      ++i;
      goto LABEL_26;
    }
    if ( v7 > 4 )
      break;
    if ( v7 == 3 )
    {
      v9 = a1[2] & 0x3F | (unsigned __int16)(v4 << 12) | ((v8 & 0x3F) << 6);
      if ( (unsigned int)(v9 - 2048) > 0xF7FD )
        return (unsigned int)(v9 - 65534) < 2 ? -59 : -61;
      if ( (unsigned int)(v9 - 55296) <= 0x7FF )
        return 4294967236LL;
    }
    else if ( (v8 & 0x3F | ((unsigned __int8)(v4 & 0x1F) << 6)) - 128 > 0x77Fu )
    {
      return 4294967235LL;
    }
LABEL_26:
    a2 -= v6;
    a1 += v6;
  }
  if ( v7 == 5 )
    return (((a1[2] & 0x3F) << 12)
          | ((a1[3] & 0x3F) << 6)
          | ((v4 & 3) << 24)
          | a1[4] & 0x3F
          | ((unsigned __int8)(v8 & 0x3F) << 18))
         - 0x200000 < 0x3E00000u
         ? -63
         : -61;
  else
    return (((a1[2] & 0x3F) << 18)
          | ((a1[3] & 0x3F) << 12)
          | ((a1[4] & 0x3F) << 6)
          | ((v4 & 1) << 30)
          | a1[5] & 0x3F
          | ((unsigned __int8)(v8 & 0x3F) << 24))
         - 0x4000000 < 0x7C000000u
         ? -63
         : -61;
}
