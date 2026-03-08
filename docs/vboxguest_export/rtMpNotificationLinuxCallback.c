__int64 __fastcall rtMpNotificationLinuxCallback(__int64 a1, __int64 a2, unsigned int a3)
{
  char v3; // cl
  __int64 v4; // rax

  v3 = a2 - 2;
  if ( (unsigned __int64)(a2 - 2) > 0x14 )
    return 0;
  v4 = 1LL << v3;
  if ( ((1LL << v3) & 0x100010) != 0 )
  {
    if ( a3 > 0x3FF || a3 >= nr_cpu_ids || !_bittest((const signed __int32 *)g_MpPendingOfflineSet, a3) )
      return 0;
  }
  else
  {
    if ( (v4 & 0x80008) != 0 )
    {
      if ( a3 <= 0x3FF && a3 < nr_cpu_ids )
        _interlockedbittestandset((volatile signed __int32 *)g_MpPendingOfflineSet, a3);
      goto LABEL_12;
    }
    if ( (v4 & 0x10001) == 0 )
      return 0;
    if ( a3 > 0x3FF )
      goto LABEL_12;
  }
  if ( a3 < nr_cpu_ids )
    _interlockedbittestandreset((volatile signed __int32 *)g_MpPendingOfflineSet, a3);
LABEL_12:
  if ( (v4 & 0x110011) != 0 )
  {
    rtMpNotificationDoCallbacks(1u, a3);
  }
  else if ( (v4 & 0x80008) != 0 )
  {
    rtMpNotificationDoCallbacks(2u, a3);
  }
  return 0;
}
