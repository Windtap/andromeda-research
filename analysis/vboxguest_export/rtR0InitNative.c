__int64 rtR0InitNative()
{
  g_prtR0LnxWorkQueue = _alloc_workqueue_key("%s", (_BYTE *)&loc_7 + 1);
  return g_prtR0LnxWorkQueue == 0 ? 0xFFFFFFF8 : 0;
}
