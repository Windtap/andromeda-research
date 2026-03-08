__int64 __fastcall VBoxGuest_RTSpinlockCreate(__int64 *a1, int a2)
{
  __int64 v2; // rax

  if ( a2 != 4 && a2 != 2 )
    return 4294967294LL;
  v2 = VBoxGuest_RTMemAllocTag(24);
  if ( !v2 )
    return 4294967288LL;
  *(_DWORD *)v2 = 424150056;
  *(_DWORD *)(v2 + 4) = a2;
  *(_QWORD *)(v2 + 8) = 0;
  *(_DWORD *)(v2 + 16) = 0;
  *a1 = v2;
  return 0;
}
