__int64 __fastcall vbglPhysHeapChunkAlloc(__int64 a1)
{
  unsigned int v1; // ebp
  __int64 v2; // rbx
  int v3; // eax
  __int64 v4; // rdx
  bool v5; // zf
  __int64 DefaultInstance; // rax
  unsigned __int64 v8[4]; // [rsp+0h] [rbp-20h] BYREF

  v8[0] = -1;
  if ( (unsigned int)a1 > 0x7FFFFFF )
    return 0;
  v1 = (unsigned int)&unk_10047 + a1;
  LOWORD(v1) = 0;
  v2 = VBoxGuest_RTMemContAlloc(v8, v1);
  if ( !v2 )
  {
    DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( DefaultInstance )
      VBoxGuest_RTLogLoggerEx(
        DefaultInstance,
        16,
        32,
        "vbglPhysHeapChunkAlloc: failed to alloc %u (%#x) contiguous bytes.\n",
        v1,
        v1);
    return 0;
  }
  if ( v8[0] > 0xFFFFFFFF || v8[0] + v1 > 0x100000000LL )
  {
    VBoxGuest_RTAssertMsg1Weak(
      "PhysAddr < _4G && PhysAddr + cbChunk <= _4G",
      320,
      "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxsf/VBoxGuestR0LibPhysHeap.c",
      "vbglPhysHeapChunkAlloc");
    VBoxGuest_RTAssertShouldPanic();
    __debugbreak();
  }
  *(_DWORD *)(v2 + 4) = v1;
  *(_DWORD *)v2 = -1378038580;
  v3 = v8[0];
  *(_DWORD *)(v2 + 12) = 0;
  *(_QWORD *)(v2 + 16) = 0;
  *(_QWORD *)(v2 + 24) = 0;
  *(_DWORD *)(v2 + 32) = -1378108485;
  *(_DWORD *)(v2 + 8) = v3;
  *(_QWORD *)(v2 + 36) = v1 - 72;
  *(_QWORD *)(v2 + 48) = 0;
  *(_QWORD *)(v2 + 56) = 0;
  *(_QWORD *)(v2 + 64) = v2;
  vbglPhysHeapInsertBlock(0, v2 + 32);
  v4 = *(_QWORD *)&algn_10484[28];
  v5 = *(_QWORD *)&algn_10484[28] == 0;
  *(_QWORD *)(v2 + 16) = *(_QWORD *)&algn_10484[28];
  if ( !v5 )
    *(_QWORD *)(v4 + 24) = v2;
  *(_QWORD *)&algn_10484[28] = v2;
  return v2 + 32;
}
