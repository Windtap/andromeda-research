__int64 __fastcall VbglR0PhysHeapInit(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  int v8; // ebx

  v8 = -(vbglPhysHeapChunkAlloc(0, a1, a2, a3, a4, a5, a6, a7, a8) == 0);
  VBoxGuest_RTSemFastMutexCreate(&unk_320C8);
  return v8 & 0xFFFFFFF8;
}
