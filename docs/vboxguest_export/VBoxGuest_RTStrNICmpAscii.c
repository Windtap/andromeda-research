int __fastcall VBoxGuest_RTStrNICmpAscii(unsigned __int8 *a1, const char *a2, unsigned __int64 a3)
{
  int result; // eax
  const char *v4; // rbx
  unsigned __int8 v5; // cl
  int v6; // edx
  unsigned int v7; // eax
  unsigned __int64 v8; // [rsp+0h] [rbp-20h] BYREF
  const char *v9; // [rsp+8h] [rbp-18h] BYREF
  unsigned int v10[3]; // [rsp+14h] [rbp-Ch] BYREF

  result = 0;
  v9 = (const char *)a1;
  v8 = a3;
  if ( a3 )
  {
    v4 = a2;
    if ( a1 != (unsigned __int8 *)a2 )
    {
      if ( !a1 )
        return -1;
      if ( a2 )
      {
        while ( 1 )
        {
          if ( a3 && (v7 = *(unsigned __int8 *)v9, (v7 & 0x80u) == 0) )
          {
            v10[0] = *(unsigned __int8 *)v9++;
            v8 = a3 - 1;
          }
          else
          {
            if ( (int)VBoxGuest_RTStrGetCpNExInternal((unsigned __int8 **)&v9, &v8, (int *)v10) < 0 )
              return VBoxGuest_RTStrNCmp(v9 - 1, v4, v8 + 1);
            v7 = v10[0];
          }
          v5 = *v4++;
          v6 = v5;
          if ( v7 != v5 )
          {
            if ( v7 > 0x7F )
              return 1;
            if ( v7 - 65 <= 0x19 )
              v7 += 32;
            if ( (unsigned int)v5 - 65 <= 0x19 )
              v6 = v5 + 32;
            result = v7 - v6;
            if ( result )
              return result;
          }
          if ( v5 )
          {
            a3 = v8;
            if ( v8 )
              continue;
          }
          return 0;
        }
      }
      return 1;
    }
  }
  return result;
}
