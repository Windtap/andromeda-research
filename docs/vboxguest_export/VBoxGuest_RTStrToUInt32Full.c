int __fastcall VBoxGuest_RTStrToUInt32Full(unsigned __int8 *a1, unsigned int a2, _DWORD *a3)
{
  int result; // eax
  unsigned __int64 v5; // [rsp+0h] [rbp-10h] BYREF

  result = VBoxGuest_RTStrToUInt64Full(a1, a2, &v5);
  if ( result >= 0 && (v5 & 0xFFFFFFFF00000000LL) != 0 )
    result = 55;
  if ( a3 )
    *a3 = v5;
  return result;
}
