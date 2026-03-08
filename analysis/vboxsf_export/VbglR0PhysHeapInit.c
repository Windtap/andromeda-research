__int64 VbglR0PhysHeapInit()
{
  int v0; // ebx

  v0 = -(vbglPhysHeapChunkAlloc(0) == 0);
  VBoxGuest_RTSemFastMutexCreate(&algn_10484[36]);
  return v0 & 0xFFFFFFF8;
}
