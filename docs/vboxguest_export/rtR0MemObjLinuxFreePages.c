__int64 __fastcall rtR0MemObjLinuxFreePages(__int64 a1)
{
  __int64 result; // rax
  unsigned __int64 v2; // rax
  int v3; // esi
  __int64 v4; // rax
  __int64 v5; // rbp

  result = *(_QWORD *)(a1 + 88);
  if ( result )
  {
    --result;
    do
      _InterlockedAnd8((volatile signed __int8 *)(*(_QWORD *)(a1 + 8 * result-- + 96) + 1LL), 0xFBu);
    while ( result != -1 );
    if ( *(_BYTE *)(a1 + 64) )
    {
      v2 = *(_QWORD *)(a1 + 88) >> 1;
      if ( v2 )
      {
        v3 = 0;
        do
        {
          ++v3;
          v2 >>= 1;
        }
        while ( v2 );
        v4 = __ROL8__(-2, v3);
      }
      else
      {
        v4 = -2;
        v3 = 0;
      }
      result = _free_pages(*(_QWORD *)(a1 + 96), v3 - ((unsigned int)((*(_QWORD *)(a1 + 88) & v4) == 0) - 1));
      goto LABEL_10;
    }
    v5 = *(_QWORD *)(a1 + 88);
    if ( !v5 )
    {
LABEL_10:
      *(_QWORD *)(a1 + 88) = 0;
      return result;
    }
    do
      result = _free_pages(*(_QWORD *)(a1 + 8 * v5-- + 88), 0);
    while ( v5 );
    *(_QWORD *)(a1 + 88) = 0;
  }
  return result;
}
