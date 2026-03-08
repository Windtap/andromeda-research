__int64 __fastcall vbsf_nls_to_shflstring(__int64 a1, const char *a2, _QWORD *a3)
{
  size_t v4; // rbp
  __int64 v5; // rax
  unsigned __int64 v6; // r15
  unsigned __int64 v7; // rbx
  int v8; // eax
  int v9; // r14d
  __int64 result; // rax
  __int64 v11; // rdi
  _WORD *v12; // rcx
  _BYTE *v13; // r14
  unsigned __int64 v14; // r15
  int v15; // eax
  _WORD *v16; // rbx
  int v17; // [rsp+0h] [rbp-60h]
  _WORD *v19; // [rsp+10h] [rbp-50h]
  unsigned __int16 v20; // [rsp+1Eh] [rbp-42h] BYREF
  _WORD v21[32]; // [rsp+20h] [rbp-40h] BYREF

  v4 = strlen(a2);
  v5 = *(_QWORD *)(a1 + 8);
  if ( v5 )
  {
    if ( v4 )
    {
      v6 = 0;
      v7 = 0;
      while ( 1 )
      {
        v9 = (*(__int64 (__fastcall **)(const char *, _QWORD, unsigned __int16 *))(v5 + 24))(
               &a2[v6],
               (unsigned int)(v4 - v6),
               &v20);
        if ( v9 < 0 )
          return 4294967274LL;
        v8 = utf32_to_utf8(v20, v21, 16);
        if ( v8 <= 0 )
          return 4294967274LL;
        v6 += v9;
        v7 += v8;
        if ( v4 <= v6 )
          break;
        v5 = *(_QWORD *)(a1 + 8);
      }
      if ( v7 + 1 > 0xFFFF )
        goto LABEL_10;
      v11 = v7 + 5;
    }
    else
    {
      v11 = 5;
      v7 = 0;
    }
    v12 = (_WORD *)_kmalloc(v11, 37748928);
    v19 = v12;
    result = 4294967284LL;
    if ( v12 )
    {
      v12[1] = v7;
      v13 = v12 + 2;
      *v12 = v7 + 1;
      if ( v4 )
      {
        v14 = 0;
        while ( 1 )
        {
          v17 = (*(__int64 (__fastcall **)(const char *, _QWORD, _WORD *))(*(_QWORD *)(a1 + 8) + 24LL))(
                  &a2[v14],
                  (unsigned int)(v4 - v14),
                  v21);
          if ( v17 < 0 )
            break;
          v15 = utf32_to_utf8(v21[0], v13, (unsigned int)v7);
          if ( v15 <= 0 || v15 > v7 )
            break;
          v7 -= v15;
          v13 += v15;
          v14 += v17;
          if ( v4 <= v14 )
            goto LABEL_24;
        }
        kfree(v19);
        result = 4294967274LL;
        v19 = 0;
      }
      else
      {
LABEL_24:
        *v13 = 0;
        result = 0;
      }
    }
    goto LABEL_11;
  }
  if ( v4 + 1 <= 0xFFFF )
  {
    v16 = (_WORD *)_kmalloc(v4 + 5, 37748928);
    v19 = v16;
    result = 4294967284LL;
    if ( v16 )
    {
      v16[1] = v4;
      *v16 = v4 + 1;
      memcpy(v16 + 2, a2, v4);
      *((_BYTE *)v16 + v4 + 4) = 0;
      result = 0;
    }
    goto LABEL_11;
  }
LABEL_10:
  v19 = 0;
  result = 4294967260LL;
LABEL_11:
  *a3 = v19;
  return result;
}
