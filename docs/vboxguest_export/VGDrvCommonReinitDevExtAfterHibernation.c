__int64 __fastcall VGDrvCommonReinitDevExtAfterHibernation(__int64 a1, int a2)
{
  __int64 result; // rax

  result = vgdrvReportGuestInfo(a2);
  if ( (int)result >= 0 )
    return vgdrvReportDriverStatus_constprop_15();
  return result;
}
