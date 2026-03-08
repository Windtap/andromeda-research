unsigned __int64 __fastcall VBoxGuest_RTTimeToRfc2822(
        int *a1,
        __int64 a2,
        __int64 a3,
        char a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12)
{
  bool v12; // zf
  __int64 v13; // r8
  char *v14; // r9
  char *v15; // rcx
  unsigned __int64 result; // rax
  int v17; // r10d
  int v18; // r11d
  char v19; // bp
  int v20; // [rsp+0h] [rbp-48h]
  int v21; // [rsp+8h] [rbp-40h]
  int v22; // [rsp+10h] [rbp-38h]
  int v23; // [rsp+18h] [rbp-30h]

  if ( (a1[4] & 3) != 3 || (v17 = a1[5]) == 0 )
  {
    v12 = (a4 & 1) == 0;
    v13 = *((unsigned __int8 *)a1 + 8);
    v14 = g_apszMonths[*((unsigned __int8 *)a1 + 4)];
    v15 = g_apszWeekDays[*((unsigned __int8 *)a1 + 5)];
    v23 = *((unsigned __int8 *)a1 + 11);
    v22 = *((unsigned __int8 *)a1 + 10);
    v21 = *((unsigned __int8 *)a1 + 9);
    v20 = *a1;
    if ( v12 )
    {
      result = VBoxGuest_RTStrPrintf(
                 a2,
                 a3,
                 (__int64)"%s, %u %s %04RI32 %02u:%02u:%02u -0000",
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 a12,
                 v15,
                 v13,
                 v14,
                 v20,
                 v21,
                 v22,
                 v23);
      if ( result > 0x1A && *(_BYTE *)(a2 + result - 5) == 45 )
        return result;
    }
    else
    {
      result = VBoxGuest_RTStrPrintf(
                 a2,
                 a3,
                 (__int64)"%s, %u %s %04RI32 %02u:%02u:%02u GMT",
                 a5,
                 a6,
                 a7,
                 a8,
                 a9,
                 a10,
                 a11,
                 a12,
                 v15,
                 v13,
                 v14,
                 v20,
                 v21,
                 v22,
                 v23);
      if ( result > 0x1A && *(_BYTE *)(a2 + result - 1) == 84 )
        return result;
    }
    return -41;
  }
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
             (__int64)"%s, %u %s %04RI32 %02u:%02u:%02u %c%02u%02u",
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             a11,
             a12,
             g_apszWeekDays[*((unsigned __int8 *)a1 + 5)],
             *((unsigned __int8 *)a1 + 8),
             g_apszMonths[*((unsigned __int8 *)a1 + 4)],
             *a1,
             *((unsigned __int8 *)a1 + 9),
             *((unsigned __int8 *)a1 + 10),
             *((unsigned __int8 *)a1 + 11),
             v18,
             v17 / 0x3Cu,
             v17 % 0x3Cu);
  if ( result <= 0x1A || *(_BYTE *)(a2 + result - 5) != v19 )
    return -41;
  return result;
}
