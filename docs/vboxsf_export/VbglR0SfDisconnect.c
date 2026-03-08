__int64 __fastcall VbglR0SfDisconnect(__int64 a1)
{
  __int64 v2; // rdi
  __int64 result; // rax

  v2 = *(_QWORD *)(a1 + 8);
  if ( v2 )
  {
    result = VbglR0HGCMDisconnect(v2, *(_DWORD *)a1);
    *(_DWORD *)a1 = 0;
    *(_QWORD *)(a1 + 8) = 0;
  }
  return result;
}
