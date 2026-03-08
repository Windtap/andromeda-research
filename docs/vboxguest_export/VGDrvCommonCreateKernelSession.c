__int64 __fastcall VGDrvCommonCreateKernelSession(__int64 a1, _QWORD *a2)
{
  __int64 v2; // rax
  _QWORD *v3; // rbx
  unsigned int v4; // ebx
  __int64 DefaultInstance; // rax
  int v7; // r8d
  int v8; // r9d

  v2 = VBoxGuest_RTMemAllocZTag(320, "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/VBoxGuest.c");
  v3 = (_QWORD *)v2;
  if ( v2 )
  {
    *(_DWORD *)(v2 + 20) = -1;
    *(_QWORD *)(v2 + 24) = -1;
    *(_QWORD *)(v2 + 32) = a1;
    *(_DWORD *)(v2 + 16) = 2;
    VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a1 + 128));
    **(_QWORD **)(a1 + 144) = v3;
    v3[1] = *(_QWORD *)(a1 + 144);
    *v3 = a1 + 136;
    ++*(_DWORD *)(a1 + 152);
    *(_QWORD *)(a1 + 144) = v3;
    VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 128));
    *a2 = v3;
    return 0;
  }
  else
  {
    v4 = -8;
    DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( DefaultInstance )
      VBoxGuest_RTLogLoggerEx(
        DefaultInstance,
        16,
        32,
        (unsigned int)"VGDrvCommonCreateKernelSession: no memory!\n",
        v7,
        v8);
  }
  return v4;
}
