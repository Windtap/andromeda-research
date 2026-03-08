__int64 __fastcall vbsf_reg_release(_QWORD *a1, __int64 a2)
{
  __int64 v3; // rbx
  __int64 v4; // r13
  __int64 v5; // rax
  __int64 v6; // rdi
  int *v7; // r14

  v3 = *(_QWORD *)(a2 + 208);
  v4 = a1[69];
  if ( v3 )
  {
    v5 = a1[5];
    v6 = a1[6];
    v7 = *(int **)(v5 + 1120);
    if ( v6 && *(_QWORD *)(v6 + 80) && (unsigned int)filemap_fdatawrite() != -5 )
      filemap_fdatawait(a1[6], a2);
    *(_QWORD *)(a2 + 208) = 0;
    if ( _InterlockedExchangeAdd((volatile signed __int32 *)(v3 + 28), 0xFFFFFFFF) == 1 )
      vbsf_handle_release_slow((__int64 *)v3, v7);
    *(_QWORD *)(v4 + 48) = -1;
  }
  return 0;
}
