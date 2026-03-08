__int64 __fastcall rtThreadRelease_part_26(__int64 a1)
{
  signed __int32 v2; // eax
  unsigned __int32 v3; // r12d
  __int64 v5; // rbp
  __int64 v6; // rdi

  v2 = _InterlockedExchangeAdd((volatile signed __int32 *)(a1 + 36), 0xFFFFFFFF);
  v3 = v2 - 1;
  if ( v2 != 1 )
    return v3;
  if ( _bittest((const signed __int32 *)(a1 + 72), 2u) )
  {
    _InterlockedExchangeAdd((volatile signed __int32 *)(a1 + 36), 1u);
    rtThreadRemove(a1);
    _InterlockedExchangeAdd((volatile signed __int32 *)(a1 + 36), 0xFFFFFFFF);
  }
  _InterlockedExchange((volatile __int32 *)(a1 + 32), 422970900);
  _InterlockedExchange64((volatile __int64 *)a1, 0);
  v5 = *(_QWORD *)(a1 + 56);
  *(_DWORD *)(a1 + 64) = 0;
  v6 = *(_QWORD *)(a1 + 48);
  *(_QWORD *)(a1 + 56) = 0;
  *(_QWORD *)(a1 + 48) = 0;
  VBoxGuest_RTSemEventMultiDestroy(v6);
  if ( v5 )
    VBoxGuest_RTSemEventMultiDestroy(v5);
  rtThreadNativeDestroy(a1);
  VBoxGuest_RTMemFree(a1);
  return v3;
}
