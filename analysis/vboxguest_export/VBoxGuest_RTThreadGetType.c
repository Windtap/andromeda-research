__int64 __fastcall VBoxGuest_RTThreadGetType(__int64 a1)
{
  __int64 v1; // rax
  unsigned int v2; // ebx

  v1 = rtThreadGet(a1);
  if ( !v1 )
    return 0;
  v2 = *(_DWORD *)(v1 + 64);
  if ( *(_DWORD *)(v1 + 36) )
    rtThreadRelease_part_26(v1);
  return v2;
}
