__int64 __fastcall VBoxGuest_RTErrConvertFromErrno(
        unsigned int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  if ( a1 )
    return VBoxGuest_RTErrConvertFromErrno_part_26(a1, a2, a3, a4, a5, a6, a7, a8, a9);
  else
    return 0;
}
