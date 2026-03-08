void *__fastcall VBoxGuest_RTMemAllocZVarTag(unsigned __int64 a1)
{
  if ( a1 > 0xF )
    return VBoxGuest_RTMemAllocZTag((a1 + 15) & 0xFFFFFFFFFFFFFFF0LL);
  else
    return VBoxGuest_RTMemAllocZTag((a1 + 7) & 0xFFFFFFFFFFFFFFF8LL);
}
