__int64 __fastcall VBoxGuest_RTTimerStart(__int64 a1, unsigned __int64 a2)
{
  bool v2; // zf
  signed __int32 v3; // ebp
  __int64 result; // rax
  __int64 v5; // [rsp+0h] [rbp-38h] BYREF
  unsigned __int64 v6; // [rsp+8h] [rbp-30h]
  __int64 v7; // [rsp+10h] [rbp-28h] BYREF
  __int64 v8; // [rsp+18h] [rbp-20h]

  if ( (unsigned __int64)(a1 + 0x200000) <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL
    || *(_DWORD *)a1 != 423037200 )
  {
    return 4294967292LL;
  }
  if ( !*(_BYTE *)(a1 + 16) )
    return 4294967228LL;
  v2 = *(_BYTE *)(a1 + 18) == 0;
  v6 = a2;
  if ( !v2 )
    return rtTimerLnxOmniStart(a1, &v5);
  v7 = 0;
  v8 = 0;
  ktime_get_ts64(&v7);
  v5 = v8 + 1000000000 * v7;
  _InterlockedExchange64((volatile __int64 *)(a1 + 192), a2 + v5);
  while ( 1 )
  {
    v3 = *(_DWORD *)(a1 + 208);
    if ( !v3 )
      break;
    if ( (unsigned int)(v3 - 4) > 1 )
      return 4294967068LL;
    if ( v3 == _InterlockedCompareExchange((volatile signed __int32 *)(a1 + 208), 6, v3) )
    {
      *(_BYTE *)(a1 + 16) = 0;
      return 0;
    }
LABEL_11:
    _mm_pause();
  }
  if ( _InterlockedCompareExchange((volatile signed __int32 *)(a1 + 208), 1, 0) )
    goto LABEL_11;
  *(_BYTE *)(a1 + 16) = 0;
  if ( *(_BYTE *)(a1 + 17) )
  {
    result = VBoxGuest_RTMpOnSpecific(*(_DWORD *)(a1 + 20), (__int64)rtTimerLnxStartOnSpecificCpu, a1, (__int64)&v5);
    if ( (int)result < 0 )
    {
      *(_BYTE *)(a1 + 16) = 1;
      _InterlockedExchange((volatile __int32 *)(a1 + 208), 0);
    }
    else
    {
      return 0;
    }
  }
  else
  {
    rtTimerLnxStartSubTimer(a1 + 104, v5, v6, 0, *(_BYTE *)(a1 + 19));
    return 0;
  }
  return result;
}
