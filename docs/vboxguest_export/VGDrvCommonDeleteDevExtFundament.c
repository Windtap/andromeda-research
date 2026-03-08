__int64 __fastcall VGDrvCommonDeleteDevExtFundament(__int64 a1)
{
  __int64 result; // rax

  if ( *(_DWORD *)a1 == 195939070 )
  {
    *(_DWORD *)a1 = -559034160;
    VBoxGuest_RTSemFastMutexDestroy(*(_QWORD *)(a1 + 160));
    VBoxGuest_RTSpinlockDestroy(*(_QWORD *)(a1 + 24));
    return VBoxGuest_RTSpinlockDestroy(*(_QWORD *)(a1 + 128));
  }
  return result;
}
