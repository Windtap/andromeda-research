__int64 __fastcall sf_mount(__int64 a1, __int64 a2, __int64 a3, char *a4)
{
  __int64 result; // rax
  _DWORD v6[102]; // [rsp+0h] [rbp-198h] BYREF

  if ( *(_DWORD *)a4 == -33620224 )
    return sf_mount_part_4(a1, a2, (__int64)a4);
  memset(v6, 0, 0x178u);
  v6[1] = 376;
  v6[92] = -1;
  v6[91] = -1;
  v6[76] = -1;
  v6[78] = -1;
  v6[77] = -1;
  v6[93] = 2;
  if ( a3 )
    strlcpy(&v6[2], a3, 256);
  LODWORD(result) = vbsf_parse_mount_options(a4, v6);
  if ( (_DWORD)result )
    return (int)result;
  else
    return mount_nodev(a1, (unsigned int)a2, v6, vbsf_read_super_26);
}
