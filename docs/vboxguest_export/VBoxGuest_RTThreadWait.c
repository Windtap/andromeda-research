__int64 __fastcall VBoxGuest_RTThreadWait(__int64 a1, unsigned int a2, _DWORD *a3)
{
  return rtThreadWait(a1, a2, a3, 1);
}
