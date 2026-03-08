__int64 __fastcall VBoxGuest_RTThreadGetName(__int64 a1)
{
  __int64 v1; // rax
  __int64 v2; // rbx

  if ( !a1 )
    return 0;
  v1 = rtThreadGet(a1);
  v2 = v1;
  if ( !v1 )
    return 0;
  if ( *(_DWORD *)(v1 + 36) )
    rtThreadRelease_part_26(v1);
  return v2 + 104;
}
