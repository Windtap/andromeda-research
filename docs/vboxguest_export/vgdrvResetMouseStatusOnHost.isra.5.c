__int64 vgdrvResetMouseStatusOnHost_isra_5()
{
  int v0; // ebx
  __int64 v1; // rdi
  __int64 DefaultInstance; // rax
  __int64 v4; // [rsp+8h] [rbp-10h] BYREF

  v0 = VbglR0GRAlloc(&v4, 36, 2);
  if ( v0 >= 0 )
  {
    v1 = v4;
    *(_DWORD *)(v4 + 24) = 0;
    *(_DWORD *)(v1 + 28) = 0;
    *(_DWORD *)(v1 + 32) = 0;
    v0 = VbglR0GRPerform(v1);
    if ( v0 < 0 )
    {
      DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
      if ( DefaultInstance )
        VBoxGuest_RTLogLoggerEx(
          DefaultInstance,
          16,
          32,
          (unsigned int)"%Rfn: %M",
          (unsigned int)"vgdrvResetMouseStatusOnHost",
          (unsigned int)"failed with rc=%Rrc\n");
    }
    VbglR0GRFree(v4);
  }
  return (unsigned int)v0;
}
