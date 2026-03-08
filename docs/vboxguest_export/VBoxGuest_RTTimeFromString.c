__int64 __fastcall VBoxGuest_RTTimeFromString(__int64 a1, unsigned __int8 *a2)
{
  unsigned __int8 *v3; // rdi
  unsigned __int8 *v4; // rax
  unsigned __int8 *v5; // rsi
  char v6; // dl
  int v7; // ecx
  char v8; // bp
  unsigned __int8 *v9; // rax
  unsigned __int8 *v10; // rdi
  unsigned __int8 *v11; // rax
  unsigned __int8 *v12; // rdi
  int v13; // eax
  int v14; // edx
  __int64 v15; // rax
  unsigned int v16; // ecx
  __int16 v17; // ax
  __int64 v18; // rdx
  __int16 v19; // dx
  unsigned __int8 *v20; // rax
  unsigned __int8 *v21; // rdi
  unsigned __int8 *v22; // rax
  unsigned __int8 *v23; // rdi
  unsigned __int8 *v24; // rax
  unsigned __int8 *v25; // rdi
  int v26; // eax
  unsigned __int8 *v27; // rdi
  unsigned __int8 v28; // al
  unsigned __int8 *i; // rax
  int v30; // edx
  int v32; // eax
  unsigned __int8 v33; // al
  int v34; // eax
  int v35; // edx
  int v36; // eax
  unsigned __int8 *v37; // rbp
  int v38; // eax
  unsigned int v39; // eax
  int v40; // eax
  unsigned int v41; // eax
  unsigned __int8 *v42; // [rsp+0h] [rbp-20h] BYREF
  char v43; // [rsp+Eh] [rbp-12h] BYREF
  _BYTE v44[17]; // [rsp+Fh] [rbp-11h] BYREF

  v3 = a2;
  v42 = a2;
  if ( (unsigned int)((char)*a2 - 9) <= 4 || *a2 == 32 )
  {
    v4 = a2 + 1;
    do
    {
      do
      {
        v42 = v4;
        v5 = v4++;
        v6 = *(v4 - 1);
      }
      while ( (unsigned int)(v6 - 9) <= 4 );
    }
    while ( v6 == 32 );
    v3 = v5;
  }
  *(_DWORD *)(a1 + 16) = 3;
  *(_DWORD *)(a1 + 20) = 0;
  if ( (unsigned int)VBoxGuest_RTStrToInt32Ex(v3, &v42, 0xAu, (_DWORD *)a1) != 76 )
    return 0;
  v7 = *(_DWORD *)a1;
  v8 = 0;
  if ( (*(_DWORD *)a1 & 3) == 0 && (v7 != 100 * (v7 / 100) || v7 == 400 * (v7 / 400)) )
  {
    *(_DWORD *)(a1 + 16) |= 0x40u;
    v8 = 1;
  }
  v9 = v42;
  v10 = ++v42;
  if ( *v9 != 45 )
    return 0;
  if ( VBoxGuest_RTStrToUInt8Ex(v10, &v42, 0xAu, (_BYTE *)(a1 + 4)) != 76 )
    return 0;
  if ( (unsigned __int8)(*(_BYTE *)(a1 + 4) - 1) > 0xBu )
    return 0;
  v11 = v42;
  v12 = ++v42;
  if ( *v11 != 45 )
    return 0;
  v13 = VBoxGuest_RTStrToUInt8Ex(v12, &v42, 0xAu, (_BYTE *)(a1 + 8));
  if ( v13 )
  {
    if ( v13 != 76 )
      return 0;
  }
  v14 = *(unsigned __int8 *)(a1 + 4);
  v15 = v14 - 1;
  v16 = v8 ? (unsigned __int8)g_acDaysInMonthsLeap[v15] : (unsigned __int8)g_acDaysInMonths[v15];
  v17 = *(unsigned __int8 *)(a1 + 8);
  if ( !(_BYTE)v17 || v16 < (unsigned __int8)v17 )
    return 0;
  v18 = v14 - 1;
  v19 = v8 ? g_aiDayOfYearLeap[v18] : g_aiDayOfYear[v18];
  *(_BYTE *)(a1 + 5) = -1;
  *(_WORD *)(a1 + 6) = v19 + v17 - 1;
  v20 = v42;
  v21 = ++v42;
  if ( *v20 != 84 )
    return 0;
  if ( VBoxGuest_RTStrToUInt8Ex(v21, &v42, 0xAu, (_BYTE *)(a1 + 9)) != 76 )
    return 0;
  if ( *(_BYTE *)(a1 + 9) > 0x17u )
    return 0;
  v22 = v42;
  v23 = ++v42;
  if ( *v22 != 58 )
    return 0;
  if ( VBoxGuest_RTStrToUInt8Ex(v23, &v42, 0xAu, (_BYTE *)(a1 + 10)) != 76 )
    return 0;
  if ( *(_BYTE *)(a1 + 10) > 0x3Bu )
    return 0;
  v24 = v42;
  v25 = ++v42;
  if ( *v24 != 58 )
    return 0;
  v26 = VBoxGuest_RTStrToUInt8Ex(v25, &v42, 0xAu, (_BYTE *)(a1 + 11));
  if ( (unsigned int)(v26 - 76) > 1 )
  {
    if ( v26 )
      return 0;
  }
  if ( *(_BYTE *)(a1 + 11) > 0x3Bu )
    return 0;
  v27 = v42;
  if ( *v42 == 46 )
  {
    v37 = ++v42;
    v38 = VBoxGuest_RTStrToUInt32Ex(v42, &v42, 0xAu, (_DWORD *)(a1 + 12));
    if ( (unsigned int)(v38 - 76) > 1 && v38 )
      return 0;
    v39 = *(_DWORD *)(a1 + 12);
    if ( v39 > 0x3B9AC9FF )
      return 0;
    v27 = v42;
    switch ( v42 - v37 )
    {
      case 1LL:
        v41 = 100000000 * v39;
        *(_DWORD *)(a1 + 12) = v41;
        break;
      case 2LL:
        v41 = 10000000 * v39;
        *(_DWORD *)(a1 + 12) = v41;
        break;
      case 3LL:
        v41 = 1000000 * v39;
        *(_DWORD *)(a1 + 12) = v41;
        break;
      case 4LL:
        v41 = 100000 * v39;
        *(_DWORD *)(a1 + 12) = v41;
        break;
      case 5LL:
        v41 = 10000 * v39;
        *(_DWORD *)(a1 + 12) = v41;
        break;
      case 6LL:
        v41 = 1000 * v39;
        *(_DWORD *)(a1 + 12) = v41;
        break;
      case 7LL:
        v41 = 100 * v39;
        *(_DWORD *)(a1 + 12) = v41;
        break;
      case 8LL:
        v41 = 10 * v39;
        *(_DWORD *)(a1 + 12) = v41;
        break;
      case 9LL:
        goto LABEL_33;
      default:
        return 0;
    }
    if ( v41 > 0x3B9AC9FF )
      return 0;
  }
  else
  {
    *(_DWORD *)(a1 + 12) = 0;
  }
LABEL_33:
  v28 = *v27;
  if ( *v27 == 90 )
  {
    v34 = *(_DWORD *)(a1 + 16);
    *(_DWORD *)(a1 + 20) = 0;
    ++v27;
    *(_DWORD *)(a1 + 16) = v34 & 0xFFFFFFFC | 2;
    goto LABEL_36;
  }
  if ( v28 == 45 || v28 == 43 )
  {
    v43 = 0;
    v32 = VBoxGuest_RTStrToInt8Ex(v27, &v42, 0xAu, &v43);
    if ( (unsigned int)(v32 - 76) > 1 && v32 )
      return 0;
    v44[0] = 0;
    v33 = *v42;
    if ( *v42 == 58 )
    {
      v40 = VBoxGuest_RTStrToUInt8Ex(v42 + 1, &v42, 0xAu, v44);
      if ( v40 != 77 && v40 )
        return 0;
      v35 = v44[0];
    }
    else
    {
      if ( (v33 & 0xDF) != 0 && v33 != 9 )
        return 0;
      v35 = 0;
    }
    if ( v43 < 0 )
      v36 = 60 * v43 - v35;
    else
      v36 = v35 + 60 * v43;
    *(_DWORD *)(a1 + 20) = v36;
    if ( (int)abs32(v36) <= 840 )
    {
      v27 = v42;
      goto LABEL_36;
    }
    return 0;
  }
LABEL_36:
  for ( i = v27 + 1; ; ++i )
  {
    v42 = i;
    v30 = (char)*(i - 1);
    if ( !*(i - 1) )
      break;
    if ( v30 != 9 && v30 != 32 )
      return 0;
  }
  rtTimeNormalizeInternal(a1);
  return a1;
}
