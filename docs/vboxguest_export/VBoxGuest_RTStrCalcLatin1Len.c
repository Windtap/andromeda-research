__int64 __fastcall VBoxGuest_RTStrCalcLatin1Len(unsigned __int8 *a1)
{
  __int64 v2; // [rsp+0h] [rbp-8h] BYREF

  if ( (int)rtUtf8CalcLatin1Length(a1, 0xFFFFFFFFFFFFFFFFLL, &v2) < 0 )
    return 0;
  else
    return v2;
}
