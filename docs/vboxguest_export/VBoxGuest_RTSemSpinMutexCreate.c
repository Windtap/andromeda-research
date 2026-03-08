__int64 __fastcall VBoxGuest_RTSemSpinMutexCreate(__int64 *a1, int a2)
{
  _DWORD *v2; // rax
  __int64 v3; // rbx
  int v4; // eax
  unsigned int v6; // [rsp+4h] [rbp-1Ch]

  if ( (a2 & 0xFFFFFFFE) != 0 )
    return 4294967294LL;
  v2 = VBoxGuest_RTMemAllocZTag(56);
  v3 = (__int64)v2;
  if ( !v2 )
    return 4294967288LL;
  *v2 = 409403913;
  v2[1] = a2;
  *((_QWORD *)v2 + 1) = -1;
  v2[4] = 0;
  v4 = VBoxGuest_RTSemEventCreateEx(v2 + 6, 1, 0, 0);
  if ( v4 < 0 )
  {
    v6 = v4;
    VBoxGuest_RTMemFree(v3);
    return v6;
  }
  else
  {
    *a1 = v3;
    return 0;
  }
}
