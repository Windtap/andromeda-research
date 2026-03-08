__int64 __fastcall vbsf_inode_rename(__int64 a1, __int64 a2, __int64 a3, __int64 a4, int a5)
{
  int v7; // ebx
  unsigned int v8; // r15d
  int *v9; // rbp
  __int64 v11; // r14
  int v12; // r9d
  __int64 v13; // rsi
  int v14; // eax
  int v15; // edx
  int v16; // ebp
  int PhysAddr; // eax
  int v18; // eax
  char v19; // al
  unsigned __int64 v20; // rsi
  int v21; // edi
  int v22; // eax
  int v23; // eax
  __int64 v24; // rdi
  int v25; // ebx
  __int64 v26; // rbx
  __int64 v27; // rax
  __int64 v28; // rdx
  __int64 v29; // rax
  __int64 v30; // rdx
  int v31; // eax
  int v32; // esi
  void *v33; // rdi
  int v34; // eax
  __int64 v36; // [rsp+8h] [rbp-70h]
  unsigned __int16 *v37; // [rsp+10h] [rbp-68h]
  void **v38; // [rsp+18h] [rbp-60h]
  unsigned int v39; // [rsp+20h] [rbp-58h]
  int v40; // [rsp+24h] [rbp-54h]
  void *src; // [rsp+40h] [rbp-38h] BYREF

  v7 = 6 - ((**(_WORD **)(a2 + 48) & 0x4000) == 0);
  if ( (a5 & 0xFFFFFFFE) != 0 )
    return (unsigned int)-22;
  v8 = -18;
  if ( a5 )
    v7 &= ~4u;
  v9 = *(int **)(*(_QWORD *)(a3 + 40) + 1120LL);
  if ( v9 == *(int **)(*(_QWORD *)(a1 + 40) + 1120LL) )
  {
    v36 = *(_QWORD *)(a3 + 552);
    v8 = vbsf_path_from_dentry(v9, v36, a4, &src, "vbsf_inode_rename");
    if ( !v8 )
    {
      v11 = VbglR0PhysHeapAlloc((unsigned int)*(unsigned __int16 *)src + 180);
      if ( v11 )
      {
        v38 = *(void ***)(*(_QWORD *)(a2 + 48) + 552LL);
        v37 = (unsigned __int16 *)*v38;
        memcpy((void *)(v11 + 176), src, *(unsigned __int16 *)src + 4LL);
        v12 = *v9;
        v13 = 0x77FF80000000LL;
        if ( (unsigned __int64)v37 >= 0xFFFFFFFF80000000LL )
          v13 = phys_base;
        if ( (g_fHostFeatures & 2) != 0 )
        {
          v14 = *(unsigned __int16 *)(v11 + 176);
          v15 = v14 + 180;
          v16 = v14 + 128;
        }
        else
        {
          v16 = 128;
          v15 = 180;
        }
        *(_DWORD *)v11 = v15;
        *(_DWORD *)(v11 + 16) = v15;
        *(_DWORD *)(v11 + 4) = (_DWORD)&unk_10001;
        *(_DWORD *)(v11 + 8) = 0;
        *(_DWORD *)(v11 + 12) = -225;
        *(_DWORD *)(v11 + 20) = 0;
        v40 = v12;
        v39 = v15;
        PhysAddr = VbglR0PhysHeapGetPhysAddr(v11);
        *(_BYTE *)(v11 + 28) = 0;
        *(_DWORD *)(v11 + 52) = v16;
        *(_DWORD *)(v11 + 24) = PhysAddr + 52;
        v18 = g_SfClient;
        *(_DWORD *)(v11 + 56) = (_DWORD)&unk_10001;
        *(_DWORD *)(v11 + 60) = 63;
        *(_DWORD *)(v11 + 64) = -225;
        *(_DWORD *)(v11 + 84) = v18;
        v19 = g_fHostFeatures;
        *(_DWORD *)(v11 + 68) = 0;
        *(_DWORD *)(v11 + 72) = 2;
        *(_DWORD *)(v11 + 76) = 0;
        *(_DWORD *)(v11 + 80) = -225;
        *(_DWORD *)(v11 + 88) = 14;
        *(_DWORD *)(v11 + 92) = 4;
        *(_DWORD *)(v11 + 96) = 1;
        *(_DWORD *)(v11 + 100) = v40;
        if ( (v19 & 4) != 0 )
        {
          *(_DWORD *)(v11 + 112) = 12;
          v20 = (unsigned __int64)v37 + v13 + 0x80000000LL;
          v21 = *v37;
          *(_DWORD *)(v11 + 120) = 108;
          *(_DWORD *)(v11 + 160) = 1;
          *(_WORD *)(v11 + 166) = 1;
          *(_DWORD *)(v11 + 116) = v21 + 4;
          *(_QWORD *)(v11 + 168) = v20 & 0xFFFFFFFFFFFFF000LL;
          *(_WORD *)(v11 + 164) = v20 & 0xFFF;
        }
        else
        {
          *(_DWORD *)(v11 + 112) = 5;
          v32 = *v37;
          *(_QWORD *)(v11 + 120) = v37;
          *(_DWORD *)(v11 + 116) = v32 + 4;
        }
        if ( (v19 & 2) != 0 )
        {
          v22 = *(unsigned __int16 *)(v11 + 176);
          *(_DWORD *)(v11 + 128) = 11;
          *(_DWORD *)(v11 + 136) = v22 + 4;
          v23 = *(unsigned __int8 *)(v11 + 132);
          BYTE1(v23) = 124;
          *(_DWORD *)(v11 + 132) = v23;
          *(_BYTE *)(v11 + 132) = 1;
        }
        else
        {
          v31 = *(unsigned __int16 *)(v11 + 176);
          *(_DWORD *)(v11 + 128) = 5;
          *(_DWORD *)(v11 + 132) = v31 + 4;
          *(_QWORD *)(v11 + 136) = v11 + 176;
        }
        v24 = *(_QWORD *)&algn_FA24[4];
        *(_DWORD *)(v11 + 148) = v7;
        *(_DWORD *)(v11 + 144) = 1;
        v25 = VbglR0HGCMFastCall(v24, v11, v39);
        if ( v25 < 0 )
        {
          VbglR0PhysHeapFree(v11);
        }
        else
        {
          v25 = *(_DWORD *)(v11 + 80);
          VbglR0PhysHeapFree(v11);
          if ( v25 >= 0 )
          {
            v26 = *(_QWORD *)(a1 + 552);
            *v38 = src;
            kfree(v37);
            src = 0;
            *(_BYTE *)(v36 + 8) = 1;
            *(_BYTE *)(v26 + 8) = 1;
            v27 = *(_QWORD *)(a2 + 24);
            if ( v27 )
            {
              v28 = jiffies;
              do
              {
                *(_QWORD *)(v27 + 120) = v28;
                v27 = *(_QWORD *)(v27 + 24);
              }
              while ( v27 != *(_QWORD *)(v27 + 24) );
            }
            v29 = *(_QWORD *)(a4 + 24);
            if ( v29 )
            {
              v30 = jiffies;
              do
              {
                *(_QWORD *)(v29 + 120) = v30;
                v29 = *(_QWORD *)(v29 + 24);
              }
              while ( v29 != *(_QWORD *)(v29 + 24) );
            }
            return v8;
          }
        }
        if ( v25 == -140 || v25 == -127 )
          *(_QWORD *)(a2 + 120) = jiffies - 0x3FFFFFFFLL;
        v34 = VBoxGuest_RTErrConvertToErrno((unsigned int)v25);
        v33 = src;
        v8 = -v34;
      }
      else
      {
        v33 = src;
        v8 = -12;
      }
      if ( v33 )
        kfree(v33);
    }
  }
  return v8;
}
