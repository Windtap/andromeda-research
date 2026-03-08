unsigned __int64 __fastcall VBoxGuest_RTTimeSpecFromString(unsigned __int64 a1, unsigned __int8 *a2)
{
  _BYTE v3[32]; // [rsp+0h] [rbp-20h] BYREF

  if ( VBoxGuest_RTTimeFromString((__int64)v3, a2) )
    return VBoxGuest_RTTimeImplode(a1, (__int64)v3);
  else
    return 0;
}
