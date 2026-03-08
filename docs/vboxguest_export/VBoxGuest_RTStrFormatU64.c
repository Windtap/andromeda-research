__int64 __fastcall VBoxGuest_RTStrFormatU64(
        char *dest,
        unsigned __int64 a2,
        unsigned __int64 a3,
        unsigned int a4,
        int a5,
        int a6,
        __int16 a7)
{
  __int16 v12; // r9
  int v13; // eax
  __int64 v14; // rbp
  char v16[88]; // [rsp+0h] [rbp-58h] BYREF

  v12 = a7 & 0x7FF | 0x4000;
  if ( a2 > 0x3F )
    return (int)VBoxGuest_RTStrFormatNumber(dest, a3, a4, a5, a6, v12);
  v13 = VBoxGuest_RTStrFormatNumber(v16, a3, a4, a5, a6, v12);
  v14 = v13;
  if ( a2 >= v13 )
  {
    memcpy(dest, v16, v13 + 1LL);
    return v14;
  }
  else
  {
    if ( a2 )
    {
      memcpy(dest, v16, a2 - 1);
      dest[a2 - 1] = 0;
    }
    return -41;
  }
}
