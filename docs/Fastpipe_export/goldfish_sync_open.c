__int64 __fastcall goldfish_sync_open(__int64 a1, __int64 a2)
{
  _QWORD *v2; // rax

  mutex_lock(&g_mutex_lock_ioctl);
  v2 = (_QWORD *)kmem_cache_alloc_trace(kmalloc_caches[3], 37781696, 8);
  if ( v2 )
  {
    *v2 = 0;
    *(_QWORD *)(a2 + 208) = v2;
    mutex_unlock(&g_mutex_lock_ioctl);
    return 0;
  }
  else
  {
    printk(byte_4220);
    mutex_unlock(&g_mutex_lock_ioctl);
    return 4294967284LL;
  }
}
