__int64 __fastcall VBoxGuest_RTThreadUserSignal(__int64 a1)
{
  __int64 v1; // rax
  __int64 v2; // rbx
  unsigned int v3; // ebp

  v1 = rtThreadGet(a1);
  v2 = v1;
  if ( v1 )
  {
    v3 = VBoxGuest_RTSemEventMultiSignal(*(_QWORD *)(v1 + 48));
    if ( *(_DWORD *)(v2 + 36) )
      rtThreadRelease_part_26(v2);
  }
  else
  {
    return (unsigned int)-4;
  }
  return v3;
}
