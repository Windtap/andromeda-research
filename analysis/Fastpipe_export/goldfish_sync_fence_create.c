__int64 __fastcall goldfish_sync_fence_create(__int64 *a1, unsigned int a2)
{
  __int64 v2; // r14
  __int64 v3; // r12
  int unused_fd_flags; // eax
  unsigned int v5; // ebp
  __int64 v6; // rax
  __int64 result; // rax
  char v8[296]; // [rsp+8h] [rbp-128h] BYREF

  if ( !a1 )
    return 0xFFFFFFFFLL;
  v2 = *a1;
  v3 = sw_sync_pt_create(*a1);
  if ( !v3 )
  {
    printk(byte_4100, v2, a2);
    return 0xFFFFFFFFLL;
  }
  unused_fd_flags = get_unused_fd_flags(0x80000);
  v5 = unused_fd_flags;
  if ( unused_fd_flags < 0 )
  {
    printk(byte_4140, (unsigned int)unused_fd_flags);
    goto LABEL_11;
  }
  gensym(v8);
  v6 = sync_fence_create(v8, v3);
  if ( !v6 )
  {
    printk(byte_4178, v2, a2, v3);
    put_unused_fd(v5);
LABEL_11:
    sync_pt_free(v3);
    return 0xFFFFFFFFLL;
  }
  sync_fence_install(v6, v5);
  result = v5;
  if ( _InterlockedIncrement((volatile signed __int32 *)a1 + 3) <= 1 && !_warned_19792 )
  {
    warn_slowpath_null("/media/code/p-emulator-vk/kernel/include/linux/kref.h", 46);
    _warned_19792 = 1;
    return v5;
  }
  return result;
}
