__int64 __fastcall rtTimeConvertToZulu(__int64 a1)
{
  int v1; // eax
  int v2; // edx
  int v4; // ebp
  unsigned __int16 v5; // ax
  int v6; // ecx
  __int16 v7; // ax
  bool v8; // zf

  v1 = *(_DWORD *)(a1 + 16);
  if ( (v1 & 3) == 2 )
    return a1;
  v2 = *(_DWORD *)(a1 + 20);
  *(_DWORD *)(a1 + 20) = 0;
  *(_DWORD *)(a1 + 16) = v1 & 0xFFFFFFFC | 2;
  if ( !v2 )
    return a1;
  v4 = *(unsigned __int8 *)(a1 + 10) + 60 * *(unsigned __int8 *)(a1 + 9) - v2;
  while ( v4 > 1439 )
  {
    v4 -= 1440;
    rtTimeNormalizeInternal(a1);
    ++*(_BYTE *)(a1 + 8);
    *(_WORD *)(a1 + 6) = 0;
    rtTimeNormalizeInternal(a1);
  }
  for ( ; v4 < 0; v4 += 1440 )
  {
    while ( 1 )
    {
      rtTimeNormalizeInternal(a1);
      v5 = *(_WORD *)(a1 + 6);
      if ( v5 <= 1u )
        break;
      *(_BYTE *)(a1 + 4) = 0;
      *(_WORD *)(a1 + 6) = v5 - 1;
      *(_BYTE *)(a1 + 8) = 0;
      rtTimeNormalizeInternal(a1);
      v4 += 1440;
      if ( v4 >= 0 )
        goto LABEL_14;
    }
    v6 = *(_DWORD *)a1 - 1;
    v7 = 365;
    v8 = ((*(_BYTE *)a1 - 1) & 3) == 0;
    *(_DWORD *)a1 = v6;
    if ( v8 )
    {
      v7 = 366;
      if ( v6 == 100 * (v6 / 100) )
        v7 = 366 - (v6 != 400 * (v6 / 400));
    }
    *(_DWORD *)(a1 + 16) &= 0xFFFFFF3F;
    *(_WORD *)(a1 + 6) = v7;
    *(_BYTE *)(a1 + 8) = 31;
    *(_BYTE *)(a1 + 4) = 12;
    rtTimeNormalizeInternal(a1);
  }
LABEL_14:
  *(_BYTE *)(a1 + 9) = v4 / 60;
  *(_BYTE *)(a1 + 10) = v4 % 60;
  return a1;
}
