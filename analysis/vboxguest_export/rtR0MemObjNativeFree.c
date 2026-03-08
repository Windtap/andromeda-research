__int64 __fastcall rtR0MemObjNativeFree(__int64 a1)
{
  __int64 v2; // rax
  unsigned __int64 v3; // rdx
  __int64 result; // rax
  __int64 v5; // rdx
  unsigned __int64 v6; // rax
  unsigned __int64 v7; // r12
  __int64 i; // rbp
  volatile signed __int8 *v9; // rdi
  __int64 v10; // rdi
  __int64 v11; // rdi

  switch ( *(_DWORD *)(a1 + 8) )
  {
    case 1:
    case 2:
    case 3:
    case 5:
    case 6:
      if ( *(_QWORD *)(a1 + 72) )
      {
        free_vm_area();
        kfree(*(_QWORD *)(a1 + 80));
        *(_QWORD *)(a1 + 72) = 0;
        *(_QWORD *)(a1 + 80) = 0;
      }
      else if ( *(_BYTE *)(a1 + 66) )
      {
        vunmap(*(_QWORD *)(a1 + 24));
        *(_BYTE *)(a1 + 66) = 0;
      }
      *(_QWORD *)(a1 + 24) = 0;
      rtR0MemObjLinuxFreePages(a1);
      result = 0;
      break;
    case 4:
      v5 = *(_QWORD *)(a1 + 48);
      if ( v5 != -1 )
      {
        v6 = __readgsqword((unsigned int)&current_task);
        v7 = 0;
        if ( v5 == *(_DWORD *)(v6 + 1940) )
        {
          if ( v6 )
          {
            v11 = *(_QWORD *)(v6 + 1768);
            v7 = v6;
            if ( v11 )
              down_read(v11 + 104);
          }
        }
        for ( i = *(_QWORD *)(a1 + 88); i; --i )
        {
          v9 = *(volatile signed __int8 **)(a1 + 8 * i + 88);
          if ( (*(_QWORD *)v9 & 0x400LL) == 0 )
          {
            _InterlockedOr8(v9, 0x10u);
            v9 = *(volatile signed __int8 **)(a1 + 8 * i + 88);
          }
          put_page(v9);
        }
        if ( v7 )
        {
          v10 = *(_QWORD *)(v7 + 1768);
          if ( v10 )
            up_read(v10 + 104);
        }
      }
      result = 0;
      break;
    case 7:
      v2 = *(_QWORD *)(a1 + 48);
      if ( v2 != -1 )
        goto LABEL_3;
      vunmap(*(_QWORD *)(a1 + 24));
      _free_pages(*(_QWORD *)(a1 + 96), 0);
      *(_QWORD *)(a1 + 96) = 0;
      *(_QWORD *)(a1 + 88) = 0;
      goto LABEL_4;
    case 8:
      v2 = *(_QWORD *)(a1 + 48);
      if ( v2 == -1 )
      {
        vunmap(*(_QWORD *)(a1 + 24));
      }
      else
      {
LABEL_3:
        v3 = __readgsqword((unsigned int)&current_task);
        if ( v2 == *(_DWORD *)(v3 + 1940) && v3 && *(_QWORD *)(v3 + 1768) )
          vm_munmap(*(_QWORD *)(a1 + 24), *(_QWORD *)(a1 + 16));
      }
LABEL_4:
      *(_QWORD *)(a1 + 24) = 0;
      result = 0;
      break;
    default:
      result = 4294967071LL;
      break;
  }
  return result;
}
