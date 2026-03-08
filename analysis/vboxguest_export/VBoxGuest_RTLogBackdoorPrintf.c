__int64 VBoxGuest_RTLogBackdoorPrintf(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        ...)
{
  gcc_va_list va; // [rsp+0h] [rbp-48h] BYREF

  va_start(va, a9);
  return VBoxGuest_RTStrFormatV(
           (__int64 (*)(__int64, const char *, ...))rtLogBackdoorOutput,
           0,
           (__int64 (__fastcall *)(__int64, __int64 (*)(__int64, const char *, ...), __int64, char **, __int64 *, _QWORD, _DWORD, unsigned int, int))rtlogFormatStr,
           0,
           a1,
           (__int64 *)va);
}
