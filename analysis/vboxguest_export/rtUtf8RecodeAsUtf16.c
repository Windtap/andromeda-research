__int64 __fastcall rtUtf8RecodeAsUtf16(unsigned __int8 *a1, __int64 a2, _WORD *a3, __int64 a4)
{
  __int16 v4; // ax
  __int64 v5; // r8
  __int64 result; // rax
  int v7; // eax
  unsigned int v8; // eax
  unsigned __int8 v9; // cl
  unsigned __int8 v10; // cl
  __int16 v11; // ax

  while ( a2 )
  {
    v4 = *a1;
    if ( !(_BYTE)v4 )
      break;
    if ( !a4 )
      goto LABEL_14;
    v5 = a4 - 1;
    if ( (v4 & 0x80u) != 0 )
    {
      if ( (v4 & 0xE0) == 0xC0 )
      {
        v9 = a1[1];
        a1 += 2;
        a2 -= 2;
        *a3++ = ((v4 & 0x1F) << 6) | v9 & 0x3F;
        a4 = v5;
        continue;
      }
      if ( (v4 & 0xF0) == 0xE0 )
      {
        v10 = a1[2];
        a1 += 3;
        a2 -= 3;
        ++a3;
        v11 = ((*(a1 - 2) & 0x3F) << 6) | v10 & 0x3F | (v4 << 12);
        a4 = v5;
        *(a3 - 1) = v11;
        continue;
      }
      v7 = ((a1[1] & 0x3F) << 12) | ((a1[2] & 0x3F) << 6) | a1[3] & 0x3F | ((v4 & 7) << 18);
      if ( a4 != 1 )
      {
        v8 = v7 - (_DWORD)&loc_10000;
        a4 -= 2;
        a1 += 4;
        a2 -= 4;
        a3 += 2;
        *(a3 - 1) = v8 & 0x3FF | 0xDC00;
        *(a3 - 2) = (v8 >> 10) | 0xD800;
        continue;
      }
LABEL_14:
      result = 4294967255LL;
      goto LABEL_7;
    }
    --a2;
    *a3 = v4;
    ++a1;
    ++a3;
    --a4;
  }
  result = 0;
LABEL_7:
  *a3 = 0;
  return result;
}
