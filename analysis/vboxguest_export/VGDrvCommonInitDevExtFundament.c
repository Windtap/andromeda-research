__int64 __fastcall VGDrvCommonInitDevExtFundament(__int64 a1)
{
  __int64 v1; // rax
  int v2; // ebp
  __int64 DefaultInstance; // rax
  int v5; // r9d
  __int64 v6; // rax
  int v7; // r9d
  __int64 v8; // rax
  int v9; // r9d

  *(_WORD *)(a1 + 4) = -1;
  *(_QWORD *)(a1 + 56) = a1 + 56;
  *(_QWORD *)(a1 + 64) = a1 + 56;
  *(_QWORD *)(a1 + 72) = a1 + 72;
  *(_QWORD *)(a1 + 80) = a1 + 72;
  *(_QWORD *)(a1 + 88) = a1 + 88;
  *(_QWORD *)(a1 + 96) = a1 + 88;
  *(_QWORD *)(a1 + 104) = a1 + 104;
  *(_QWORD *)(a1 + 112) = a1 + 104;
  *(_QWORD *)(a1 + 136) = a1 + 136;
  *(_QWORD *)(a1 + 144) = a1 + 136;
  v1 = 0;
  *(_DWORD *)(a1 + 120) = 0;
  *(_QWORD *)(a1 + 8) = 0;
  *(_QWORD *)(a1 + 16) = 0;
  *(_QWORD *)(a1 + 24) = 0;
  *(_DWORD *)(a1 + 32) = 0;
  *(_QWORD *)(a1 + 40) = 0;
  *(_QWORD *)(a1 + 48) = -1;
  *(_DWORD *)(a1 + 152) = 0;
  *(_BYTE *)(a1 + 156) = 0;
  *(_DWORD *)(a1 + 124) = 0;
  *(_QWORD *)(a1 + 128) = 0;
  *(_QWORD *)(a1 + 160) = 0;
  *(_DWORD *)(a1 + 168) = 0;
  *(_DWORD *)(a1 + 172) = 0;
  *(_BYTE *)(a1 + 176) = 1;
  *(_QWORD *)(a1 + 192) = 0;
  *(_QWORD *)(a1 + 184) = 0;
  *(_QWORD *)(a1 + 200) = 0;
  *(_QWORD *)(a1 + 208) = 0;
  *(_QWORD *)(a1 + 656) = 0;
  *(_DWORD *)(a1 + 216) = 0;
  do
  {
    *(_DWORD *)(a1 + 220 + v1) = 0;
    v1 += 4;
  }
  while ( v1 != 128 );
  *(_DWORD *)(a1 + 348) = 0;
  LOBYTE(v1) = 0;
  *(_DWORD *)(a1 + 352) = -1;
  do
  {
    *(_DWORD *)(a1 + 356 + v1) = 0;
    v1 += 4;
  }
  while ( v1 != 128 );
  *(_DWORD *)(a1 + 484) = 0;
  LOBYTE(v1) = 0;
  *(_DWORD *)(a1 + 488) = -1;
  *(_DWORD *)(a1 + 492) = 0;
  *(_DWORD *)(a1 + 496) = 0;
  *(_DWORD *)(a1 + 500) = 0;
  do
  {
    *(_DWORD *)(a1 + 504 + v1) = 0;
    v1 += 4;
  }
  while ( v1 != 128 );
  *(_DWORD *)(a1 + 632) = 0;
  *(_DWORD *)(a1 + 636) = -1;
  v2 = VBoxGuest_RTSpinlockCreate(a1 + 24, 2, "VBoxGuestEvent");
  if ( v2 < 0 )
  {
    DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( DefaultInstance )
      VBoxGuest_RTLogLoggerEx(
        DefaultInstance,
        16,
        32,
        (unsigned int)"VGDrvCommonInitDevExt: failed to create spinlock, rc=%Rrc!\n",
        v2,
        v5);
  }
  else
  {
    v2 = VBoxGuest_RTSpinlockCreate(a1 + 128, 2, "VBoxGuestSession");
    if ( v2 < 0 )
    {
      v8 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
      if ( v8 )
        VBoxGuest_RTLogLoggerEx(
          v8,
          16,
          32,
          (unsigned int)"VGDrvCommonInitDevExt: failed to create spinlock, rc=%Rrc!\n",
          v2,
          v9);
    }
    else
    {
      v2 = VBoxGuest_RTSemFastMutexCreate(a1 + 160);
      if ( v2 >= 0 )
      {
        *(_DWORD *)a1 = 195939070;
        return 0;
      }
      v6 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
      if ( v6 )
        VBoxGuest_RTLogLoggerEx(
          v6,
          16,
          32,
          (unsigned int)"VGDrvCommonInitDevExt: failed to create mutex, rc=%Rrc!\n",
          v2,
          v7);
      VBoxGuest_RTSpinlockDestroy(*(_QWORD *)(a1 + 128));
    }
    VBoxGuest_RTSpinlockDestroy(*(_QWORD *)(a1 + 24));
  }
  *(_DWORD *)a1 = 0;
  return (unsigned int)v2;
}
