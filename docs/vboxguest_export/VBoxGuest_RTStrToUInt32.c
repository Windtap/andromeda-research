__int64 __fastcall VBoxGuest_RTStrToUInt32(unsigned __int8 *a1)
{
  unsigned int v2; // [rsp+4h] [rbp-4h] BYREF

  if ( VBoxGuest_RTStrToUInt32Ex(a1, 0, 0, &v2) < 0 )
    return 0;
  else
    return v2;
}
