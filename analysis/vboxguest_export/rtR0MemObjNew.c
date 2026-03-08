_DWORD *__fastcall rtR0MemObjNew(__int64 a1, int a2, __int64 a3, __int64 a4)
{
  __int64 v6; // rbx
  _DWORD *result; // rax

  v6 = a1;
  if ( !a1 )
    v6 = 64;
  result = VBoxGuest_RTMemAllocZTag(v6);
  if ( result )
  {
    *result = 425792016;
    result[1] = v6;
    result[2] = a2;
    result[3] = 0;
    *((_QWORD *)result + 2) = a4;
    *((_QWORD *)result + 3) = a3;
  }
  return result;
}
