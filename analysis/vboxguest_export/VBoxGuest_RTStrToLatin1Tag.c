__int64 __fastcall VBoxGuest_RTStrToLatin1Tag(unsigned __int8 *a1, _QWORD *a2)
{
  __int64 result; // rax
  _BYTE *v3; // rbx
  unsigned int v4; // [rsp+4h] [rbp-24h]
  __int64 v5[4]; // [rsp+8h] [rbp-20h] BYREF

  *a2 = 0;
  result = rtUtf8CalcLatin1Length(a1, 0xFFFFFFFFFFFFFFFFLL, v5);
  if ( (int)result >= 0 )
  {
    v3 = (_BYTE *)VBoxGuest_RTMemAllocTag(v5[0] + 1);
    result = 4294967232LL;
    if ( v3 )
    {
      result = rtUtf8RecodeAsLatin1(a1, 0xFFFFFFFFFFFFFFFFLL, v3, v5[0]);
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
