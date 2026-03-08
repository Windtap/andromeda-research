__int64 __fastcall rtR0MemObjNativeEnterPhys(_QWORD *a1, __int64 a2, __int64 a3, int a4)
{
  _DWORD *v5; // rax

  v5 = rtR0MemObjNew(104, 5, 0, a3);
  if ( !v5 )
    return 4294967288LL;
  *((_QWORD *)v5 + 6) = a2;
  *((_BYTE *)v5 + 56) = 0;
  v5[15] = a4;
  *a1 = v5;
  return 0;
}
