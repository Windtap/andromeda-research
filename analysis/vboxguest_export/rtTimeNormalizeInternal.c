__int64 __fastcall rtTimeNormalizeInternal(__int64 a1)
{
  int v1; // r9d
  int v2; // ebp
  int v3; // edx
  unsigned __int8 v4; // si
  unsigned __int8 v5; // r10
  int i; // ebx
  int v7; // ecx
  int v8; // eax
  unsigned __int8 v9; // dl
  unsigned int v10; // ecx
  __int64 v11; // rcx
  __int64 v12; // rsi
  int v13; // edx
  int v14; // r11d
  unsigned int v15; // r10d
  unsigned int v16; // r8d
  unsigned int v17; // esi
  unsigned int v18; // ecx
  __int64 v19; // rax
  int v20; // r11d
  char v21; // al
  unsigned int v22; // ebx
  int v23; // ecx
  __int64 v24; // kr00_8
  int v26; // eax
  int v27; // eax
  __int16 v28; // cx
  __int64 v29; // r8
  int v30; // r8d
  __int64 v31; // rax
  __int16 v32; // ax
  int v33; // ebp
  __int64 v34; // r11
  __int64 v35; // rax
  int v36; // ebp
  int v37; // esi
  int v38; // ecx
  __int16 *v39; // rsi
  int v40; // eax
  __int64 v41; // rcx
  __int64 v42; // r8

  v1 = 0;
  v2 = *(_DWORD *)a1;
  if ( (*(_DWORD *)a1 & 3) == 0 )
  {
    v1 = 1;
    if ( v2 == 100 * (v2 / 100) )
      LOBYTE(v1) = v2 == 400 * (v2 / 400);
  }
  v3 = *(unsigned __int16 *)(a1 + 6);
  if ( (_WORD)v3 )
  {
    v26 = *(unsigned __int8 *)(a1 + 4);
    if ( !(_BYTE)v26
      || (v28 = *(unsigned __int8 *)(a1 + 8), !(_BYTE)v28)
      || (unsigned __int8)v26 > 0xCu
      || ((v29 = v26 - 1, !(_BYTE)v1)
        ? (v30 = (unsigned __int8)g_acDaysInMonths[v29])
        : (v30 = (unsigned __int8)g_acDaysInMonthsLeap[v29]),
          v30 < (unsigned __int8)v28
       || ((v31 = v26 - 1, !(_BYTE)v1) ? (v32 = g_aiDayOfYear[v31]) : (v32 = g_aiDayOfYearLeap[v31]),
           (_WORD)v3 != v32 + v28 - 1)) )
    {
      for ( i = *(_DWORD *)(a1 + 16); ; *(_DWORD *)(a1 + 16) = i )
      {
        v14 = (unsigned __int16)v3;
        if ( (_BYTE)v1 )
        {
          if ( (unsigned __int16)v3 <= 0x16Eu )
          {
            v39 = g_aiDayOfYearLeap;
LABEL_85:
            *(_BYTE *)(a1 + 4) = 1;
            if ( (unsigned __int16)v3 < (unsigned __int16)v39[1] )
            {
              v42 = 0;
            }
            else
            {
              v40 = 2;
              do
              {
                v41 = (unsigned __int8)v40;
                *(_BYTE *)(a1 + 4) = v40++;
              }
              while ( (unsigned __int16)v3 >= (unsigned __int16)v39[v41] );
              v42 = 2 * v41 - 2;
            }
            *(_BYTE *)(a1 + 8) = v3 + 1 - *((_BYTE *)v39 + v42);
            goto LABEL_23;
          }
          v27 = 366;
        }
        else
        {
          if ( (unsigned __int16)v3 <= 0x16Du )
          {
            v39 = g_aiDayOfYear;
            goto LABEL_85;
          }
          v27 = 365;
        }
        ++v2;
        v1 = 0;
        *(_DWORD *)a1 = v2;
        *(_WORD *)(a1 + 6) = v3 - v27;
        if ( (v2 & 3) == 0 )
        {
          v1 = 1;
          if ( v2 == 100 * (v2 / 100) )
            LOBYTE(v1) = v2 == 400 * (v2 / 400);
        }
        LOBYTE(i) = i & 0x3F;
        v3 -= v27;
      }
    }
    v14 = (unsigned __int16)v3;
    i = *(_DWORD *)(a1 + 16);
LABEL_23:
    v15 = *(_DWORD *)(a1 + 12);
    v16 = *(unsigned __int8 *)(a1 + 11);
    v17 = *(unsigned __int8 *)(a1 + 10);
    v18 = *(unsigned __int8 *)(a1 + 9);
    if ( v15 <= 0x3B9AC9FF )
      goto LABEL_27;
    do
    {
      v15 -= 1000000000;
      ++v16;
    }
    while ( v15 > 0x3B9AC9FF );
    *(_DWORD *)(a1 + 12) = v15;
    if ( v16 <= 0x3B )
      goto LABEL_30;
    do
    {
      v16 -= 60;
      ++v17;
LABEL_27:
      ;
    }
    while ( v16 > 0x3B );
    while ( v17 > 0x3B )
    {
      v17 -= 60;
      ++v18;
LABEL_30:
      ;
    }
    if ( v18 <= 0x17 )
    {
LABEL_40:
      *(_BYTE *)(a1 + 11) = v16;
      *(_BYTE *)(a1 + 10) = v17;
      *(_BYTE *)(a1 + 9) = v18;
      if ( (_BYTE)v1 )
      {
        LOBYTE(i) = i & 0x7F;
        v22 = i | 0x40;
      }
      else
      {
        v22 = i & 0xFFFFFFBF;
        LOBYTE(v22) = v22 | 0x80;
      }
      *(_DWORD *)(a1 + 16) = v22;
      if ( (unsigned int)(v2 - 1670) > 0x257 )
      {
        if ( v2 > 1969 )
        {
          v33 = v2 - 1;
          v34 = v14 - 1;
          do
          {
            v35 = 365;
            if ( (v33 & 3) == 0 )
            {
              v35 = 366;
              if ( v33 == 100 * (v33 / 100) )
                v35 = 366LL - (v33 != 400 * (v33 / 400));
            }
            --v33;
            v34 += v35;
          }
          while ( v33 != 1969 );
          *(_BYTE *)(a1 + 5) = (v34 + 3) % 7uLL;
          return a1;
        }
        v36 = v2 + 1;
        v37 = (v1 << 31 >> 31) + v14 - 366;
        do
        {
          v38 = 365;
          if ( (v36 & 3) == 0 )
          {
            LOBYTE(v38) = 110;
            if ( v36 == 100 * (v36 / 100) )
              v38 = 366 - (v36 != 400 * (v36 / 400));
          }
          ++v36;
          v37 -= v38;
        }
        while ( v36 != 1970 );
        v23 = v37 - 8 * (v37 / 7) + v37 / 7 + 10;
        v24 = -1840700269LL * v23;
      }
      else
      {
        v23 = (g_aoffYear[v2 - 1670] + v14 - 1) % 7 + 10;
        v24 = -1840700269LL * v23;
      }
      *(_BYTE *)(a1 + 5) = v23 - 7 * (((v23 + HIDWORD(v24)) >> 2) - (v23 >> 31));
      return a1;
    }
    while ( 1 )
    {
      while ( 1 )
      {
        v18 -= 24;
        v19 = *(unsigned __int8 *)(a1 + 4);
        v20 = (unsigned __int16)v3 + 1;
        if ( !(_BYTE)v1 )
          break;
        if ( v20 == (unsigned __int16)g_aiDayOfYearLeap[v19] )
          goto LABEL_38;
LABEL_34:
        ++*(_BYTE *)(a1 + 8);
        *(_WORD *)(a1 + 6) = ++v3;
        v14 = (unsigned __int16)v3;
LABEL_35:
        if ( v18 <= 0x17 )
          goto LABEL_40;
      }
      if ( v20 != (unsigned __int16)g_aiDayOfYear[v19] )
        goto LABEL_34;
LABEL_38:
      v21 = *(_BYTE *)(a1 + 4);
      if ( v21 == 12 )
      {
        ++v2;
        v1 = 0;
        *(_DWORD *)a1 = v2;
        if ( (v2 & 3) == 0 )
        {
          v1 = 1;
          if ( v2 == 100 * (v2 / 100) )
            LOBYTE(v1) = v2 == 400 * (v2 / 400);
        }
        LOBYTE(i) = i & 0x3F;
        *(_BYTE *)(a1 + 4) = 1;
        *(_DWORD *)(a1 + 16) = i;
        v14 = 1;
        v3 = 1;
        *(_WORD *)(a1 + 6) = 1;
        *(_BYTE *)(a1 + 8) = 1;
        goto LABEL_35;
      }
      *(_WORD *)(a1 + 6) = ++v3;
      v14 = (unsigned __int16)v3;
      *(_BYTE *)(a1 + 4) = v21 + 1;
      *(_BYTE *)(a1 + 8) = 1;
      if ( v18 <= 0x17 )
        goto LABEL_40;
    }
  }
  v4 = *(_BYTE *)(a1 + 4);
  if ( v4 )
  {
    v5 = *(_BYTE *)(a1 + 8);
    if ( v5 )
    {
      i = *(_DWORD *)(a1 + 16);
      v7 = v2 + 1;
      if ( v4 > 0xCu )
      {
        do
        {
          v4 -= 12;
          v1 = 0;
          v2 = v7;
          if ( (v7 & 3) == 0 )
          {
            v1 = 1;
            if ( v7 == 100 * (v7 / 100) )
              LOBYTE(v1) = v7 == 400 * (v7 / 400);
          }
          LOBYTE(i) = i & 0x3F;
          ++v7;
        }
        while ( v4 > 0xCu );
        *(_BYTE *)(a1 + 4) = v4;
        *(_DWORD *)a1 = v2;
        *(_DWORD *)(a1 + 16) = i;
      }
      v8 = v5;
      v9 = v4;
      while ( 1 )
      {
        v11 = v9 - 1;
        if ( (_BYTE)v1 )
        {
          v10 = (unsigned __int8)g_acDaysInMonthsLeap[v11];
          if ( v10 >= (unsigned __int8)v8 )
            goto LABEL_20;
        }
        else
        {
          v10 = (unsigned __int8)g_acDaysInMonths[v11];
          if ( v10 >= (unsigned __int8)v8 )
          {
LABEL_20:
            v12 = v9 - 1;
            if ( (_BYTE)v1 )
              v13 = (unsigned __int16)g_aiDayOfYearLeap[v12];
            else
              v13 = (unsigned __int16)g_aiDayOfYear[v12];
            v3 = v13 + v8 - 1;
            *(_WORD *)(a1 + 6) = v3;
            v14 = (unsigned __int16)v3;
            goto LABEL_23;
          }
        }
        *(_BYTE *)(a1 + 8) = v8 - v10;
        if ( v9 == 12 )
        {
          ++v2;
          v1 = 0;
          *(_BYTE *)(a1 + 4) = 1;
          *(_DWORD *)a1 = v2;
          if ( (v2 & 3) == 0 && (v1 = 1, v2 == 100 * (v2 / 100)) )
          {
            v9 = 1;
            LOBYTE(v1) = v2 == 400 * (v2 / 400);
            LOBYTE(i) = i & 0x3F;
            *(_DWORD *)(a1 + 16) = i;
          }
          else
          {
            LOBYTE(i) = i & 0x3F;
            v9 = 1;
            *(_DWORD *)(a1 + 16) = i;
          }
        }
        else
        {
          *(_BYTE *)(a1 + 4) = ++v9;
        }
        v8 = (unsigned __int8)(v8 - v10);
      }
    }
  }
  return 0;
}
