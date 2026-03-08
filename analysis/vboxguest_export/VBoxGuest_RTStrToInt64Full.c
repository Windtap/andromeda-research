__int64 __fastcall VBoxGuest_RTStrToInt64Full(unsigned __int8 *a1, unsigned int a2, __int64 *a3)
{
  __int64 result; // rax
  char v4; // dl
  unsigned __int8 *v5; // rax
  char v6; // dl
  unsigned __int8 *v7; // [rsp+0h] [rbp-8h] BYREF

  result = VBoxGuest_RTStrToInt64Ex(a1, &v7, a2, a3);
  if ( (int)result >= 0 )
  {
    v4 = *v7;
    if ( *v7 )
    {
      if ( (unsigned int)(result - 76) <= 1 )
      {
        return (unsigned int)-(int)result;
      }
      else
      {
        if ( v4 != 9 && v4 != 32 )
          return 4294967220LL;
        v5 = v7 + 1;
        do
        {
          do
          {
            v7 = v5++;
            v6 = *(v5 - 1);
          }
          while ( v6 == 9 );
        }
        while ( v6 == 32 );
        result = 4294967219LL;
        if ( v6 )
          return 4294967220LL;
      }
    }
  }
  return result;
}
