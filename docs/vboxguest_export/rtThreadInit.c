__int64 rtThreadInit()
{
  __int64 result; // rax
  int v1; // ebx

  result = VBoxGuest_RTSpinlockCreate(&g_ThreadSpinlock, 2, "RTThread");
  if ( (int)result >= 0 )
  {
    v1 = rtThreadNativeInit();
    if ( v1 < 0 )
    {
      VBoxGuest_RTSpinlockDestroy(g_ThreadSpinlock);
      g_ThreadSpinlock = 0;
      return (unsigned int)v1;
    }
    else
    {
      g_frtThreadInitialized = 1;
      return 0;
    }
  }
  return result;
}
