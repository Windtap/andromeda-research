__int64 __fastcall vbsf_nlscpy(__int64 a1, _BYTE *a2, unsigned __int64 a3, char *a4, __int64 a5)
{
  char *v5; // r12
  _BYTE *v6; // rbp
  __int64 v7; // rbx
  unsigned int v8; // r13d
  __int64 result; // rax
  int v10; // r15d
  unsigned __int16 v11[26]; // [rsp+4h] [rbp-34h] BYREF

  v5 = a4;
  v6 = a2;
  v7 = a5;
  if ( *(_QWORD *)(a1 + 8) )
  {
    v8 = a3 - 1;
    if ( a5 )
    {
      while ( 1 )
      {
        v10 = utf8_to_utf32(v5, (unsigned int)v7, v11);
        if ( v10 < 0 )
          return 4294967274LL;
        result = (*(__int64 (__fastcall **)(_QWORD, _BYTE *, _QWORD))(*(_QWORD *)(a1 + 8) + 16LL))(v11[0], v6, v8);
        if ( (int)result < 0 )
          return result;
        v6 += (int)result;
        v8 -= result;
        v5 += v10;
        v7 -= v10;
        if ( !v7 )
          goto LABEL_9;
      }
    }
    else
    {
LABEL_9:
      *v6 = 0;
      return 0;
    }
  }
  else
  {
    result = 4294967260LL;
    if ( a3 >= a5 + 1 )
    {
      memcpy(a2, a4, a5 + 1);
      return 0;
    }
  }
  return result;
}
