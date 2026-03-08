__int64 __fastcall VBoxGuest_RTHeapSimpleSize(__int64 a1, __int64 a2)
{
  __int64 v2; // rax
  __int64 v3; // rdx
  __int64 v4; // rax

  if ( !a2
    || (unsigned __int64)(a2 + 0x200000) <= 0x200FFF
    || (a2 & 0xFF00000000000000LL) != 0 && (a2 & 0xFF00000000000000LL) != 0xFF00000000000000LL
    || a2 != ((a2 + 31) & 0xFFFFFFFFFFFFFFE0LL) )
  {
    return 0;
  }
  v2 = *(_QWORD *)(a2 - 32);
  v3 = a2 - 32;
  if ( v2 )
    v4 = v2 - v3;
  else
    v4 = *(_QWORD *)(*(_QWORD *)(a2 - 16) + 16LL) - v3;
  return v4 - 32;
}
