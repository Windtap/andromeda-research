__int64 __fastcall VBoxGuest_RTThreadGetNative(__int64 a1)
{
  __int64 v1; // rbx
  __int64 v2; // rax

  v1 = -1;
  v2 = rtThreadGet(a1);
  if ( !v2 )
    return v1;
  v1 = *(_QWORD *)v2;
  if ( !*(_DWORD *)(v2 + 36) )
    return v1;
  rtThreadRelease_part_26(v2);
  return v1;
}
