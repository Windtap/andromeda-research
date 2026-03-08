__int64 __fastcall VBoxGuest_RTThreadUserWaitNoResume(__int64 a1, unsigned int a2)
{
  __int64 v2; // rax
  __int64 v3; // rbx
  unsigned int v4; // ebp

  v2 = rtThreadGet(a1);
  v3 = v2;
  if ( v2 )
  {
    v4 = VBoxGuest_RTSemEventMultiWaitNoResume(*(_QWORD *)(v2 + 48), a2);
    if ( *(_DWORD *)(v3 + 36) )
      rtThreadRelease_part_26(v3);
  }
  else
  {
    return (unsigned int)-4;
  }
  return v4;
}
