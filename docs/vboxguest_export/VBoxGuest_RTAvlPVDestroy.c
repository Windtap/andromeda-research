__int64 __fastcall VBoxGuest_RTAvlPVDestroy(__int64 *a1, __int64 (__fastcall *a2)(__int64, __int64), __int64 a3)
{
  __int64 v4; // r8
  __int64 v6; // rdi
  unsigned int i; // eax
  __int64 v8; // r8
  __int64 v9; // rcx
  unsigned int v10; // r13d
  __int64 v11; // rax
  __int64 result; // rax
  _QWORD v13[31]; // [rsp+0h] [rbp-F8h]

  v4 = *a1;
  if ( *a1 )
  {
    v13[0] = *a1;
    v6 = v4;
    for ( i = 1; ; v6 = v13[i - 1] )
    {
      v9 = *(_QWORD *)(v6 + 8);
      if ( v9 || (v9 = *(_QWORD *)(v6 + 16)) != 0 )
      {
        v8 = i++;
        v13[v8] = v9;
      }
      else
      {
        v10 = i - 1;
        if ( i == 1 )
        {
          *a1 = 0;
        }
        else
        {
          v11 = v13[i - 2];
          if ( *(_QWORD *)(v11 + 8) == v6 )
            *(_QWORD *)(v11 + 8) = 0;
          else
            *(_QWORD *)(v11 + 16) = 0;
        }
        result = a2(v6, a3);
        if ( (_DWORD)result )
          return result;
        i = v10;
      }
      if ( !i )
        return 0;
    }
  }
  return 0;
}
