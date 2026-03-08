unsigned __int64 __fastcall vbsf_iter_max_span_of_pages(int *a1)
{
  int v1; // edx
  __int64 v2; // rsi
  __int64 v3; // rdx
  unsigned __int64 v4; // rax
  __int64 v5; // rcx
  unsigned __int64 v6; // rdi
  unsigned __int64 result; // rax
  unsigned __int64 v8; // rsi
  unsigned __int64 v9; // r8
  unsigned __int64 v10; // rcx
  __int64 v11; // rax
  unsigned __int64 v12; // rsi
  unsigned __int64 v13; // r8
  __int64 v14; // rcx

  v1 = *a1;
  if ( (*a1 & 6) == 0 || (v1 & 2) != 0 )
  {
    v2 = *((_QWORD *)a1 + 4);
    v3 = *((_QWORD *)a1 + 3);
    if ( !v2 )
      return 1;
    v4 = *((_QWORD *)a1 + 1);
    if ( !v4 )
    {
      v5 = v2 - 1;
      v6 = 0;
      result = 1;
      goto LABEL_9;
    }
    v10 = *(_QWORD *)(v3 + 8);
    if ( v4 < v10 )
    {
      v6 = 0;
      v14 = ((*(_DWORD *)v3 + (_DWORD)v4) & 0xFFF) + v10 - v4;
      result = (unsigned __int64)(v14 + 4095) >> 12;
      if ( (v14 & 0xFFF) == 0 )
        v6 = (unsigned __int64)(v14 + 4095) >> 12;
    }
    else
    {
      v6 = 0;
      result = 1;
    }
    v5 = v2 - 2;
    v3 += 16;
    if ( v2 == 1 )
    {
LABEL_15:
      if ( v6 >= result )
        return v6;
      return result;
    }
    while ( 1 )
    {
LABEL_9:
      while ( 1 )
      {
        v8 = *(_QWORD *)(v3 + 8);
        if ( v8 )
          break;
LABEL_8:
        --v5;
        v3 += 16;
        if ( v5 == -1 )
          goto LABEL_15;
      }
      if ( (*(_QWORD *)v3 & 0xFFF) == 0 )
      {
        if ( (v8 & 0xFFF) != 0 )
        {
          v12 = v6 + ((v8 + 4095) >> 12);
          if ( result < v12 )
            result = v12;
          v6 = 0;
        }
        else
        {
          v6 += v8 >> 12;
        }
        goto LABEL_8;
      }
      if ( result < v6 )
        result = v6;
      v9 = v8 + (*(_QWORD *)v3 & 0xFFFLL);
      if ( (v9 & 0xFFF) != 0 )
      {
        v13 = v6 + ((v9 + 4095) >> 12);
        if ( result < v13 )
          result = v13;
        v6 = 0;
        goto LABEL_8;
      }
      --v5;
      v3 += 16;
      v6 = v8 >> 12;
      if ( v5 == -1 )
        goto LABEL_15;
    }
  }
  v11 = 8190;
  if ( (v1 & 4) != 0 )
  {
    LOWORD(v11) = 1;
    if ( *((_QWORD *)a1 + 4) )
      v11 = *((_QWORD *)a1 + 4);
    v11 *= 8190;
  }
  return (unsigned __int64)(*((_QWORD *)a1 + 2) + v11) >> 12;
}
