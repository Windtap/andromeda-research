__int64 __fastcall rtR0MemObjNativeLockKernel(_QWORD *a1, unsigned __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 v3; // r13
  unsigned __int64 v4; // rbp
  unsigned __int64 v5; // rbx
  _DWORD *v6; // r12
  unsigned __int64 v7; // rbp
  __int64 v8; // rax
  __int64 v10; // r9
  unsigned __int64 v11; // rdx
  __int64 v12; // rax
  unsigned __int64 v13; // rsi

  if ( a2 <= 0xFFFF87FFFFFFFFFFLL || a2 + a3 <= 0xFFFF87FFFFFFFFFFLL )
    return 4294967294LL;
  v3 = a3 >> 12;
  v4 = high_memory;
  v5 = a2 + a3 - 1;
  v6 = rtR0MemObjNew(8 * (a3 >> 12) + 96, 4, a2, a3);
  if ( !v6 )
    return 4294967288LL;
  if ( v5 < v4 )
  {
    v10 = phys_base;
    v11 = v3 - 1;
    if ( v3 )
    {
      do
      {
        v12 = 0x77FF80000000LL;
        v13 = v5 + 0x80000000;
        if ( v5 >= 0xFFFFFFFF80000000LL )
          v12 = v10;
        v5 -= 4096LL;
        *(_QWORD *)&v6[2 * v11-- + 24] = ((v13 + v12) >> 12 << 6) - 0x160000000000LL;
      }
      while ( v11 != -1 );
    }
    goto LABEL_9;
  }
  if ( !v3 )
  {
LABEL_9:
    *((_QWORD *)v6 + 6) = -1;
    *((_QWORD *)v6 + 11) = v3;
    *a1 = v6;
    return 0;
  }
  v7 = v3;
  while ( 1 )
  {
    v8 = VBoxGuest_rtR0MemObjLinuxVirtToPage(v5);
    if ( !v8 )
      break;
    *(_QWORD *)&v6[2 * v7 + 22] = v8;
    v5 -= 4096LL;
    if ( !--v7 )
      goto LABEL_9;
  }
  rtR0MemObjDelete((__int64)v6);
  return 4294967291LL;
}
