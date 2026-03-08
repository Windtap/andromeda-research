__int64 __fastcall VBoxGuest_RTMemExecAllocTag(__int64 a1)
{
  __int64 v2; // [rsp+0h] [rbp-8h] BYREF

  if ( (int)rtR0MemAllocEx(a1, 2, &v2) >= 0 && v2 )
    return v2 + 16;
  else
    return 0;
}
