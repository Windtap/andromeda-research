__int64 __fastcall rtR0MemObjLinuxVMap(__int64 a1, char a2)
{
  unsigned __int64 v3; // rdi
  __int64 v5; // rax
  __int64 v6; // rax
  __int64 v7; // rbp
  __int64 v8; // rax
  __int64 v9; // rdx
  bool v10; // zf
  __int64 v11; // r10
  unsigned __int64 v12; // rcx
  __int64 v13; // rax
  __int64 *v14; // r8
  __int64 v15; // rcx
  __int64 v16; // rax

  if ( !a2 )
  {
    if ( *(_BYTE *)(a1 + 64) )
    {
      *(_QWORD *)(a1 + 24) = ((*(_QWORD *)(a1 + 96) + 0x160000000000LL) >> 6 << 12) - 0x780000000000LL;
      return 0;
    }
    v5 = vmap(a1 + 96, *(unsigned int *)(a1 + 88), 4, 0x8000000000000003LL);
    *(_QWORD *)(a1 + 24) = v5;
    if ( v5 )
    {
      *(_BYTE *)(a1 + 66) = 1;
      return 0;
    }
    return 4294967221LL;
  }
  v3 = *(_QWORD *)(a1 + 88);
  if ( v3 > 0x1FFFFFFFFFFFFFFFLL )
    return 4294967221LL;
  v6 = _kmalloc(8 * v3, 37748928);
  v7 = v6;
  if ( !v6 )
    return 4294967221LL;
  v8 = alloc_vm_area(*(_QWORD *)(a1 + 16), v6);
  *(_QWORD *)(a1 + 72) = v8;
  if ( !v8 )
  {
    kfree(v7);
    return 4294967221LL;
  }
  v10 = *(_QWORD *)(a1 + 88) == 0;
  *(_QWORD *)(a1 + 80) = v7;
  if ( !v10 )
  {
    v11 = 0x160000000000LL;
    v12 = 0;
    do
    {
      v13 = ((__int64 (__fastcall *)(unsigned __int64, unsigned __int64, __int64, unsigned __int64, _QWORD))pv_mmu_ops[30])(
              _supported_pte_mask & 0x8000000000000003LL | ((*(_QWORD *)(a1 + 8 * v12 + 96) + v11) >> 6 << 12),
              0x8000000000000003LL,
              v9,
              v12,
              *(_QWORD *)(v7 + 8 * v12));
      *v14 = v13;
      v12 = v15 + 1;
    }
    while ( v12 < *(_QWORD *)(a1 + 88) );
    v8 = *(_QWORD *)(a1 + 72);
  }
  v16 = *(_QWORD *)(v8 + 8);
  *(_BYTE *)(a1 + 66) = 1;
  *(_QWORD *)(a1 + 24) = v16;
  return 0;
}
