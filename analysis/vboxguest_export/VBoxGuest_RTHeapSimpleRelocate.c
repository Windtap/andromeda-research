__int64 __fastcall VBoxGuest_RTHeapSimpleRelocate(unsigned __int64 a1, char *a2)
{
  __int64 v2; // rax
  char *v3; // r8
  __int64 v4; // rax
  __int64 v5; // rax
  _QWORD *v6; // rax
  char *v7; // rdx
  __int64 v8; // rcx
  __int64 v9; // rcx
  __int64 v10; // rcx
  __int64 v11; // rcx

  if ( a1 + 0x200000 <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL
    || *(_QWORD *)a1 != 425263365 )
  {
    return 4294967292LL;
  }
  v2 = *(_QWORD *)(a1 + 16);
  v3 = (char *)(*(_QWORD *)(a1 + 8) + a1 - v2);
  if ( v3 != a2 )
    return 4294967294LL;
  if ( v2 )
    *(_QWORD *)(a1 + 16) = &a2[v2];
  v4 = *(_QWORD *)(a1 + 32);
  if ( v4 )
    *(_QWORD *)(a1 + 32) = &v3[v4];
  v5 = *(_QWORD *)(a1 + 40);
  if ( v5 )
    *(_QWORD *)(a1 + 40) = &v3[v5];
  v6 = (_QWORD *)(a1 + 64);
  if ( a1 != -64 && *(_QWORD *)(a1 + 16) > (unsigned __int64)v6 )
  {
    while ( 1 )
    {
      if ( *v6 )
      {
        v7 = &v3[*v6];
        *v6 = v7;
      }
      else
      {
        v7 = 0;
      }
      v8 = v6[1];
      if ( v8 )
        v6[1] = &v3[v8];
      v9 = v6[2];
      if ( v9 )
        v6[2] = &v3[v9];
      if ( (v6[3] & 1) != 0 )
      {
        v10 = v6[4];
        if ( v10 )
          v6[4] = &v3[v10];
        v11 = v6[5];
        if ( v11 )
          v6[5] = &v3[v11];
      }
      if ( !v7 || (unsigned __int64)v7 >= *(_QWORD *)(a1 + 16) )
        break;
      v6 = v7;
    }
  }
  return 0;
}
