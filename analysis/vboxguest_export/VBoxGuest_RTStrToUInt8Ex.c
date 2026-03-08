int __fastcall VBoxGuest_RTStrToUInt8Ex(unsigned __int8 *a1, unsigned __int8 **a2, unsigned int a3, _BYTE *a4)
{
  int result; // eax
  unsigned __int64 v6; // [rsp+0h] [rbp-10h] BYREF

  result = VBoxGuest_RTStrToUInt64Ex(a1, a2, a3, &v6);
  if ( result >= 0 && (v6 & 0xFFFFFFFFFFFFFF00LL) != 0 )
    result = 55;
  if ( a4 )
    *a4 = v6;
  return result;
}
