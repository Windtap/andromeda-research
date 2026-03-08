__int64 __fastcall rtLatin1RecodeAsUtf8(unsigned __int8 *a1, __int64 a2, unsigned __int8 *a3, unsigned __int64 a4)
{
  unsigned __int8 *v7; // r12
  unsigned __int8 v8; // al
  unsigned __int64 v9; // r8
  __int64 result; // rax

  v7 = &a1[a2];
  while ( a1 != v7 )
  {
    v8 = *a1++;
    if ( !v8 )
      break;
    v9 = 2LL - (v8 < 0x80u);
    if ( a4 < v9 )
    {
      result = 4294967255LL;
      goto LABEL_8;
    }
    a4 -= v9;
    if ( v8 > 0x7Fu )
    {
      a3 = VBoxGuest_RTStrPutCpInternal(a3, v8);
      continue;
    }
    *a3++ = v8;
  }
  result = 0;
LABEL_8:
  *a3 = 0;
  return result;
}
