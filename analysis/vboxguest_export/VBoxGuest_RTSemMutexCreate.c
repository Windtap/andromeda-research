__int64 __fastcall VBoxGuest_RTSemMutexCreate(__int64 *a1)
{
  __int64 v1; // rax

  v1 = VBoxGuest_RTMemAllocTag(40);
  if ( !v1 )
    return 4294967288LL;
  *(_DWORD *)v1 = 424805137;
  *(_DWORD *)(v1 + 4) = 0;
  *(_QWORD *)(v1 + 24) = 0;
  *(_DWORD *)(v1 + 32) = 1;
  *(_QWORD *)(v1 + 8) = v1 + 8;
  *(_QWORD *)(v1 + 16) = v1 + 8;
  *(_DWORD *)(v1 + 36) = 0;
  *a1 = v1;
  return 0;
}
