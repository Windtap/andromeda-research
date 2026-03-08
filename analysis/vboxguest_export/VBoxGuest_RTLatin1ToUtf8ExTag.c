__int64 __fastcall VBoxGuest_RTLatin1ToUtf8ExTag(
        unsigned __int8 *a1,
        __int64 a2,
        unsigned __int8 **a3,
        unsigned __int64 a4,
        unsigned __int64 *a5)
{
  __int64 result; // rax
  unsigned __int64 v10; // rax
  unsigned __int8 *v11; // rbx
  unsigned __int64 v12; // rax
  __int64 v13; // rdi
  unsigned int v14; // [rsp+4h] [rbp-3Ch]
  unsigned __int64 v15[7]; // [rsp+8h] [rbp-38h] BYREF

  result = rtLatin1CalcUtf8Length(a1, a2, (__int64 *)v15);
  if ( (int)result < 0 )
    return result;
  v10 = v15[0];
  if ( a5 )
    *a5 = v15[0];
  if ( !a4 || (v11 = *a3) == 0 )
  {
    v12 = v10 + 1;
    v13 = 1;
    *a3 = 0;
    if ( v12 >= a4 )
      a4 = v12;
    if ( a4 )
      v13 = a4;
    v11 = (unsigned __int8 *)VBoxGuest_RTMemAllocTag(v13);
    result = 4294967232LL;
    if ( !v11 )
      return result;
    *v11 = 0;
    result = rtLatin1RecodeAsUtf8(a1, a2, v11, a4 - 1);
    if ( (int)result < 0 )
    {
      v14 = result;
      VBoxGuest_RTMemFree((__int64)v11);
      return v14;
    }
LABEL_15:
    *a3 = v11;
    return result;
  }
  if ( a4 <= v10 )
    return 4294967255LL;
  result = rtLatin1RecodeAsUtf8(a1, a2, *a3, a4 - 1);
  if ( (int)result >= 0 )
    goto LABEL_15;
  return result;
}
