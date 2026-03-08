__int64 __fastcall VBoxGuest_RTStrCalcUtf16LenEx(unsigned __int8 *a1, unsigned __int64 a2, __int64 *a3)
{
  __int64 result; // rax
  __int64 v5; // rdx
  _QWORD v6[2]; // [rsp+0h] [rbp-10h] BYREF

  if ( a2 == -1 )
    result = rtUtf8CalcUtf16Length(a1, v6);
  else
    result = rtUtf8CalcUtf16LengthN(a1, a2, v6);
  if ( a3 )
  {
    if ( (int)result < 0 )
      v5 = -1;
    else
      v5 = v6[0];
    *a3 = v5;
  }
  return result;
}
