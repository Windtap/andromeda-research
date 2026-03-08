__int64 __fastcall vbsf_dir_release(__int64 a1, __int64 a2)
{
  __int64 v2; // rbx
  __int64 v3; // rax
  __int64 v4; // rdi
  __int64 v5; // rbp

  v2 = *(_QWORD *)(a2 + 208);
  if ( v2 )
  {
    v3 = *(_QWORD *)(a1 + 40);
    v4 = *(_QWORD *)(v2 + 64);
    v5 = *(_QWORD *)(v3 + 1120);
    *(_DWORD *)(v2 + 56) = 428344584;
    *(_DWORD *)(v2 + 76) = 0;
    *(_DWORD *)(v2 + 72) = 0;
    *(_QWORD *)(v2 + 88) = 0;
    *(_BYTE *)(v2 + 96) = 0;
    if ( v4 )
    {
      kfree(v4);
      *(_QWORD *)(v2 + 64) = 0;
    }
    if ( _InterlockedExchangeAdd((volatile signed __int32 *)(v2 + 28), 0xFFFFFFFF) == 1 )
      vbsf_handle_release_slow(v2, v5, "vbsf_dir_release");
  }
  return 0;
}
