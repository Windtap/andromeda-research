__int64 __fastcall VBoxGuest_RTStrToUtf16Tag(unsigned __int8 *a1, _QWORD *a2)
{
  __int64 result; // rax
  _WORD *v3; // rbx
  unsigned int v4; // [rsp+4h] [rbp-24h]
  __int64 v5[4]; // [rsp+8h] [rbp-20h] BYREF

  *a2 = 0;
  result = rtUtf8CalcUtf16Length(a1, v5);
  if ( (int)result >= 0 )
  {
    v3 = (_WORD *)VBoxGuest_RTMemAllocTag(2 * v5[0] + 2);
    result = 4294967231LL;
    if ( v3 )
    {
      result = rtUtf8RecodeAsUtf16(a1, -1, v3, v5[0]);
      if ( (int)result < 0 )
      {
        v4 = result;
        VBoxGuest_RTMemFree((__int64)v3);
        return v4;
      }
      else
      {
        *a2 = v3;
      }
    }
  }
  return result;
}
