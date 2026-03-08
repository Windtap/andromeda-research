unsigned __int64 *__fastcall rtThreadRemoveLocked(__int64 a1)
{
  unsigned __int64 *result; // rax

  result = VBoxGuest_RTAvlPVRemove((unsigned __int64 **)&g_ThreadTree, *(_QWORD *)a1);
  if ( result )
  {
    _InterlockedExchangeAdd(&g_cThreadInTree, 0xFFFFFFFF);
    return (unsigned __int64 *)(unsigned int)_InterlockedExchangeAdd(
                                               &VBoxGuest_g_acRTThreadTypeStats[*(unsigned int *)(a1 + 64)],
                                               0xFFFFFFFF);
  }
  return result;
}
