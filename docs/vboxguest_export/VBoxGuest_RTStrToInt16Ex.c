__int64 __fastcall VBoxGuest_RTStrToInt16Ex(unsigned __int8 *a1, unsigned __int8 **a2, unsigned int a3, _WORD *a4)
{
  __int64 result; // rax
  __int64 v6; // [rsp+0h] [rbp-10h] BYREF

  result = VBoxGuest_RTStrToInt64Ex(a1, a2, a3, &v6);
  if ( (int)result >= 0 && v6 != (__int16)v6 )
    result = 55;
  if ( a4 )
    *a4 = v6;
  return result;
}
