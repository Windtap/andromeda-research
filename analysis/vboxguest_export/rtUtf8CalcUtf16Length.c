__int64 __fastcall rtUtf8CalcUtf16Length(unsigned __int8 *a1, _QWORD *a2)
{
  __int64 i; // rax
  __int16 v3; // dx
  bool v4; // zf
  unsigned int v5; // ecx
  __int64 v6; // rdx
  int v7; // ecx
  __int64 result; // rax
  unsigned __int8 v9; // r8
  unsigned __int8 v10; // cl
  unsigned __int8 v11; // si
  unsigned __int8 v12; // r9
  unsigned __int8 v13; // di
  unsigned __int8 v14; // r8
  unsigned __int8 v15; // cl
  unsigned __int8 v16; // si
  unsigned __int8 v17; // di

  for ( i = 0; ; ++i )
  {
    v3 = *a1;
    v4 = (_BYTE)v3 == 0;
    if ( (v3 & 0x80u) == 0 )
      break;
LABEL_5:
    if ( (v3 & 0xE0) == 0xC0 )
    {
      if ( (a1[1] & 0xC0) != 0x80 || (a1[1] & 0x3F | ((unsigned __int8)(v3 & 0x1F) << 6)) - 128 > 0x77Fu )
        return 4294967235LL;
      v6 = 2;
    }
    else if ( (v3 & 0xF0) == 0xE0 )
    {
      if ( (a1[1] & 0xC0) != 0x80 || (a1[2] & 0xC0) != 0x80 )
        return 4294967235LL;
      v7 = a1[2] & 0x3F | (unsigned __int16)(v3 << 12) | ((a1[1] & 0x3F) << 6);
      if ( (unsigned int)(v7 - 2048) > 0xF7FD )
        return (unsigned int)(v7 - 65534) < 2 ? -59 : -61;
      if ( (unsigned int)(v7 - 55296) <= 0x7FF )
        return 4294967236LL;
      v6 = 3;
    }
    else
    {
      if ( (v3 & 0xF8) != 0xF0 )
      {
        if ( (v3 & 0xFC) == 0xF8 )
        {
          v14 = a1[1];
          result = 4294967235LL;
          if ( (v14 & 0xC0) == 0x80 )
          {
            v15 = a1[2];
            if ( (v15 & 0xC0) == 0x80 )
            {
              v16 = a1[3];
              if ( (v16 & 0xC0) == 0x80 )
              {
                v17 = a1[4];
                if ( (v17 & 0xC0) == 0x80 )
                  return (((v14 & 0x3F) << 18)
                        | ((v15 & 0x3F) << 12)
                        | ((v16 & 0x3F) << 6)
                        | v17 & 0x3F
                        | ((unsigned __int8)(v3 & 3) << 24))
                       - 0x200000 < 0x3E00000u
                       ? -63
                       : -61;
              }
            }
          }
        }
        else
        {
          result = 4294967235LL;
          if ( (v3 & 0xFE) == 0xFC )
          {
            v9 = a1[1];
            if ( (v9 & 0xC0) == 0x80 )
            {
              v10 = a1[2];
              if ( (v10 & 0xC0) == 0x80 )
              {
                v11 = a1[3];
                if ( (v11 & 0xC0) == 0x80 )
                {
                  v12 = a1[4];
                  if ( (v12 & 0xC0) == 0x80 )
                  {
                    v13 = a1[5];
                    if ( (v13 & 0xC0) == 0x80 )
                      return (((v9 & 0x3F) << 24)
                            | ((v10 & 0x3F) << 18)
                            | ((v11 & 0x3F) << 12)
                            | ((v12 & 0x3F) << 6)
                            | v13 & 0x3F
                            | ((unsigned __int8)(v3 & 1) << 30))
                           - 0x4000000 < 0x7C000000u
                           ? -63
                           : -61;
                  }
                }
              }
            }
          }
        }
        return result;
      }
      if ( (a1[1] & 0xC0) != 0x80 )
        return 4294967235LL;
      if ( (a1[2] & 0xC0) != 0x80 )
        return 4294967235LL;
      if ( (a1[3] & 0xC0) != 0x80 )
        return 4294967235LL;
      v5 = ((v3 & 7) << 18) | a1[3] & 0x3F | ((a1[1] & 0x3F) << 12) | ((a1[2] & 0x3F) << 6);
      if ( v5 - 0x10000 > 0x1EFFFF )
        return 4294967235LL;
      if ( v5 > 0x10FFFF )
        return 4294967233LL;
      ++i;
      v6 = 4;
    }
    a1 += v6;
  }
  while ( !v4 )
  {
    v3 = *++a1;
    ++i;
    v4 = (_BYTE)v3 == 0;
    if ( (v3 & 0x80u) != 0 )
      goto LABEL_5;
  }
  *a2 = i;
  return 0;
}
