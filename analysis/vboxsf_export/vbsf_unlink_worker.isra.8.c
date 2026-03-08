__int64 __fastcall vbsf_unlink_worker_isra_8(__int64 a1, __int64 a2, __int64 a3, int a4)
{
  int *v7; // r13
  unsigned int v8; // ebx
  __int64 v10; // rax
  __int64 v11; // r15
  _WORD *v12; // rax
  int v13; // r14d
  int v14; // esi
  int v15; // r13d
  int v16; // edx
  int PhysAddr; // eax
  bool v18; // zf
  int v19; // eax
  int v20; // eax
  int v21; // eax
  __int64 v22; // rdi
  int v23; // eax
  __int64 v24; // rdx
  int v25; // r13d
  unsigned int v26; // [rsp+0h] [rbp-48h]
  __int64 v27; // [rsp+8h] [rbp-40h]
  void *src; // [rsp+10h] [rbp-38h] BYREF

  v7 = *(int **)(a1 + 1120);
  v8 = vbsf_path_from_dentry(v7, a2, a3, &src, "vbsf_unlink_worker");
  if ( !v8 )
  {
    v10 = VbglR0PhysHeapAlloc((unsigned int)*(unsigned __int16 *)src + 148);
    v11 = v10;
    if ( v10 )
    {
      v27 = v10 + 144;
      memcpy((void *)(v10 + 144), src, *(unsigned __int16 *)src + 4LL);
      v12 = *(_WORD **)(a3 + 48);
      v13 = 2 - (a4 == 0);
      if ( v12 && (*v12 & 0xA000) == 0xA000 )
        v13 |= 4u;
      v14 = *v7;
      if ( (g_fHostFeatures & 2) != 0 )
      {
        v25 = *(unsigned __int16 *)(v11 + 144);
        v16 = v25 + 148;
        v15 = v25 + 96;
      }
      else
      {
        v15 = 96;
        v16 = 148;
      }
      *(_DWORD *)v11 = v16;
      *(_DWORD *)(v11 + 16) = v16;
      *(_DWORD *)(v11 + 4) = (_DWORD)&unk_10001;
      *(_DWORD *)(v11 + 8) = 0;
      *(_DWORD *)(v11 + 12) = -225;
      *(_DWORD *)(v11 + 20) = 0;
      v26 = v16;
      PhysAddr = VbglR0PhysHeapGetPhysAddr(v11);
      *(_BYTE *)(v11 + 28) = 0;
      *(_DWORD *)(v11 + 52) = v15;
      *(_DWORD *)(v11 + 24) = PhysAddr + 52;
      v18 = (g_fHostFeatures & 2) == 0;
      v19 = g_SfClient;
      *(_DWORD *)(v11 + 56) = (_DWORD)&unk_10001;
      *(_DWORD *)(v11 + 60) = 63;
      *(_DWORD *)(v11 + 64) = -225;
      *(_DWORD *)(v11 + 68) = 0;
      *(_DWORD *)(v11 + 72) = 2;
      *(_DWORD *)(v11 + 76) = 0;
      *(_DWORD *)(v11 + 80) = -225;
      *(_DWORD *)(v11 + 84) = v19;
      *(_DWORD *)(v11 + 88) = 11;
      *(_DWORD *)(v11 + 92) = 3;
      *(_DWORD *)(v11 + 96) = 1;
      *(_DWORD *)(v11 + 100) = v14;
      v20 = *(unsigned __int16 *)(v11 + 144);
      if ( v18 )
      {
        *(_DWORD *)(v11 + 112) = 5;
        *(_DWORD *)(v11 + 116) = v20 + 4;
        *(_QWORD *)(v11 + 120) = v27;
      }
      else
      {
        *(_DWORD *)(v11 + 112) = 11;
        *(_DWORD *)(v11 + 120) = v20 + 4;
        v21 = *(unsigned __int8 *)(v11 + 116);
        BYTE1(v21) = 92;
        *(_DWORD *)(v11 + 116) = v21;
        *(_BYTE *)(v11 + 116) = 1;
      }
      v22 = *(_QWORD *)&algn_FA24[4];
      *(_DWORD *)(v11 + 132) = v13;
      *(_DWORD *)(v11 + 128) = 1;
      v23 = VbglR0HGCMFastCall(v22, v11, v26);
      if ( v23 >= 0 )
        v23 = *(_DWORD *)(v11 + 80);
      v24 = *(_QWORD *)(a3 + 48);
      if ( v24 )
        *(_BYTE *)(*(_QWORD *)(v24 + 552) + 8LL) = 1;
      if ( v23 < 0 )
      {
        if ( (unsigned int)(v23 + 103) <= 1 )
        {
          *(_BYTE *)(a2 + 8) = 1;
          d_drop(a3);
        }
        else
        {
          v8 = -(int)VBoxGuest_RTErrConvertToErrno((unsigned int)v23);
        }
      }
      else
      {
        *(_BYTE *)(a2 + 8) = 1;
      }
      VbglR0PhysHeapFree(v11);
    }
    else
    {
      v8 = -12;
    }
    kfree(src);
  }
  return v8;
}
