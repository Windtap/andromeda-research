char __fastcall VBDrvCommonIsOptionValueTrue(char *a1)
{
  char v1; // dl
  char result; // al

  if ( a1 )
  {
    while ( 1 )
    {
      v1 = *a1;
      if ( !*a1 )
        break;
      if ( (unsigned int)(v1 - 9) > 4 && v1 != 32 )
      {
        if ( (v1 & 0xDF) == 0x4E )
          return 0;
        result = 0;
        if ( (v1 & 0xDD) != 0x44 )
        {
          if ( (v1 & 0xDF) == 0x4F )
          {
            return (a1[1] & 0xDF) != 70;
          }
          else
          {
            result = 1;
            if ( v1 == 48 )
              return a1[1] != 0;
          }
        }
        return result;
      }
      ++a1;
    }
  }
  return 0;
}
