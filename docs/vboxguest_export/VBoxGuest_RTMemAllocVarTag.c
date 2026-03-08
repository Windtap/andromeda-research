__int64 __fastcall VBoxGuest_RTMemAllocVarTag(unsigned __int64 a1)
{
  if ( a1 > 0xF )
    return VBoxGuest_RTMemAllocTag((a1 + 15) & 0xFFFFFFFFFFFFFFF0LL);
  else
    return VBoxGuest_RTMemAllocTag((a1 + 7) & 0xFFFFFFFFFFFFFFF8LL);
}
