__int64 __fastcall vgdrvBitUsageTrackerChange_isra_1(__int64 a1, unsigned int a2, int a3)
{
  __int64 result; // rax
  int v4; // ecx
  bool v5; // zf
  int v6; // ecx
  int v7; // ecx
  int v8; // ecx
  __int64 v9; // rcx
  int *v10; // r9
  int v11; // r8d
  int v12; // ecx
  int v13; // ecx

  result = 0;
  if ( a2 )
  {
    while ( 1 )
    {
      v5 = !_BitScanForward((unsigned int *)&v7, a2);
      v8 = v5 ? 0 : v7 + 1;
      v9 = (unsigned int)(v8 - 1);
      v10 = (int *)(a1 + 4 * v9);
      v11 = 1 << v9;
      v12 = *v10;
      if ( (a3 & v11) != 0 )
        break;
      v13 = v12 + 1;
      *v10 = v13;
      if ( v13 == 1 )
      {
        *(_DWORD *)(a1 + 128) |= v11;
        result = 1;
        v6 = ~v11;
LABEL_5:
        a2 &= v6;
        if ( !a2 )
          return result;
      }
      else
      {
        a2 &= ~v11;
        if ( !a2 )
          return result;
      }
    }
    v4 = v12 - 1;
    *v10 = v4;
    v5 = v4 == 0;
    v6 = ~v11;
    if ( v5 )
    {
      *(_DWORD *)(a1 + 128) &= v6;
      result = 1;
    }
    goto LABEL_5;
  }
  return result;
}
