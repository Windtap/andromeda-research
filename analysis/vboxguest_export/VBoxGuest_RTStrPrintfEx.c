__int64 VBoxGuest_RTStrPrintfEx(
        __int64 (__fastcall *a1)(__int64, __int64 (*)(__int64, const char *, ...), __int64, char **, __int64 *, _QWORD, _DWORD, unsigned int, int),
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        ...)
{
  gcc_va_list va; // [rsp+0h] [rbp-48h] BYREF

  va_start(va, a13);
  return VBoxGuest_RTStrPrintfExV(a1, a2, a3, a4, a5, (__int64 *)va);
}
