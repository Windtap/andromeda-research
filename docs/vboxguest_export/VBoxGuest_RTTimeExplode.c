__int64 __fastcall VBoxGuest_RTTimeExplode(__int64 a1, __int64 *a2)
{
  __int64 v2; // rcx
  __int64 v3; // rsi
  int v4; // ecx
  int v5; // eax
  __int64 v6; // rcx
  __int64 v7; // rax
  int v8; // edx
  int v9; // r8d
  int v10; // eax
  int v11; // esi
  int v12; // edx
  int i; // edx
  int j; // ecx
  int v15; // r8d
  int v16; // esi
  __int16 *v17; // r8
  int v18; // eax
  int v19; // edx
  __int64 v20; // rcx
  char v21; // al

  *(_DWORD *)(a1 + 16) = 2;
  v2 = *a2;
  v3 = *a2 / 1000000000;
  v4 = v2 - 1000000000 * v3;
  v5 = v4;
  if ( v4 < 0 )
  {
    v5 = v4 + 1000000000;
    --v3;
  }
  *(_DWORD *)(a1 + 12) = v5;
  v6 = v3 / 60;
  v7 = v3 + 4 * (v3 / 60) - ((v3 / 60) << 6);
  v8 = v3 + 4 * (v3 / 60) - ((unsigned int)(v3 / 60) << 6);
  if ( (int)v7 < 0 )
  {
    LOBYTE(v8) = v7 + 60;
    LODWORD(v6) = v6 - 1;
  }
  *(_BYTE *)(a1 + 11) = v8;
  v9 = (int)v6 / 60;
  v10 = (int)v6 % 60;
  if ( (int)v6 % 60 < 0 )
  {
    LOBYTE(v10) = v10 + 60;
    --v9;
  }
  *(_BYTE *)(a1 + 10) = v10;
  v11 = v9 / 24;
  v12 = v9 % 24;
  if ( v9 % 24 < 0 )
  {
    LOBYTE(v12) = v12 + 24;
    --v11;
  }
  *(_BYTE *)(a1 + 9) = v12;
  *(_BYTE *)(a1 + 5) = (v11 % 7 + 10) % 7;
  for ( i = v11 / 365 + 300; v11 >= g_aoffYear[i + 1]; ++i )
    ;
  for ( j = g_aoffYear[i]; v11 < j; j = g_aoffYear[i] )
    --i;
  v15 = i + 1670;
  v16 = v11 - j;
  *(_DWORD *)a1 = i + 1670;
  *(_WORD *)(a1 + 6) = v16 + 1;
  if ( (((_BYTE)i - 122) & 3) != 0 || v15 == 100 * (v15 / 100) && v15 != 400 * (v15 / 400) )
  {
    *(_DWORD *)(a1 + 16) = 130;
    v17 = &g_aiDayOfYear;
  }
  else
  {
    *(_DWORD *)(a1 + 16) = 66;
    v17 = &g_aiDayOfYearLeap;
  }
  v18 = v16 + 1;
  v19 = v16 / 32;
  v20 = v16 / 32;
  if ( v16 + 1 >= (unsigned __int16)v17[v20 + 1] )
  {
    do
      v20 = ++v19;
    while ( v18 >= (unsigned __int16)v17[v19 + 1] );
  }
  *(_BYTE *)(a1 + 4) = v19 + 1;
  v21 = v18 - LOBYTE(v17[v20]);
  *(_DWORD *)(a1 + 20) = 0;
  *(_BYTE *)(a1 + 8) = v21 + 1;
  return a1;
}
