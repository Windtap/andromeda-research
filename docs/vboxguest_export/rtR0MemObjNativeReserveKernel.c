__int64 __fastcall rtR0MemObjNativeReserveKernel(_QWORD *a1, __int64 a2, unsigned __int64 a3, unsigned __int64 a4)
{
  __int64 result; // rax
  unsigned __int64 v6; // r12
  __int64 v7; // rbp
  __int64 v8; // rax
  __int64 v9; // rbx
  unsigned __int64 v10; // r8
  __int64 v11; // r12
  _QWORD *v12; // rax

  result = 4294967259LL;
  v6 = a3 >> 12;
  if ( a2 == -1 && a4 <= 0x1000 )
  {
    v7 = _alloc_pages_nodemask(37880514, 0, (char *)&contig_page_data + 7680, 0);
    if ( !v7 )
      return 4294967288LL;
    v8 = VBoxGuest_RTMemAllocTag(8 * v6);
    v9 = v8;
    if ( v8 )
    {
      v10 = v6 - 1;
      if ( v6 )
      {
        do
          *(_QWORD *)(v8 + 8 * v10--) = v7;
        while ( v10 != -1 );
      }
      v11 = vmap(v8, (unsigned int)v6, 4, 0x8000000000000161LL);
      VBoxGuest_RTMemFree(v9);
      if ( v11 )
      {
        v12 = rtR0MemObjNew(104, 7, v11, a3);
        if ( v12 )
        {
          v12[6] = -1;
          v12[11] = 1;
          v12[12] = v7;
          *a1 = v12;
          return 0;
        }
        vunmap(v11);
      }
    }
    _free_pages(v7, 0);
    return 4294967288LL;
  }
  return result;
}
