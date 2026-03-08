__int64 __fastcall VBoxGuest_RTStrFree(__int64 a1)
{
  __int64 result; // rax

  if ( a1 )
    return VBoxGuest_RTMemFree(a1);
  return result;
}
