int __fastcall VBoxGuest_RTStrICmpAscii(unsigned __int8 *a1, const char *a2)
{
  const char *v2; // rbx
  unsigned __int8 v3; // cl
  int v4; // edx
  unsigned int v5; // eax
  int result; // eax
  const char *v7; // [rsp+0h] [rbp-18h] BYREF
  unsigned int v8[3]; // [rsp+Ch] [rbp-Ch] BYREF

  v2 = a2;
  v7 = (const char *)a1;
  if ( a1 == (unsigned __int8 *)a2 )
    return 0;
  if ( a1 )
  {
    if ( !a2 )
      return 1;
    while ( 1 )
    {
      v5 = *a1;
      if ( (v5 & 0x80u) == 0 )
      {
        v8[0] = *a1;
        v7 = (const char *)(a1 + 1);
      }
      else
      {
        if ( (int)VBoxGuest_RTStrGetCpExInternal((unsigned __int8 **)&v7, (int *)v8) < 0 )
          return VBoxGuest_RTStrCmp(v7 - 1, v2);
        v5 = v8[0];
      }
      v3 = *v2++;
      v4 = v3;
      if ( v5 != v3 )
      {
        if ( v5 > 0x7F )
          return 1;
        if ( v5 - 65 <= 0x19 )
          v5 += 32;
        if ( (unsigned int)v3 - 65 <= 0x19 )
          v4 = v3 + 32;
        result = v5 - v4;
        if ( result )
          return result;
      }
      if ( !v3 )
        return 0;
      a1 = (unsigned __int8 *)v7;
    }
  }
  return -1;
}
