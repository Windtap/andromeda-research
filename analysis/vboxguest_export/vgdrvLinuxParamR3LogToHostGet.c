size_t __fastcall vgdrvLinuxParamR3LogToHostGet(char *a1)
{
  const char *v1; // rsi
  char *v2; // rax

  v1 = "enabled";
  if ( !byte_30A1C )
    v1 = "disabled";
  v2 = strcpy(a1, v1);
  return strlen(v2);
}
