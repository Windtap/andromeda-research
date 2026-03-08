__int64 __fastcall rtR0MemObjLink(__int64 a1, __int64 a2)
{
  __int64 v2; // rbp
  _DWORD *v3; // rax

  v2 = *(unsigned int *)(a1 + 36);
  if ( (unsigned int)v2 < *(_DWORD *)(a1 + 32) )
  {
    v3 = *(_DWORD **)(a1 + 40);
LABEL_3:
    *(_QWORD *)&v3[2 * v2] = a2;
    ++*(_DWORD *)(a1 + 36);
    *(_QWORD *)(a2 + 32) = a1;
    return 0;
  }
  v3 = VBoxGuest_RTMemReallocTag(*(_DWORD **)(a1 + 40), 8LL * (unsigned int)(v2 + 32));
  if ( v3 )
  {
    *(_QWORD *)(a1 + 40) = v3;
    *(_DWORD *)(a1 + 32) = v2 + 32;
    goto LABEL_3;
  }
  return 4294967288LL;
}
