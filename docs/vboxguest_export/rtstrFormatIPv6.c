__int64 __fastcall rtstrFormatIPv6(
        __int64 (*a1)(__int64, const char *, ...),
        __int64 a2,
        __int64 a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v12; // eax
  unsigned __int64 v13; // r14
  unsigned __int64 v14; // rdx
  unsigned __int64 v15; // r9
  unsigned __int64 v16; // r13
  unsigned __int64 v17; // rax
  unsigned __int64 v18; // rsi
  __int64 v19; // rbx
  __int16 v20; // si
  __int64 v21; // rax
  __int64 v22; // rbx
  unsigned __int64 v23; // r13
  __int64 v24; // rcx
  __int64 v25; // rax
  __int64 v26; // r15
  __int64 v27; // rax
  double v28; // xmm4_8
  double v29; // xmm5_8
  __int64 v30; // rax
  __int16 v31; // si
  __int64 v32; // r15
  __int64 v33; // rax
  __int64 v36; // [rsp+20h] [rbp-58h]
  unsigned __int64 v37; // [rsp+28h] [rbp-50h]
  bool v38; // [rsp+30h] [rbp-48h]
  _BYTE v39[56]; // [rsp+40h] [rbp-38h] BYREF

  if ( *(_QWORD *)a3 )
  {
    v13 = 8;
    v38 = 0;
  }
  else
  {
    v12 = *(_DWORD *)(a3 + 8);
    if ( v12 )
    {
      if ( v12 == -65536 )
      {
        v13 = 6;
        v38 = 1;
      }
      else
      {
        v38 = v12 == 0xFFFF;
        v13 = 2LL * (v12 != 0xFFFF) + 6;
      }
    }
    else
    {
      v13 = (*(_DWORD *)(a3 + 12) & 0xFEFFFFFF) == 0 ? 8LL : 6LL;
      v38 = (*(_DWORD *)(a3 + 12) & 0xFEFFFFFF) != 0;
    }
  }
  v14 = 0;
  v15 = 0;
  v16 = 0;
  while ( 1 )
  {
    v17 = v14;
    if ( !*(_WORD *)(a3 + 2 * v14) )
    {
      do
        ++v17;
      while ( v17 < v13 && !*(_WORD *)(a3 + 2 * v17) );
      v18 = v17 - v14;
      if ( v17 - v14 > v16 && v18 > 1 )
      {
        v15 = v14;
        v16 = v17 - v14;
        if ( v13 - v17 <= v18 )
          break;
      }
    }
    v14 = v17 + 1;
    if ( v17 + 1 >= v13 )
    {
      v19 = 0;
      if ( !v16 )
      {
        while ( 1 )
        {
          v20 = *(_WORD *)(a3 + 2 * v16++);
          v21 = rtstrFormatIPv6HexWord(v39, __ROR2__(v20, 8));
          v22 = a1(a2, v39, v21) + v19;
          if ( v16 >= v13 )
            break;
          v19 = a1(a2, ":", 1) + v22;
        }
        goto LABEL_30;
      }
      break;
    }
  }
  v23 = v15 + v16;
  if ( v15 )
  {
    v24 = 0;
    v22 = 0;
    do
    {
      v37 = v15;
      v36 = v24;
      v25 = rtstrFormatIPv6HexWord(v39, __ROR2__(*(_WORD *)(a3 + 2 * v24), 8));
      v26 = a1(a2, v39, v25);
      v27 = a1(a2, ":", 1);
      v15 = v37;
      v22 += v27 + v26;
      v24 = v36 + 1;
    }
    while ( v36 + 1 != v37 );
  }
  else
  {
    v22 = a1(a2, ":", 1);
  }
  if ( v23 == v13 )
  {
    v22 += a1(a2, ":", 1);
    if ( !v38 )
      return v22;
    goto LABEL_32;
  }
  while ( v23 < v13 )
  {
    v30 = a1(a2, ":", 1);
    v31 = *(_WORD *)(a3 + 2 * v23++);
    v32 = v30;
    v33 = rtstrFormatIPv6HexWord(v39, __ROR2__(v31, 8));
    v22 += a1(a2, v39, v33) + v32;
  }
LABEL_30:
  if ( !v38 )
    return v22;
  v22 += a1(a2, ":", 1);
LABEL_32:
  v22 += VBoxGuest_RTStrFormat(
           a1,
           a2,
           0,
           0,
           (__int64)"%u.%u.%u.%u",
           a4,
           a5,
           a6,
           a7,
           v28,
           v29,
           a10,
           a11,
           *(unsigned __int8 *)(a3 + 12),
           *(unsigned __int8 *)(a3 + 13),
           *(unsigned __int8 *)(a3 + 14),
           *(unsigned __int8 *)(a3 + 15));
  return v22;
}
