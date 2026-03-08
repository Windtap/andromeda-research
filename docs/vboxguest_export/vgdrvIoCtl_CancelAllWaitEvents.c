__int64 __fastcall vgdrvIoCtl_CancelAllWaitEvents(__int64 a1, __int64 a2)
{
  __int64 v3; // r15
  _QWORD *v4; // r12
  _QWORD *v5; // rbp
  char v6; // dl
  _QWORD *v7; // rbx
  _QWORD *v9; // rdx
  _QWORD *v10; // rax
  __int64 v11; // rdi
  __int64 v12; // rax

  v3 = a1 + 88;
  v4 = (_QWORD *)(a1 + 56);
  VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a1 + 24));
  v5 = *(_QWORD **)(a1 + 56);
  v6 = 0;
  v7 = (_QWORD *)*v5;
  if ( v5 == (_QWORD *)(a1 + 56) )
    goto LABEL_8;
  while ( 1 )
  {
    if ( v5[4] == a2 )
    {
      v9 = (_QWORD *)v5[1];
      *((_DWORD *)v5 + 5) = -1;
      v10 = (_QWORD *)*v5;
      *v9 = *v5;
      v10[1] = v9;
      v11 = v5[3];
      *v5 = 0;
      v5[1] = 0;
      VBoxGuest_RTSemEventMultiSignal(v11);
      v6 = 1;
      **(_QWORD **)(a1 + 96) = v5;
      v12 = *(_QWORD *)(a1 + 96);
      *v5 = v3;
      v5[1] = v12;
      *(_QWORD *)(a1 + 96) = v5;
    }
    if ( v4 == v7 )
      break;
    v5 = v7;
    v7 = (_QWORD *)*v7;
  }
  if ( !v6 )
LABEL_8:
    *(_BYTE *)(a2 + 316) = 1;
  VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 24));
  return 0;
}
