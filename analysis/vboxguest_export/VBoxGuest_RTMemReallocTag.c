_DWORD *__fastcall VBoxGuest_RTMemReallocTag(_DWORD *src, unsigned __int64 a2)
{
  unsigned __int64 v2; // rax
  unsigned int v3; // edx
  __int64 v4; // rbp
  _QWORD v6[3]; // [rsp+0h] [rbp-18h] BYREF

  if ( !a2 && src )
  {
    v4 = 0;
    VBoxGuest_RTMemFree((__int64)src);
    return (_DWORD *)v4;
  }
  if ( !src )
    return (_DWORD *)VBoxGuest_RTMemAllocTag(a2);
  if ( *(src - 4) != 403243289 )
    return 0;
  v2 = (unsigned int)*(src - 2);
  if ( a2 > v2 || v2 - a2 > 0x80 )
  {
    if ( (int)rtR0MemAllocEx(a2, 0, v6) >= 0 && v6[0] )
    {
      v3 = *(src - 2);
      v4 = v6[0] + 16LL;
      if ( *(_DWORD *)(v6[0] + 8LL) <= v3 )
        v3 = *(_DWORD *)(v6[0] + 8LL);
      memcpy((void *)(v6[0] + 16LL), src, v3);
      rtR0MemFree(src - 4);
      return (_DWORD *)v4;
    }
    return 0;
  }
  *(src - 1) = a2;
  return src;
}
