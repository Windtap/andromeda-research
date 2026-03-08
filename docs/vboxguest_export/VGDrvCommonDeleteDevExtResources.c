void __fastcall VGDrvCommonDeleteDevExtResources(__int64 a1, __int64 a2)
{
  bool v3; // zf
  int v4; // ebp
  __int64 v5; // rdi
  __int64 v6; // rbp
  __int64 v7; // rax
  __int64 DefaultInstance; // rax
  int v9; // r9d
  _QWORD v10[3]; // [rsp+0h] [rbp-18h] BYREF

  if ( *(_DWORD *)a1 == -889275714 )
  {
    *(_DWORD *)a1 = 195939070;
    if ( *(_QWORD *)(a1 + 640) )
    {
      VBoxGuest_RTTimerDestroy();
      a2 = 0;
      vgdrvHeartbeatHostConfigure(a1, 0);
    }
    VbglR0GRFree(*(_QWORD *)(a1 + 656));
    v3 = *(_QWORD *)(a1 + 16) == 0;
    *(_QWORD *)(a1 + 656) = 0;
    if ( !v3 )
    {
      a2 = 32;
      v4 = VbglR0GRAlloc(v10, 32, 21);
      if ( v4 < 0
        || (v5 = v10[0],
            *(_DWORD *)(v10[0] + 24LL) = 0,
            *(_DWORD *)(v5 + 28) = 0,
            v4 = VbglR0GRPerform(v5),
            VbglR0GRFree(v10[0]),
            v4 < 0) )
      {
        DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
        if ( DefaultInstance )
        {
          a2 = 16;
          VBoxGuest_RTLogLoggerEx(
            DefaultInstance,
            16,
            32,
            (unsigned int)"vgdrvTermUnfixGuestMappings: Failed to unfix the guest mappings! rc=%Rrc\n",
            v4,
            v9);
        }
      }
      else
      {
        a2 = 1;
        VBoxGuest_RTR0MemObjFree(*(_QWORD *)(a1 + 16), 1);
      }
      *(_QWORD *)(a1 + 16) = 0;
    }
    v6 = a1 + 136;
    if ( *(_QWORD *)(a1 + 144) != a1 + 136 )
    {
      v7 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
      if ( v7 )
      {
        a2 = 16;
        VBoxGuest_RTLogLoggerEx(
          v7,
          16,
          32,
          (unsigned int)"%Rfn: %M",
          (unsigned int)"VGDrvCommonDeleteDevExtResources",
          (unsigned int)"session list not empty!\n");
      }
      *(_QWORD *)(a1 + 136) = v6;
      *(_QWORD *)(a1 + 144) = v6;
    }
    *(_DWORD *)(a1 + 216) = 0;
    vgdrvResetEventFilterOnHost_isra_3(0);
    vgdrvResetCapabilitiesOnHost_isra_4(0, a2);
    vgdrvResetMouseStatusOnHost_isra_5(0, a2);
    vgdrvCloseMemBalloon(a1, 0);
    *(_QWORD *)(a1 + 40) = 0;
    _InterlockedExchange((volatile __int32 *)(a1 + 32), 0);
    vgdrvDeleteWaitList((__int64 **)(a1 + 56));
    vgdrvDeleteWaitList((__int64 **)(a1 + 72));
    vgdrvDeleteWaitList((__int64 **)(a1 + 88));
    vgdrvDeleteWaitList((__int64 **)(a1 + 104));
    VbglR0TerminatePrimary(a1 + 104, 0);
    *(_QWORD *)(a1 + 8) = 0;
    *(_WORD *)(a1 + 4) = 0;
  }
}
