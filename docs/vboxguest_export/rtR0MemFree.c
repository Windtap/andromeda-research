__int64 __fastcall rtR0MemFree(_DWORD *a1)
{
  int v1; // eax
  __int64 v2; // rax
  __int64 v3; // rbx
  _DWORD *v4; // rbp

  v1 = a1[1];
  ++*a1;
  if ( v1 < 0 )
    return kfree(a1);
  if ( (v1 & 0x20000000) != 0 )
  {
    v2 = *((_QWORD *)a1 - 2);
    v3 = *(unsigned int *)(v2 + 40);
    v4 = *(_DWORD **)(v2 + 32);
    vunmap(*(_QWORD *)(v2 + 8));
    for ( ; v3; --v3 )
      _free_pages(*(_QWORD *)&v4[2 * v3 - 2], 0);
    a1 = v4;
    return kfree(a1);
  }
  return vfree();
}
