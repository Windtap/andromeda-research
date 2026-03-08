void __fastcall rtlogLoggerExVLocked(__int64 a1, int a2, int a3, __int64 a4, __int64 *a5)
{
  __int64 v5; // [rsp+0h] [rbp-18h] BYREF
  int v6; // [rsp+8h] [rbp-10h]
  int v7; // [rsp+Ch] [rbp-Ch]

  if ( (*(_DWORD *)(a1 + 49160) & 0x7DFF8010) != 0 )
  {
    v5 = a1;
    v7 = a3;
    v6 = a2;
    VBoxGuest_RTStrFormatV(
      (__int64 (*)(__int64, const char *, ...))rtLogOutputPrefixed,
      (__int64)&v5,
      (__int64 (__fastcall *)(__int64, __int64 (*)(__int64, const char *, ...), __int64, char **, __int64 *, _QWORD, _DWORD, unsigned int, int))rtlogFormatStr,
      0,
      a4,
      a5);
  }
  else
  {
    VBoxGuest_RTStrFormatV(
      (__int64 (*)(__int64, const char *, ...))rtLogOutput,
      a1,
      (__int64 (__fastcall *)(__int64, __int64 (*)(__int64, const char *, ...), __int64, char **, __int64 *, _QWORD, _DWORD, unsigned int, int))rtlogFormatStr,
      0,
      a4,
      a5);
  }
  if ( (*(_BYTE *)(a1 + 49160) & 2) == 0 )
  {
    if ( *(_DWORD *)(a1 + 49152) )
      rtlogFlush_isra_12(a1);
  }
}
