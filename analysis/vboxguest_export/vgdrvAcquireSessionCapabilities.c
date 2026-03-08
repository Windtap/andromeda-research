__int64 __fastcall vgdrvAcquireSessionCapabilities(__int64 a1, __int64 a2, int a3, int a4, int a5, char a6)
{
  int v10; // r15d
  int v11; // eax
  int v12; // eax
  int v13; // r15d
  int v14; // eax
  int v15; // ebp
  __int64 v16; // rdi
  int v17; // eax
  int v18; // r13d
  unsigned int v19; // r12d
  int v20; // esi
  __int64 DefaultInstance; // rax
  int v22; // r9d
  int v23; // r8d
  const char *v24; // rcx
  __int64 v26; // rax
  int v27; // ebp
  __int64 v28; // rax
  int v29; // r9d
  __int64 v30; // rax
  unsigned int v31; // [rsp+1Ch] [rbp-3Ch]
  _QWORD v32[7]; // [rsp+20h] [rbp-38h] BYREF

  v32[0] = 0;
  if ( (a3 & 0xFFFFFFF8) != 0 )
  {
    DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( !DefaultInstance )
      return (unsigned int)-2;
    v22 = a2;
    v23 = a3;
    v24 = "vgdrvAcquireSessionCapabilities: invalid fOrMask=%#x (pSession=%p fNotMask=%#x fFlags=%#x)\n";
LABEL_27:
    VBoxGuest_RTLogLoggerEx(DefaultInstance, 16, 32, (_DWORD)v24, v23, v22);
    return (unsigned int)-2;
  }
  if ( (a5 & 0xFFFFFFFE) != 0 )
  {
    DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( !DefaultInstance )
      return (unsigned int)-2;
    v22 = a2;
    v23 = a5;
    v24 = "vgdrvAcquireSessionCapabilities: invalid fFlags=%#x (pSession=%p fOrMask=%#x fNotMask=%#x)\n";
    goto LABEL_27;
  }
  v10 = a4 & ~a3;
  if ( !a5 )
  {
    v11 = VbglR0GRAlloc(v32, 32, 56);
    if ( v11 < 0 )
    {
      if ( !a6 )
      {
        v31 = v11;
        v30 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
        if ( v30 )
          VBoxGuest_RTLogLoggerEx(
            v30,
            16,
            32,
            (unsigned int)"vgdrvAcquireSessionCapabilities: pSession=%p fOrMask=%#x fNotMask=%#x fFlags=%#x: VbglR0GRAllo"
                          "c failure: %Rrc\n",
            a2,
            a3);
        return v31;
      }
      v32[0] = 0;
    }
    else if ( !a6 )
    {
      *(_DWORD *)(v32[0] + 20LL) = *(_DWORD *)(a2 + 16);
    }
  }
  VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a1 + 24));
  if ( (a3 & *(_DWORD *)(a1 + 496)) != 0 )
  {
    VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 24));
    if ( v32[0] )
      VbglR0GRFree(v32[0]);
    v19 = -79;
    v26 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( v26 )
      VBoxGuest_RTLogLoggerEx(
        v26,
        16,
        32,
        (unsigned int)"vgdrvAcquireSessionCapabilities: pSession=%p fOrMask=%#x fNotMask=%#x fFlags=%#x: calling caps acq"
                      "uire for set caps\n",
        a2,
        a3);
  }
  else
  {
    *(_DWORD *)(a1 + 492) |= a3;
    if ( a5 )
      goto LABEL_24;
    v12 = *(_DWORD *)(a2 + 304);
    v13 = v12 & v10;
    v14 = ~v12;
    v15 = v14 & a3;
    if ( (v15 & *(_DWORD *)(a1 + 500) & v14) != 0 )
    {
      v19 = -138;
      VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 24));
      VbglR0GRFree(v32[0]);
      return v19;
    }
    if ( v15 )
    {
      *(_DWORD *)(a2 + 304) |= v15;
      *(_DWORD *)(a1 + 500) |= v15;
    }
    if ( v13 )
    {
      *(_DWORD *)(a2 + 304) &= ~v13;
      *(_DWORD *)(a1 + 500) &= ~v13;
    }
    if ( v15 | v13 || *(_DWORD *)(a1 + 636) == -1 )
    {
      v16 = v32[0];
      if ( v32[0] )
      {
        v17 = *(_DWORD *)(a1 + 500) | *(_DWORD *)(a1 + 632);
        *(_DWORD *)(v32[0] + 24LL) = v17;
        if ( v17 != *(_DWORD *)(a1 + 636) )
        {
          *(_DWORD *)(a1 + 636) = v17;
          *(_DWORD *)(v16 + 28) = ~*(_DWORD *)(v16 + 24);
          v18 = VbglR0GRPerform(v16);
          if ( v18 < 0 )
          {
            *(_DWORD *)(a1 + 636) = -1;
            if ( !a6 )
            {
              if ( v15 )
              {
                v27 = ~v15;
                *(_DWORD *)(a2 + 304) &= v27;
                *(_DWORD *)(a1 + 500) &= v27;
              }
              if ( v13 )
              {
                *(_DWORD *)(a2 + 304) |= v13;
                *(_DWORD *)(a1 + 500) |= v13;
              }
              VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 24));
              v28 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
              if ( v28 )
                VBoxGuest_RTLogLoggerEx(
                  v28,
                  16,
                  32,
                  (unsigned int)"vgdrvAcquireSessionCapabilities: vgdrvUpdateCapabilitiesOnHostWithReqAndLock failed: rc=%Rrc\n",
                  v18,
                  v29);
              v19 = v18;
              VbglR0GRFree(v32[0]);
              return v19;
            }
          }
        }
      }
    }
    VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 24));
    if ( v32[0] )
      VbglR0GRFree(v32[0]);
    v19 = 0;
    if ( v15 )
    {
      if ( (v15 & 1) != 0 )
      {
        VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a1 + 24));
        v20 = 32;
      }
      else
      {
        VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a1 + 24));
        if ( !*(_DWORD *)(a1 + 120) )
          goto LABEL_24;
        v20 = 0;
      }
      vgdrvDispatchEventsLocked(a1, v20);
LABEL_24:
      v19 = 0;
      VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 24));
    }
  }
  return v19;
}
