__int64 __fastcall vbsf_unlock_user_pages(__int64 a1, __int64 a2, char a3, char a4)
{
  char v4; // r12
  __int64 i; // rbx
  __int64 result; // rax
  _QWORD *v7; // rbp

  v4 = 0;
  if ( !a4 )
    v4 = a3;
  for ( i = a2; i; --i )
  {
    while ( 1 )
    {
      v7 = *(_QWORD **)(a1 + 8 * i - 8);
      if ( v4 )
      {
        if ( (*v7 & 0x400LL) == 0 )
          break;
      }
      result = put_page(*(_QWORD *)(a1 + 8 * i-- - 8));
      if ( !i )
        return result;
    }
    set_page_dirty(*(_QWORD *)(a1 + 8 * i - 8));
    result = put_page(v7);
  }
  return result;
}
