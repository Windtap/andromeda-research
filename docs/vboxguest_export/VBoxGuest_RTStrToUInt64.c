unsigned __int64 __fastcall VBoxGuest_RTStrToUInt64(unsigned __int8 *a1)
{
  unsigned __int64 v2; // [rsp+0h] [rbp-8h] BYREF

  if ( VBoxGuest_RTStrToUInt64Ex(a1, 0, 0, &v2) < 0 )
    return 0;
  else
    return v2;
}
