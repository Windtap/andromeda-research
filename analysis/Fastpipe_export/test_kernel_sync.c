__int64 test_kernel_sync()
{
  __int64 *v0; // rbx
  unsigned int v1; // ebp
  __int64 v2; // rax
  char v4[272]; // [rsp+0h] [rbp-110h] BYREF

  gensym(v4);
  v0 = (__int64 *)goldfish_sync_timeline_create(v4);
  v1 = goldfish_sync_fence_create(v0, 1u);
  goldfish_sync_timeline_inc((__int64)v0, 1);
  v2 = sync_fence_fdget(v1);
  return sync_fence_wait(v2, -1);
}
