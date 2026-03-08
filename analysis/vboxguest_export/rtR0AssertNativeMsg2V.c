__int64 __fastcall rtR0AssertNativeMsg2V(__int64 a1, __int64 a2, __int64 *a3)
{
  _BYTE v4[256]; // [rsp+0h] [rbp-100h] BYREF

  VBoxGuest_RTStrPrintfV((__int64)v4, 255, a2, a3);
  v4[255] = 0;
  return printk(byte_2859D, v4);
}
