void __fastcall VBoxGuest_RTMemContFree(__int64 a1, __int64 a2)
{
  unsigned __int64 v2; // rdx
  unsigned __int64 v3; // rax
  int v4; // esi
  int v5; // eax
  __int64 v6; // r8
  __int64 v7; // rax
  __int64 v8; // rsi
  bool v9; // cf
  __int64 v10; // rdi
  __int64 v11; // rdi
  __int64 v12; // rax

  if ( a1 )
  {
    v2 = (unsigned __int64)(a2 + 4095) >> 12;
    v3 = (unsigned __int64)(unsigned int)v2 >> 1;
    if ( v3 )
    {
      v4 = 0;
      do
      {
        ++v4;
        v3 >>= 1;
      }
      while ( v3 );
      v5 = __ROL4__(-2, v4);
    }
    else
    {
      v5 = -2;
      v4 = 0;
    }
    v6 = v5 & (unsigned int)v2;
    v7 = 0x77FF80000000LL;
    v8 = v4 - ((unsigned int)(v6 == 0) - 1);
    v9 = __CFADD__(a1, 0x80000000LL);
    v10 = a1 + 0x80000000LL;
    if ( v9 )
      v7 = phys_base;
    v11 = ((unsigned __int64)(v7 + v10) >> 12 << 6) - 0x160000000000LL;
    if ( (_DWORD)v2 )
    {
      v12 = 0;
      do
      {
        _InterlockedAnd8((volatile signed __int8 *)(v11 + 1 + v12), 0xFBu);
        v12 += 64;
      }
      while ( v12 != ((unsigned int)(v2 - 1) + 1LL) << 6 );
    }
    _free_pages(v11, v8);
  }
}
