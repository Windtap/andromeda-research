__int64 __fastcall VbglR0PhysHeapGetPhysAddr(__int64 a1)
{
  __int64 result; // rax

  result = 0;
  if ( a1 && a1 != 40 && (*(_BYTE *)(a1 - 32) & 1) != 0 )
    return (unsigned int)a1 - (unsigned int)*(_QWORD *)(a1 - 8) + *(_DWORD *)(*(_QWORD *)(a1 - 8) + 8LL);
  return result;
}
