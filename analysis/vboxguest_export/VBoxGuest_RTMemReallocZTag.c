_DWORD *__fastcall VBoxGuest_RTMemReallocZTag(_DWORD *a1, unsigned __int64 a2, unsigned __int64 a3)
{
  _DWORD *result; // rax
  _DWORD *v5; // rbx

  result = VBoxGuest_RTMemReallocTag(a1, a3);
  v5 = result;
  if ( result )
  {
    if ( a3 > a2 )
    {
      memset((char *)result + a2, 0, a3 - a2);
      return v5;
    }
  }
  return result;
}
