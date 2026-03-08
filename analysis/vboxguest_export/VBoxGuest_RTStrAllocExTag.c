__int64 __fastcall VBoxGuest_RTStrAllocExTag(_QWORD *a1, __int64 a2)
{
  __int64 v3; // rdi
  _BYTE *v4; // rax

  v3 = 1;
  if ( a2 )
    v3 = a2;
  v4 = (_BYTE *)VBoxGuest_RTMemAllocTag(v3);
  *a1 = v4;
  if ( !v4 )
    return 4294967232LL;
  *v4 = 0;
  return 0;
}
