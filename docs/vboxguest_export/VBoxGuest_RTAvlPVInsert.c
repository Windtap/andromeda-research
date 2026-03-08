__int64 __fastcall VBoxGuest_RTAvlPVInsert(unsigned __int64 **a1, unsigned __int64 *a2)
{
  __int64 v2; // rcx
  unsigned __int64 v3; // r8
  unsigned __int64 v4; // rdx
  unsigned __int64 **v5; // rax
  unsigned __int64 *v6; // rax
  int v7; // edx
  __int64 *v8; // rdi
  __int64 v9; // rax
  __int64 v10; // rcx
  unsigned __int8 v11; // r8
  int v12; // r9d
  __int64 v13; // rsi
  unsigned __int8 v14; // r10
  int v15; // r11d
  int v16; // ebx
  __int64 v17; // rsi
  __int64 v18; // r10
  unsigned __int8 v19; // r9
  int v20; // r11d
  int v21; // r10d
  __int64 v23; // rcx
  unsigned __int8 v24; // r8
  int v25; // r11d
  __int64 v26; // r9
  int v27; // r9d
  char v28; // cl
  _QWORD v29[28]; // [rsp+8h] [rbp-E0h]

  v2 = 0;
  v3 = *a2;
  while ( 1 )
  {
    v6 = *a1;
    v7 = v2;
    if ( !*a1 )
    {
      a2[2] = 0;
      a2[1] = 0;
      *((_BYTE *)a2 + 24) = 1;
      *a1 = a2;
LABEL_8:
      if ( !v7 )
        return 1;
      while ( 1 )
      {
        v8 = (__int64 *)v29[--v7];
        v9 = *v8;
        v10 = *(_QWORD *)(*v8 + 8);
        if ( v10 )
        {
          v11 = *(_BYTE *)(v10 + 24);
          v12 = v11;
        }
        else
        {
          v12 = 0;
          v11 = 0;
        }
        v13 = *(_QWORD *)(v9 + 16);
        if ( v13 )
        {
          v14 = *(_BYTE *)(v13 + 24);
          v15 = v14;
          v16 = v14 + 1;
        }
        else
        {
          v16 = 1;
          v15 = 0;
          v14 = 0;
        }
        if ( v16 >= v12 )
        {
          if ( v12 + 1 >= v15 )
          {
            v28 = v11 + 1;
            if ( v14 > v11 )
              v28 = v14 + 1;
            if ( *(_BYTE *)(v9 + 24) == v28 )
              return 1;
            *(_BYTE *)(v9 + 24) = v28;
          }
          else
          {
            v23 = *(_QWORD *)(v13 + 8);
            if ( v23 )
            {
              v24 = *(_BYTE *)(v23 + 24);
              v25 = v24;
            }
            else
            {
              v25 = 0;
              v24 = 0;
            }
            v26 = *(_QWORD *)(v13 + 16);
            if ( v26 )
              v27 = *(unsigned __int8 *)(v26 + 24);
            else
              v27 = 0;
            if ( v27 < v25 )
            {
              *(_QWORD *)(v13 + 8) = *(_QWORD *)(v23 + 16);
              *(_QWORD *)(v9 + 16) = *(_QWORD *)(v23 + 8);
              *(_QWORD *)(v23 + 16) = v13;
              *(_QWORD *)(v23 + 8) = v9;
              *(_BYTE *)(v9 + 24) = v24;
              *(_BYTE *)(v13 + 24) = v24;
              *(_BYTE *)(v23 + 24) = v14;
              *v8 = v23;
            }
            else
            {
              *(_QWORD *)(v9 + 16) = v23;
              *(_QWORD *)(v13 + 8) = v9;
              *(_BYTE *)(v9 + 24) = v24 + 1;
              *(_BYTE *)(v13 + 24) = v24 + 2;
              *v8 = v13;
            }
          }
          goto LABEL_8;
        }
        v17 = *(_QWORD *)(v10 + 16);
        v18 = *(_QWORD *)(v10 + 8);
        if ( v17 )
        {
          v19 = *(_BYTE *)(v17 + 24);
          v20 = v19;
          if ( v18 )
            goto LABEL_16;
        }
        else
        {
          v20 = 0;
          v19 = 0;
          if ( v18 )
          {
LABEL_16:
            v21 = *(unsigned __int8 *)(v18 + 24);
            goto LABEL_17;
          }
        }
        v21 = 0;
LABEL_17:
        if ( v21 < v20 )
        {
          *(_QWORD *)(v10 + 16) = *(_QWORD *)(v17 + 8);
          *(_QWORD *)(v9 + 8) = *(_QWORD *)(v17 + 16);
          *(_QWORD *)(v17 + 8) = v10;
          *(_QWORD *)(v17 + 16) = v9;
          *(_BYTE *)(v9 + 24) = v19;
          *(_BYTE *)(v10 + 24) = v19;
          *(_BYTE *)(v17 + 24) = v11;
          *v8 = v17;
          goto LABEL_8;
        }
        *(_QWORD *)(v9 + 8) = v17;
        *(_QWORD *)(v10 + 16) = v9;
        *(_BYTE *)(v9 + 24) = v19 + 1;
        *(_BYTE *)(v10 + 24) = v19 + 2;
        *v8 = v10;
        if ( !v7 )
          return 1;
      }
    }
    v4 = *v6;
    v29[v2] = a1;
    if ( v4 == v3 )
      return 0;
    a1 = (unsigned __int64 **)(v6 + 1);
    v5 = (unsigned __int64 **)(v6 + 2);
    if ( v3 >= v4 )
      a1 = v5;
    ++v2;
  }
}
