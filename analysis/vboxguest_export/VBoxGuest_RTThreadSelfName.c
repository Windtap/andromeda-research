__int64 VBoxGuest_RTThreadSelfName()
{
  __int64 v0; // rax
  __int64 v1; // rax
  __int64 v2; // rbx

  v0 = VBoxGuest_RTThreadSelf();
  if ( !v0 )
    return 0;
  v1 = rtThreadGet(v0);
  v2 = v1;
  if ( !v1 )
    return 0;
  if ( *(_DWORD *)(v1 + 36) )
    rtThreadRelease_part_26(v1);
  return v2 + 104;
}
