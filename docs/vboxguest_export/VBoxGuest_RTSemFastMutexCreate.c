__int64 __fastcall VBoxGuest_RTSemFastMutexCreate(__int64 *a1)
{
  __int64 v1; // rax

  v1 = VBoxGuest_RTMemAllocTag(32);
  if ( !v1 )
    return 4294967288LL;
  *(_DWORD *)v1 = 412221699;
  *(_DWORD *)(v1 + 8) = 0;
  *(_DWORD *)(v1 + 12) = 1;
  *(_QWORD *)(v1 + 16) = v1 + 16;
  *(_QWORD *)(v1 + 24) = v1 + 16;
  *a1 = v1;
  return 0;
}
