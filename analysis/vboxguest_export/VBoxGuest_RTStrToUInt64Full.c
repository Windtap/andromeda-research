int __fastcall VBoxGuest_RTStrToUInt64Full(unsigned __int8 *a1, unsigned int a2, unsigned __int64 *a3)
{
  int result; // eax
  char v4; // dl
  unsigned __int8 *v5; // rax
  char v6; // dl
  unsigned __int8 *v7; // [rsp+0h] [rbp-8h] BYREF

  result = VBoxGuest_RTStrToUInt64Ex(a1, &v7, a2, a3);
  if ( result >= 0 )
  {
    v4 = *v7;
    if ( *v7 )
    {
      if ( (unsigned int)(result - 76) <= 1 )
      {
        return -result;
      }
      else
      {
        if ( v4 != 9 && v4 != 32 )
          return -76;
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
        result = -77;
        if ( v6 )
          return -76;
      }
    }
  }
  return result;
}
