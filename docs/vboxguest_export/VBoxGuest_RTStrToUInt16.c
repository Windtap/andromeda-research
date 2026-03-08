__int64 __fastcall VBoxGuest_RTStrToUInt16(unsigned __int8 *a1)
{
  unsigned __int16 v2; // [rsp+6h] [rbp-2h] BYREF

  if ( VBoxGuest_RTStrToUInt16Ex(a1, 0, 0, &v2) < 0 )
    return 0;
  else
    return v2;
}
