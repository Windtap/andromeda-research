__int64 __fastcall vbsf_iter_lock_pages_constprop_23(
        int *a1,
        unsigned __int8 a2,
        _QWORD *a3,
        unsigned __int64 a4,
        _QWORD *a5,
        unsigned __int64 *a6,
        _QWORD *a7,
        __int64 *a8)
{
  unsigned __int64 v9; // rbp
  int v11; // eax
  __int64 result; // rax
  __int64 v13; // rdx
  __int64 v14; // rdx
  __int64 v15; // r13
  unsigned __int64 v16; // r12
  __int64 v17; // rdx
  __int64 v18; // r14
  __int64 v19; // rax
  __int64 v20; // r15
  __int16 v21; // r15
  __int64 v22; // r15
  __int64 v23; // rax
  _QWORD *v24; // rax
  unsigned __int64 v25; // rdi
  __int64 v26; // r14
  unsigned __int64 v27; // r13
  unsigned int v28; // ebp
  __int64 v29; // rcx
  __int64 v31; // [rsp+8h] [rbp-60h]
  unsigned __int64 v32; // [rsp+8h] [rbp-60h]
  __int64 v33; // [rsp+8h] [rbp-60h]
  _QWORD *v35; // [rsp+20h] [rbp-48h]
  __int64 v36; // [rsp+28h] [rbp-40h] BYREF
  _QWORD v37[7]; // [rsp+30h] [rbp-38h] BYREF

  v9 = a4;
  v11 = *a1;
  v36 = 0;
  result = v11 & 2;
  if ( (_DWORD)result )
  {
    v16 = 0;
    v33 = 0;
    a3[3] = *((_QWORD *)a1 + 2);
    a3[4] = *(_QWORD *)a1;
    a3[5] = *((_QWORD *)a1 + 1);
    a3[6] = *((_QWORD *)a1 + 2);
    a3[7] = *((_QWORD *)a1 + 3);
    a3[8] = *((_QWORD *)a1 + 4);
    while ( 1 )
    {
      v22 = iov_iter_single_seg_count(a1);
      if ( !v22 )
      {
        do
        {
          iov_iter_advance(a1, 0);
          v23 = iov_iter_single_seg_count(a1);
        }
        while ( !v23 );
        v22 = v23;
      }
      v24 = (_QWORD *)*((_QWORD *)a1 + 3);
      v25 = *((_QWORD *)a1 + 1) + *v24;
      v26 = (*((_WORD *)a1 + 4) + *(_WORD *)v24) & 0xFFF;
      if ( v16 )
      {
        if ( ((*((_WORD *)a1 + 4) + *(_WORD *)v24) & 0xFFF) != 0 )
          goto LABEL_37;
      }
      else
      {
        v36 = (*((_WORD *)a1 + 4) + *(_WORD *)v24) & 0xFFF;
      }
      v27 = (unsigned __int64)(v22 + 4095) >> 12;
      if ( v27 > v9 )
      {
        v27 = v9;
        v22 = (v9 << 12) - v26;
      }
      result = vbsf_lock_kernel_pages(v25, a2, v27, (__int64)&a5[v16]);
      if ( (_DWORD)result )
        goto LABEL_46;
      v16 += v27;
      iov_iter_advance(a1, v22);
      v33 += v22;
      v9 -= v27;
      if ( !v9 || (((_DWORD)v22 + (_DWORD)v26) & 0xFFF) != 0 || !*((_QWORD *)a1 + 2) )
      {
LABEL_37:
        v15 = v33;
LABEL_38:
        v17 = v36;
LABEL_39:
        result = 0;
        goto LABEL_40;
      }
    }
  }
  v13 = *a3;
  if ( v13 )
  {
    *a5 = v13;
    v14 = a3[1];
    *a3 = 0;
    v15 = a3[2];
    a3[1] = 0;
    a3[2] = 0;
    v36 = v14;
    if ( (unsigned __int64)(v15 + v14) <= 0xFFF || !*((_QWORD *)a1 + 2) )
    {
      *a7 = v14;
      *a8 = v15;
      *a6 = 1;
      return result;
    }
    v9 = a4 - 1;
    v16 = 1;
  }
  else
  {
    v16 = 0;
    v15 = 0;
    a3[3] = *((_QWORD *)a1 + 2);
    a3[4] = *(_QWORD *)a1;
    a3[5] = *((_QWORD *)a1 + 1);
    a3[6] = *((_QWORD *)a1 + 2);
    a3[7] = *((_QWORD *)a1 + 3);
    a3[8] = *((_QWORD *)a1 + 4);
  }
  v35 = a3;
  while ( v16 )
  {
    v18 = iov_iter_single_seg_count(a1);
    if ( !v18 )
    {
      do
      {
        iov_iter_advance(a1, 0);
        v19 = iov_iter_single_seg_count(a1);
      }
      while ( !v19 );
      v18 = v19;
    }
    v20 = v16;
    result = iov_iter_get_pages(a1, &a5[v16], *((_QWORD *)a1 + 2), 1, v37);
    if ( result <= 0 )
    {
      if ( !result )
        goto LABEL_54;
LABEL_45:
      if ( (_DWORD)result )
      {
LABEL_46:
        if ( v16 )
        {
          v28 = result;
          do
            put_page(a5[--v16]);
          while ( v16 );
          result = v28;
        }
        goto LABEL_47;
      }
LABEL_24:
      v17 = v36;
      goto LABEL_40;
    }
    v31 = result;
    iov_iter_advance(a1, result);
    if ( v37[0] )
    {
      v29 = a5[v16];
      v35[1] = v37[0];
      v35[2] = v31;
      *v35 = v29;
LABEL_23:
      result = 0;
      goto LABEL_24;
    }
    v15 += v31;
    ++v16;
    --v9;
    if ( v31 != 4096 || !v9 )
      goto LABEL_23;
    if ( v18 != 4096 )
    {
      result = iov_iter_get_pages(a1, &a5[v20 + 1], *((_QWORD *)a1 + 2), (unsigned int)v9, v37);
      v21 = result;
      if ( result <= 0 )
      {
        if ( result )
          goto LABEL_45;
LABEL_54:
        result = 4294967282LL;
        goto LABEL_46;
      }
      v15 += result;
      v32 = (unsigned __int64)(result + 4095) >> 12;
      iov_iter_advance(a1, result);
      v16 += v32;
      v9 -= v32;
      if ( !v9 || (v21 & 0xFFF) != 0 )
        goto LABEL_23;
    }
LABEL_10:
    if ( !*((_QWORD *)a1 + 2) )
      goto LABEL_38;
  }
  result = iov_iter_get_pages(a1, a5, *((_QWORD *)a1 + 2), (unsigned int)v9, &v36);
  if ( result > 0 )
  {
    v15 = result;
    iov_iter_advance(a1, result);
    v17 = v36;
    v16 = (unsigned __int64)(v15 + v36 + 4095) >> 12;
    v9 -= v16;
    if ( !v9 || (((_WORD)v15 + (_WORD)v36) & 0xFFF) != 0 )
      goto LABEL_39;
    goto LABEL_10;
  }
  if ( result )
    goto LABEL_45;
  result = 4294967282LL;
LABEL_47:
  v17 = 0;
  v16 = 0;
  v15 = 0;
LABEL_40:
  *a7 = v17;
  *a8 = v15;
  *a6 = v16;
  return result;
}
