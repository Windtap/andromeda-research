__int64 VbglR0PhysHeapTerminate()
{
  while ( qword_320C0 )
    vbglPhysHeapChunkDelete(qword_320C0);
  return VBoxGuest_RTSemFastMutexDestroy(unk_320C8);
}
