__int64 __fastcall VBoxGuest_RTErrInfoAdd(__int64 a1, unsigned int a2, char *a3)
{
  if ( a1 )
  {
    if ( (*(_BYTE *)a1 & 4) != 0 )
    {
      VBoxGuest_RTStrCat(*(char **)(a1 + 16), *(_QWORD *)(a1 + 8), a3);
      return a2;
    }
    while ( *a3 == 32 )
      ++a3;
    VBoxGuest_RTStrCopy(*(char **)(a1 + 16), *(_QWORD *)(a1 + 8), a3);
    *(_DWORD *)(a1 + 4) = a2;
    *(_DWORD *)a1 |= 4u;
  }
  return a2;
}
