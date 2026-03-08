__int64 __fastcall VBoxGuest_RTErrInfoSet(__int64 a1, unsigned int a2, const char *a3)
{
  if ( a1 )
  {
    VBoxGuest_RTStrCopy(*(char **)(a1 + 16), *(_QWORD *)(a1 + 8), a3);
    *(_DWORD *)(a1 + 4) = a2;
    *(_DWORD *)a1 |= 4u;
  }
  return a2;
}
