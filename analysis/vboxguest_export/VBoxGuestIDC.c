__int64 __fastcall VBoxGuestIDC(__int64 a1, __int64 a2, __int64 a3, unsigned __int64 a4)
{
  __int64 result; // rax
  unsigned int v6; // [rsp+0h] [rbp-20h]
  __int64 v8; // [rsp+10h] [rbp-10h] BYREF

  if ( (unsigned __int64)(a3 + 0x200000) <= 0x200FFF )
    return 4294967290LL;
  if ( (a3 & 0xFF00000000000000LL) != 0 && (a3 & 0xFF00000000000000LL) != 0xFF00000000000000LL || a4 <= 0x17 )
    return 4294967290LL;
  v8 = a1;
  if ( a1 )
  {
    result = 4294967292LL;
    if ( (unsigned __int64)(a1 + 0x200000) > 0x200FFF
      && ((a1 & 0xFF00000000000000LL) == 0 || (a1 & 0xFF00000000000000LL) == 0xFF00000000000000LL) )
    {
      result = 4294967292LL;
      if ( *(_UNKNOWN **)(a1 + 32) == &g_DevExt )
        return VGDrvCommonIoCtl(a2, &g_DevExt, a1, a3, a4);
    }
  }
  else
  {
    result = 4294967292LL;
    if ( a2 == 3224917567LL )
    {
      result = VGDrvCommonCreateKernelSession(&g_DevExt, &v8);
      if ( (int)result >= 0 )
      {
        result = VGDrvCommonIoCtl(3224917567LL, &g_DevExt, v8, a3, a4);
        if ( (int)result < 0 )
        {
          v6 = result;
          VGDrvCommonCloseSession(&g_DevExt, v8);
          return v6;
        }
      }
    }
  }
  return result;
}
