__int64 VbglR0PhysHeapTerminate()
{
  while ( *(_QWORD *)&algn_10484[28] )
    vbglPhysHeapChunkDelete(*(__int64 *)&algn_10484[28]);
  return VBoxGuest_RTSemFastMutexDestroy(*(_QWORD *)&algn_10484[36]);
}
