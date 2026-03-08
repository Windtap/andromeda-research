__int64 __fastcall VBoxGuest_RTTimeToString(
        unsigned int *a1,
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned __int64 v11; // rax
  int v13; // ecx
  int v14; // r10d
  char v15; // bp
  unsigned __int64 v16; // rax
  int v17; // [rsp+0h] [rbp-48h]
  int v18; // [rsp+0h] [rbp-48h]
  int v19; // [rsp+8h] [rbp-40h]
  int v20; // [rsp+8h] [rbp-40h]
  int v21; // [rsp+10h] [rbp-38h]
  int v22; // [rsp+10h] [rbp-38h]
  unsigned int v23; // [rsp+18h] [rbp-30h]
  unsigned int v24; // [rsp+18h] [rbp-30h]
  int v25; // [rsp+20h] [rbp-28h]
  unsigned int v26; // [rsp+28h] [rbp-20h]
  unsigned int v27; // [rsp+30h] [rbp-18h]

  if ( (a1[4] & 3) == 3 )
  {
    v13 = a1[5];
    if ( v13 )
    {
      v14 = 43;
      v15 = 43;
      if ( v13 < 0 )
      {
        v13 = -v13;
        LOBYTE(v14) = 45;
        v15 = 45;
      }
      v25 = v14;
      v26 = v13 / 0x3Cu;
      v27 = v13 % 0x3Cu;
      v24 = a1[3];
      v22 = *((unsigned __int8 *)a1 + 11);
      v20 = *((unsigned __int8 *)a1 + 10);
      v18 = *((unsigned __int8 *)a1 + 9);
      v16 = VBoxGuest_RTStrPrintf(
              a2,
              a3,
              (__int64)"%RI32-%02u-%02uT%02u:%02u:%02u.%09RU32%c%02d%:02d",
              a4,
              a5,
              a6,
              a7,
              a8,
              a9,
              a10,
              a11,
              *a1,
              *((unsigned __int8 *)a1 + 4),
              *((unsigned __int8 *)a1 + 8),
              v18,
              v20,
              v22,
              v24,
              v25,
              v26,
              v27);
      if ( v16 <= 0xF || *(_BYTE *)(a2 + v16 - 6) != v15 )
        return 0;
      return a2;
    }
  }
  v23 = a1[3];
  v21 = *((unsigned __int8 *)a1 + 11);
  v19 = *((unsigned __int8 *)a1 + 10);
  v17 = *((unsigned __int8 *)a1 + 9);
  v11 = VBoxGuest_RTStrPrintf(
          a2,
          a3,
          (__int64)"%RI32-%02u-%02uT%02u:%02u:%02u.%09RU32Z",
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          a11,
          *a1,
          *((unsigned __int8 *)a1 + 4),
          *((unsigned __int8 *)a1 + 8),
          v17,
          v19,
          v21,
          v23);
  if ( v11 > 0xF && *(_BYTE *)(a2 + v11 - 1) == 90 )
    return a2;
  return 0;
}
