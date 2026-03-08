__int64 __fastcall goldfish_sync_ioctl(__int64 a1, int a2, __int64 a3)
{
  __int64 result; // rax
  __int64 *v4; // r12
  __int64 v6; // rbx
  unsigned int v7; // r13d
  __int64 v8; // rax
  volatile signed __int32 *v9; // rax
  volatile signed __int32 *v10; // r12
  __int64 v11; // r15
  __int64 v12; // r14
  int unused_fd_flags; // eax
  unsigned int v14; // r13d
  __int64 v15; // rax
  __int64 v16; // rbx
  __int64 v17; // rax
  __int64 v18; // rdi
  __int64 v19; // [rsp+0h] [rbp-168h] BYREF
  __int64 v20; // [rsp+8h] [rbp-160h]
  unsigned int v21; // [rsp+10h] [rbp-158h]
  char s[32]; // [rsp+18h] [rbp-150h] BYREF
  char v23[8]; // [rsp+38h] [rbp-130h] BYREF
  __int64 v24; // [rsp+40h] [rbp-128h]
  __int64 v25; // [rsp+48h] [rbp-120h]
  volatile signed __int32 *v26; // [rsp+50h] [rbp-118h]

  result = -25;
  v4 = *(__int64 **)(a1 + 208);
  if ( a2 == -1072152576 )
  {
    mutex_lock(&g_mutex_lock_ioctl);
    if ( copy_from_user(&v19, a3, 24) )
    {
      printk(byte_4250);
      mutex_unlock(&g_mutex_lock_ioctl);
      return -14;
    }
    if ( !v20 )
      goto LABEL_22;
    if ( (unsigned __int64)(v20 - 1) > 1 )
    {
      v6 = *v4;
      if ( !*v4 )
      {
        gensym(v23);
        v17 = goldfish_sync_timeline_create(v23);
        *v4 = v17;
        v6 = v17;
      }
      v7 = goldfish_sync_fence_create((__int64 *)v6, *(_DWORD *)(v6 + 8) + 1);
      v21 = v7;
      if ( !copy_to_user(a3, &v19, 24) )
      {
        v8 = *v4;
        *(_QWORD *)v23 = 5;
        v24 = v19;
        v26 = (volatile signed __int32 *)v8;
        v25 = v20;
LABEL_9:
        sendSerialCallToHost(1, v23, 32, 0, 0, 0);
LABEL_10:
        mutex_unlock(&g_mutex_lock_ioctl);
        return 0;
      }
      sys_close(v7);
      v18 = v6 + 12;
      if ( !_InterlockedSub((volatile signed __int32 *)(v6 + 12), 1u) )
LABEL_24:
        delete_timeline_obj(v18);
LABEL_22:
      mutex_unlock(&g_mutex_lock_ioctl);
      return -14;
    }
    sprintf(s, "ld_timeline:%x", s_uNameIndex);
    ++s_uNameIndex;
    v9 = (volatile signed __int32 *)goldfish_sync_timeline_create(s);
    v10 = v9;
    if ( !v9 )
    {
      printk(byte_41F8);
      goto LABEL_10;
    }
    v11 = *(_QWORD *)v9;
    sprintf(v23, "ld_fence:%x", s_uNameIndex);
    ++s_uNameIndex;
    v12 = sw_sync_pt_create(v11);
    if ( !v12 )
    {
      v14 = -1;
      printk(byte_4100, v11, 1);
      goto LABEL_19;
    }
    unused_fd_flags = get_unused_fd_flags(0x80000);
    v14 = unused_fd_flags;
    if ( unused_fd_flags < 0 )
    {
      printk(byte_4140, (unsigned int)unused_fd_flags);
    }
    else
    {
      v15 = sync_fence_create(v23, v12);
      v16 = v15;
      if ( v15 )
      {
        sync_fence_install(v15, v14);
        if ( strlen((const char *)(v16 + 12)) > 0x17 )
          printk(byte_42D0, v16 + 12);
        *(_QWORD *)(v16 + 36) = v11;
LABEL_19:
        v21 = v14;
        if ( !copy_to_user(a3, &v19, 24) )
        {
          v26 = v10;
          *(_QWORD *)v23 = 5;
          v24 = v19;
          v25 = v20;
          goto LABEL_9;
        }
        printk(byte_4308);
        sys_close(v14);
        v18 = (__int64)(v10 + 3);
        if ( !_InterlockedSub(v10 + 3, 1u) )
          goto LABEL_24;
        goto LABEL_22;
      }
      printk(byte_4288, v11, 1, v12);
      put_unused_fd(v14);
    }
    v14 = -1;
    sync_pt_free(v12);
    goto LABEL_19;
  }
  return result;
}
