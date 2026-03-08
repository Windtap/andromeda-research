__int64 __fastcall vbsf_show_options(__int64 a1, __int64 a2)
{
  __int64 v2; // rbx
  int v3; // edx
  int v4; // edx
  int v5; // edx
  int v6; // edx
  int v7; // edx
  int v8; // eax
  const char **v9; // rax
  const char *v10; // rdx
  int v11; // edx
  int v12; // edx
  int v13; // edx
  int v14; // edx

  v2 = *(_QWORD *)(*(_QWORD *)(a2 + 104) + 1120LL);
  if ( v2 )
  {
    v3 = *(_DWORD *)(v2 + 808);
    if ( v3 != -1 )
      seq_printf(a1, ",ttl=%d", v3);
    v4 = *(_DWORD *)(v2 + 812);
    if ( v4 >= 0 )
      seq_printf(a1, ",dcachettl=%d", v4);
    v5 = *(_DWORD *)(v2 + 816);
    if ( v5 >= 0 )
      seq_printf(a1, ",inodettl=%d", v5);
    v6 = *(_DWORD *)(v2 + 44);
    if ( v6 != 2048 )
      seq_printf(a1, ",maxiopages=%u", v6);
    v7 = *(_DWORD *)(v2 + 48);
    if ( v7 != (_DWORD)&unk_10000 )
      seq_printf(a1, ",dirbuf=%u", v7);
    v8 = *(_DWORD *)(v2 + 60);
    switch ( v8 )
    {
      case 3:
        seq_puts(a1, ",cache=read");
        break;
      case 4:
        seq_puts(a1, ",cache=readwrite");
        break;
      case 1:
        seq_puts(a1, ",cache=none");
        break;
    }
    v9 = *(const char ***)(v2 + 8);
    v10 = "utf8";
    if ( v9 )
      v10 = *v9;
    seq_printf(a1, ",iocharset=%s", v10);
    seq_printf(a1, ",uid=%u,gid=%u", *(_DWORD *)(v2 + 20), *(_DWORD *)(v2 + 24));
    v11 = *(_DWORD *)(v2 + 28);
    if ( v11 != -1 )
      seq_printf(a1, ",dmode=0%o", v11);
    v12 = *(_DWORD *)(v2 + 32);
    if ( v12 != -1 )
      seq_printf(a1, ",fmode=0%o", v12);
    v13 = *(_DWORD *)(v2 + 36);
    if ( v13 )
      seq_printf(a1, ",dmask=0%o", v13);
    v14 = *(_DWORD *)(v2 + 40);
    if ( v14 )
      seq_printf(a1, ",fmask=0%o", v14);
    if ( *(_BYTE *)(v2 + 64) )
    {
      seq_puts(a1, ",tag=");
      seq_escape(a1, v2 + 64, " \t\n\\");
    }
  }
  return 0;
}
