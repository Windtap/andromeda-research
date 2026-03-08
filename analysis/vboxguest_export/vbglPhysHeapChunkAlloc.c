__int64 __fastcall vbglPhysHeapChunkAlloc(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // ebp
  __int64 v10; // rbx
  double v11; // xmm4_8
  double v12; // xmm5_8
  int v13; // eax
  __int64 v14; // rdx
  bool v15; // zf
  __int64 DefaultInstance; // rax
  double v18; // xmm4_8
  double v19; // xmm5_8
  unsigned __int64 v20[4]; // [rsp+0h] [rbp-20h] BYREF

  v20[0] = -1;
  if ( a1 > 0x7FFFFFF )
    return 0;
  v9 = a1 + 65607;
  LOWORD(v9) = 0;
  v10 = VBoxGuest_RTMemContAlloc(v20, v9);
  if ( !v10 )
  {
    DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(0x860010u);
    if ( DefaultInstance )
      VBoxGuest_RTLogLoggerEx(
        DefaultInstance,
        16,
        0x86u,
        "vbglPhysHeapChunkAlloc: failed to alloc %u (%#x) contiguous bytes.\n",
        a2,
        a3,
        a4,
        a5,
        v18,
        v19,
        a8,
        a9,
        v9,
        v9);
    return 0;
  }
  if ( v20[0] > 0xFFFFFFFF || v20[0] + v9 > 0x100000000LL )
  {
    VBoxGuest_RTAssertMsg1(
      (__int64)"PhysAddr < _4G && PhysAddr + cbChunk <= _4G",
      0x140u,
      (__int64)"/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/VBoxGuestR0LibPhysHeap.c",
      (__int64)"vbglPhysHeapChunkAlloc",
      a2,
      a3,
      a4,
      a5,
      v11,
      v12,
      a8,
      a9);
    __debugbreak();
  }
  *(_DWORD *)(v10 + 4) = v9;
  *(_DWORD *)v10 = -1378038580;
  v13 = v20[0];
  *(_DWORD *)(v10 + 12) = 0;
  *(_QWORD *)(v10 + 16) = 0;
  *(_QWORD *)(v10 + 24) = 0;
  *(_DWORD *)(v10 + 32) = -1378108485;
  *(_DWORD *)(v10 + 8) = v13;
  *(_QWORD *)(v10 + 36) = v9 - 72;
  *(_QWORD *)(v10 + 48) = 0;
  *(_QWORD *)(v10 + 56) = 0;
  *(_QWORD *)(v10 + 64) = v10;
  vbglPhysHeapInsertBlock(0, v10 + 32);
  v14 = qword_320C0;
  v15 = qword_320C0 == 0;
  *(_QWORD *)(v10 + 16) = qword_320C0;
  if ( !v15 )
    *(_QWORD *)(v14 + 24) = v10;
  qword_320C0 = v10;
  return v10 + 32;
}
