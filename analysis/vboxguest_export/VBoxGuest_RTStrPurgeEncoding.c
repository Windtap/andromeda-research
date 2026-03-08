__int64 __fastcall VBoxGuest_RTStrPurgeEncoding(unsigned __int8 *a1)
{
  __int64 v1; // rbx
  int v2; // edx
  unsigned __int8 *v4; // [rsp+0h] [rbp-18h] BYREF
  int v5[3]; // [rsp+Ch] [rbp-Ch] BYREF

  v1 = 0;
  v4 = a1;
  do
  {
    while ( 1 )
    {
      while ( 1 )
      {
        v2 = *v4;
        if ( (v2 & 0x80u) != 0 )
          break;
        v5[0] = *v4++;
        if ( !v2 )
          return v1;
      }
      if ( (int)VBoxGuest_RTStrGetCpExInternal(&v4, v5) >= 0 )
        break;
      ++v1;
      *(v4 - 1) = 63;
    }
  }
  while ( v5[0] );
  return v1;
}
