__int64 **__fastcall VBoxGuest_RTHeapSimpleAllocZ(__int64 *a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // rax
  __int64 v4; // rbx
  __int64 **v5; // rax
  __int64 **v6; // rbp

  v3 = a3;
  if ( (unsigned __int64)(a1 + 0x40000) <= 0x200FFF
    || ((unsigned __int64)a1 & 0xFF00000000000000LL) != 0
    && ((unsigned __int64)a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 0;
  }
  v4 = 32;
  if ( a2 > 0x1F )
    v4 = (a2 + 31) & 0xFFFFFFFFFFFFFFE0LL;
  if ( a3 <= 0x1F )
    v3 = 32;
  v5 = rtHeapSimpleAllocBlock(a1, v4, v3);
  if ( !v5 )
    return 0;
  v6 = v5 + 4;
  memset(v5 + 4, 0, v4);
  return v6;
}
