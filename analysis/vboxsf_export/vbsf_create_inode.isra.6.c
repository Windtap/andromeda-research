__int64 __fastcall vbsf_create_inode_isra_6(_QWORD *a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, char a6)
{
  __int64 v10; // r15
  __int64 v11; // rax
  __int64 v12; // rbx
  __int64 v13; // rax
  __int64 DefaultInstance; // rax

  v10 = kmem_cache_alloc_trace(kmalloc_caches[1], 37748928, 72);
  if ( v10 )
  {
    v11 = iunique(*a1, 16);
    v12 = iget_locked(*a1, v11);
    if ( v12 )
    {
      *(_QWORD *)v10 = a3;
      v13 = jiffies;
      *(_BYTE *)(v10 + 8) = 0;
      *(_QWORD *)(v10 + 48) = -1;
      *(_QWORD *)(v10 + 16) = v13;
      *(_QWORD *)(v10 + 56) = v10 + 56;
      *(_QWORD *)(v10 + 64) = v10 + 56;
      *(_QWORD *)(v12 + 552) = v10;
      vbsf_init_inode(v12, v10, a4, a5);
      if ( a6 )
        d_instantiate(a2, v12);
      unlock_new_inode(v12);
    }
    else
    {
      v12 = 0;
      kfree(v10);
    }
  }
  else
  {
    v12 = 0;
    DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
    if ( DefaultInstance )
      VBoxGuest_RTLogLoggerEx(
        DefaultInstance,
        16,
        337,
        "%Rfn: %M",
        "vbsf_create_inode",
        "could not allocate memory for new inode info\n");
  }
  return v12;
}
