__int64 __fastcall rtUtf8Decode(unsigned __int8 *a1, __int64 a2, _DWORD *a3, __int64 a4)
{
  int v4; // eax
  _DWORD *v5; // r8
  unsigned __int8 v6; // r9
  __int64 result; // rax
  unsigned __int8 v8; // r9
  unsigned __int8 v9; // r9
  unsigned __int8 v10; // r9
  int v11; // eax
  int v12; // r9d
  unsigned __int8 v13; // r9

  if ( a2 && (v4 = *a1, (_BYTE)v4) )
  {
    if ( a4 )
    {
      v5 = a3 + 1;
      do
      {
        --a4;
        a3 = v5;
        if ( (v4 & 0x80u) == 0 )
        {
          *(v5 - 1) = v4;
          ++a1;
          --a2;
        }
        else
        {
          if ( (v4 & 0x20) == 0 )
          {
            v6 = a1[1];
            a2 -= 2;
            a1 += 2;
            *(v5 - 1) = v6 & 0x3F | ((v4 & 0x1F) << 6);
            if ( !a2 )
              goto LABEL_12;
            goto LABEL_7;
          }
          if ( (v4 & 0x10) != 0 )
          {
            if ( (v4 & 8) != 0 )
            {
              if ( (v4 & 4) != 0 )
              {
                v13 = a1[5];
                a1 += 6;
                a2 -= 6;
                v11 = ((*(a1 - 4) & 0x3F) << 18)
                    | ((*(a1 - 3) & 0x3F) << 12)
                    | ((*(a1 - 2) & 0x3F) << 6)
                    | v13 & 0x3F
                    | ((v4 & 1) << 30);
                v12 = (*(a1 - 5) & 0x3F) << 24;
              }
              else
              {
                v10 = a1[4];
                a1 += 5;
                a2 -= 6;
                v11 = ((*(a1 - 3) & 0x3F) << 12) | ((*(a1 - 2) & 0x3F) << 6) | v10 & 0x3F | ((v4 & 3) << 24);
                v12 = (*(a1 - 4) & 0x3F) << 18;
              }
              *(v5 - 1) = v12 | v11;
            }
            else
            {
              v9 = a1[3];
              a1 += 4;
              a2 -= 4;
              *(v5 - 1) = ((*(a1 - 3) & 0x3F) << 12) | ((*(a1 - 2) & 0x3F) << 6) | v9 & 0x3F | ((v4 & 7) << 18);
            }
          }
          else
          {
            v8 = a1[2];
            a1 += 3;
            a2 -= 3;
            *(v5 - 1) = ((*(a1 - 2) & 0x3F) << 6) | v8 & 0x3F | (unsigned __int16)((_WORD)v4 << 12);
          }
        }
        if ( !a2 )
          goto LABEL_12;
LABEL_7:
        v4 = *a1;
        if ( !(_BYTE)v4 )
          goto LABEL_12;
        ++v5;
      }
      while ( a4 );
    }
    result = 4294967255LL;
  }
  else
  {
LABEL_12:
    result = 0;
  }
  *a3 = 0;
  return result;
}
