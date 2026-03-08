size_t __fastcall rtLogRingBufWrite(__int64 a1, char *a2, size_t a3)
{
  _BYTE *v4; // rcx
  _BYTE *v5; // r14
  size_t v6; // rbx
  size_t v7; // r15
  size_t i; // rbp
  char *v9; // r13
  size_t result; // rax
  _BYTE *v11; // rbp
  _BYTE *v12; // rax
  __int64 v13; // [rsp+0h] [rbp-38h]

  v4 = *(_BYTE **)(a1 + 88);
  v5 = (_BYTE *)(*(_QWORD *)(a1 + 80) + 16LL);
  v6 = *(unsigned int *)(a1 + 68) - 32LL;
  v7 = v6;
  if ( v6 <= v4 - v5 )
    v4 = (_BYTE *)(*(_QWORD *)(a1 + 80) + 16LL);
  else
    v7 = v6 - (v4 - v5);
  if ( v7 > a3 )
  {
    v12 = memcpy(v4, a2, a3);
    v12[a3] = 0;
    *(_QWORD *)(a1 + 88) = &v12[a3];
    result = *(_QWORD *)(a1 + 72);
    *(_QWORD *)(a1 + 72) = result + a3;
  }
  else
  {
    v13 = *(unsigned int *)(a1 + 68);
    i = a3 - v7;
    v9 = &a2[v7];
    memcpy(v4, a2, v7);
    result = *(_QWORD *)(a1 + 72);
    *(_QWORD *)(a1 + 72) = result + v7;
    *(_QWORD *)(a1 + 88) = v5;
    if ( v6 <= i )
    {
      for ( i = i - v13 + 32; ; i -= v6 )
      {
        memcpy(v5, v9, v6);
        v9 += v6;
        *(_QWORD *)(a1 + 72) += v6;
        result = i - v6;
        if ( v6 > i )
          break;
      }
    }
    if ( i )
    {
      memcpy(v5, v9, i);
      result = i + *(_QWORD *)(a1 + 72);
      *(_QWORD *)(a1 + 72) = result;
    }
    v11 = &v5[i];
    *v11 = 0;
    *(_QWORD *)(a1 + 88) = v11;
  }
  return result;
}
