__int64 __fastcall VBoxGuest_RTLogComPrintfV(__int64 a1, __int64 *a2)
{
  return VBoxGuest_RTStrFormatV(
           (__int64 (*)(__int64, const char *, ...))rtLogComOutput,
           0,
           (__int64 (__fastcall *)(__int64, __int64 (*)(__int64, const char *, ...), __int64, char **, __int64 *, _QWORD, _DWORD, unsigned int, int))rtlogFormatStr,
           0,
           a1,
           a2);
}
