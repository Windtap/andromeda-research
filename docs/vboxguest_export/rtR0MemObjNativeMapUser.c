__int64 __fastcall rtR0MemObjNativeMapUser(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        unsigned __int64 a4,
        int a5,
        __int64 a6,
        unsigned __int64 a7,
        __int64 a8)
{
  unsigned int v8; // r15d
  unsigned __int64 v9; // rbx
  unsigned __int64 v13; // r12
  unsigned __int64 v14; // r14
  __int64 v15; // r13
  __int64 vma; // rax
  __int64 v17; // r15
  int inserted; // eax
  int v19; // eax
  __int64 v20; // r15
  unsigned __int64 v21; // rbp
  __int64 v22; // r13
  __int64 v23; // r15
  __int64 v24; // rax
  unsigned __int64 v25; // [rsp+0h] [rbp-58h]
  __int64 v26; // [rsp+8h] [rbp-50h]
  _DWORD *v27; // [rsp+10h] [rbp-48h]

  v8 = -37;
  v9 = __readgsqword((unsigned int)&current_task);
  if ( a6 == *(_DWORD *)(v9 + 1940) && v9 && a4 <= 0x1000 )
  {
    if ( !a8 )
      a8 = *(_QWORD *)(a2 + 16);
    v8 = -8;
    v27 = rtR0MemObjNew(104, 8, 0, a8);
    if ( v27 )
    {
      v26 = rtR0MemObjLinuxDoMmap_isra_18(a3, a8, a5);
      if ( v26 == -1 )
      {
LABEL_17:
        rtR0MemObjDelete((__int64)v27);
        return v8;
      }
      v25 = rtR0MemObjLinuxConvertProt(a5, 0);
      down_write(*(_QWORD *)(v9 + 1768) + 104LL);
      v13 = (a7 + a8) >> 12;
      if ( *(_QWORD *)(a2 + 88) )
      {
        v14 = a7 >> 12;
        if ( v13 > a7 >> 12 )
        {
          v15 = v26;
          while ( 1 )
          {
            vma = find_vma(*(_QWORD *)(v9 + 1768), v15);
            v17 = vma;
            if ( !vma )
              break;
            inserted = vm_insert_page(vma, v15, *(_QWORD *)(a2 + 8 * v14 + 96));
            *(_QWORD *)(v17 + 80) |= 0x4040000uLL;
            if ( inserted )
              goto LABEL_15;
            ++v14;
            v15 += 4096;
            if ( v13 <= v14 )
              goto LABEL_20;
          }
LABEL_28:
          v8 = -225;
LABEL_16:
          up_write(*(_QWORD *)(v9 + 1768) + 104LL);
          vm_munmap(v26, a8);
          goto LABEL_17;
        }
      }
      else
      {
        v19 = *(_DWORD *)(a2 + 8);
        if ( v19 == 5 || v19 == 3 )
        {
          v20 = *(_QWORD *)(a2 + 48);
          if ( v20 != -1 )
          {
            v21 = a7 >> 12;
            if ( v13 > a7 >> 12 )
            {
              v22 = v26;
              v23 = v20 - v26;
              do
              {
                v24 = find_vma(*(_QWORD *)(v9 + 1768), v22);
                if ( !v24 )
                  goto LABEL_28;
                if ( (unsigned int)remap_pfn_range(v24, v22, v23 + v22, 4096, v25) )
                {
LABEL_15:
                  v8 = -8;
                  goto LABEL_16;
                }
                ++v21;
                v22 += 4096;
              }
              while ( v13 > v21 );
            }
          }
        }
      }
LABEL_20:
      v8 = 0;
      up_write(*(_QWORD *)(v9 + 1768) + 104LL);
      *((_QWORD *)v27 + 3) = v26;
      *((_QWORD *)v27 + 6) = a6;
      *a1 = v27;
    }
  }
  return v8;
}
