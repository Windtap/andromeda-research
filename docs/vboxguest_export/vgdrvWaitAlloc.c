__int64 __fastcall vgdrvWaitAlloc(_QWORD *a1, __int64 a2)
{
  __int64 v2; // rbx
  _QWORD *v3; // rdx
  __int64 v4; // rax
  __int64 v5; // rdi
  __int64 v7; // rax
  int v8; // ebp
  __int64 v9; // rax
  int v10; // r8d
  int v11; // r9d
  __int64 DefaultInstance; // rax
  int v13; // r9d
  __int64 v14; // rdi

  if ( (_QWORD *)a1[14] != a1 + 13 && a1[13] )
  {
    VBoxGuest_RTSpinlockAcquire(a1[3]);
    if ( a1 + 13 != (_QWORD *)a1[14] )
    {
      v2 = a1[13];
      if ( v2 )
      {
        v3 = *(_QWORD **)(v2 + 8);
        v4 = *(_QWORD *)v2;
        *v3 = *(_QWORD *)v2;
        *(_QWORD *)(v4 + 8) = v3;
        *(_QWORD *)v2 = 0;
        *(_QWORD *)(v2 + 8) = 0;
        VBoxGuest_RTSpinlockRelease(a1[3]);
LABEL_6:
        v5 = *(_QWORD *)(v2 + 24);
        *(_DWORD *)(v2 + 16) = 0;
        *(_DWORD *)(v2 + 20) = 0;
        *(_QWORD *)(v2 + 32) = a2;
        *(_QWORD *)(v2 + 40) = 0;
        VBoxGuest_RTSemEventMultiReset(v5);
        return v2;
      }
    }
    VBoxGuest_RTSpinlockRelease(a1[3]);
  }
  v7 = VBoxGuest_RTMemAllocTag(48, "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/VBoxGuest.c");
  v2 = v7;
  if ( v7 )
  {
    v8 = VBoxGuest_RTSemEventMultiCreate(v7 + 24);
    if ( v8 >= 0 )
    {
      *(_QWORD *)v2 = 0;
      *(_QWORD *)(v2 + 8) = 0;
      goto LABEL_6;
    }
    DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( DefaultInstance && (unsigned int)s_LogRelMaxIt_cLogged_9113 <= 0x1F )
    {
      ++s_LogRelMaxIt_cLogged_9113;
      VBoxGuest_RTLogLoggerEx(
        DefaultInstance,
        16,
        32,
        (unsigned int)"vgdrvWaitAlloc: RTSemEventMultiCreate failed with rc=%Rrc!\n",
        v8,
        v13);
    }
    v14 = v2;
    v2 = 0;
    VBoxGuest_RTMemFree(v14);
  }
  else
  {
    v9 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( v9 )
    {
      if ( (unsigned int)s_LogRelMaxIt_cLogged_9111 <= 0x1F )
      {
        ++s_LogRelMaxIt_cLogged_9111;
        VBoxGuest_RTLogLoggerEx(v9, 16, 32, (unsigned int)"vgdrvWaitAlloc: out-of-memory!\n", v10, v11);
      }
    }
    else
    {
      return 0;
    }
  }
  return v2;
}
