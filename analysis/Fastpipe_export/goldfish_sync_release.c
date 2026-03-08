__int64 __fastcall goldfish_sync_release(__int64 a1, __int64 a2)
{
  __int64 *v2; // rbx
  __int64 v3; // rax

  mutex_lock(&g_mutex_lock_ioctl);
  v2 = *(__int64 **)(a2 + 208);
  v3 = *v2;
  if ( *v2 && !_InterlockedSub((volatile signed __int32 *)(v3 + 12), 1u) )
    delete_timeline_obj(v3 + 12);
  *v2 = 0;
  kfree(v2);
  mutex_unlock(&g_mutex_lock_ioctl);
  return 0;
}
