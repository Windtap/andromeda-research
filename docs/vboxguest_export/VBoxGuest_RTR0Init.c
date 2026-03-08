__int64 VBoxGuest_RTR0Init()
{
  unsigned __int32 v0; // eax
  __int64 result; // rax
  unsigned int v2; // [rsp+0h] [rbp-4h]

  v0 = _InterlockedIncrement(&g_crtR0Users);
  if ( v0 == 1 )
  {
    result = rtR0InitNative();
    if ( (int)result >= 0 )
    {
      result = rtThreadInit();
      if ( (int)result < 0 )
      {
        v2 = result;
        rtR0TermNative();
        return v2;
      }
    }
  }
  else if ( v0 <= 1 )
  {
    _InterlockedExchangeAdd(&g_crtR0Users, 0xFFFFFFFF);
    return 4294967069LL;
  }
  else
  {
    return 0;
  }
  return result;
}
