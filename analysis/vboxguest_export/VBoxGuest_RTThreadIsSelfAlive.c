__int64 VBoxGuest_RTThreadIsSelfAlive()
{
  unsigned int v0; // ebx
  __int64 v2; // rax

  v0 = 0;
  if ( !g_frtThreadInitialized )
    return 0;
  v2 = VBoxGuest_RTThreadSelf();
  if ( !v2 )
    return 0;
  LOBYTE(v0) = (unsigned int)(*(_DWORD *)(v2 + 40) - 3) <= 0xA;
  return v0;
}
