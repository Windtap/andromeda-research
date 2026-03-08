__int64 VbglR0TerminateClient()
{
  __int64 result; // rax

  VbglR0HGCMTerminate();
  VbglR0IdcClose((unsigned __int64)&algn_10484[84]);
  VBoxGuest_RTSemMutexDestroy(*(_QWORD *)&algn_10484[116]);
  *(_QWORD *)&algn_10484[116] = 0;
  result = VbglR0PhysHeapTerminate();
  g_vbgldata = 0;
  return result;
}
