__int64 __fastcall VBoxGuest_RTMemFreeEx(__int64 a1)
{
  __int64 result; // rax

  if ( a1 )
  {
    if ( *(_DWORD *)(a1 - 16) == 403243289 )
      return rtR0MemFree(a1 - 16);
  }
  return result;
}
