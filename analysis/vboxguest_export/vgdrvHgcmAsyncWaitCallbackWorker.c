__int64 __fastcall vgdrvHgcmAsyncWaitCallbackWorker(__int64 a1, __int64 a2, char a3, unsigned int a4)
{
  __int64 v8; // rax
  __int64 v9; // rbp
  __int64 v10; // rdi
  __int64 result; // rax
  __int64 v12; // rdi
  int v13; // r12d
  __int64 v14; // rax
  _QWORD *v15; // rdx
  __int64 v16; // rdi
  __int64 v17; // rax
  _QWORD *v18; // rdx
  __int64 DefaultInstance; // rax
  int v20; // r9d

  while ( 1 )
  {
    VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a2 + 24));
    v10 = *(_QWORD *)(a2 + 24);
    if ( (*(_DWORD *)(a1 + 24) & 1) != 0 )
      goto LABEL_6;
    VBoxGuest_RTSpinlockRelease(v10);
    v8 = vgdrvWaitAlloc((_QWORD *)a2, 0);
    v9 = v8;
    if ( v8 )
      break;
    if ( a3 )
      return 4294967257LL;
    VBoxGuest_RTThreadSleep(1);
  }
  *(_DWORD *)(v8 + 16) = 2;
  *(_QWORD *)(v8 + 40) = a1;
  VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a2 + 24));
  **(_QWORD **)(a2 + 80) = v9;
  *(_QWORD *)(v9 + 8) = *(_QWORD *)(a2 + 80);
  *(_QWORD *)v9 = a2 + 72;
  *(_QWORD *)(a2 + 80) = v9;
  if ( (*(_DWORD *)(a1 + 24) & 1) != 0 )
  {
    v17 = *(_QWORD *)v9;
    *(_DWORD *)(v9 + 16) = 0;
    v18 = *(_QWORD **)(v9 + 8);
    *(_DWORD *)(v9 + 20) = 0;
    *(_QWORD *)(v9 + 40) = 0;
    *v18 = v17;
    *(_QWORD *)(v17 + 8) = v18;
    *(_QWORD *)v9 = 0;
    *(_QWORD *)(v9 + 8) = 0;
    **(_QWORD **)(a2 + 112) = v9;
    *(_QWORD *)(v9 + 8) = *(_QWORD *)(a2 + 112);
    *(_QWORD *)v9 = a2 + 104;
    v10 = *(_QWORD *)(a2 + 24);
    *(_QWORD *)(a2 + 112) = v9;
LABEL_6:
    VBoxGuest_RTSpinlockRelease(v10);
    return 0;
  }
  VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a2 + 24));
  v12 = *(_QWORD *)(v9 + 24);
  if ( a3 )
    v13 = VBoxGuest_RTSemEventMultiWaitNoResume(v12, a4);
  else
    v13 = VBoxGuest_RTSemEventMultiWait(v12, a4);
  result = 4294966933LL;
  if ( v13 != -363 )
  {
    if ( v13 < 0 && v13 != -40 && (v13 != -39 || a3 != 1) )
    {
      DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
      if ( DefaultInstance )
        VBoxGuest_RTLogLoggerEx(
          DefaultInstance,
          16,
          32,
          (unsigned int)"vgdrvHgcmAsyncWaitCallback: wait failed! %Rrc\n",
          v13,
          v20);
    }
    VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a2 + 24));
    v14 = *(_QWORD *)v9;
    *(_DWORD *)(v9 + 16) = 0;
    v15 = *(_QWORD **)(v9 + 8);
    *(_DWORD *)(v9 + 20) = 0;
    *(_QWORD *)(v9 + 40) = 0;
    *v15 = v14;
    *(_QWORD *)(v14 + 8) = v15;
    *(_QWORD *)v9 = 0;
    *(_QWORD *)(v9 + 8) = 0;
    **(_QWORD **)(a2 + 112) = v9;
    *(_QWORD *)(v9 + 8) = *(_QWORD *)(a2 + 112);
    *(_QWORD *)v9 = a2 + 104;
    v16 = *(_QWORD *)(a2 + 24);
    *(_QWORD *)(a2 + 112) = v9;
    VBoxGuest_RTSpinlockRelease(v16);
    return (unsigned int)v13;
  }
  return result;
}
