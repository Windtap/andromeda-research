__int64 __fastcall rtThreadInsert(
        __int64 a1,
        unsigned __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // rbx
  bool v11; // cf
  volatile signed __int32 *v12; // r13
  char v13; // al
  double v14; // xmm4_8
  double v15; // xmm5_8
  double v17; // xmm4_8
  double v18; // xmm5_8

  VBoxGuest_RTSpinlockAcquire(g_ThreadSpinlock);
  if ( *(_DWORD *)(a1 + 40) != 2 )
  {
    v10 = g_ThreadTree;
    if ( !g_ThreadTree )
    {
LABEL_6:
      v12 = (volatile signed __int32 *)(a1 + 72);
      if ( !a1 )
        return VBoxGuest_RTSpinlockRelease(g_ThreadSpinlock);
      goto LABEL_7;
    }
    while ( 1 )
    {
      v11 = a2 < *(_QWORD *)v10;
      if ( a2 == *(_QWORD *)v10 )
        break;
      while ( !v11 )
      {
        v10 = *(_QWORD *)(v10 + 16);
        if ( !v10 )
          goto LABEL_6;
        v11 = a2 < *(_QWORD *)v10;
        if ( a2 == *(_QWORD *)v10 )
          goto LABEL_12;
      }
      v10 = *(_QWORD *)(v10 + 8);
      if ( !v10 )
        goto LABEL_6;
    }
LABEL_12:
    if ( a1 != v10 )
    {
      v12 = (volatile signed __int32 *)(a1 + 72);
      _interlockedbittestandreset((volatile signed __int32 *)(a1 + 72), 2u);
      rtThreadRemoveLocked(v10);
      if ( (*(_BYTE *)(v10 + 72) & 1) != 0 && *(_DWORD *)(v10 + 36) )
        rtThreadRelease_part_26(v10);
LABEL_7:
      _InterlockedExchange64((volatile __int64 *)a1, a2);
      v13 = VBoxGuest_RTAvlPVInsert((unsigned __int64 **)&g_ThreadTree, (unsigned __int64 *)a1);
      _InterlockedOr(v12, 4u);
      if ( v13 )
      {
        _InterlockedExchangeAdd(&g_cThreadInTree, 1u);
        _InterlockedExchangeAdd(&VBoxGuest_g_acRTThreadTypeStats[*(unsigned int *)(a1 + 64)], 1u);
      }
      else
      {
        VBoxGuest_RTAssertMsg1(
          (__int64)"fRc",
          0x1D5u,
          (__int64)"/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/common/misc/thread.c",
          (__int64)"rtThreadInsert",
          a3,
          a4,
          a5,
          a6,
          v14,
          v15,
          a9,
          a10);
        VBoxGuest_RTAssertMsg2Weak(
          (__int64)"Lock problem? %p (%RTnthrd) %s\n",
          a3,
          a4,
          a5,
          a6,
          v17,
          v18,
          a9,
          a10,
          a1,
          a2,
          a1 + 104);
        __debugbreak();
      }
    }
  }
  return VBoxGuest_RTSpinlockRelease(g_ThreadSpinlock);
}
