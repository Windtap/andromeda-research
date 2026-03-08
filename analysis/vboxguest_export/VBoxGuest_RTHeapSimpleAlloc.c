__int64 **__fastcall VBoxGuest_RTHeapSimpleAlloc(__int64 *a1, unsigned __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // rax
  __int64 **v4; // rax

  if ( (unsigned __int64)(a1 + 0x40000) <= 0x200FFF
    || ((unsigned __int64)a1 & 0xFF00000000000000LL) != 0
    && ((unsigned __int64)a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 0;
  }
  v3 = 32;
  if ( a2 > 0x1F )
    v3 = (a2 + 31) & 0xFFFFFFFFFFFFFFE0LL;
  if ( a3 <= 0x1F )
    a3 = 32;
  v4 = rtHeapSimpleAllocBlock(a1, v3, a3);
  if ( v4 )
    return v4 + 4;
  else
    return 0;
}
