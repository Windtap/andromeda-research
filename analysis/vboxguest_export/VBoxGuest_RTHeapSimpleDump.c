__int64 __fastcall VBoxGuest_RTHeapSimpleDump(_QWORD *a1, void (*a2)(const char *, ...))
{
  const void **v2; // rbx
  const void *v3; // rax
  const void **v4; // rcx
  const void *v5; // r9
  const void *v6; // r8
  int v7; // eax
  int v8; // edx

  v2 = (const void **)(a1 + 8);
  a2("**** Dumping Heap %p - cbHeap=%zx cbFree=%zx ****\n", a1, a1[1], a1[3]);
  if ( a1 != (_QWORD *)-64LL )
  {
    do
    {
      while ( 1 )
      {
        v3 = v2[4] ? *v2 : (const void *)a1[2];
        v4 = (const void **)*v2;
        v5 = v2[3];
        v6 = v2[1];
        v7 = -32 - (_DWORD)v2 + (_DWORD)v3;
        v8 = (_DWORD)v2 - ((_DWORD)a1 + 64);
        if ( ((unsigned __int8)v5 & 1) == 0 )
          break;
        a2(
          "%p  %06x FREE pNext=%p pPrev=%p fFlags=%#x cb=%#06x : cb=%#06x pNext=%p pPrev=%p\n",
          v2,
          v8,
          v4,
          v6,
          (_DWORD)v5,
          v7,
          (unsigned int)v2[6],
          v2[4],
          v2[5]);
        v2 = (const void **)*v2;
        if ( !v2 )
          return ((__int64 (*)(const char *, ...))a2)("**** Done dumping Heap %p ****\n", a1);
      }
      a2("%p  %06x USED pNext=%p pPrev=%p fFlags=%#x cb=%#06x\n", v2, v8, v4, v6, (_DWORD)v5, v7);
      v2 = (const void **)*v2;
    }
    while ( v2 );
  }
  return ((__int64 (*)(const char *, ...))a2)("**** Done dumping Heap %p ****\n", a1);
}
