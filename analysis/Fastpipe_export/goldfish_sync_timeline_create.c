__int64 goldfish_sync_timeline_create()
{
  __int64 v0; // rbx
  __int64 result; // rax

  v0 = sw_sync_timeline_create();
  if ( v0 )
  {
    result = kmem_cache_alloc_trace(kmalloc_caches[4], 37781696, 16);
    *(_QWORD *)result = v0;
    *(_DWORD *)(result + 8) = 0;
    *(_DWORD *)(result + 12) = 1;
  }
  else
  {
    printk(byte_41F8);
    return 0;
  }
  return result;
}
