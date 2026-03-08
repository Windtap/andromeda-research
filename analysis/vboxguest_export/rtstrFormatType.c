__int64 __fastcall rtstrFormatType(
        __int64 (*a1)(__int64, const char *, ...),
        __int64 a2,
        _QWORD *a3,
        unsigned int *a4,
        unsigned int a5,
        unsigned int a6,
        __int64 a7)
{
  unsigned int v7; // eax
  __int64 *v8; // rsi
  _BYTE *v9; // rdi
  char v10; // al
  _BYTE *v11; // rcx
  char v12; // al
  size_t v13; // r14
  int v14; // r15d
  int v15; // r12d
  int i; // r13d
  __int64 v17; // rbx
  size_t v18; // rbp
  size_t v19; // rdx
  int v20; // eax
  __int64 v22; // rbx
  __int64 v23; // rbx
  __int64 v26; // [rsp+20h] [rbp-48h]

  v7 = *a4;
  if ( *a4 >= 0x30 )
  {
    v8 = (__int64 *)*((_QWORD *)a4 + 1);
    *((_QWORD *)a4 + 1) = v8 + 1;
  }
  else
  {
    v8 = (__int64 *)(*((_QWORD *)a4 + 2) + v7);
    *a4 = v7 + 8;
  }
  v26 = *v8;
  v9 = (_BYTE *)(*a3 + 2LL);
  *a3 = v9;
  v10 = *v9;
  if ( *v9 == 93 )
  {
    v11 = v9;
    v13 = 0;
  }
  else
  {
    if ( !v10 || v10 == 37 || v10 == 91 )
      return 0;
    v11 = v9;
    while ( 1 )
    {
      v12 = *++v11;
      if ( *v11 == 93 )
        break;
      if ( !v12 || v12 == 37 || v12 == 91 )
        return 0;
    }
    v13 = v11 - v9;
  }
  v14 = 0;
  *a3 = v11 + 1;
  v15 = g_cTypes - 1;
  for ( i = (g_cTypes - 1) / 2; ; i = v14 + (v15 - v14) / 2 )
  {
    v17 = (__int64)i << 6;
    v18 = (unsigned __int8)g_aTypes[v17];
    v19 = v18;
    if ( v13 <= v18 )
      v19 = v13;
    v20 = memcmp(v9, (char *)&unk_32141 + v17, v19);
    if ( v20 )
    {
      if ( v15 == v14 )
        goto LABEL_32;
      if ( v20 < 0 )
        goto LABEL_20;
      goto LABEL_23;
    }
    if ( v18 == v13 )
      break;
    if ( v18 > v13 )
    {
      if ( v15 == v14 )
        goto LABEL_32;
LABEL_20:
      v15 = i - 1;
      goto LABEL_24;
    }
    if ( v15 == v14 )
      goto LABEL_32;
LABEL_23:
    v14 = i + 1;
LABEL_24:
    if ( v15 < v14 )
      goto LABEL_32;
  }
  if ( i >= 0 )
  {
    _mm_mfence();
    return ((__int64 (__fastcall *)(__int64 (*)(__int64, const char *, ...), __int64, char *, __int64, _QWORD, _QWORD, __int64, __int64))qword_32170[8 * (__int64)i])(
             a1,
             a2,
             (char *)&unk_32141 + 64 * (__int64)i,
             v26,
             a5,
             a6,
             a7,
             qword_32148[8 * (__int64)i + 6]);
  }
LABEL_32:
  v22 = a1(a2, "<missing:%R[", 12);
  v23 = a1(a2, v9, v13) + v22;
  return v23 + a1(a2, "]>", 2);
}
