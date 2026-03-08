__int64 rtR0TermNative()
{
  __int64 result; // rax

  flush_workqueue(g_prtR0LnxWorkQueue);
  result = destroy_workqueue(g_prtR0LnxWorkQueue);
  g_prtR0LnxWorkQueue = 0;
  return result;
}
