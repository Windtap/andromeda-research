__int64 __fastcall rtLogComOutput(__int64 a1, unsigned __int8 *a2, __int64 a3)
{
  if ( a3 )
    VBoxGuest_RTLogWriteCom(a2, a3);
  return a3;
}
