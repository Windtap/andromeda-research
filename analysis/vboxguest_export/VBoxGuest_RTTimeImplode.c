unsigned __int64 __fastcall VBoxGuest_RTTimeImplode(unsigned __int64 a1, __int64 a2)
{
  __int64 v2; // r9
  int v3; // r10d
  int v4; // ebx
  int v5; // r11d
  unsigned __int16 v6; // ax
  int v7; // ecx
  int v8; // r8d
  int v9; // ebp
  __int64 v10; // rax
  __int64 v11; // rax

  if ( a1 + 0x200000 <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 0;
  }
  if ( (unsigned __int64)(a2 + 0x200000) <= 0x200FFF
    || (a2 & 0xFF00000000000000LL) != 0 && (a2 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 0;
  }
  v2 = *(unsigned int *)(a2 + 12);
  if ( (unsigned int)v2 > 0x3B9AC9FF )
    return 0;
  v3 = *(unsigned __int8 *)(a2 + 11);
  if ( (unsigned __int8)v3 > 0x3Bu )
    return 0;
  v4 = *(unsigned __int8 *)(a2 + 10);
  if ( (unsigned __int8)v4 > 0x3Bu )
    return 0;
  v5 = *(unsigned __int8 *)(a2 + 9);
  if ( (unsigned __int8)v5 > 0x17u )
    return 0;
  v6 = *(_WORD *)(a2 + 6);
  if ( !v6 )
    return 0;
  v7 = *(_DWORD *)a2;
  v8 = 365;
  if ( (*(_DWORD *)a2 & 3) == 0 )
  {
    LOBYTE(v8) = 110;
    if ( v7 == 100 * (v7 / 100) )
      v8 = 366 - (v7 != 400 * (v7 / 400));
  }
  if ( v8 < v6 )
    return 0;
  if ( (unsigned int)(v7 - 1677) > 0x249 )
    return 0;
  v9 = g_aoffYear[v7 - 1670] + v6;
  if ( (unsigned int)(v9 + 106751) > 0x341FF )
    return 0;
  v10 = v2 + 1000000000LL * (3600 * v5 + v3 + 60 * v4);
  if ( v10 > 0x4DE2E24EFFFFLL && v9 == 106752 )
    return 0;
  if ( v10 <= 0xB1AEFFFFFFLL && v9 == -106751 )
    return 0;
  v11 = 86400000000000LL * (v9 - 1) + v10;
  if ( (*(_DWORD *)(a2 + 16) & 3) == 3 )
    v11 -= 60000000000LL * *(int *)(a2 + 20);
  *(_QWORD *)a1 = v11;
  return a1;
}
