__int64 __fastcall vbsf_lock_kernel_pages(unsigned __int64 a1, __int64 a2, unsigned __int64 a3, __int64 a4)
{
  _BYTE *v4; // rax
  unsigned __int64 v7; // rcx
  __int64 v8; // rbp
  unsigned __int64 v9; // rdx
  unsigned __int64 v10; // r8
  unsigned __int64 v11; // r12
  __int64 v12; // rcx
  __int64 v13; // rax
  unsigned __int64 v14; // rbx
  __int64 v16; // rax
  __int64 v17; // rbx
  unsigned __int64 i; // rbp
  __int64 v19; // rdi
  char page_tail; // al
  __int64 v21; // [rsp+0h] [rbp-38h]

  v4 = (_BYTE *)a1;
  v7 = a3 << 12;
  v8 = a3 - 1;
  v9 = a1 & 0xFFFFFFFFFFFFF000LL;
  v10 = v7 + (a1 & 0xFFFFFFFFFFFFF000LL) - 1;
  v11 = v10;
  if ( !(_BYTE)a2 )
  {
    v9 = v8;
    if ( a3 )
    {
      do
      {
        LOBYTE(v7) = *v4;
        --v9;
        v4 += 4096;
      }
      while ( v9 != -1 );
      goto LABEL_4;
    }
LABEL_29:
    v8 = -1;
    goto LABEL_4;
  }
  if ( !a3 )
    goto LABEL_29;
  v9 = v8;
  do
  {
    v7 = (unsigned __int8)*v4;
    --v9;
    v4 += 4096;
    *(v4 - 4096) = v7;
  }
  while ( v9 != -1 );
LABEL_4:
  if ( a1 > 0xFFFF87FFFFFFFFFFLL && high_memory > v10 )
  {
    if ( a3 )
    {
      v12 = 0x77FF80000000LL;
      while ( 1 )
      {
        v13 = v12;
        if ( v11 >= 0xFFFFFFFF80000000LL )
          v13 = phys_base;
        v14 = ((v11 + 0x80000000 + v13) >> 12 << 6) - 0x160000000000LL;
        *(_QWORD *)(a4 + 8 * v8) = v14;
        if ( (*(_QWORD *)(v14 + 32) & 1) == 0 || (v21 = v12, page_tail = _get_page_tail(v14), v12 = v21, !page_tail) )
          _InterlockedIncrement((volatile signed __int32 *)(v14 + 28));
        v11 -= 4096LL;
        if ( !v8 )
          break;
        --v8;
      }
    }
    return 0;
  }
  if ( !a3 )
    return 0;
  while ( 1 )
  {
    v16 = VBoxGuest_rtR0MemObjLinuxVirtToPage(v11, a2, v9, v7);
    v17 = v16;
    if ( !v16 )
      break;
    *(_QWORD *)(a4 + 8 * v8) = v16;
    if ( (*(_QWORD *)(v16 + 32) & 1) == 0 || !(unsigned __int8)_get_page_tail(v16) )
      _InterlockedIncrement((volatile signed __int32 *)(v17 + 28));
    v11 -= 4096LL;
    if ( !v8 )
      return 0;
    --v8;
  }
  for ( i = v8 + 1; a3 > i; ++i )
  {
    v19 = *(_QWORD *)(a4 + 8 * i);
    put_page(v19);
  }
  return 4294967282LL;
}
