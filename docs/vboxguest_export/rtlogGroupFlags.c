__int64 __fastcall rtlogGroupFlags(_BYTE *a1)
{
  __int64 result; // rax
  _BYTE *v2; // rbp
  char i; // dl
  __int64 v4; // r11
  char *v5; // rcx
  char *v6; // rsi
  char v7; // dl
  int v8; // r9d
  int v9; // edx
  int v10; // r8d

  result = 0;
  v2 = a1;
  for ( i = *a1; i == 46; v2 = v5 )
  {
    v4 = 0;
    while ( 2 )
    {
      v5 = v2 + 1;
      v6 = (&aFlags_25990)[2 * v4];
      v7 = *v6;
      while ( 1 )
      {
        v8 = v7;
        v9 = *v5;
        v10 = v9 + 32;
        if ( (unsigned int)(v9 - 65) > 0x19 )
          v10 = *v5;
        if ( v8 != v10 )
          break;
        v7 = *++v6;
        ++v5;
        if ( !*v6 )
        {
          i = *v5;
          if ( (unsigned __int8)((*v5 & 0xDF) - 65) > 0x19u && (unsigned __int8)(i - 48) > 9u )
          {
            result = dword_24188[4 * (unsigned int)v4] | (unsigned int)result;
            goto LABEL_13;
          }
          break;
        }
      }
      if ( ++v4 != 35 )
        continue;
      break;
    }
    i = v2[1];
    v5 = v2 + 1;
LABEL_13:
    ;
  }
  if ( i == 61 )
  {
    if ( v2[1] == 126 )
      return (unsigned int)~VBoxGuest_RTStrToInt32(v2 + 2);
    else
      return VBoxGuest_RTStrToInt32(v2 + 1);
  }
  return result;
}
