__int64 __fastcall VBoxGuest_RTLogCloneRC(__int64 a1, __int64 a2, unsigned __int64 a3, int a4, int a5, int a6)
{
  __int64 v7; // rbp
  __int64 result; // rax
  size_t v10; // rdx
  int v11; // eax

  if ( !a2 || !a5 || !a4 || a3 <= 0x801F )
    return 4294967294LL;
  v7 = a1;
  *(_DWORD *)(a2 + 32776) = a4;
  *(_DWORD *)(a2 + 0x8000) = 0;
  *(_BYTE *)(a2 + 32772) = 0;
  *(_DWORD *)(a2 + 32780) = a5;
  *(_DWORD *)(a2 + 32784) = 422709041;
  *(_DWORD *)(a2 + 32788) = a6 | 1;
  *(_DWORD *)(a2 + 32792) = 1;
  *(_DWORD *)(a2 + 32796) = 0;
  if ( a1 || (v7 = VBoxGuest_RTLogDefaultInstance()) != 0 )
  {
    result = 4294967255LL;
    v10 = 4LL * *(unsigned int *)(v7 + 49184);
    if ( a3 < v10 + 32796 )
      return result;
    memcpy((void *)(a2 + 32796), (const void *)(v7 + 49188), v10);
    *(_DWORD *)(a2 + 32792) = *(_DWORD *)(v7 + 49184);
    *(_BYTE *)(a2 + 32772) = *(_BYTE *)(*(_QWORD *)(v7 + 49168) + 40LL);
    v11 = *(_DWORD *)(a2 + 32788) | *(_DWORD *)(v7 + 49160);
    *(_DWORD *)(a2 + 32788) = v11;
    if ( *(_DWORD *)(v7 + 49164) )
    {
      if ( ((*(_DWORD *)(v7 + 49160) | a6) & 1) == 0 )
        *(_DWORD *)(a2 + 32788) = v11 & 0xFFFFFFFE;
    }
  }
  return 0;
}
