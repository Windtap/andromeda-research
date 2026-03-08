__int64 __fastcall vbsf_parse_mount_options(char *a1, _DWORD *a2)
{
  char *v2; // rax
  char *v3; // rbx
  __int64 v4; // rax
  const char *v5; // rcx
  const char *v7; // rax
  __int64 v8; // rbx
  int v9; // eax
  __int64 matched; // rax
  __int64 v11; // rbx
  __int64 v12; // rax
  __int64 DefaultInstance; // rax
  char *v14; // [rsp+0h] [rbp-60h] BYREF
  int v15; // [rsp+Ch] [rbp-54h] BYREF
  _BYTE v16[80]; // [rsp+10h] [rbp-50h] BYREF

  v14 = a1;
  if ( !a1 )
    return 4294967274LL;
  do
  {
LABEL_2:
    v2 = strsep(&v14, ",");
    v3 = v2;
    if ( !v2 )
      return (unsigned int)v3;
  }
  while ( !*v2 );
  switch ( (unsigned int)match_token(v2, &vbsf_tokens, v16) )
  {
    case 0u:
    case 1u:
      matched = match_strdup(v16);
      v11 = matched;
      if ( !matched )
      {
        LODWORD(v3) = -12;
        DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
        if ( DefaultInstance )
          VBoxGuest_RTLogLoggerEx(DefaultInstance, 16, 337, "vboxsf: Could not allocate memory for iocharset!\n");
        return (unsigned int)v3;
      }
      strlcpy(a2 + 66, matched, 32);
      kfree(v11);
      goto LABEL_2;
    case 2u:
      if ( (unsigned int)match_int(v16, &v15) )
        return 4294967274LL;
      a2[74] = v15;
      goto LABEL_2;
    case 3u:
      if ( (unsigned int)match_int(v16, &v15) )
        return 4294967274LL;
      a2[75] = v15;
      goto LABEL_2;
    case 4u:
      if ( (unsigned int)match_int(v16, &v15) )
        return 4294967274LL;
      a2[76] = v15;
      goto LABEL_2;
    case 5u:
      if ( (unsigned int)match_octal(v16, &v15) )
        return 4294967274LL;
      a2[77] = v15;
      goto LABEL_2;
    case 6u:
      if ( (unsigned int)match_octal(v16, &v15) )
        return 4294967274LL;
      a2[78] = v15;
      goto LABEL_2;
    case 7u:
      if ( (unsigned int)match_octal(v16, &v15) )
        return 4294967274LL;
      a2[79] = v15;
      goto LABEL_2;
    case 8u:
      if ( (unsigned int)match_octal(v16, &v15) )
        return 4294967274LL;
      a2[80] = v15;
      goto LABEL_2;
    case 9u:
      if ( (unsigned int)match_octal(v16, &v15) )
        return 4294967274LL;
      v9 = v15;
      a2[80] = v15;
      a2[79] = v9;
      goto LABEL_2;
    case 0xAu:
      if ( (unsigned int)match_int(v16, &v15) )
        return 4294967274LL;
      a2[89] = v15;
      goto LABEL_2;
    case 0xBu:
      if ( (unsigned int)match_int(v16, &v15) )
        return 4294967274LL;
      a2[90] = v15;
      goto LABEL_2;
    case 0xCu:
      if ( (unsigned int)match_int(v16, &v15) )
        return 4294967274LL;
      a2[91] = v15;
      goto LABEL_2;
    case 0xDu:
      if ( (unsigned int)match_int(v16, &v15) )
        return 4294967274LL;
      a2[92] = v15;
      goto LABEL_2;
    case 0xEu:
      v7 = (const char *)match_strdup(v16);
      v8 = (__int64)v7;
      if ( v7 )
      {
        if ( !strcmp(v7, "default") || !strcmp(v7, "strict") )
        {
          a2[93] = 2;
        }
        else if ( !strcmp(v7, "none") )
        {
          a2[93] = 1;
        }
        else if ( !strcmp(v7, "read") )
        {
          a2[93] = 3;
        }
        else if ( !strcmp(v7, "readwrite") )
        {
          a2[93] = 4;
        }
        else
        {
          printk(&unk_C368, v7);
        }
LABEL_44:
        kfree(v8);
        goto LABEL_2;
      }
      v4 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
      v5 = "vboxsf: Could not allocate memory for cachemode!\n";
      if ( v4 )
LABEL_6:
        VBoxGuest_RTLogLoggerEx(v4, 16, 337, v5);
LABEL_7:
      LODWORD(v3) = -12;
      return (unsigned int)v3;
    case 0xFu:
      v12 = match_strdup(v16);
      v8 = v12;
      if ( !v12 )
      {
        v4 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
        v5 = "vboxsf: Could not allocate memory for automount tag!\n";
        if ( v4 )
          goto LABEL_6;
        goto LABEL_7;
      }
      strlcpy(a2 + 81, v12, 32);
      goto LABEL_44;
    default:
      printk(&unk_C3E8, v3);
      return 4294967274LL;
  }
}
