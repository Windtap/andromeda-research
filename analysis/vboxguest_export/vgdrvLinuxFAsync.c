__int64 __fastcall vgdrvLinuxFAsync(__int64 a1, __int64 a2, __int64 a3)
{
  return fasync_helper(a1, a2, a3, &g_pFAsyncQueue);
}
