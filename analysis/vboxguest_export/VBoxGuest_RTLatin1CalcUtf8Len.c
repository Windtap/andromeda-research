__int64 __fastcall VBoxGuest_RTLatin1CalcUtf8Len(unsigned __int8 *a1)
{
  __int64 v2; // [rsp+0h] [rbp-8h] BYREF

  if ( (int)rtLatin1CalcUtf8Length(a1, -1, &v2) < 0 )
    return 0;
  else
    return v2;
}
