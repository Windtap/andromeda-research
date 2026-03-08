__int64 __fastcall vbsf_handle_release_slow(__int64 *a1, int *a2)
{
  __int64 v3; // rax
  _QWORD *v4; // rcx
  __int64 v5; // r8
  __int64 v6; // rdx
  int v7; // r13d
  __int64 v8; // r12
  _DWORD *v9; // rax
  _DWORD *v10; // rbx
  int PhysAddr; // eax
  __int64 v12; // rdi
  int v13; // eax

  v3 = raw_spin_lock_irqsave(&g_SfHandleLock);
  v6 = *((unsigned int *)a1 + 6);
  if ( (v6 & 0x80u) != 0LL )
  {
    LOBYTE(v6) = v6 & 0x7F;
    v4 = (_QWORD *)a1[1];
    *((_DWORD *)a1 + 6) = v6;
    v6 = *a1;
    *v4 = *a1;
    *(_QWORD *)(v6 + 8) = v4;
    *a1 = 0;
    a1[1] = 0;
  }
  raw_spin_unlock_irqrestore(&g_SfHandleLock, v3, v6, v4, v5);
  v7 = *a2;
  v8 = a1[2];
  v9 = (_DWORD *)VbglR0PhysHeapAlloc(128);
  v10 = v9;
  if ( v9 )
  {
    *v9 = 128;
    v9[1] = (_DWORD)&unk_10001;
    v9[2] = 0;
    v9[3] = -225;
    v9[4] = 128;
    v9[5] = 0;
    PhysAddr = VbglR0PhysHeapGetPhysAddr(v9);
    v12 = *(_QWORD *)&algn_FA24[4];
    *((_BYTE *)v10 + 28) = 0;
    v10[13] = 76;
    v10[6] = PhysAddr + 52;
    v13 = g_SfClient;
    v10[14] = (_DWORD)&unk_10001;
    v10[15] = 63;
    v10[16] = -225;
    v10[17] = 0;
    v10[18] = 2;
    v10[19] = 0;
    v10[20] = -225;
    v10[21] = v13;
    v10[22] = 4;
    v10[23] = 2;
    v10[24] = 1;
    v10[25] = v7;
    v10[28] = 2;
    *(_QWORD *)(v10 + 29) = v8;
    VbglR0HGCMFastCall(v12, v10, 128);
    VbglR0PhysHeapFree(v10);
  }
  a1[2] = -1;
  *((_DWORD *)a1 + 6) = 423039528;
  kfree(a1);
  return 0;
}
