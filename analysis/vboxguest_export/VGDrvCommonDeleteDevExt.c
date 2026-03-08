__int64 __fastcall VGDrvCommonDeleteDevExt(__int64 a1, __int64 a2)
{
  VGDrvCommonDeleteDevExtResources(a1, a2);
  return VGDrvCommonDeleteDevExtFundament(a1);
}
