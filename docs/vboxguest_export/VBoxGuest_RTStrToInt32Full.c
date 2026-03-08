__int64 __fastcall VBoxGuest_RTStrToInt32Full(unsigned __int8 *a1, unsigned int a2, _DWORD *a3)
{
  __int64 result; // rax
  __int64 v5; // [rsp+0h] [rbp-10h] BYREF

  result = VBoxGuest_RTStrToInt64Full(a1, a2, &v5);
  if ( (int)result >= 0 && v5 != (int)v5 )
    result = 55;
  if ( a3 )
    *a3 = v5;
  return result;
}
