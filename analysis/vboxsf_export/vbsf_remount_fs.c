__int64 __fastcall vbsf_remount_fs(__int64 a1, __int64 a2, char *a3)
{
  __int64 v3; // rbp
  __int64 result; // rax
  __int64 v5; // rax
  __int64 v6; // rbx
  _QWORD *v7; // r12
  _DWORD v8[100]; // [rsp+0h] [rbp-190h] BYREF

  v3 = *(_QWORD *)(a1 + 1120);
  if ( *(_DWORD *)a3 == -33620224 )
  {
    vbsf_super_info_copy_remount_options(*(_QWORD *)(a1 + 1120), (__int64)a3);
  }
  else
  {
    memset(v8, 0, 0x178u);
    v8[92] = -1;
    v8[91] = -1;
    v8[76] = -1;
    v8[78] = -1;
    v8[77] = -1;
    v8[93] = 2;
    v8[1] = 376;
    result = vbsf_parse_mount_options(a3, v8);
    if ( (_DWORD)result )
      return result;
    vbsf_super_info_copy_remount_options(v3, (__int64)v8);
  }
  v5 = ilookup(a1, 1);
  v6 = v5;
  if ( !v5 )
    return 4294967258LL;
  v7 = *(_QWORD **)(v5 + 552);
  if ( (unsigned int)vbsf_stat("vbsf_remount_fs", v3, *v7, v8, 0) )
    BUG();
  vbsf_init_inode(v6, v7, v8, v3);
  iput(v6);
  return 0;
}
