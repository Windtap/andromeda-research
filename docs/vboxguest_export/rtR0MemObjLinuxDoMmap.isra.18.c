__int64 __fastcall rtR0MemObjLinuxDoMmap_isra_18(__int64 a1, __int64 a2, char a3)
{
  __int64 v3; // rcx
  __int64 v4; // rax
  __int64 v5; // rdx

  v3 = 0;
  if ( (a3 & 7) != 0 )
  {
    v3 = a3 & 3 | 4u;
    if ( (a3 & 4) == 0 )
      v3 = a3 & 3;
  }
  if ( a1 == -1 )
    v4 = vm_mmap(0, 0, a2, v3, 33, 0);
  else
    v4 = vm_mmap(0, a1, a2, v3, 49, 0);
  v5 = -1;
  if ( (v4 & 0xFFF) == 0 )
    return v4;
  return v5;
}
