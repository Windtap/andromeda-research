__int64 __fastcall rtR0MemObjNativeReserveUser(_QWORD *a1, __int64 a2, __int64 a3, unsigned __int64 a4, __int64 a5)
{
  __int64 result; // rax
  unsigned __int64 v8; // rdx
  __int64 v9; // rax
  __int64 v10; // r12
  _DWORD *v11; // rax

  result = 4294967259LL;
  v8 = __readgsqword((unsigned int)&current_task);
  if ( a5 == *(_DWORD *)(v8 + 1940) && v8 && a4 <= 0x1000 )
  {
    v9 = rtR0MemObjLinuxDoMmap_isra_18(a2, a3, 0);
    v10 = v9;
    if ( v9 == -1 )
    {
      return 4294967288LL;
    }
    else
    {
      v11 = rtR0MemObjNew(104, 7, v9, a3);
      if ( v11 )
      {
        *((_QWORD *)v11 + 6) = a5;
        *a1 = v11;
        return 0;
      }
      else
      {
        vm_munmap(v10, a3);
        return 4294967288LL;
      }
    }
  }
  return result;
}
