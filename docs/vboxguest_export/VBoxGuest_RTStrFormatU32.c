__int64 __fastcall VBoxGuest_RTStrFormatU32(
        char *dest,
        unsigned __int64 a2,
        unsigned int a3,
        unsigned int a4,
        int a5,
        int a6,
        __int16 a7)
{
  __int16 v10; // r9
  int v11; // eax
  __int64 v12; // rbp
  char v14[88]; // [rsp+0h] [rbp-58h] BYREF

  v10 = a7 & 0x7FF | 0x2000;
  if ( a2 > 0x3F )
    return (int)VBoxGuest_RTStrFormatNumber(dest, a3, a4, a5, a6, v10);
  v11 = VBoxGuest_RTStrFormatNumber(v14, a3, a4, a5, a6, v10);
  v12 = v11;
  if ( a2 >= v11 )
  {
    memcpy(dest, v14, v11 + 1LL);
    return v12;
  }
  else
  {
    if ( a2 )
    {
      memcpy(dest, v14, a2 - 1);
      dest[a2 - 1] = 0;
    }
    return -41;
  }
}
