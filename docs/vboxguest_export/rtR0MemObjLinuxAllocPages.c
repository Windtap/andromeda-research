__int64 __fastcall rtR0MemObjLinuxAllocPages(
        __int64 *a1,
        int a2,
        unsigned __int64 a3,
        unsigned __int64 a4,
        int a5,
        char a6,
        char a7,
        unsigned int a8)
{
  unsigned __int64 v10; // rbx
  __int64 v11; // r12
  _DWORD *v12; // rax
  __int64 v13; // r14
  unsigned __int64 v14; // rax
  int v15; // esi
  __int64 v16; // rax
  __int64 v17; // rax
  __int64 v18; // rdx
  __int64 v19; // r12
  bool v20; // cl
  unsigned __int64 j; // rdx
  __int64 v22; // r8
  unsigned int v24; // r12d
  __int64 v25; // r15
  __int64 v26; // rax
  __int64 i; // rbx
  unsigned __int64 v28; // rax
  int v29; // ecx
  __int64 v30; // rax

  v10 = a3 >> 12;
  v11 = 8 * (a3 >> 12);
  v12 = rtR0MemObjNew(v11 + 96, a2, 0, a3);
  v13 = (__int64)v12;
  if ( !v12 )
    return 4294967288LL;
  *((_QWORD *)v12 + 11) = v10;
  if ( v10 >= 0x100 )
    a5 |= 0x10400u;
  if ( a3 > 0x2000 && !a6 )
    goto LABEL_21;
  v14 = v10 >> 1;
  if ( v10 >> 1 )
  {
    v15 = 0;
    do
    {
      ++v15;
      v14 >>= 1;
    }
    while ( v14 );
    v16 = __ROL8__(-2, v15);
  }
  else
  {
    v16 = -2;
    v15 = 0;
  }
  v17 = _alloc_pages_nodemask(
          a5 | 0x4200u,
          v15 - ((unsigned int)((v10 & v16) == 0) - 1),
          (char *)&contig_page_data + 7680,
          0);
  if ( !v17 )
  {
    if ( a6 )
    {
LABEL_28:
      rtR0MemObjDelete(v13);
      return a8;
    }
LABEL_21:
    if ( !v10 )
    {
      *(_BYTE *)(v13 + 64) = 0;
      *(_BYTE *)(v13 + 65) = a7;
LABEL_19:
      *a1 = v13;
      return 0;
    }
    v24 = a5 | 0x200;
    v25 = 0;
    while ( 1 )
    {
      v26 = _alloc_pages_nodemask(v24, 0, (char *)&contig_page_data + 7680, 0);
      *(_QWORD *)(v13 + 8 * v25 + 96) = v26;
      if ( !v26 )
        break;
      if ( ++v25 == v10 )
      {
        *(_BYTE *)(v13 + 64) = 0;
        v20 = 0;
        *(_BYTE *)(v13 + 65) = a7;
        goto LABEL_15;
      }
    }
    for ( i = v25; i; --i )
      _free_pages(*(_QWORD *)(v13 + 8 * i + 88), 0);
    goto LABEL_28;
  }
  if ( v10 )
  {
    v18 = v13;
    v19 = v13 + v11;
    do
    {
      *(_QWORD *)(v18 + 96) = v17;
      v18 += 8;
      v17 += 64;
    }
    while ( v18 != v19 );
    *(_BYTE *)(v13 + 64) = 1;
    *(_BYTE *)(v13 + 65) = a7;
    v20 = a4 > 0x1000;
LABEL_15:
    for ( j = 0; j < v10; ++j )
      _InterlockedOr8((volatile signed __int8 *)(*(_QWORD *)(v13 + 8 * j + 96) + 1LL), 4u);
  }
  else
  {
    *(_BYTE *)(v13 + 64) = 1;
    *(_BYTE *)(v13 + 65) = a7;
    v20 = a4 > 0x1000;
  }
  if ( !v20 )
    goto LABEL_19;
  v22 = (*(_QWORD *)(v13 + 96) + 0x160000000000LL) >> 6 << 12;
  if ( ((a4 - 1) & v22) == 0 )
    goto LABEL_19;
  v28 = v10 >> 1;
  if ( v10 >> 1 )
  {
    v29 = 0;
    do
    {
      ++v29;
      v28 >>= 1;
    }
    while ( v28 );
    v30 = __ROL8__(-2, v29);
  }
  else
  {
    v30 = -2;
    v29 = 0;
  }
  printk(
    "rtR0MemObjLinuxAllocPages(cb=0x%lx, uAlignment=0x%lx): alloc_pages(..., %d) returned physical memory at 0x%lx!\n",
    a3,
    a4,
    v29 - (((v10 & v30) == 0) - 1),
    v22);
  rtR0MemObjLinuxFreePages(v13);
  return a8;
}
