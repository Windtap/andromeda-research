__int64 __fastcall VBoxGuest_RTErrInfoSetV(__int64 a1, unsigned int a2, __int64 a3, __int64 *a4)
{
  if ( a1 )
  {
    VBoxGuest_RTStrPrintfV(*(_QWORD *)(a1 + 16), *(_QWORD *)(a1 + 8), a3, a4);
    *(_DWORD *)(a1 + 4) = a2;
    *(_DWORD *)a1 |= 4u;
  }
  return a2;
}
