__int64 __fastcall VGDrvCommonCreateUserSession(__int64 a1, int a2, __int64 *a3)
{
  __int64 v4; // rbx
  __int64 v5; // rax
  unsigned int v6; // ebx
  __int64 DefaultInstance; // rax
  int v9; // r8d
  int v10; // r9d

  v4 = VBoxGuest_RTMemAllocZTag(320, "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/VBoxGuest.c");
  if ( v4 )
  {
    *(_DWORD *)(v4 + 20) = VBoxGuest_RTProcSelf();
    v5 = VBoxGuest_RTR0ProcHandleSelf();
    *(_DWORD *)(v4 + 16) = a2;
    *(_QWORD *)(v4 + 24) = v5;
    *(_QWORD *)(v4 + 32) = a1;
    *(_BYTE *)(v4 + 317) = (a2 & 0x8000) != 0;
    VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a1 + 128));
    **(_QWORD **)(a1 + 144) = v4;
    *(_QWORD *)(v4 + 8) = *(_QWORD *)(a1 + 144);
    *(_QWORD *)v4 = a1 + 136;
    ++*(_DWORD *)(a1 + 152);
    *(_QWORD *)(a1 + 144) = v4;
    VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 128));
    *a3 = v4;
    return 0;
  }
  else
  {
    v6 = -8;
    DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( DefaultInstance )
      VBoxGuest_RTLogLoggerEx(
        DefaultInstance,
        16,
        32,
        (unsigned int)"VGDrvCommonCreateUserSession: no memory!\n",
        v9,
        v10);
  }
  return v6;
}
