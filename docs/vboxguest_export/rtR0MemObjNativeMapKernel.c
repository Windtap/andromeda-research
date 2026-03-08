__int64 __fastcall rtR0MemObjNativeMapKernel(
        _QWORD *a1,
        __int64 a2,
        __int64 a3,
        unsigned __int64 a4,
        int a5,
        unsigned __int64 a6,
        unsigned __int64 a7)
{
  unsigned __int64 v7; // rbx
  _DWORD *v10; // rbp
  __int64 result; // rax
  __int64 v12; // rax
  unsigned __int64 v13; // rax
  __int64 v14; // rax
  unsigned int v15; // ebx

  v7 = a7;
  if ( a3 != -1 || a4 > 0x1000 )
    return 4294967259LL;
  if ( !a7 )
    v7 = *(_QWORD *)(a2 + 16) - a6;
  v10 = rtR0MemObjNew(104, 8, 0, v7);
  result = 4294967288LL;
  if ( v10 )
  {
    if ( *(_QWORD *)(a2 + 88) )
    {
      v13 = rtR0MemObjLinuxConvertProt(a5, 1);
      v14 = vmap(a2 + 8 * (a6 >> 12) + 96, v7 >> 12, 4, v13);
      *((_QWORD *)v10 + 3) = v14;
      if ( v14 )
      {
        *((_BYTE *)v10 + 66) = 1;
LABEL_10:
        *((_QWORD *)v10 + 6) = -1;
        result = 0;
        *a1 = v10;
        return result;
      }
      v15 = -75;
    }
    else
    {
      if ( *(_DWORD *)(a2 + 60) == 1 )
        v12 = ioremap_nocache(*(_QWORD *)(a2 + 48) + a6, v7);
      else
        v12 = ioremap_cache(*(_QWORD *)(a2 + 48) + a6, v7);
      *((_QWORD *)v10 + 3) = v12;
      if ( v12 )
        goto LABEL_10;
      v15 = -8;
    }
    rtR0MemObjDelete((__int64)v10);
    return v15;
  }
  return result;
}
