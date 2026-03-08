__int64 __fastcall VBoxGuest_RTLatin1ToUtf8Tag(unsigned __int8 *a1, unsigned __int8 **a2)
{
  __int64 result; // rax
  unsigned __int8 *v3; // rbx
  unsigned int v4; // [rsp+4h] [rbp-24h]
  unsigned __int64 v5[4]; // [rsp+8h] [rbp-20h] BYREF

  *a2 = 0;
  result = rtLatin1CalcUtf8Length(a1, -1, (__int64 *)v5);
  if ( (int)result >= 0 )
  {
    v3 = (unsigned __int8 *)VBoxGuest_RTMemAllocTag(v5[0] + 1);
    result = 4294967232LL;
    if ( v3 )
    {
      result = rtLatin1RecodeAsUtf8(a1, -1, v3, v5[0]);
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
