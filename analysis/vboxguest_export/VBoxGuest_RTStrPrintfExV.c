__int64 __fastcall VBoxGuest_RTStrPrintfExV(
        __int64 (__fastcall *a1)(__int64, __int64 (*)(__int64, const char *, ...), __int64, char **, __int64 *, _QWORD, _DWORD, unsigned int, int),
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 *a6)
{
  _QWORD v7[2]; // [rsp+0h] [rbp-10h] BYREF

  if ( !a4 )
    return 0;
  v7[0] = a3;
  v7[1] = a4 - 1;
  return VBoxGuest_RTStrFormatV((__int64 (*)(__int64, const char *, ...))strbufoutput, (__int64)v7, a1, a2, a5, a6);
}
