__int64 __fastcall VBoxGuest_RTStrPrintfV(__int64 a1, __int64 a2, __int64 a3, __int64 *a4)
{
  _QWORD v5[2]; // [rsp+0h] [rbp-10h] BYREF

  if ( !a2 )
    return 0;
  v5[0] = a1;
  v5[1] = a2 - 1;
  return VBoxGuest_RTStrFormatV((__int64 (*)(__int64, const char *, ...))strbufoutput, (__int64)v5, 0, 0, a3, a4);
}
