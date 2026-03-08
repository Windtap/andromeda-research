__int64 __fastcall VBoxGuest_RTLogSetDefaultInstance(__int64 a1)
{
  return _InterlockedExchange64(&g_pLogger, a1);
}
