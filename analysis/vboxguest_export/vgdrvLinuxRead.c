char __fastcall vgdrvLinuxRead(__int64 a1, _BYTE *a2, __int64 a3, _QWORD *a4)
{
  __int64 v4; // rdi
  char result; // al

  v4 = *(_QWORD *)(a1 + 208);
  if ( *a4 )
    return -22;
  result = 0;
  if ( *(_DWORD *)(v4 + 296) != dword_309FC )
  {
    if ( a3 )
    {
      *(_DWORD *)(v4 + 296) = dword_309FC;
      *a2 = 0;
      return 1;
    }
  }
  return result;
}
