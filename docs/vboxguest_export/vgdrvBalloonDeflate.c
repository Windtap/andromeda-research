__int64 __fastcall vgdrvBalloonDeflate(_QWORD *a1, _DWORD *a2)
{
  __int64 i; // rbx
  int v3; // ebx
  __int64 DefaultInstance; // rax
  int v6; // r9d
  __int64 v7; // rax

  for ( i = 0; i != 256; ++i )
    *(_QWORD *)&a2[2 * i + 8] = VBoxGuest_RTR0MemObjGetPagePhysAddr(*a1, i);
  a2[7] = 0;
  *a2 = 2080;
  a2[6] = 256;
  v3 = VbglR0GRPerform(a2);
  if ( v3 < 0 )
  {
    DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( DefaultInstance )
      VBoxGuest_RTLogLoggerEx(
        DefaultInstance,
        16,
        32,
        (unsigned int)"vgdrvBalloonDeflate: VbglR0GRPerform failed. rc=%Rrc\n",
        v3,
        v6);
  }
  else
  {
    v3 = VBoxGuest_RTR0MemObjFree(*a1, 1);
    if ( v3 < 0 )
    {
      v7 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
      if ( v7 )
        VBoxGuest_RTLogLoggerEx(
          v7,
          16,
          32,
          (unsigned int)"vgdrvBalloonDeflate: RTR0MemObjFree(%p,true) -> %Rrc; this is *BAD*!\n",
          *a1,
          v3);
    }
    else
    {
      *a1 = 0;
      return 0;
    }
  }
  return (unsigned int)v3;
}
