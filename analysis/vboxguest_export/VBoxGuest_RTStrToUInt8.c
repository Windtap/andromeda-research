__int64 __fastcall VBoxGuest_RTStrToUInt8(unsigned __int8 *a1)
{
  unsigned __int8 v2; // [rsp+7h] [rbp-1h] BYREF

  if ( VBoxGuest_RTStrToUInt8Ex(a1, 0, 0, &v2) < 0 )
    return 0;
  else
    return v2;
}
