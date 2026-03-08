__int64 __fastcall rtR0MemAllocEx(unsigned __int64 a1, int a2, _QWORD *a3)
{
  int v3; // r13d
  int v4; // r12d
  __int64 result; // rax
  unsigned __int64 v6; // rdi
  __int64 vm_area; // rax
  unsigned __int64 v8; // rbp
  __int64 v9; // r14
  __int64 v10; // rbx
  __int64 v11; // r15
  __int64 v12; // rax
  __int64 *v13; // rax
  _DWORD *v14; // rax
  __int64 v15; // rsi
  __int64 v16; // rbp

  v3 = a1;
  v4 = a2;
  if ( (a2 & 2) != 0 )
  {
    result = 4294967259LL;
    if ( (a2 & 0xC) != 0 )
      return result;
    v6 = (a1 + 4127) & 0xFFFFFFFFFFFFF000LL;
    vm_area = _get_vm_area(v6, 2, -1610612736, -16777216);
    v8 = v6 >> 12;
    v9 = vm_area;
    if ( !vm_area )
    {
      v14 = 0;
      goto LABEL_12;
    }
    *(_DWORD *)(vm_area + 40) = 0;
    *(_QWORD *)(vm_area + 32) = 0;
    v10 = _kmalloc(8 * v8, 37749440);
    if ( !v10 )
    {
      vunmap(*(_QWORD *)(v9 + 8));
      v14 = 0;
      goto LABEL_12;
    }
    v11 = 0;
    if ( v8 )
    {
      while ( 1 )
      {
        v12 = _alloc_pages_nodemask(37749442, 0, (char *)&contig_page_data + 7680, 0);
        *(_QWORD *)(v10 + 8 * v11) = v12;
        if ( !v12 )
          break;
        if ( ++v11 == v8 )
          goto LABEL_10;
      }
      if ( v8 != v11 )
        goto LABEL_23;
    }
    else
    {
      v11 = 0;
    }
LABEL_10:
    *(_DWORD *)(v9 + 40) = v8;
    *(_QWORD *)(v9 + 32) = v10;
    if ( !(unsigned int)map_vm_area(v9, 355, v10) )
    {
      v13 = *(__int64 **)(v9 + 8);
      *v13 = v9;
      v14 = v13 + 2;
      *((_QWORD *)v14 - 1) = 0;
LABEL_12:
      v4 = a2 | 0x20000000;
      goto LABEL_13;
    }
LABEL_23:
    v16 = v11;
    vunmap(*(_QWORD *)(v9 + 8));
    if ( v11 )
    {
      do
        _free_pages(*(_QWORD *)(v10 + 8 * v16-- - 8), 0);
      while ( v16 );
    }
    kfree(v10);
    v14 = 0;
    goto LABEL_12;
  }
  if ( a1 <= 0xFFF0 || (a2 & 0xC) != 0 )
  {
    v15 = 37749440;
    if ( (v4 & 4) != 0 )
      v15 = 34079264;
    v14 = (_DWORD *)_kmalloc(a1 + 16, v15);
    if ( v14 || a1 <= 0x1000 )
    {
      v4 |= 0x80000000;
    }
    else
    {
      if ( (v4 & 0xC) != 0 )
        return 4294967288LL;
      v4 &= ~0x80000000;
      v14 = (_DWORD *)vmalloc(a1 + 16);
    }
  }
  else
  {
    v14 = (_DWORD *)vmalloc(a1 + 16);
  }
LABEL_13:
  if ( !v14 )
    return 4294967288LL;
  *v14 = 403243289;
  v14[1] = v4;
  v14[2] = v3;
  v14[3] = v3;
  *a3 = v14;
  return 0;
}
