__int64 __fastcall vbsf_writepage(__int64 a1)
{
  _QWORD *v2; // rbp
  _QWORD *v3; // r12
  volatile signed __int32 *v4; // rbx
  __int64 v5; // r15
  unsigned int v6; // r14d
  __int64 v7; // rdx
  int v8; // esi
  int PhysAddr; // eax
  int v10; // eax
  __int64 v11; // rdi
  int v12; // eax
  unsigned __int64 v13; // r14
  unsigned int v14; // ebp
  bool v16; // cc
  __int64 v17; // [rsp+0h] [rbp-58h]
  int *v18; // [rsp+8h] [rbp-50h]
  unsigned __int64 v19; // [rsp+10h] [rbp-48h]
  int v20; // [rsp+1Ch] [rbp-3Ch]
  __int64 v21; // [rsp+20h] [rbp-38h]

  v2 = **(_QWORD ***)(a1 + 8);
  v3 = (_QWORD *)v2[69];
  v4 = vbsf_handle_find((__int64)v3, 2, 4u);
  if ( !v4 )
  {
    v16 = (unsigned __int64)s_cCalls_46519++ <= 0xF;
    v14 = -5;
    if ( v16 )
      printk("vbsf_writepage: no writable handle for %s..\n", (const char *)(*v3 + 4LL));
    goto LABEL_18;
  }
  v18 = *(int **)(v2[5] + 1120LL);
  v5 = VbglR0PhysHeapAlloc(192);
  if ( !v5 )
  {
    v14 = -12;
    goto LABEL_20;
  }
  v6 = 4096;
  v19 = v2[10];
  if ( *(_QWORD *)(a1 + 16) == v19 >> 12 )
    v6 = v19 & 0xFFF;
  v17 = *(_QWORD *)(a1 + 16) << 12;
  *(_WORD *)(v5 + 180) = 0;
  *(_QWORD *)(v5 + 184) = (a1 + 0x160000000000LL) >> 6 << 12;
  v7 = *((_QWORD *)v4 + 2);
  v8 = *v18;
  *(_DWORD *)v5 = 192;
  *(_DWORD *)(v5 + 4) = (_DWORD)&unk_10001;
  *(_DWORD *)(v5 + 8) = 0;
  *(_DWORD *)(v5 + 12) = -225;
  *(_DWORD *)(v5 + 16) = 192;
  *(_DWORD *)(v5 + 20) = 0;
  v21 = v7;
  PhysAddr = VbglR0PhysHeapGetPhysAddr(v5);
  *(_BYTE *)(v5 + 28) = 0;
  *(_DWORD *)(v5 + 52) = 140;
  *(_DWORD *)(v5 + 24) = PhysAddr + 52;
  v10 = g_SfClient;
  *(_DWORD *)(v5 + 56) = (_DWORD)&unk_10001;
  *(_DWORD *)(v5 + 60) = 63;
  *(_QWORD *)(v5 + 132) = v17;
  v11 = *(_QWORD *)&algn_FA24[4];
  *(_DWORD *)(v5 + 84) = v10;
  LOBYTE(v10) = g_fHostFeatures;
  *(_QWORD *)(v5 + 116) = v21;
  *(_DWORD *)(v5 + 100) = v8;
  *(_WORD *)(v5 + 182) = 1;
  *(_DWORD *)(v5 + 64) = -225;
  *(_DWORD *)(v5 + 68) = 0;
  *(_DWORD *)(v5 + 72) = 2;
  *(_DWORD *)(v5 + 76) = 0;
  *(_DWORD *)(v5 + 80) = -225;
  *(_DWORD *)(v5 + 88) = 6;
  *(_DWORD *)(v5 + 92) = 5;
  *(_DWORD *)(v5 + 96) = 1;
  *(_DWORD *)(v5 + 112) = 2;
  *(_DWORD *)(v5 + 128) = 2;
  *(_DWORD *)(v5 + 144) = 1;
  *(_DWORD *)(v5 + 148) = v6;
  *(_DWORD *)(v5 + 160) = (v10 & 8) == 0 ? 10 : 13;
  *(_DWORD *)(v5 + 164) = v6;
  *(_DWORD *)(v5 + 168) = 124;
  *(_DWORD *)(v5 + 176) = 1;
  if ( (int)VbglR0HGCMFastCall(v11, v5, 192) < 0 )
  {
    v3[5] = v3[4];
    goto LABEL_24;
  }
  v12 = *(_DWORD *)(v5 + 80);
  v3[5] = v3[4];
  if ( v6 != *(_DWORD *)(v5 + 148) )
  {
LABEL_24:
    v14 = -5;
    VbglR0PhysHeapFree(v5);
LABEL_20:
    if ( _InterlockedExchangeAdd(v4 + 7, 0xFFFFFFFF) == 1 )
      vbsf_handle_release_slow((__int64 *)v4, v18);
LABEL_18:
    _InterlockedOr8((volatile signed __int8 *)a1, 2u);
    unlock_page(a1);
    return v14;
  }
  v20 = v12;
  VbglR0PhysHeapFree(v5);
  if ( v20 < 0 )
  {
    v14 = -5;
    goto LABEL_20;
  }
  v13 = v6 + v17;
  if ( v19 < v13 && v13 > v2[10] )
    v2[10] = v13;
  if ( (*(_QWORD *)a1 & 2) != 0 )
    _InterlockedAnd8((volatile signed __int8 *)a1, 0xFDu);
  _InterlockedOr8((volatile signed __int8 *)a1, 8u);
  unlock_page(a1);
  v14 = 0;
  if ( _InterlockedExchangeAdd(v4 + 7, 0xFFFFFFFF) == 1 )
    vbsf_handle_release_slow((__int64 *)v4, v18);
  return v14;
}
