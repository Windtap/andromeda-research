__int64 __fastcall rtThreadWait(__int64 a1, unsigned int a2, _DWORD *a3, char a4)
{
  __int64 v6; // rax
  __int64 v7; // rbx
  int v8; // ebp
  __int64 v9; // rdi

  if ( a1 && (v6 = rtThreadGet(a1), (v7 = v6) != 0) )
  {
    v8 = -30;
    if ( (*(_BYTE *)(v6 + 68) & 1) != 0 )
    {
      v9 = *(_QWORD *)(v6 + 56);
      v8 = a4 ? VBoxGuest_RTSemEventMultiWait(v9, a2) : VBoxGuest_RTSemEventMultiWaitNoResume(v9, a2);
      if ( v8 >= 0 )
      {
        if ( a3 )
          *a3 = *(_DWORD *)(v7 + 76);
        if ( _interlockedbittestandreset((volatile signed __int32 *)(v7 + 68), 0) )
        {
          if ( *(_DWORD *)(v7 + 36) )
            rtThreadRelease_part_26(v7);
          _mm_mfence();
          if ( g_cThreadInTree == 1 )
          {
            _mm_mfence();
            if ( *(_DWORD *)(v7 + 36) > 1u )
              rtThreadNativeWaitKludge(v7);
          }
        }
      }
    }
    if ( *(_DWORD *)(v7 + 36) )
      rtThreadRelease_part_26(v7);
  }
  else
  {
    return (unsigned int)-4;
  }
  return (unsigned int)v8;
}
