__int64 __fastcall vbsf_dir_emit_nls(
        __int64 a1,
        __int64 a2,
        unsigned __int16 a3,
        __int64 a4,
        unsigned int a5,
        __int64 a6)
{
  int v8; // eax
  unsigned int v9; // edx
  unsigned int v10; // eax
  char s[279]; // [rsp+1h] [rbp-117h] BYREF

  v8 = vbsf_nlscpy(a6, s, 255, a2, a3);
  v9 = 1;
  if ( !v8 )
  {
    v10 = strlen(s);
    LOBYTE(v9) = (*(unsigned int (__fastcall **)(__int64, char *, _QWORD, _QWORD, __int64, _QWORD))a1)(
                   a1,
                   s,
                   v10,
                   *(_QWORD *)(a1 + 8),
                   a4,
                   a5) == 0;
  }
  return v9;
}
