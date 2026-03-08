__int64 __fastcall rtR0MemObjDelete(__int64 a1)
{
  __int64 result; // rax

  if ( a1 )
  {
    *(_DWORD *)a1 = -425792017;
    *(_DWORD *)(a1 + 8) = 9;
    return VBoxGuest_RTMemFree(a1);
  }
  return result;
}
