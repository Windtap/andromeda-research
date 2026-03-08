__int64 __fastcall VBoxGuest_RTStrToInt64Ex(unsigned __int8 *a1, unsigned __int8 **a2, unsigned int a3, __int64 *a4)
{
  char v5; // bl
  __int64 v6; // rax
  __int64 v7; // r12
  char v8; // cl
  __int64 v9; // r10
  unsigned __int8 *v10; // r8
  unsigned __int64 v11; // r9
  __int64 result; // rax
  __int64 v13; // r9
  __int64 v14; // r11
  unsigned __int8 v15; // dl
  char v16; // al
  unsigned __int8 v17; // dl

  v5 = 1;
  while ( 1 )
  {
    v6 = *a1;
    if ( (_BYTE)v6 != 43 )
      break;
    v5 = 1;
LABEL_4:
    ++a1;
  }
  if ( (_BYTE)v6 == 45 )
  {
    v5 ^= 1u;
    goto LABEL_4;
  }
  if ( a3 )
  {
    if ( a3 != 16 || (_BYTE)v6 != 48 )
      goto LABEL_9;
    if ( (a1[1] & 0xDF) == 0x58 )
    {
      v6 = a1[2];
      if ( (unsigned __int8)g_auchDigits[(unsigned __int8)v6] <= 0xFu )
      {
        a1 += 2;
        goto LABEL_9;
      }
    }
    goto LABEL_48;
  }
  a3 = 10;
  if ( (_BYTE)v6 == 48 )
  {
    v17 = a1[1];
    if ( (v17 & 0xDF) == 0x58 )
    {
      v6 = a1[2];
      if ( (unsigned __int8)g_auchDigits[(unsigned __int8)v6] <= 0xFu )
      {
        a1 += 2;
        a3 = 16;
        goto LABEL_9;
      }
    }
    v6 = v17;
    if ( (unsigned __int8)g_auchDigits[v17] <= 7u )
    {
      ++a1;
      a3 = 8;
      goto LABEL_9;
    }
    a3 = 10;
LABEL_48:
    v7 = a3;
    v6 = 48;
    v8 = g_auchShift[a3];
    goto LABEL_10;
  }
LABEL_9:
  v7 = a3;
  v8 = g_auchShift[a3];
  if ( !(_BYTE)v6 )
  {
    v10 = a1;
    v14 = 0;
    result = 0;
    goto LABEL_20;
  }
LABEL_10:
  v9 = (unsigned __int8)g_auchDigits[v6];
  v10 = a1;
  if ( (unsigned __int8)v9 >= a3 )
  {
    v14 = 0;
    result = 0;
    goto LABEL_20;
  }
  v11 = 0;
  result = 0;
  while ( 2 )
  {
    v14 = v9 + v7 * v11;
    if ( v14 < v11 )
    {
      v13 = *++v10;
      result = 55;
      if ( !(_BYTE)v13 )
        break;
      goto LABEL_15;
    }
    if ( v11 >> v8 )
      result = 55;
    v13 = *++v10;
    if ( (_BYTE)v13 )
    {
LABEL_15:
      v9 = (unsigned __int8)g_auchDigits[v13];
      if ( (unsigned __int8)v9 >= a3 )
        break;
      v11 = v14;
      continue;
    }
    break;
  }
  if ( v14 < 0 && (v14 != 0x8000000000000000LL || v5 == 1) )
    result = 55;
LABEL_20:
  if ( a4 )
  {
    if ( !v5 )
      v14 = -v14;
    *a4 = v14;
  }
  if ( a1 == v10 )
    result = 4294967240LL;
  if ( a2 )
    *a2 = v10;
  if ( !(_DWORD)result )
  {
    v15 = *v10;
    if ( *v10 )
    {
      if ( v15 == 9 || v15 == 32 )
      {
        do
        {
          do
            v16 = *++v10;
          while ( *v10 == 9 );
        }
        while ( v16 == 32 );
        return 77 - (unsigned int)(v16 != 0);
      }
      else
      {
        return 76;
      }
    }
  }
  return result;
}
