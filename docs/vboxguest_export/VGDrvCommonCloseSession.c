__int64 __fastcall VGDrvCommonCloseSession(__int64 a1, __int64 a2)
{
  unsigned int v3; // ebx
  _QWORD *v4; // rdx
  __int64 v5; // rax
  __int64 v6; // rdi
  __int64 v7; // rax
  __int64 v8; // rdi

  v3 = 0;
  VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a1 + 128));
  v4 = *(_QWORD **)(a2 + 8);
  v5 = *(_QWORD *)a2;
  *v4 = *(_QWORD *)a2;
  *(_QWORD *)(v5 + 8) = v4;
  *(_QWORD *)a2 = 0;
  *(_QWORD *)(a2 + 8) = 0;
  v6 = *(_QWORD *)(a1 + 128);
  --*(_DWORD *)(a1 + 152);
  VBoxGuest_RTSpinlockRelease(v6);
  vgdrvAcquireSessionCapabilities(a1, a2, 0, -1, 0, 1);
  vgdrvSetSessionCapabilities(a1, a2, 0, -1, 0, 0, 1);
  vgdrvSetSessionEventFilter(a1, a2, 0, -1, 1);
  vgdrvSetSessionMouseStatus(a1, a2, 0, -1, 1);
  vgdrvIoCtl_CancelAllWaitEvents(a1, a2);
  do
  {
    while ( 1 )
    {
      v7 = a2 + 4LL * v3;
      if ( *(_DWORD *)(v7 + 40) )
        break;
      if ( ++v3 == 64 )
        goto LABEL_5;
    }
    v8 = *(unsigned int *)(v7 + 40);
    *(_DWORD *)(v7 + 40) = 0;
    ++v3;
    VbglR0HGCMInternalDisconnect(v8, 1, vgdrvHgcmAsyncWaitCallback, a1, 0xFFFFFFFFLL);
  }
  while ( v3 != 64 );
LABEL_5:
  *(_QWORD *)(a2 + 32) = 0;
  *(_DWORD *)(a2 + 20) = -1;
  *(_QWORD *)(a2 + 24) = -1;
  vgdrvCloseMemBalloon(a1, a2);
  return VBoxGuest_RTMemFree(a2);
}
