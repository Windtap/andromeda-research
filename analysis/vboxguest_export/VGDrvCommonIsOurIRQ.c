__int64 __fastcall VGDrvCommonIsOurIRQ(__int64 a1)
{
  __int64 v1; // rax
  unsigned int v2; // ebp

  VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a1 + 24));
  v1 = *(_QWORD *)(a1 + 8);
  if ( v1 )
  {
    v2 = *(unsigned __int8 *)(v1 + 8);
    VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 24));
    return v2;
  }
  else
  {
    VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 24));
    return 0;
  }
}
