unsigned __int64 *__fastcall rtThreadGetByNative(unsigned __int64 a1)
{
  unsigned __int64 *v1; // rax
  bool v2; // cf
  unsigned __int64 *v3; // rbx

  VBoxGuest_RTSpinlockAcquire(g_ThreadSpinlock);
  v1 = (unsigned __int64 *)g_ThreadTree;
  if ( g_ThreadTree )
  {
    while ( 1 )
    {
      v2 = a1 < *v1;
      if ( a1 == *v1 )
        break;
      while ( !v2 )
      {
        v1 = (unsigned __int64 *)v1[2];
        if ( !v1 )
          goto LABEL_5;
        v2 = a1 < *v1;
        if ( a1 == *v1 )
          goto LABEL_9;
      }
      v1 = (unsigned __int64 *)v1[1];
      if ( !v1 )
        goto LABEL_5;
    }
LABEL_9:
    v3 = v1;
  }
  else
  {
LABEL_5:
    v3 = 0;
  }
  VBoxGuest_RTSpinlockRelease(g_ThreadSpinlock);
  return v3;
}
