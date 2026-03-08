__int64 __fastcall rtR0MemObjNativeProtect(__int64 a1, unsigned __int64 a2, __int64 a3, int a4)
{
  unsigned __int64 v6; // rax
  __int64 v7; // r15
  unsigned __int64 v8; // rbp
  unsigned __int64 v9; // rbx
  unsigned __int64 v10; // rdi
  __int64 v11; // rsi
  unsigned __int64 v13; // [rsp+0h] [rbp-38h]

  if ( !*(_QWORD *)(a1 + 72) || !*(_QWORD *)(a1 + 80) )
    return 4294967259LL;
  v6 = rtR0MemObjLinuxConvertProt(a4, 1);
  v7 = *(_QWORD *)(a1 + 80);
  v8 = v6;
  v9 = a2 >> 12;
  v13 = (a2 + a3) >> 12;
  if ( v13 > a2 >> 12 )
  {
    do
    {
      v10 = _supported_pte_mask & v8;
      if ( (v8 & 1) == 0 )
        v10 = v8;
      v11 = ((__int64 (__fastcall *)(unsigned __int64))pv_mmu_ops[30])(((*(_QWORD *)(a1 + 8 * v9 + 96) + 0x160000000000LL) >> 6 << 12) | v10);
      ((void (__fastcall *)(_QWORD, __int64))pv_mmu_ops[19])(*(_QWORD *)(v7 + 8 * v9++), v11);
    }
    while ( v9 != v13 );
  }
  preempt_count_add(1);
  pv_mmu_ops[8]();
  preempt_count_sub(1);
  if ( !__readgsdword((unsigned int)&_preempt_count) )
    __preempt_schedule();
  return 0;
}
