__int64 __fastcall ld_onRecvSerialCallGLES(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5, _DWORD *a6)
{
  unsigned int v8; // r13d
  __int64 v9; // r12
  __int64 v10; // rax
  char v12[296]; // [rsp+0h] [rbp-128h] BYREF

  v8 = *(_DWORD *)(a2 + 20);
  v9 = *(_QWORD *)a2;
  mutex_lock(&g_mutex_lock_ioctl);
  switch ( *(_DWORD *)(a2 + 16) )
  {
    case 0:
      return mutex_unlock(&g_mutex_lock_ioctl);
    case 1:
      gensym(v12);
      v10 = goldfish_sync_timeline_create(v12);
      *(_DWORD *)(a4 + 16) = 1;
      goto LABEL_3;
    case 2:
      LODWORD(v10) = goldfish_sync_fence_create((__int64 *)v9, v8);
      *(_DWORD *)(a4 + 16) = 2;
      v10 = (int)v10;
LABEL_3:
      *(_QWORD *)a4 = v10;
      *(_DWORD *)(a4 + 20) = 0;
      *(_QWORD *)(a4 + 8) = *(_QWORD *)(a2 + 8);
      *a6 = 24;
      break;
    case 3:
      goldfish_sync_timeline_inc(v9, v8);
      break;
    case 4:
      if ( !_InterlockedSub((volatile signed __int32 *)(v9 + 12), 1u) )
        delete_timeline_obj(v9 + 12);
      break;
    default:
      printk(byte_4330);
      break;
  }
  return mutex_unlock(&g_mutex_lock_ioctl);
}
