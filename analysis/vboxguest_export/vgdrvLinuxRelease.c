__int64 __fastcall vgdrvLinuxRelease(__int64 a1, __int64 a2)
{
  VGDrvCommonCloseSession(&g_DevExt, *(_QWORD *)(a2 + 208));
  *(_QWORD *)(a2 + 208) = 0;
  return 0;
}
