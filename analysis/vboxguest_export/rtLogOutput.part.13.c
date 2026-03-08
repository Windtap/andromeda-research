__int64 __fastcall rtLogOutput_part_13(__int64 a1, char *a2, unsigned __int64 a3)
{
  __int64 v3; // r14
  __int64 v7; // rdi
  size_t v8; // rbx

  v3 = 0;
  while ( 1 )
  {
    v7 = *(unsigned int *)(a1 + 49152);
    v8 = 49151 - v7;
    if ( a3 <= 49151 - v7 )
      v8 = a3;
    v3 += v8;
    memcpy((void *)(a1 + v7), a2, v8);
    *(_DWORD *)(a1 + 49152) += v8;
    a3 -= v8;
    if ( !a3 )
      break;
    a2 += v8;
    rtlogFlush_isra_12(a1);
  }
  return v3;
}
