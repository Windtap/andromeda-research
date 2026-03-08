__int64 __fastcall vgdrvIoCtl_HGCMCallInner_constprop_14(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        int a4,
        char a5,
        char a6,
        char a7,
        unsigned __int64 a8)
{
  int v9; // r13d
  __int64 v10; // rdx
  unsigned __int64 v13; // rdx
  unsigned int i; // eax
  _BOOL4 v15; // edx
  int v16; // ecx
  int v17; // eax
  unsigned int v18; // ebp
  __int64 v20; // rax
  int v21; // r9d
  __int64 DefaultInstance; // rax
  int v23; // r9d
  __int64 v24; // rax
  __int64 v25; // rax
  const char *v26; // r8

  v9 = *(_DWORD *)(a3 + 24);
  v10 = *(unsigned __int16 *)(a3 + 38);
  if ( (unsigned __int16)v10 > 0x20u )
  {
    DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( DefaultInstance )
      VBoxGuest_RTLogLoggerEx(
        DefaultInstance,
        16,
        32,
        (unsigned int)"VBOXGUEST_IOCTL_HGCM_CALL: cParm=%RX32 is not sane\n",
        *(unsigned __int16 *)(a3 + 38),
        v23);
    return (unsigned int)-2;
  }
  if ( a6 )
    v13 = 12 * v10 + 40;
  else
    v13 = 16 * v10 + 40;
  if ( a8 < v13 )
  {
    v24 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( v24 )
    {
      v18 = -2;
      VBoxGuest_RTLogLoggerEx(
        v24,
        16,
        32,
        (unsigned int)"VBOXGUEST_IOCTL_HGCM_CALL: cbData=%#zx (%zu) required size is %#zx (%zu)\n",
        a8,
        a8);
      return v18;
    }
    return (unsigned int)-2;
  }
  *(_DWORD *)(a3 + 16) = v13;
  VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a1 + 128));
  for ( i = 0; i != 64; ++i )
  {
    if ( v9 == *(_DWORD *)(a2 + 4 * (i + 8LL) + 8) )
    {
      VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 128));
      v15 = 0;
      if ( !a7 )
        v15 = *(_QWORD *)(a2 + 24) == -1;
      v16 = *(_DWORD *)(a2 + 16);
      if ( a6 )
      {
        if ( a5 )
          v17 = VbglR0HGCMInternalCall32(
                  a3,
                  a8,
                  v15,
                  v16,
                  (unsigned int)vgdrvHgcmAsyncWaitCallbackInterruptible,
                  a1,
                  a4);
        else
          v17 = VbglR0HGCMInternalCall32(a3, a8, v15, v16, (unsigned int)vgdrvHgcmAsyncWaitCallback, a1, a4);
      }
      else if ( a5 )
      {
        v17 = VbglR0HGCMInternalCall(a3, a8, v15, v16, (unsigned int)vgdrvHgcmAsyncWaitCallbackInterruptible, a1, a4);
      }
      else
      {
        v17 = VbglR0HGCMInternalCall(a3, a8, v15, v16, (unsigned int)vgdrvHgcmAsyncWaitCallback, a1, a4);
      }
      if ( v17 < 0 )
      {
        v18 = v17;
        if ( (unsigned int)(v17 + 40) > 1 )
        {
          v25 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
          if ( v25 )
          {
            if ( (unsigned int)s_LogRelMaxIt_cLogged_9398 <= 0x1F )
            {
              v26 = "64";
              ++s_LogRelMaxIt_cLogged_9398;
              if ( a6 )
                v26 = "32";
              VBoxGuest_RTLogLoggerEx(
                v25,
                16,
                32,
                (unsigned int)"VBOXGUEST_IOCTL_HGCM_CALL: %s Failed. rc=%Rrc (Hdr.rc=%Rrc).\n",
                (_DWORD)v26,
                v18);
            }
          }
        }
      }
      else
      {
        return *(unsigned int *)(a3 + 12);
      }
      return v18;
    }
  }
  VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 128));
  v20 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
  if ( v20 )
  {
    v18 = -4;
    if ( (unsigned int)s_LogRelMaxIt_cLogged_9395 <= 0x1F )
    {
      ++s_LogRelMaxIt_cLogged_9395;
      VBoxGuest_RTLogLoggerEx(
        v20,
        16,
        32,
        (unsigned int)"VBOXGUEST_IOCTL_HGCM_CALL: Invalid handle. u32Client=%RX32\n",
        v9,
        v21);
    }
  }
  else
  {
    return (unsigned int)-4;
  }
  return v18;
}
