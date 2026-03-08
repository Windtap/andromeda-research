void __fastcall vbsf_reg_write_sync_page_cache_isra_15_part_16(
        __int64 a1,
        __int64 a2,
        unsigned int a3,
        char *a4,
        _QWORD *a5,
        unsigned int a6)
{
  unsigned int i; // ebx
  int v9; // eax
  size_t v10; // rbp
  volatile signed __int8 *page; // rax
  volatile signed __int8 *v12; // r13
  __int64 v13; // rax
  __int64 v14; // rcx
  size_t v15; // rdx
  size_t v16; // [rsp+0h] [rbp-58h]
  __int64 v17; // [rsp+8h] [rbp-50h]
  __int64 v20; // [rsp+20h] [rbp-38h]

  for ( i = a3; i; i -= v10 )
  {
    while ( 1 )
    {
      v10 = 4096 - (a2 & 0xFFF);
      v17 = a2 & 0xFFF;
      if ( v10 > i )
        v10 = i;
      page = (volatile signed __int8 *)pagecache_get_page(a1, a2 >> 12, 2, 0);
      v12 = page;
      if ( page )
      {
        if ( a1 == *((_QWORD *)page + 1)
          && a2 >> 12 == *((_QWORD *)page + 2)
          && (*(_QWORD *)page & 0x10) == 0
          && (*(_QWORD *)page & 0x2000LL) == 0 )
        {
          v13 = (__int64)(page + 0x160000000000LL) >> 6 << 12;
          v14 = v13 - 0x780000000000LL;
          if ( a4 )
          {
            memcpy((void *)(v14 + v17), a4, v10);
          }
          else
          {
            v20 = v13 - 0x780000000000LL;
            v15 = 4096 - a6;
            v16 = v15;
            if ( v10 <= v15 )
              v15 = v10;
            memcpy(
              (void *)(v14 + v17),
              (const void *)(((*a5 + 0x160000000000LL) >> 6 << 12) - 0x780000000000LL + a6),
              v15);
            if ( v10 > v16 )
              memcpy(
                (void *)(v20 + v16 + v17),
                (const void *)(((a5[1] + 0x160000000000LL) >> 6 << 12) - 0x780000000000LL),
                v10 - v16);
          }
          if ( v10 == 4096 )
            _InterlockedOr8(v12, 8u);
          mark_page_accessed(v12);
        }
        unlock_page(v12);
        put_page(v12);
      }
      if ( !a4 )
        break;
      a4 += v10;
      v9 = v10;
LABEL_4:
      a2 += v10;
      i -= v9;
      if ( !i )
        return;
    }
    a6 += v10;
    v9 = v10;
    if ( a6 <= 0xFFF )
      goto LABEL_4;
    a6 &= 0xFFFu;
    a2 += v10;
    ++a5;
  }
}
