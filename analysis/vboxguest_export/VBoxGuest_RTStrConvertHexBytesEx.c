__int64 __fastcall VBoxGuest_RTStrConvertHexBytesEx(
        unsigned __int64 a1,
        char *a2,
        __int64 a3,
        int a4,
        unsigned __int64 *a5,
        _QWORD *a6)
{
  char *v6; // rbx
  char v7; // bp
  char v8; // r10
  unsigned __int8 *v9; // r11
  __int64 result; // rax
  char v11; // al
  char *v12; // rcx
  unsigned __int8 *v13; // r11
  char v14; // r10
  char v15; // al

  if ( a6 )
    *a6 = 0;
  if ( a5 )
    *a5 = 0;
  if ( a1 + 0x200000 <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 4294967290LL;
  }
  if ( (a4 & 0xFFFFFFFE) != 0 )
    return 4294967283LL;
  if ( a4 )
  {
    v6 = a2;
    v7 = 1;
    while ( 1 )
    {
      while ( 1 )
      {
        while ( 1 )
        {
          v8 = g_auchDigits[*(unsigned __int8 *)a1];
          if ( (unsigned __int8)v8 <= 0xFu )
            break;
          v9 = (unsigned __int8 *)(a1 + 1);
          if ( v8 != -3 )
          {
            if ( !v7 )
            {
              v11 = g_auchDigits[*(unsigned __int8 *)a1];
              v12 = v6;
              goto LABEL_38;
            }
            if ( a3 )
            {
              v12 = v6 + 1;
              *v6 = 0;
              --a3;
              v11 = v8;
              goto LABEL_38;
            }
LABEL_14:
            if ( a6 )
              *a6 = v6 - a2;
            if ( a5 )
              *a5 = a1;
            return 4294967255LL;
          }
          if ( v7 )
          {
            if ( !a3 )
              goto LABEL_14;
            *v6 = 0;
            --a3;
            ++a1;
            ++v6;
          }
          else
          {
            ++a1;
            v7 = 1;
          }
        }
        v9 = (unsigned __int8 *)(a1 + 2);
        v11 = g_auchDigits[*(unsigned __int8 *)(a1 + 1)];
        if ( (unsigned __int8)v11 > 0xFu )
          break;
        if ( !a3 )
          goto LABEL_60;
        --a3;
        a1 += 2LL;
        ++v6;
        v7 = 0;
        *(v6 - 1) = v11 | (16 * v8);
      }
      if ( !v7 )
        break;
      if ( !a3 )
      {
LABEL_60:
        if ( a6 )
          *a6 = v6 - a2;
        if ( a5 )
        {
          *a5 = a1 + 1;
          return 4294967255LL;
        }
        return 4294967255LL;
      }
      v12 = v6 + 1;
      --a3;
      *v6 = v8;
      if ( v11 != -3 )
        goto LABEL_38;
      a1 += 2LL;
      ++v6;
    }
    if ( a6 )
      *a6 = v6 - a2;
    if ( a5 )
    {
      *a5 = a1;
      return 4294944894LL;
    }
    return 4294944894LL;
  }
  v11 = g_auchDigits[*(unsigned __int8 *)a1];
  if ( (unsigned __int8)v11 > 0xFu )
  {
    v9 = (unsigned __int8 *)(a1 + 1);
    v12 = a2;
LABEL_38:
    if ( a6 )
      *a6 = v12 - a2;
    if ( a5 )
      *a5 = (unsigned __int64)(v9 - 1);
    if ( v11 == -2 )
    {
      result = 0;
      if ( a3 )
        return a6 == 0 ? -22401 : 22401;
    }
    else if ( !a3 || a6 )
    {
      if ( v11 == -4 )
      {
        do
          v15 = g_auchDigits[*v9++];
        while ( v15 == -4 );
        return (unsigned int)(v15 != -2) + 76;
      }
      else
      {
        return 77;
      }
    }
    else
    {
      return 4294944895LL;
    }
    return result;
  }
  v13 = (unsigned __int8 *)(a1 + 2);
  v14 = g_auchDigits[*(unsigned __int8 *)(a1 + 1)];
  if ( (unsigned __int8)v14 > 0xFu )
  {
    v13 = (unsigned __int8 *)a1;
    v12 = a2;
LABEL_50:
    if ( a6 )
      *a6 = v12 - a2;
    if ( a5 )
      *a5 = (unsigned __int64)v13;
    return 4294944894LL;
  }
  if ( a3 )
  {
    v12 = a2;
    while ( 1 )
    {
      ++v12;
      --a3;
      *(v12 - 1) = v14 | (16 * v11);
      v11 = g_auchDigits[*v13];
      if ( (unsigned __int8)v11 > 0xFu )
        break;
      v14 = g_auchDigits[v13[1]];
      if ( (unsigned __int8)v14 > 0xFu )
        goto LABEL_50;
      if ( !a3 )
        goto LABEL_56;
      v13 += 2;
    }
    v9 = v13 + 1;
    goto LABEL_38;
  }
  v13 = (unsigned __int8 *)a1;
  v12 = a2;
LABEL_56:
  if ( a6 )
    *a6 = v12 - a2;
  if ( !a5 )
    return 4294967255LL;
  *a5 = (unsigned __int64)v13;
  return 4294967255LL;
}
