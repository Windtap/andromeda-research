__int64 __fastcall VBoxGuest_RTLogGetFlags(__int64 a1, _BYTE *a2, unsigned __int64 a3)
{
  _BYTE *v4; // r12
  int v5; // r14d
  char *v6; // rbx
  unsigned __int8 v7; // dl
  bool v8; // al
  size_t v9; // rbp
  void *v10; // rdi
  __int64 result; // rax

  v4 = a2;
  if ( !a1 )
  {
    a1 = VBoxGuest_RTLogDefaultInstance();
    if ( !a1 )
    {
      *a2 = 0;
      return 0;
    }
  }
  v5 = *(_DWORD *)(a1 + 49160);
  v6 = &byte_25114;
  v7 = 0;
  while ( 1 )
  {
    if ( *v6 )
      v8 = (v5 & *((_DWORD *)v6 - 1)) == 0;
    else
      v8 = (v5 & *((_DWORD *)v6 - 1)) != 0;
    if ( !v8 )
      goto LABEL_9;
    v9 = *(_QWORD *)(v6 - 12);
    if ( v9 + v7 + 1 > a3 )
      break;
    if ( v7 )
    {
      *v4 = 32;
      --a3;
      ++v4;
    }
    v10 = v4;
    a3 -= v9;
    v4 += v9;
    memcpy(v10, *(const void **)(v6 - 20), v9);
    v7 = 1;
LABEL_9:
    v6 += 32;
    if ( v6 == (char *)&jpt_1A3E7[2] + 4 )
    {
      result = 0;
      goto LABEL_13;
    }
  }
  result = 4294967255LL;
LABEL_13:
  *v4 = 0;
  return result;
}
