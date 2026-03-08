__int64 pciDevIrqHandler()
{
  if ( !__indword(g_IOPortBase) )
    return 1;
  my_wake_up_constprop_5();
  _wake_up(&g_waitSerialCallQueue, 3, 1, 0);
  if ( _InterlockedExchange(&g_callSeqToGuest, *(_DWORD *)(g_pPipeMem + 49480)) == *(_DWORD *)(g_pPipeMem + 49480) )
    return 1;
  queue_work_on(0x2000, system_wq, &g_serialRecvWorkItem);
  return 1;
}
