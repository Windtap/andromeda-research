__int64 __fastcall rtUtf8Length(unsigned __int8 *a1, unsigned __int64 a2, _QWORD *a3, _QWORD *a4)
{
  __int16 v4; // r8
  __int64 v5; // r9
  unsigned __int8 *i; // rax
  __int64 v7; // rbx
  unsigned int v8; // r11d
  unsigned __int8 v9; // r10
  int v11; // r8d

  if ( a2 )
  {
    v4 = *a1;
    v5 = 0;
    for ( i = a1; (_BYTE)v4; v4 = *i )
    {
      if ( (v4 & 0x80u) == 0 )
      {
        --a2;
        ++i;
        ++v5;
        if ( !a2 )
          break;
      }
      else
      {
        if ( (v4 & 0xE0) == 0xC0 )
        {
          if ( a2 <= 1 )
            return 4294967235LL;
          v7 = 2;
          v8 = 2;
        }
        else
        {
          if ( (v4 & 0xF0) == 0xE0 )
          {
            if ( a2 <= 2 )
              return 4294967235LL;
            v7 = 3;
            v8 = 3;
          }
          else
          {
            if ( (v4 & 0xF8) == 0xF0 )
            {
              if ( a2 <= 3 )
                return 4294967235LL;
              v7 = 4;
              v8 = 4;
            }
            else
            {
              if ( (v4 & 0xFC) == 0xF8 )
              {
                if ( a2 <= 4 )
                  return 4294967235LL;
                v7 = 5;
                v8 = 5;
              }
              else
              {
                if ( (v4 & 0xFE) != 0xFC || a2 <= 5 || (i[5] & 0xC0) != 0x80 )
                  return 4294967235LL;
                v7 = 6;
                v8 = 6;
              }
              if ( (i[4] & 0xC0) != 0x80 )
                return 4294967235LL;
            }
            if ( (i[3] & 0xC0) != 0x80 )
              return 4294967235LL;
          }
          if ( (i[2] & 0xC0) != 0x80 )
            return 4294967235LL;
        }
        v9 = i[1];
        if ( (v9 & 0xC0) != 0x80 )
          return 4294967235LL;
        if ( v8 == 4 )
        {
          if ( (((v9 & 0x3F) << 12) | ((i[2] & 0x3F) << 6) | i[3] & 0x3F | ((unsigned __int8)(v4 & 7) << 18))
             - (int)&loc_10000 > 0x1EFFFFu )
            return 4294967235LL;
        }
        else if ( v8 <= 4 )
        {
          if ( v8 == 3 )
          {
            v11 = ((v9 & 0x3F) << 6) | i[2] & 0x3F | (unsigned __int16)(v4 << 12);
            if ( (unsigned int)(v11 - 2048) > 0xF7FD )
              return (unsigned int)(v11 - 65534) < 2 ? -59 : -61;
            if ( (unsigned int)(v11 - 55296) <= 0x7FF )
              return 4294967236LL;
          }
          else if ( (v9 & 0x3F | ((unsigned __int8)(v4 & 0x1F) << 6)) - 128 > 0x77Fu )
          {
            return 4294967235LL;
          }
        }
        else if ( v8 == 5 )
        {
          if ( (((v9 & 0x3F) << 18)
              | ((i[2] & 0x3F) << 12)
              | ((i[3] & 0x3F) << 6)
              | i[4] & 0x3F
              | ((unsigned __int8)(v4 & 3) << 24))
             - 0x200000 > 0x3DFFFFFu )
            return 4294967235LL;
        }
        else if ( (((v9 & 0x3F) << 24)
                 | ((i[2] & 0x3F) << 18)
                 | ((i[3] & 0x3F) << 12)
                 | ((i[4] & 0x3F) << 6)
                 | i[5] & 0x3F
                 | ((unsigned __int8)(v4 & 1) << 30))
                - 0x4000000 > 0x7BFFFFFFu )
        {
          return 4294967235LL;
        }
        a2 -= v7;
        i += v7;
        ++v5;
        if ( !a2 )
          break;
      }
    }
  }
  else
  {
    i = a1;
    v5 = 0;
  }
  *a3 = v5;
  if ( a4 )
    *a4 = i - a1;
  return 0;
}
