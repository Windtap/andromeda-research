__int64 __fastcall rtTimerLnxCallbackHandleMigration(__int64 a1, __int64 a2)
{
  __int64 result; // rax
  unsigned __int32 v3; // edx

  if ( *(_DWORD *)(a1 + 24) > 1u )
    result = VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a1 + 8));
  while ( 1 )
  {
    v3 = *(_DWORD *)(a2 + 104);
    if ( v3 == 7 )
      break;
    if ( v3 > 7 )
    {
      if ( v3 <= 9 )
        goto LABEL_13;
    }
    else if ( !v3 )
    {
      goto LABEL_13;
    }
    result = (unsigned int)_InterlockedCompareExchange((volatile signed __int32 *)(a2 + 104), 0, v3);
    if ( v3 == (_DWORD)result )
    {
LABEL_13:
      if ( *(_DWORD *)(a1 + 24) > 1u )
        return VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 8));
      return result;
    }
  }
  if ( *(_DWORD *)(a1 + 24) > 1u )
    VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 8));
  return rtTimerLnxCallbackDestroy(a1, a2);
}
