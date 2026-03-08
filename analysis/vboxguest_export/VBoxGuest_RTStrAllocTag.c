_BYTE *__fastcall VBoxGuest_RTStrAllocTag(__int64 a1)
{
  __int64 v1; // rax
  _BYTE *result; // rax

  v1 = 1;
  if ( a1 )
    v1 = a1;
  result = (_BYTE *)VBoxGuest_RTMemAllocTag(v1);
  if ( result )
    *result = 0;
  return result;
}
