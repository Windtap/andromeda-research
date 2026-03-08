__int64 __fastcall VBoxGuest_RTSemEventMultiCreateEx(_QWORD *a1, int a2)
{
  _DWORD *v2; // rax
  _DWORD *v3; // rbx

  if ( (a2 & 0xFFFFFFFE) != 0 )
    return 4294967294LL;
  v2 = (_DWORD *)VBoxGuest_RTMemAllocTag(40);
  v3 = v2;
  if ( !v2 )
    return 4294967288LL;
  *v2 = 421527810;
  v2[1] = -4;
  v2[2] = 1;
  _init_waitqueue_head(v2 + 4, "&pThis->Head", g_MpPendingOfflineSet);
  *a1 = v3;
  return 0;
}
