__int64 __fastcall VBoxGuest_RTStrToLatin1ExTag(
        unsigned __int8 *a1,
        unsigned __int64 a2,
        _BYTE **a3,
        unsigned __int64 a4,
        unsigned __int64 *a5)
{
  __int64 result; // rax
  unsigned __int64 v9; // rax
  _BYTE *v10; // rbp
  int v11; // ebx
  unsigned __int64 v12; // rax
  unsigned __int64 v13[7]; // [rsp+0h] [rbp-38h] BYREF

  result = rtUtf8CalcLatin1Length(a1, a2, v13);
  if ( (int)result >= 0 )
  {
    v9 = v13[0];
    if ( a5 )
      *a5 = v13[0];
    if ( a4 && (v10 = *a3) != 0 )
    {
      if ( a4 <= v9 )
        return 4294967255LL;
      result = rtUtf8RecodeAsLatin1(a1, a2, *a3, a4 - 1);
      v11 = result;
      if ( (int)result >= 0 )
        goto LABEL_8;
    }
    else
    {
      v12 = v9 + 1;
      *a3 = 0;
      if ( v12 >= a4 )
        a4 = v12;
      v10 = (_BYTE *)VBoxGuest_RTMemAllocTag(a4);
      result = 4294967232LL;
      if ( v10 )
      {
        v11 = rtUtf8RecodeAsLatin1(a1, a2, v10, a4 - 1);
        if ( v11 < 0 )
        {
          VBoxGuest_RTMemFree((__int64)v10);
          return (unsigned int)v11;
        }
LABEL_8:
        *a3 = v10;
        return (unsigned int)v11;
      }
    }
  }
  return result;
}
