__int64 __fastcall VBoxGuest_RTLogRelSetDefaultInstance(__int64 a1)
{
  return _InterlockedExchange64(&g_pRelLogger, a1);
}
