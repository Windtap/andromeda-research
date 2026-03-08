__int64 __fastcall rtR0MpNotificationNativeInit(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8)
{
  __int64 i; // rax
  unsigned int v9; // eax
  double v10; // xmm4_8
  double v11; // xmm5_8

  for ( i = 0; i != 16; ++i )
    g_MpPendingOfflineSet[i] = 0;
  v9 = register_cpu_notifier(&g_NotifierBlock);
  if ( v9 )
    return VBoxGuest_RTErrConvertFromErrno_part_26(v9, a1, a2, a3, a4, v10, v11, a7, a8);
  else
    return 0;
}
