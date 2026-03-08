__int64 **__fastcall rtHeapSimpleAllocBlock(__int64 *a1, unsigned __int64 a2, __int64 a3)
{
  __int64 **v3; // rcx
  unsigned __int64 v4; // r8
  __int64 v5; // rax
  __int64 v6; // r10
  unsigned __int64 v7; // r9
  __int64 *v8; // rdx
  __int64 **result; // rax
  __int64 *v10; // r11
  __int64 *v11; // r15
  __int64 *v12; // r13
  __int64 *v13; // rbx
  __int64 *v14; // r12
  __int64 *v15; // rbp
  __int64 *v16; // rdx
  __int64 *v17; // rdx
  __int64 *v18; // rdx
  __int64 *v19; // rsi
  __int64 *v20; // rsi
  __int64 v21; // rsi
  __int64 v22; // rsi
  __int64 *v23; // rdx
  __int64 *v24; // rdx
  __int64 *v25; // [rsp+0h] [rbp-38h]

  v3 = (__int64 **)a1[4];
  if ( !v3 )
    return 0;
  while ( 1 )
  {
    v4 = (unsigned __int64)v3[6];
    if ( v4 >= a2 )
    {
      v5 = (a3 - 1) & (unsigned __int64)(v3 + 4);
      if ( !v5 )
      {
        result = v3;
        goto LABEL_12;
      }
      v6 = a3 - v5;
      v7 = v4 - (a3 - v5);
      if ( a2 <= v7 )
        break;
    }
    v3 = (__int64 **)v3[4];
    if ( !v3 )
      return 0;
  }
  v8 = v3[1];
  result = (__int64 **)((char *)v3 + v6);
  v10 = *v3;
  v11 = v3[2];
  v12 = v3[3];
  v13 = v3[4];
  v14 = v3[5];
  v15 = v3[7];
  v3 = (__int64 **)((char *)v3 + v6);
  if ( v8 )
  {
    *v8 = (__int64)result;
    v25 = v8;
  }
  else
  {
    a1[9] = 0;
    v25 = a1 + 8;
    a1[8] = (__int64)result;
    a1[10] = (__int64)a1;
    a1[11] = 2882400000LL;
  }
  a1[3] -= v6;
  *result = v10;
  result[1] = v8;
  result[2] = v11;
  result[3] = v12;
  result[4] = v13;
  result[5] = v14;
  result[6] = (__int64 *)v4;
  result[7] = v15;
  if ( v10 )
  {
    v10[1] = (__int64)result;
    v16 = result[4];
    v7 = (unsigned __int64)result[6] - v6;
  }
  else
  {
    v16 = v13;
  }
  result[6] = (__int64 *)v7;
  result[1] = v25;
  if ( v16 )
  {
    v16[5] = (__int64)result;
    v17 = result[5];
    if ( v17 )
    {
LABEL_11:
      v17[4] = (__int64)result;
      v4 = (unsigned __int64)result[6];
      goto LABEL_12;
    }
  }
  else
  {
    a1[5] = (__int64)result;
    v17 = result[5];
    if ( v17 )
      goto LABEL_11;
  }
  a1[4] = (__int64)result;
  v4 = (unsigned __int64)result[6];
LABEL_12:
  if ( a2 + 64 > v4 )
  {
    v23 = v3[4];
    if ( v23 )
      v23[5] = (__int64)v3[5];
    else
      a1[5] = (__int64)v3[5];
    v24 = v3[5];
    if ( v24 )
      v24[4] = (__int64)v3[4];
    else
      a1[4] = (__int64)v3[4];
    a1[3] -= (__int64)v3[6];
    v3[3] = (__int64 *)((unsigned __int64)v3[3] & 0xFFFFFFFFFFFFFFFELL);
  }
  else
  {
    v18 = (__int64 *)((char *)result + a2 + 32);
    *v18 = (__int64)*v3;
    if ( *v3 )
      (*v3)[1] = (__int64)v18;
    *(__int64 **)((char *)result + a2 + 40) = (__int64 *)result;
    *(__int64 **)((char *)result + a2 + 48) = a1;
    *(__int64 **)((char *)result + a2 + 56) = (__int64 *)2882400001LL;
    v19 = v3[4];
    v18[4] = (__int64)v19;
    if ( v19 )
      v19[5] = (__int64)v18;
    else
      a1[5] = (__int64)v18;
    v20 = v3[5];
    v18[5] = (__int64)v20;
    if ( v20 )
      v20[4] = (__int64)v18;
    else
      a1[4] = (__int64)v18;
    v21 = *v18;
    if ( !*v18 )
      v21 = a1[2];
    v18[6] = v21 - (_QWORD)v18 - 32;
    v3[3] = (__int64 *)((unsigned __int64)v3[3] & 0xFFFFFFFFFFFFFFFELL);
    *v3 = v18;
    v22 = a1[3] - (_QWORD)v3[6];
    a1[3] = v22;
    a1[3] = v18[6] + v22;
  }
  return result;
}
