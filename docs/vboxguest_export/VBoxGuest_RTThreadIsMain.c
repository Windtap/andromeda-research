_BOOL8 __fastcall VBoxGuest_RTThreadIsMain(__int64 a1)
{
  __int64 v1; // rax
  _BOOL4 v2; // ebx

  v1 = rtThreadGet(a1);
  if ( !v1 )
    return 0;
  v2 = (*(_DWORD *)(v1 + 72) & 8) != 0;
  if ( *(_DWORD *)(v1 + 36) )
    rtThreadRelease_part_26(v1);
  return v2;
}
