__int64 __fastcall VBoxGuest_RTAvlPVDoWithAll(
        __int64 *a1,
        int a2,
        __int64 (__fastcall *a3)(__int64, __int64),
        __int64 a4)
{
  __int64 v4; // r15
  char v5; // al
  unsigned int v6; // r13d
  unsigned int v9; // ebx
  __int64 v10; // rax
  __int64 v11; // rdx
  __int64 result; // rax
  __int64 v13; // rax
  __int64 v14; // rax
  __int64 v15; // rdx
  __int64 v16; // rax
  _QWORD v17[27]; // [rsp+8h] [rbp-128h]
  _BYTE v18[80]; // [rsp+E0h] [rbp-50h]

  v4 = *a1;
  if ( *a1 )
  {
    v5 = 0;
    v6 = 0;
    v18[0] = 0;
    v17[0] = v4;
    v9 = 1;
    if ( !a2 )
    {
      while ( 1 )
      {
        v18[v6] = v5 + 1;
        if ( v5 || (v14 = *(_QWORD *)(v4 + 16)) == 0 )
        {
          result = a3(v4, a4);
          if ( (_DWORD)result )
            return result;
          v16 = *(_QWORD *)(v4 + 8);
          if ( v16 )
          {
            v18[v6] = 0;
            v17[v6] = v16;
          }
          else
          {
            v9 = v6;
          }
        }
        else
        {
          v15 = v9++;
          v18[v15] = 0;
          v17[v15] = v14;
        }
        if ( !v9 )
          return 0;
        v6 = v9 - 1;
        v4 = v17[v9 - 1];
        v5 = v18[v9 - 1];
      }
    }
    while ( 1 )
    {
      v18[v6] = v5 + 1;
      if ( v5 || (v10 = *(_QWORD *)(v4 + 8)) == 0 )
      {
        result = a3(v4, a4);
        if ( (_DWORD)result )
          return result;
        v13 = *(_QWORD *)(v4 + 16);
        if ( v13 )
        {
          v17[v6] = v13;
          v18[v6] = 0;
          goto LABEL_7;
        }
        v9 = v6;
      }
      else
      {
        v11 = v9++;
        v18[v11] = 0;
        v17[v11] = v10;
      }
      if ( !v9 )
        return 0;
LABEL_7:
      v6 = v9 - 1;
      v4 = v17[v9 - 1];
      v5 = v18[v9 - 1];
    }
  }
  return 0;
}
