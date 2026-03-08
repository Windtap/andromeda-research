__int64 __fastcall VBoxGuest_RTTimeFromRfc2822(__int64 a1, unsigned __int8 *a2)
{
  unsigned __int8 *v3; // rax
  char v4; // dl
  int v5; // edx
  int v6; // eax
  int v7; // eax
  unsigned __int8 *v8; // rdi
  signed __int8 v9; // cl
  int v10; // edx
  unsigned __int8 *v11; // rax
  int v12; // ecx
  int v13; // eax
  int v14; // eax
  int v15; // ecx
  int v16; // ecx
  unsigned __int8 *v17; // rax
  unsigned __int8 *v18; // rsi
  char v19; // dl
  unsigned __int8 *v20; // rax
  char v21; // dl
  unsigned __int8 *v22; // rdi
  unsigned __int8 *v23; // rax
  int v24; // ecx
  char v25; // si
  unsigned __int8 *v26; // rax
  char v27; // dl
  int v28; // edx
  __int64 v29; // rax
  unsigned int v30; // ecx
  __int16 v31; // ax
  __int64 v32; // rdx
  __int16 v33; // dx
  unsigned __int8 *v34; // rax
  unsigned __int8 *v35; // rdi
  unsigned __int8 *v36; // rax
  unsigned __int8 *v37; // rdi
  int v38; // eax
  int v40; // ecx
  int v41; // ecx
  int v42; // eax
  int v43; // eax
  unsigned __int8 *v44; // rsi
  unsigned __int8 *v45; // rax
  unsigned __int8 v46; // dl
  int v47; // ecx
  unsigned __int8 *v48; // rax
  char v49; // dl
  unsigned __int8 *v50; // rax
  signed __int8 v51; // cl
  int v52; // edx
  unsigned __int8 *v53; // rax
  unsigned __int8 *v54; // rdi
  bool v55; // bp
  int v56; // ecx
  int v57; // esi
  int v58; // ecx
  int v59; // esi
  int v60; // ecx
  int v61; // ecx
  __int64 v62; // rdx
  unsigned __int8 *v63; // rax
  unsigned __int8 *i; // rax
  int v65; // edx
  unsigned int v66; // edx
  int v67; // ecx
  unsigned __int8 *v68; // rdi
  signed __int8 v69; // al
  int v70; // edx
  int v71; // r12d
  int v72; // edx
  int v73; // eax
  int v74; // eax
  unsigned __int8 *v75; // rbp
  int v76; // eax
  unsigned int v77; // edx
  unsigned int v78; // edx
  int v79; // eax
  int v80; // edx
  int v81; // edx
  int v82; // edx
  unsigned __int8 *v83; // [rsp+0h] [rbp-28h] BYREF
  char v84[25]; // [rsp+Fh] [rbp-19h] BYREF

  v83 = a2;
  if ( (unsigned int)((char)*a2 - 9) <= 4 || *a2 == 32 )
  {
    v3 = a2 + 1;
    do
    {
      do
      {
        v83 = v3;
        a2 = v3++;
        v4 = *(v3 - 1);
      }
      while ( (unsigned int)(v4 - 9) <= 4 );
    }
    while ( v4 == 32 );
  }
  *(_DWORD *)(a1 + 16) = 3;
  *(_DWORD *)(a1 + 20) = 0;
  v5 = (char)*a2;
  if ( (unsigned __int8)((*a2 & 0xDF) - 65) <= 0x19u && (v6 = (char)a2[1], a2[1]) )
  {
    v40 = (char)a2[2];
    if ( (unsigned int)(v40 - 65) <= 0x19 )
      LOBYTE(v40) = v40 + 32;
    v41 = (unsigned __int8)v40 << 16;
    if ( (unsigned int)(v6 - 65) <= 0x19 )
      LOBYTE(v6) = v6 + 32;
    v42 = v41 | ((unsigned __int8)v6 << 8);
    if ( (unsigned int)(v5 - 65) <= 0x19 )
      LOBYTE(v5) = v5 + 32;
    v43 = (unsigned __int8)v5 | v42;
    switch ( v43 )
    {
      case 7237485:
        *(_BYTE *)(a1 + 5) = 0;
        break;
      case 6649204:
        *(_BYTE *)(a1 + 5) = 1;
        break;
      case 6579575:
        *(_BYTE *)(a1 + 5) = 2;
        break;
      case 7694452:
        *(_BYTE *)(a1 + 5) = 3;
        break;
      case 6910566:
        *(_BYTE *)(a1 + 5) = 4;
        break;
      case 7627123:
        *(_BYTE *)(a1 + 5) = 5;
        break;
      case 7239027:
        *(_BYTE *)(a1 + 5) = 6;
        break;
      default:
        return 0;
    }
    v44 = a2 + 3;
    do
    {
      v83 = v44;
      v45 = v44;
      v46 = *v44++;
    }
    while ( (unsigned __int8)((v46 & 0xDF) - 65) <= 0x19u );
    if ( v46 == 44 )
    {
      v83 = v44;
      v46 = v45[1];
      v45 = v44;
    }
    v47 = (char)v46;
    if ( (unsigned int)((char)v46 - 9) <= 4 || v46 == 32 )
    {
      v48 = v45 + 1;
      do
      {
        do
        {
          v83 = v48++;
          v49 = *(v48 - 1);
          v47 = v49;
        }
        while ( (unsigned int)(v49 - 9) <= 4 );
      }
      while ( v49 == 32 );
    }
    if ( (unsigned int)(v47 - 48) > 9 )
      return 0;
  }
  else
  {
    if ( (unsigned int)(v5 - 48) > 9 )
      return 0;
    *(_BYTE *)(a1 + 5) = -1;
  }
  v7 = VBoxGuest_RTStrToUInt8Ex(v83, &v83, 0xAu, (_BYTE *)(a1 + 8));
  if ( v7 && v7 != 76 )
    return 0;
  v8 = v83;
  v9 = *v83;
  v10 = (char)*v83;
  if ( (unsigned int)(v10 - 9) <= 4 || v10 == 32 )
  {
    v11 = v83 + 1;
    do
    {
      do
      {
        v83 = v11;
        v8 = v11++;
        v9 = *(v11 - 1);
        v10 = v9;
      }
      while ( (unsigned int)(v9 - 9) <= 4 );
    }
    while ( v9 == 32 );
  }
  if ( !v9 )
    return 0;
  v12 = (char)v8[1];
  if ( !v8[1] )
    return 0;
  v13 = (char)v8[2];
  if ( !v8[2] )
    return 0;
  if ( (unsigned int)(v13 - 65) <= 0x19 )
    LOBYTE(v13) = v13 + 32;
  v14 = (unsigned __int8)v13 << 16;
  if ( (unsigned int)(v12 - 65) <= 0x19 )
    LOBYTE(v12) = v12 + 32;
  v15 = v14 | ((unsigned __int8)v12 << 8);
  if ( (unsigned int)(v10 - 65) <= 0x19 )
    LOBYTE(v10) = v10 + 32;
  v16 = (unsigned __int8)v10 | v15;
  switch ( v16 )
  {
    case 7233898:
      *(_BYTE *)(a1 + 4) = 1;
      break;
    case 6448486:
      *(_BYTE *)(a1 + 4) = 2;
      break;
    case 7496045:
      *(_BYTE *)(a1 + 4) = 3;
      break;
    case 7499873:
      *(_BYTE *)(a1 + 4) = 4;
      break;
    case 7954797:
      *(_BYTE *)(a1 + 4) = 5;
      break;
    case 7239018:
      *(_BYTE *)(a1 + 4) = 6;
      break;
    case 7107946:
      *(_BYTE *)(a1 + 4) = 7;
      break;
    case 6780257:
      *(_BYTE *)(a1 + 4) = 8;
      break;
    case 7366003:
      *(_BYTE *)(a1 + 4) = 9;
      break;
    case 7627631:
      *(_BYTE *)(a1 + 4) = 10;
      break;
    case 7761774:
      *(_BYTE *)(a1 + 4) = 11;
      break;
    case 6514020:
      *(_BYTE *)(a1 + 4) = 12;
      break;
    default:
      return 0;
  }
  v17 = v8 + 3;
  do
  {
    v83 = v17;
    v18 = v17++;
    v19 = *(v17 - 1);
  }
  while ( (unsigned __int8)((v19 & 0xDF) - 65) <= 0x19u );
  if ( (unsigned int)(v19 - 9) <= 4 || v19 == 32 )
  {
    v20 = v18 + 1;
    do
    {
      do
      {
        v83 = v20;
        v18 = v20++;
        v21 = *(v20 - 1);
      }
      while ( (unsigned int)(v21 - 9) <= 4 );
    }
    while ( v21 == 32 );
  }
  if ( (unsigned int)VBoxGuest_RTStrToInt32Ex(v18, &v83, 0xAu, (_DWORD *)a1) != 76 )
    return 0;
  v22 = v83;
  v23 = (unsigned __int8 *)(v83 - v18);
  if ( v83 - v18 <= 3 )
  {
    if ( v83 - v18 == 3 )
    {
      v24 = *(_DWORD *)a1 + 1900;
      *(_DWORD *)a1 = v24;
    }
    else
    {
      if ( v23 != (_BYTE *)&loc_1 + 1 )
        return 0;
      LOWORD(v23) = 1900;
      if ( *(int *)a1 < 50 )
        LODWORD(v23) = 2000;
      v24 = (_DWORD)v23 + *(_DWORD *)a1;
      *(_DWORD *)a1 = v24;
    }
  }
  else
  {
    v24 = *(_DWORD *)a1;
  }
  v25 = 0;
  if ( (v24 & 3) == 0 && (v24 != 100 * (v24 / 100) || v24 == 400 * (v24 / 400)) )
  {
    *(_DWORD *)(a1 + 16) |= 0x40u;
    v25 = 1;
  }
  if ( (unsigned int)((char)*v22 - 9) <= 4 || *v22 == 32 )
  {
    v26 = v22 + 1;
    do
    {
      do
      {
        v83 = v26;
        v22 = v26++;
        v27 = *(v26 - 1);
      }
      while ( (unsigned int)(v27 - 9) <= 4 );
    }
    while ( v27 == 32 );
  }
  v28 = *(unsigned __int8 *)(a1 + 4);
  v29 = v28 - 1;
  if ( v25 )
    v30 = (unsigned __int8)g_acDaysInMonthsLeap[v29];
  else
    v30 = (unsigned __int8)g_acDaysInMonths[v29];
  v31 = *(unsigned __int8 *)(a1 + 8);
  if ( !(_BYTE)v31 || v30 < (unsigned __int8)v31 )
    return 0;
  v32 = v28 - 1;
  v33 = v25 ? g_aiDayOfYearLeap[v32] : g_aiDayOfYear[v32];
  *(_WORD *)(a1 + 6) = v33 + v31 - 1;
  if ( VBoxGuest_RTStrToUInt8Ex(v22, &v83, 0xAu, (_BYTE *)(a1 + 9)) != 76 )
    return 0;
  if ( *(_BYTE *)(a1 + 9) > 0x17u )
    return 0;
  v34 = v83;
  v35 = ++v83;
  if ( *v34 != 58 )
    return 0;
  if ( VBoxGuest_RTStrToUInt8Ex(v35, &v83, 0xAu, (_BYTE *)(a1 + 10)) != 76 )
    return 0;
  if ( *(_BYTE *)(a1 + 10) > 0x3Bu )
    return 0;
  v36 = v83;
  v37 = ++v83;
  if ( *v36 != 58 )
    return 0;
  v38 = VBoxGuest_RTStrToUInt8Ex(v37, &v83, 0xAu, (_BYTE *)(a1 + 11));
  if ( (unsigned int)(v38 - 76) > 1 )
  {
    if ( v38 )
      return 0;
  }
  if ( *(_BYTE *)(a1 + 11) > 0x3Bu )
    return 0;
  v50 = v83;
  if ( *v83 == 46 )
  {
    v75 = ++v83;
    v76 = VBoxGuest_RTStrToUInt32Ex(v83, &v83, 0xAu, (_DWORD *)(a1 + 12));
    if ( (unsigned int)(v76 - 76) > 1 && v76 )
      return 0;
    v77 = *(_DWORD *)(a1 + 12);
    if ( v77 > 0x3B9AC9FF )
      return 0;
    v50 = v83;
    switch ( v83 - v75 )
    {
      case 1LL:
        v78 = 100000000 * v77;
        *(_DWORD *)(a1 + 12) = v78;
        break;
      case 2LL:
        v78 = 10000000 * v77;
        *(_DWORD *)(a1 + 12) = v78;
        break;
      case 3LL:
        v78 = 1000000 * v77;
        *(_DWORD *)(a1 + 12) = v78;
        break;
      case 4LL:
        v78 = 100000 * v77;
        *(_DWORD *)(a1 + 12) = v78;
        break;
      case 5LL:
        v78 = 10000 * v77;
        *(_DWORD *)(a1 + 12) = v78;
        break;
      case 6LL:
        v78 = 1000 * v77;
        *(_DWORD *)(a1 + 12) = v78;
        break;
      case 7LL:
        v78 = 100 * v77;
        *(_DWORD *)(a1 + 12) = v78;
        break;
      case 8LL:
        v78 = 10 * v77;
        *(_DWORD *)(a1 + 12) = v78;
        break;
      case 9LL:
        goto LABEL_98;
      default:
        return 0;
    }
    if ( v78 > 0x3B9AC9FF )
      return 0;
  }
  else
  {
    *(_DWORD *)(a1 + 12) = 0;
  }
LABEL_98:
  v51 = *v50;
  v52 = (char)*v50;
  if ( (unsigned int)(v52 - 9) <= 4 || v52 == 32 )
  {
    v53 = v50 + 1;
    do
    {
      do
      {
        v83 = v53;
        v54 = v53++;
        v51 = *(v53 - 1);
        v52 = v51;
      }
      while ( (unsigned int)(v51 - 9) <= 4 );
    }
    while ( v51 == 32 );
    v50 = v54;
  }
  v55 = v51 == 45;
  if ( v51 == 45 || v51 == 43 )
  {
    v66 = (char)v50[1] - 48;
    if ( v66 > 9 )
      return 0;
    v67 = v50[2];
    if ( (unsigned int)((char)v67 - 48) > 9 )
      return 0;
    v68 = v50 + 3;
    v84[0] = 0;
    v83 = v50 + 3;
    v69 = v50[3];
    v70 = v67 + 10 * v66 - 48;
    v71 = -v70;
    if ( !v55 )
      LOBYTE(v71) = v70;
    if ( (unsigned int)(v69 - 48) <= 9 )
    {
      v79 = VBoxGuest_RTStrToUInt8Ex(v68, &v83, 0xAu, v84);
      if ( v79 != 77 && v79 )
        return 0;
      v72 = (unsigned __int8)v84[0];
    }
    else
    {
      if ( (v69 & 0xDF) != 0 && v69 != 9 )
        return 0;
      v72 = 0;
    }
    v73 = 60 * (char)v71;
    if ( (v71 & 0x80u) != 0 )
    {
      *(_DWORD *)(a1 + 20) = v73 - v72;
      if ( (int)abs32(v73 - v72) <= 840 )
        goto LABEL_116;
    }
    else
    {
      v74 = v72 + v73;
      *(_DWORD *)(a1 + 20) = v74;
      if ( (int)abs32(v74) <= 840 )
      {
        if ( !v74 && v55 )
          *(_DWORD *)(a1 + 16) = *(_DWORD *)(a1 + 16) & 0xFFFFFFFC | 2;
        goto LABEL_116;
      }
    }
    return 0;
  }
  if ( (v52 & 0xFFFFFFDF) - 65 <= 0x19 )
  {
    v56 = (char)v50[2];
    if ( (unsigned int)(v56 - 65) < 0x1A )
      LOBYTE(v56) = v56 + 32;
    v57 = (unsigned __int8)v56;
    v58 = (char)v50[1];
    v59 = v57 << 16;
    if ( (unsigned int)(v58 - 65) <= 0x19 )
      LOBYTE(v58) = v58 + 32;
    v60 = v59 | ((unsigned __int8)v58 << 8);
    if ( (unsigned int)(v52 - 65) <= 0x19 )
      LOBYTE(v52) = v52 + 32;
    v61 = (unsigned __int8)v52 | v60;
    if ( v61 == 7630183 )
    {
      v80 = *(_DWORD *)(a1 + 16);
      *(_DWORD *)(a1 + 20) = 0;
      v63 = v50 + 3;
      *(_DWORD *)(a1 + 16) = v80 & 0xFFFFFFFC | 2;
    }
    else
    {
      v62 = 7;
      if ( (_WORD)v61 == 29813 )
      {
        v81 = *(_DWORD *)(a1 + 16);
        *(_DWORD *)(a1 + 20) = 0;
        v63 = v50 + 2;
        *(_DWORD *)(a1 + 16) = v81 & 0xFFFFFFFC | 2;
      }
      else
      {
        while ( s_aLegacyTimeZones_30015[2 * v62] != v61 )
        {
          if ( --v62 == -1 )
            goto LABEL_116;
        }
        v82 = dword_24104[2 * v62];
        v63 = v50 + 3;
        *(_DWORD *)(a1 + 16) |= 3u;
        *(_DWORD *)(a1 + 20) = v82;
      }
    }
    goto LABEL_117;
  }
LABEL_116:
  v63 = v83;
LABEL_117:
  for ( i = v63 + 1; ; ++i )
  {
    v83 = i;
    v65 = (char)*(i - 1);
    if ( !*(i - 1) )
      break;
    if ( v65 != 9 && v65 != 32 )
      return 0;
  }
  rtTimeNormalizeInternal(a1);
  return a1;
}
