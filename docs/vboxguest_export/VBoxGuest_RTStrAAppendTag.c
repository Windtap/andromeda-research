__int64 __fastcall VBoxGuest_RTStrAAppendTag(const char **a1, const char *a2)
{
  if ( a2 )
    return VBoxGuest_RTStrAAppendNTag(a1, a2, 0xFFFFFFFFFFFFFFFFLL);
  else
    return 0;
}
