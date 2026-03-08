__int64 __fastcall VBoxGuest_RTLogFormatV(
        __int64 (*a1)(__int64, const char *, ...),
        __int64 a2,
        __int64 a3,
        __int64 *a4)
{
  return VBoxGuest_RTStrFormatV(
           a1,
           a2,
           (__int64 (__fastcall *)(__int64, __int64 (*)(__int64, const char *, ...), __int64, char **, __int64 *, _QWORD, _DWORD, unsigned int, int))rtlogFormatStr,
           0,
           a3,
           a4);
}
