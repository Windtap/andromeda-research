__int64 __fastcall VBoxGuest_RTSemSpinMutexDestroy(__int64 a1)
{
  __int64 result; // rax
  __int64 v3; // rdi
  unsigned int v4; // ebp

  if ( !a1 )
    return 0;
  if ( *(_DWORD *)a1 == 409403913 )
  {
    _InterlockedExchange((volatile __int32 *)a1, 420876809);
    v3 = *(_QWORD *)(a1 + 24);
    *(_QWORD *)(a1 + 24) = 0;
    v4 = VBoxGuest_RTSemEventDestroy(v3);
    VBoxGuest_RTMemFree(a1);
    return v4;
  }
  else
  {
    result = 4294966933LL;
    if ( *(_DWORD *)a1 != 420876809 )
      return 4294967292LL;
  }
  return result;
}
