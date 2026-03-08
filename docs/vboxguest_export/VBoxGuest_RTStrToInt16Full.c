__int64 __fastcall VBoxGuest_RTStrToInt16Full(unsigned __int8 *a1, unsigned int a2, _WORD *a3)
{
  __int64 result; // rax
  __int64 v5; // [rsp+0h] [rbp-10h] BYREF

  result = VBoxGuest_RTStrToInt64Full(a1, a2, &v5);
  if ( (int)result >= 0 && v5 != (__int16)v5 )
    result = 55;
  if ( a3 )
    *a3 = v5;
  return result;
}
