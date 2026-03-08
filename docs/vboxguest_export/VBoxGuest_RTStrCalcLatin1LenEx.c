__int64 __fastcall VBoxGuest_RTStrCalcLatin1LenEx(unsigned __int8 *a1, unsigned __int64 a2, __int64 *a3)
{
  __int64 result; // rax
  __int64 v5; // rdx
  __int64 v6; // [rsp+0h] [rbp-10h] BYREF

  result = rtUtf8CalcLatin1Length(a1, a2, &v6);
  if ( a3 )
  {
    if ( (int)result < 0 )
      v5 = -1;
    else
      v5 = v6;
    *a3 = v5;
  }
  return result;
}
