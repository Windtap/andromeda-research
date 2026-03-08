unsigned __int64 *__fastcall VBoxGuest_RTAvlPVRemove(unsigned __int64 **a1, unsigned __int64 a2)
{
  __int64 i; // rdx
  unsigned __int64 v3; // r8
  __int64 v4; // r9
  unsigned __int64 **v5; // rax
  unsigned __int64 *result; // rax
  unsigned int v7; // ecx
  unsigned __int64 v8; // r8
  __int64 v9; // r11
  unsigned __int64 v10; // rdx
  _QWORD *v11; // r10
  unsigned __int64 v12; // rsi
  __int64 *v13; // r8
  __int64 v14; // rdx
  __int64 v15; // rsi
  unsigned __int8 v16; // r9
  int v17; // r10d
  __int64 v18; // rdi
  unsigned __int8 v19; // r11
  int v20; // ebx
  int v21; // ebp
  __int64 v22; // rdi
  __int64 v23; // r11
  unsigned __int8 v24; // r10
  int v25; // ebx
  int v26; // r11d
  __int64 v27; // rsi
  __int64 v28; // r10
  unsigned __int8 v29; // r9
  int v30; // ebx
  int v31; // r10d
  char v32; // si
  _QWORD v33[29]; // [rsp+8h] [rbp-E8h]

  for ( i = 0; ; ++i )
  {
    result = *a1;
    v7 = i;
    if ( !*a1 )
      break;
    v3 = *result;
    v4 = (unsigned int)(i + 1);
    v33[i] = a1;
    if ( v3 == a2 )
    {
      v8 = result[1];
      v9 = (unsigned int)v4;
      if ( v8 )
      {
        v10 = *(_QWORD *)(v8 + 16);
        v11 = result + 1;
        if ( v10 )
        {
          while ( 1 )
          {
            v12 = *(_QWORD *)(v10 + 16);
            v33[v4] = v11;
            v7 = v4 + 1;
            v11 = (_QWORD *)(v8 + 16);
            if ( !v12 )
              break;
            v8 = v10;
            v4 = v7;
            v10 = v12;
          }
        }
        else
        {
          v7 = v4;
          v10 = result[1];
        }
        *v11 = *(_QWORD *)(v10 + 8);
        *(_QWORD *)(v10 + 8) = result[1];
        *(_QWORD *)(v10 + 16) = result[2];
        *(_BYTE *)(v10 + 24) = *((_BYTE *)result + 24);
        *a1 = (unsigned __int64 *)v10;
        v33[v9] = v10 + 8;
      }
      else
      {
        *a1 = (unsigned __int64 *)result[2];
      }
      while ( 1 )
      {
LABEL_15:
        if ( !v7 )
          return result;
        while ( 1 )
        {
          v13 = (__int64 *)v33[--v7];
          v14 = *v13;
          v15 = *(_QWORD *)(*v13 + 8);
          if ( v15 )
          {
            v16 = *(_BYTE *)(v15 + 24);
            v17 = v16;
          }
          else
          {
            v17 = 0;
            v16 = 0;
          }
          v18 = *(_QWORD *)(v14 + 16);
          if ( v18 )
          {
            v19 = *(_BYTE *)(v18 + 24);
            v20 = v19;
            v21 = v19 + 1;
          }
          else
          {
            v21 = 1;
            v20 = 0;
            v19 = 0;
          }
          if ( v17 <= v21 )
            break;
          v22 = *(_QWORD *)(v15 + 16);
          v23 = *(_QWORD *)(v15 + 8);
          if ( v22 )
          {
            v24 = *(_BYTE *)(v22 + 24);
            v25 = v24;
          }
          else
          {
            v25 = 0;
            v24 = 0;
          }
          if ( v23 )
            v26 = *(unsigned __int8 *)(v23 + 24);
          else
            v26 = 0;
          if ( v26 < v25 )
          {
            *(_QWORD *)(v15 + 16) = *(_QWORD *)(v22 + 8);
            *(_QWORD *)(v14 + 8) = *(_QWORD *)(v22 + 16);
            *(_QWORD *)(v22 + 8) = v15;
            *(_QWORD *)(v22 + 16) = v14;
            *(_BYTE *)(v14 + 24) = v24;
            *(_BYTE *)(v15 + 24) = v24;
            *(_BYTE *)(v22 + 24) = v16;
            *v13 = v22;
            goto LABEL_15;
          }
          *(_QWORD *)(v14 + 8) = v22;
          *(_QWORD *)(v15 + 16) = v14;
          *(_BYTE *)(v14 + 24) = v24 + 1;
          *(_BYTE *)(v15 + 24) = v24 + 2;
          *v13 = v15;
          if ( !v7 )
            return result;
        }
        if ( v20 > v17 + 1 )
          break;
        v32 = v16 + 1;
        if ( v19 > v16 )
          v32 = v19 + 1;
        if ( *(_BYTE *)(v14 + 24) == v32 )
          return result;
        *(_BYTE *)(v14 + 24) = v32;
      }
      v27 = *(_QWORD *)(v18 + 8);
      if ( v27 )
      {
        v28 = *(_QWORD *)(v18 + 16);
        v29 = *(_BYTE *)(v27 + 24);
        v30 = v29;
        if ( v28 )
          goto LABEL_31;
LABEL_45:
        v31 = 0;
      }
      else
      {
        v28 = *(_QWORD *)(v18 + 16);
        v30 = 0;
        v29 = 0;
        if ( !v28 )
          goto LABEL_45;
LABEL_31:
        v31 = *(unsigned __int8 *)(v28 + 24);
      }
      if ( v31 < v30 )
      {
        *(_QWORD *)(v18 + 8) = *(_QWORD *)(v27 + 16);
        *(_QWORD *)(v14 + 16) = *(_QWORD *)(v27 + 8);
        *(_QWORD *)(v27 + 16) = v18;
        *(_QWORD *)(v27 + 8) = v14;
        *(_BYTE *)(v14 + 24) = v29;
        *(_BYTE *)(v18 + 24) = v29;
        *(_BYTE *)(v27 + 24) = v19;
        *v13 = v27;
      }
      else
      {
        *(_QWORD *)(v14 + 16) = v27;
        *(_QWORD *)(v18 + 8) = v14;
        *(_BYTE *)(v14 + 24) = v29 + 1;
        *(_BYTE *)(v18 + 24) = v29 + 2;
        *v13 = v18;
      }
      goto LABEL_15;
    }
    a1 = (unsigned __int64 **)(result + 1);
    v5 = (unsigned __int64 **)(result + 2);
    if ( v3 <= a2 )
      a1 = v5;
  }
  return 0;
}
