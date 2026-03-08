__int64 __fastcall VBoxGuest_RTStrToInt64(unsigned __int8 *a1)
{
  __int64 v2; // [rsp+0h] [rbp-8h] BYREF

  if ( (int)VBoxGuest_RTStrToInt64Ex(a1, 0, 0, &v2) < 0 )
    return 0;
  else
    return v2;
}
