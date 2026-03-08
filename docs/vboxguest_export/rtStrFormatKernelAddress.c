unsigned __int64 __fastcall rtStrFormatKernelAddress(void *a1, size_t a2, __int64 a3, __int64 a4, __int64 a5, char a6)
{
  int v6; // r9d
  char *v8; // rsi
  unsigned __int64 v9; // rbx

  v6 = a6 & 8;
  v8 = "0xXXXXXXXXXXXXXXXX";
  if ( !v6 )
    v8 = "XXXXXXXXXXXXXXXX";
  v9 = (-(__int64)(v6 == 0) & 0xFFFFFFFFFFFFFFFELL) + 19;
  if ( v9 <= a2 )
  {
    memcpy(a1, v8, (-(__int64)(v6 == 0) & 0xFFFFFFFFFFFFFFFELL) + 19);
    return v9 - 1;
  }
  else
  {
    *((char *)memcpy(a1, v8, a2) + a2 - 1) = 0;
    return a2 - 1;
  }
}
