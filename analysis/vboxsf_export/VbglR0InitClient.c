__int64 VbglR0InitClient()
{
  int v0; // ebx
  __int64 DefaultInstance; // rax

  if ( (unsigned int)(g_vbgldata - 1) <= 1 )
    return 0;
  memset(&g_vbgldata, 0, 0x80u);
  g_vbgldata = 1;
  v0 = VbglR0PhysHeapInit();
  if ( v0 < 0 )
  {
    DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( DefaultInstance )
      VBoxGuest_RTLogLoggerEx(
        DefaultInstance,
        16,
        32,
        "vbglR0InitCommon: VbglR0PhysHeapInit failed: rc=%Rrc\n",
        (unsigned int)v0);
  }
  else
  {
    v0 = VBoxGuest_RTSemMutexCreate(&algn_10484[116]);
    if ( v0 >= 0 )
    {
      vbglR0QueryDriverInfo();
      v0 = VbglR0HGCMInit();
      if ( v0 >= 0 )
        return 0;
      VBoxGuest_RTSemMutexDestroy(*(_QWORD *)&algn_10484[116]);
      *(_QWORD *)&algn_10484[116] = 0;
    }
    VbglR0PhysHeapTerminate();
  }
  g_vbgldata = 0;
  return (unsigned int)v0;
}
