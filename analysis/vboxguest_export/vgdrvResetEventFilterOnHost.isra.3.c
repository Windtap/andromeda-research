__int64 __fastcall vgdrvResetEventFilterOnHost_isra_3(int a1)
{
  int v2; // ebx
  __int64 v3; // rdi
  __int64 DefaultInstance; // rax
  _QWORD v6[3]; // [rsp+8h] [rbp-18h] BYREF

  v2 = VbglR0GRAlloc(v6, 32, 42);
  if ( v2 >= 0 )
  {
    v3 = v6[0];
    *(_DWORD *)(v6[0] + 28LL) = ~a1;
    *(_DWORD *)(v3 + 24) = a1;
    v2 = VbglR0GRPerform(v3);
    if ( v2 < 0 )
    {
      DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
      if ( DefaultInstance )
        VBoxGuest_RTLogLoggerEx(
          DefaultInstance,
          16,
          32,
          (unsigned int)"%Rfn: %M",
          (unsigned int)"vgdrvResetEventFilterOnHost",
          (unsigned int)"failed with rc=%Rrc\n");
    }
    VbglR0GRFree(v6[0]);
  }
  return (unsigned int)v2;
}
