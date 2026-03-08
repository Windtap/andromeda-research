__int64 __fastcall rtThreadTerminate(__int64 a1, int a2)
{
  __int64 v3; // rdi
  __int64 result; // rax

  *(_DWORD *)(a1 + 76) = a2;
  _InterlockedExchange((volatile __int32 *)(a1 + 40), 2);
  _InterlockedOr((volatile signed __int32 *)(a1 + 72), 2u);
  v3 = *(_QWORD *)(a1 + 56);
  if ( v3 )
    VBoxGuest_RTSemEventMultiSignal(v3);
  rtThreadRemove(a1);
  result = *(unsigned int *)(a1 + 36);
  if ( (_DWORD)result )
    return rtThreadRelease_part_26(a1);
  return result;
}
