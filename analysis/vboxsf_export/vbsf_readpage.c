__int64 __fastcall vbsf_readpage(__int64 a1, __int64 a2)
{
  __int64 v3; // r14
  unsigned int v4; // r12d
  __int64 v6; // rax
  __int64 v7; // rbx
  __int64 v8; // rdi
  __int64 v9; // rdx
  _DWORD *v10; // rax
  __int64 v11; // r13
  __int64 v12; // r15
  __int64 v13; // r14
  int PhysAddr; // eax
  __int64 v15; // rdi
  int v16; // eax
  int v17; // r15d
  __int64 v18; // r14
  int v19; // [rsp+4h] [rbp-34h]

  v3 = *(_QWORD *)(*(_QWORD *)(a1 + 24) + 48LL);
  if ( (*(_QWORD *)a2 & 8) == 0 )
  {
    v4 = is_bad_inode(*(_QWORD *)(*(_QWORD *)(a1 + 24) + 48LL));
    if ( v4 )
    {
      v4 = -5;
    }
    else
    {
      v6 = VbglR0PhysHeapAlloc(192);
      v7 = v6;
      if ( v6 )
      {
        v8 = v6;
        v9 = *(_QWORD *)(a1 + 208);
        v10 = *(_DWORD **)(*(_QWORD *)(v3 + 40) + 1120LL);
        v11 = (a2 + 0x160000000000LL) >> 6 << 12;
        *(_WORD *)(v7 + 180) = 0;
        *(_QWORD *)(v7 + 184) = v11;
        v12 = *(_QWORD *)(v9 + 16);
        v13 = *(_QWORD *)(a2 + 16);
        LODWORD(v9) = *v10;
        *(_DWORD *)v7 = 192;
        *(_DWORD *)(v7 + 4) = (_DWORD)&unk_10001;
        *(_DWORD *)(v7 + 8) = 0;
        *(_DWORD *)(v7 + 12) = -225;
        *(_DWORD *)(v7 + 16) = 192;
        *(_DWORD *)(v7 + 20) = 0;
        v19 = v9;
        PhysAddr = VbglR0PhysHeapGetPhysAddr(v8);
        v15 = *(_QWORD *)&algn_FA24[4];
        *(_QWORD *)(v7 + 116) = v12;
        *(_DWORD *)(v7 + 24) = PhysAddr + 52;
        v16 = g_SfClient;
        *(_WORD *)(v7 + 182) = 1;
        *(_BYTE *)(v7 + 28) = 0;
        *(_DWORD *)(v7 + 100) = v19;
        *(_DWORD *)(v7 + 84) = v16;
        LOBYTE(v16) = g_fHostFeatures;
        *(_DWORD *)(v7 + 52) = 140;
        *(_DWORD *)(v7 + 56) = (_DWORD)&unk_10001;
        *(_DWORD *)(v7 + 60) = 63;
        *(_DWORD *)(v7 + 64) = -225;
        *(_DWORD *)(v7 + 68) = 0;
        *(_DWORD *)(v7 + 72) = 2;
        *(_DWORD *)(v7 + 76) = 0;
        *(_DWORD *)(v7 + 80) = -225;
        *(_DWORD *)(v7 + 88) = 5;
        *(_DWORD *)(v7 + 92) = 5;
        *(_DWORD *)(v7 + 96) = 1;
        *(_DWORD *)(v7 + 112) = 2;
        *(_DWORD *)(v7 + 128) = 2;
        *(_QWORD *)(v7 + 132) = v13 << 12;
        *(_DWORD *)(v7 + 144) = 1;
        *(_DWORD *)(v7 + 148) = 4096;
        *(_DWORD *)(v7 + 160) = (v16 & 8) == 0 ? 10 : 13;
        *(_DWORD *)(v7 + 164) = 4096;
        *(_DWORD *)(v7 + 168) = 124;
        *(_DWORD *)(v7 + 176) = 2;
        v17 = VbglR0HGCMFastCall(v15, v7, 192);
        if ( v17 >= 0 )
          v17 = *(_DWORD *)(v7 + 80);
        v18 = *(unsigned int *)(v7 + 148);
        if ( (unsigned int)v18 > 0x1000 )
        {
          VbglR0PhysHeapFree(v7);
          if ( v17 >= 0 )
          {
LABEL_12:
            _InterlockedOr8((volatile signed __int8 *)a2, 8u);
            unlock_page(a2);
            return v4;
          }
        }
        else
        {
          VbglR0PhysHeapFree(v7);
          if ( v17 >= 0 )
          {
            if ( (_DWORD)v18 != 4096 )
              memset((void *)(v11 - 0x780000000000LL + v18), 0, (unsigned int)(4096 - v18));
            goto LABEL_12;
          }
        }
        v4 = -(int)VBoxGuest_RTErrConvertToErrno((unsigned int)v17);
      }
      else
      {
        v4 = -12;
      }
    }
    _InterlockedOr8((volatile signed __int8 *)a2, 2u);
    unlock_page(a2);
    return v4;
  }
  v4 = 0;
  unlock_page(a2);
  return v4;
}
