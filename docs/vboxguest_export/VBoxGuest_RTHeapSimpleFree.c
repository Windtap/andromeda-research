void __fastcall VBoxGuest_RTHeapSimpleFree(__int64 a1, _QWORD *a2)
{
  _QWORD *v2; // rcx
  _QWORD *v3; // r8
  _QWORD *v4; // rdi
  _QWORD *v5; // rdx
  __int64 v6; // r9
  __int64 *v7; // rax
  _QWORD *v8; // r10
  bool v9; // zf
  __int64 v10; // rax
  __int64 v11; // rdx
  __int64 v12; // rsi

  if ( !a2 )
    return;
  v2 = (_QWORD *)*(a2 - 2);
  v3 = a2 - 4;
  v4 = a2 - 4;
  v5 = (_QWORD *)v2[5];
  if ( !v5 )
  {
    if ( a2 == (_QWORD *)&loc_20 )
      return;
    *(a2 - 1) |= 1uLL;
    a2[1] = 0;
    v7 = 0;
    *a2 = 0;
    v2[5] = v3;
    goto LABEL_21;
  }
  v6 = *(a2 - 4);
  if ( v6 )
  {
    v7 = (__int64 *)*(a2 - 4);
    if ( (*(_BYTE *)(v6 + 24) & 1) != 0 )
    {
LABEL_11:
      v5 = (_QWORD *)v7[5];
      if ( v3 == v5 )
        return;
      if ( v5 )
        goto LABEL_13;
      *(a2 - 1) |= 1uLL;
      a2[1] = 0;
      *a2 = v7;
      v7[5] = (__int64)v3;
LABEL_21:
      v2[4] = v3;
      goto LABEL_22;
    }
    while ( 1 )
    {
      v7 = (__int64 *)*v7;
      if ( !v7 )
        break;
      if ( (v7[3] & 1) != 0 )
        goto LABEL_11;
    }
  }
  v7 = 0;
  if ( v3 == v5 )
    return;
LABEL_13:
  v8 = a2 - 4;
  if ( (_QWORD *)*v5 == v3 )
  {
    *v5 = v6;
    v12 = *(a2 - 4);
    if ( v12 )
      *(_QWORD *)(v12 + 8) = v5;
    v4 = v5;
    v2[3] -= v5[6];
LABEL_22:
    if ( !v7 )
      goto LABEL_16;
    v8 = v4;
    if ( (_QWORD *)v7[1] != v4 )
      goto LABEL_16;
LABEL_24:
    *v4 = *v7;
    if ( *v7 )
      *(_QWORD *)(*v7 + 8) = v8;
    v4[4] = v7[4];
    v11 = v7[4];
    if ( v11 )
      *(_QWORD *)(v11 + 40) = v4;
    else
      v2[5] = v4;
    v2[3] -= v7[6];
    goto LABEL_16;
  }
  *(a2 - 1) |= 1uLL;
  *a2 = v7;
  a2[1] = v5;
  v5[4] = v3;
  if ( !v7 )
  {
    v2[5] = v3;
    goto LABEL_16;
  }
  v9 = v7[1] == (_QWORD)v3;
  v7[5] = (__int64)v3;
  if ( v9 )
    goto LABEL_24;
LABEL_16:
  if ( *v4 )
    v10 = *v4 - (_QWORD)v4 - 32LL;
  else
    v10 = v2[2] - (_QWORD)v4 - 32LL;
  v4[6] = v10;
  v2[3] += v10;
}
