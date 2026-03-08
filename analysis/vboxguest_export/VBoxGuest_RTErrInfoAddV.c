__int64 __fastcall VBoxGuest_RTErrInfoAddV(__int64 a1, unsigned int a2, _BYTE *a3, __int64 *a4)
{
  __int64 v5; // r13
  const void *v6; // rbp
  _BYTE *v7; // rax

  if ( !a1 )
    return a2;
  if ( (*(_BYTE *)a1 & 4) != 0 )
  {
    v5 = *(_QWORD *)(a1 + 8);
    v6 = *(const void **)(a1 + 16);
    v7 = memchr(v6, 0, v5 - 2);
    if ( v7 )
      VBoxGuest_RTStrPrintfV((__int64)v7, (_BYTE *)v6 + v5 - v7, (__int64)a3, a4);
    return a2;
  }
  while ( *a3 == 32 )
    ++a3;
  VBoxGuest_RTStrPrintfV(*(_QWORD *)(a1 + 16), *(_QWORD *)(a1 + 8), (__int64)a3, a4);
  *(_DWORD *)(a1 + 4) = a2;
  *(_DWORD *)a1 |= 4u;
  return a2;
}
