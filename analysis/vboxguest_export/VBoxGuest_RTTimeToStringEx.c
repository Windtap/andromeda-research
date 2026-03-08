unsigned __int64 __fastcall VBoxGuest_RTTimeToStringEx(
        unsigned int *a1,
        __int64 a2,
        __int64 a3,
        unsigned int a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  unsigned int v15; // eax
  unsigned __int64 result; // rax
  int v17; // ecx
  int v18; // esi
  char v19; // bp
  _BYTE v20[56]; // [rsp+38h] [rbp-38h] BYREF

  if ( a4 )
  {
    if ( a4 > 9 )
      return -54;
    VBoxGuest_RTStrPrintf((__int64)v20, 16, (__int64)".%09RU32", a5, a6, a7, a8, a9, a10, a11, a12, a1[3]);
    v20[a4 + 1] = 0;
    if ( (a1[4] & 3) != 3 )
    {
LABEL_3:
      result = VBoxGuest_RTStrPrintf(
                 a2,
                 a3,
                 (__int64)"%04RI32-%02u-%02uT%02u:%02u:%02u%sZ",
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 a12,
                 *a1,
                 *((unsigned __int8 *)a1 + 4),
                 *((unsigned __int8 *)a1 + 8),
                 *((unsigned __int8 *)a1 + 9),
                 *((unsigned __int8 *)a1 + 10),
                 *((unsigned __int8 *)a1 + 11),
                 v20);
      if ( result > 0x12 && *(_BYTE *)(a2 + result - 1) == 90 )
        return result;
      return -41;
    }
  }
  else
  {
    v15 = a1[4];
    v20[0] = 0;
    if ( (v15 & 3) != 3 )
      goto LABEL_3;
  }
  v17 = a1[5];
  if ( !v17 )
    goto LABEL_3;
  v18 = 43;
  v19 = 43;
  if ( v17 < 0 )
  {
    v17 = -v17;
    LOBYTE(v18) = 45;
    v19 = 45;
  }
  result = VBoxGuest_RTStrPrintf(
             a2,
             a3,
             (__int64)"%04RI32-%02u-%02uT%02u:%02u:%02u%s%c%02d%:02d",
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             *a1,
             *((unsigned __int8 *)a1 + 4),
             *((unsigned __int8 *)a1 + 8),
             *((unsigned __int8 *)a1 + 9),
             *((unsigned __int8 *)a1 + 10),
             *((unsigned __int8 *)a1 + 11),
             v20,
             v18,
             v17 / 0x3Cu,
             v17 % 0x3Cu);
  if ( result <= 0x17 || *(_BYTE *)(a2 + result - 6) != v19 )
    return -41;
  return result;
}
