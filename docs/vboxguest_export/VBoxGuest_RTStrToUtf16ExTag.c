__int64 __fastcall VBoxGuest_RTStrToUtf16ExTag(
        unsigned __int8 *a1,
        unsigned __int64 a2,
        _WORD **a3,
        unsigned __int64 a4,
        _QWORD *a5)
{
  __int64 result; // rax
  unsigned __int64 v9; // rax
  _WORD *v10; // rbp
  int v11; // ebx
  unsigned __int64 v12; // rax
  _QWORD v13[7]; // [rsp+0h] [rbp-38h] BYREF

  if ( a2 == -1 )
    result = rtUtf8CalcUtf16Length(a1, v13);
  else
    result = rtUtf8CalcUtf16LengthN(a1, a2, v13);
  if ( (int)result >= 0 )
  {
    v9 = v13[0];
    if ( a5 )
      *a5 = v13[0];
    if ( a4 && (v10 = *a3) != 0 )
    {
      if ( a4 <= v9 )
        return 4294967255LL;
      result = rtUtf8RecodeAsUtf16(a1, a2, *a3, a4 - 1);
      v11 = result;
      if ( (int)result >= 0 )
        goto LABEL_10;
    }
    else
    {
      v12 = v9 + 1;
      *a3 = 0;
      if ( v12 >= a4 )
        a4 = v12;
      v10 = (_WORD *)VBoxGuest_RTMemAllocTag(2 * a4);
      result = 4294967231LL;
      if ( v10 )
      {
        v11 = rtUtf8RecodeAsUtf16(a1, a2, v10, a4 - 1);
        if ( v11 < 0 )
        {
          VBoxGuest_RTMemFree((__int64)v10);
          return (unsigned int)v11;
        }
LABEL_10:
        *a3 = v10;
        return (unsigned int)v11;
      }
    }
  }
  return result;
}
