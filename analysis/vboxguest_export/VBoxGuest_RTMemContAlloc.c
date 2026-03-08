__int64 __fastcall VBoxGuest_RTMemContAlloc(__int64 *a1, __int64 a2)
{
  unsigned __int64 v2; // r12
  unsigned __int64 v3; // rax
  int v4; // ebx
  int v5; // eax
  unsigned int v6; // ebx
  __int64 v7; // r8
  __int64 v8; // rdx
  __int64 v9; // rax
  __int64 result; // rax

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
  v6 = v4 - (((v5 & (unsigned int)((unsigned __int64)(a2 + 4095) >> 12)) == 0) - 1);
  v7 = _alloc_pages_nodemask(516, v6, (char *)&contig_page_data + 7680, 0);
  if ( v7 || (v7 = _alloc_pages_nodemask(513, v6, (char *)&contig_page_data + 7680, 0), result = 0, v7) )
  {
    if ( (_DWORD)v2 )
    {
      v8 = 0;
      do
      {
        _InterlockedOr8((volatile signed __int8 *)(v7 + 1 + v8), 4u);
        v8 += 64;
      }
      while ( v8 != ((unsigned int)(v2 - 1) + 1LL) << 6 );
    }
    v9 = (v7 + 0x160000000000LL) >> 6 << 12;
    *a1 = v9;
    return v9 - 0x780000000000LL;
  }
  return result;
}
