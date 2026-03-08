__int64 __fastcall VBoxGuest_RTStrReallocTag(_DWORD **a1, unsigned __int64 a2)
{
  _DWORD *v3; // rdi
  _BYTE *v4; // rax

  v3 = *a1;
  if ( a2 )
  {
    if ( v3 )
    {
      v4 = VBoxGuest_RTMemReallocTag(v3, a2);
      if ( v4 )
      {
LABEL_4:
        v4[a2 - 1] = 0;
        *a1 = v4;
        return 0;
      }
    }
    else
    {
      v4 = (_BYTE *)VBoxGuest_RTMemAllocTag(a2);
      if ( v4 )
      {
        *v4 = 0;
        goto LABEL_4;
      }
    }
    return 4294967232LL;
  }
  else
  {
    VBoxGuest_RTMemFree((__int64)v3);
    *a1 = 0;
    return 0;
  }
}
