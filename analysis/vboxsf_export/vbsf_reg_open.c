__int64 __fastcall vbsf_reg_open(unsigned __int16 *a1, __int64 a2)
{
  unsigned __int16 **v3; // r14
  __int64 v4; // r13
  __int64 v5; // rax
  __int64 v6; // r15
  unsigned __int16 *v7; // r9
  __int64 v9; // rax
  __int64 v10; // rbx
  int v11; // edi
  int v12; // eax
  bool v13; // zf
  int v14; // ecx
  int v15; // edx
  int PhysAddr; // eax
  int v17; // eax
  int v18; // eax
  int v19; // eax
  int v20; // eax
  int v21; // eax
  __int64 v22; // rax
  unsigned __int16 *v23; // rdi
  unsigned int v24; // ebp
  __int64 v25; // rax
  int v26; // eax
  int v27; // eax
  __int64 v28; // rax
  __int64 v29; // rdx
  __int64 DefaultInstance; // rax
  const char *v31; // r9
  __int64 v32; // rax
  unsigned __int16 *v33; // rdi
  int *v34; // [rsp+0h] [rbp-58h]
  unsigned int v35; // [rsp+0h] [rbp-58h]
  unsigned int v36; // [rsp+8h] [rbp-50h]
  int v37; // [rsp+10h] [rbp-48h]
  int v38; // [rsp+14h] [rbp-44h]
  __int64 v39; // [rsp+18h] [rbp-40h]

  v3 = (unsigned __int16 **)*((_QWORD *)a1 + 69);
  v4 = *(_QWORD *)(a2 + 24);
  v34 = *(int **)(*((_QWORD *)a1 + 5) + 1120LL);
  v5 = kmem_cache_alloc_trace(kmalloc_caches[5], 37748928, 32);
  v6 = v5;
  if ( !v5 )
  {
    DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
    v31 = "could not allocate reg info\n";
    if ( !DefaultInstance )
      return 4294967284LL;
LABEL_26:
    VBoxGuest_RTLogLoggerEx(DefaultInstance, 16, 337, "%Rfn: %M", "vbsf_reg_open", v31, v34);
    return 4294967284LL;
  }
  *(_QWORD *)v5 = v5;
  *(_QWORD *)(v5 + 8) = v5;
  *(_DWORD *)(v5 + 28) = 1;
  *(_DWORD *)(v5 + 24) = 1963132688;
  *(_QWORD *)(v5 + 16) = -1;
  v7 = v3[6];
  if ( v7 != (unsigned __int16 *)-1LL )
  {
    *((_BYTE *)v3 + 8) = 1;
    *(_QWORD *)(v5 + 16) = v7;
    v3[6] = (unsigned __int16 *)-1LL;
    *(_QWORD *)(a2 + 208) = v5;
    *(_DWORD *)(v5 + 24) |= 3u;
    vbsf_handle_append((__int64)v3, v5);
    return 0;
  }
  v9 = VbglR0PhysHeapAlloc((unsigned int)**v3 + 260);
  v10 = v9;
  if ( !v9 )
  {
    kfree(v6);
    DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
    v31 = "Failed to allocate a VBOXSFCREATEREQ buffer!\n";
    if ( !DefaultInstance )
      return 4294967284LL;
    goto LABEL_26;
  }
  v39 = v9 + 252;
  memcpy((void *)(v9 + 252), *v3, **v3 + 4LL);
  memset((void *)(v10 + 144), 0, 0x68u);
  *(_DWORD *)(v10 + 248) = 0;
  *(_QWORD *)(v10 + 144) = -1;
  v11 = *(_DWORD *)(a2 + 64);
  LOBYTE(v11) = v11 & 0x7F;
  v12 = vbsf_linux_oflags_to_vbox(v11, (_DWORD *)(v6 + 24));
  v13 = (g_fHostFeatures & 2) == 0;
  *(_DWORD *)(v10 + 156) = v12;
  *(_DWORD *)(v10 + 208) = *a1;
  v14 = *v34;
  if ( v13 )
  {
    v38 = 92;
    v15 = 144;
  }
  else
  {
    v26 = *(unsigned __int16 *)(v10 + 252);
    v15 = v26 + 256;
    v38 = v26 + 204;
  }
  *(_DWORD *)v10 = v15;
  *(_DWORD *)(v10 + 16) = v15;
  *(_DWORD *)(v10 + 4) = (_DWORD)&unk_10001;
  *(_DWORD *)(v10 + 8) = 0;
  *(_DWORD *)(v10 + 12) = -225;
  *(_DWORD *)(v10 + 20) = 0;
  v37 = v14;
  v36 = v15;
  PhysAddr = VbglR0PhysHeapGetPhysAddr(v10);
  *(_BYTE *)(v10 + 28) = 0;
  *(_DWORD *)(v10 + 56) = (_DWORD)&unk_10001;
  *(_DWORD *)(v10 + 24) = PhysAddr + 52;
  v13 = (g_fHostFeatures & 2) == 0;
  *(_DWORD *)(v10 + 60) = 63;
  *(_DWORD *)(v10 + 64) = -225;
  *(_DWORD *)(v10 + 68) = 0;
  *(_DWORD *)(v10 + 52) = v38;
  v17 = g_SfClient;
  *(_DWORD *)(v10 + 72) = 2;
  *(_DWORD *)(v10 + 76) = 0;
  *(_DWORD *)(v10 + 80) = -225;
  *(_DWORD *)(v10 + 84) = v17;
  *(_DWORD *)(v10 + 88) = 3;
  *(_DWORD *)(v10 + 92) = 3;
  *(_DWORD *)(v10 + 96) = 1;
  *(_DWORD *)(v10 + 100) = v37;
  v18 = *(unsigned __int16 *)(v10 + 252);
  if ( v13 )
  {
    *(_DWORD *)(v10 + 112) = 5;
    *(_DWORD *)(v10 + 128) = 4;
    *(_DWORD *)(v10 + 132) = 108;
    *(_DWORD *)(v10 + 116) = v18 + 4;
    *(_QWORD *)(v10 + 120) = v39;
    *(_QWORD *)(v10 + 136) = v10 + 144;
  }
  else
  {
    *(_DWORD *)(v10 + 112) = 11;
    *(_DWORD *)(v10 + 128) = 11;
    *(_DWORD *)(v10 + 136) = 108;
    *(_DWORD *)(v10 + 120) = v18 + 4;
    v19 = *(unsigned __int8 *)(v10 + 116);
    BYTE1(v19) = -56;
    *(_DWORD *)(v10 + 116) = v19;
    v20 = *(unsigned __int8 *)(v10 + 132);
    *(_BYTE *)(v10 + 116) = 1;
    BYTE1(v20) |= 0x5Cu;
    *(_DWORD *)(v10 + 132) = v20;
    *(_BYTE *)(v10 + 132) = 3;
  }
  v21 = VbglR0HGCMFastCall(*(_QWORD *)&algn_FA24[4], v10, v36);
  if ( v21 >= 0 )
  {
    v21 = *(_DWORD *)(v10 + 80);
    if ( v21 >= 0 )
    {
      if ( *(_QWORD *)(v10 + 144) == -1 )
      {
        v27 = *(_DWORD *)(v10 + 152);
        switch ( v27 )
        {
          case 2:
            goto LABEL_33;
          case 3:
            v32 = jiffies;
            do
            {
              *(_QWORD *)(v4 + 120) = v32;
              v4 = *(_QWORD *)(v4 + 24);
            }
            while ( v4 != *(_QWORD *)(v4 + 24) );
            v33 = a1;
            v24 = -17;
            vbsf_update_inode(v33, v3, v10 + 160, v34, 0, 0);
            v25 = *(_QWORD *)(v10 + 144);
            break;
          case 1:
LABEL_33:
            v24 = -2;
            *(_QWORD *)(v4 + 120) = jiffies - 0x3FFFFFFFLL;
            v25 = *(_QWORD *)(v10 + 144);
            break;
          default:
            v28 = *(_QWORD *)(v4 + 24);
            if ( v28 )
            {
              v29 = jiffies;
              do
              {
                *(_QWORD *)(v28 + 120) = v29;
                v28 = *(_QWORD *)(v28 + 24);
              }
              while ( v28 != *(_QWORD *)(v28 + 24) );
              v25 = *(_QWORD *)(v10 + 144);
              v24 = 0;
            }
            else
            {
              v25 = -1;
              v24 = 0;
            }
            break;
        }
      }
      else
      {
        v22 = jiffies;
        do
        {
          *(_QWORD *)(v4 + 120) = v22;
          v4 = *(_QWORD *)(v4 + 24);
        }
        while ( v4 != *(_QWORD *)(v4 + 24) );
        v23 = a1;
        v24 = 0;
        vbsf_update_inode(v23, v3, v10 + 160, v34, 0, 0);
        v25 = *(_QWORD *)(v10 + 144);
      }
      *(_QWORD *)(v6 + 16) = v25;
      *(_QWORD *)(a2 + 208) = v6;
      vbsf_handle_append((__int64)v3, v6);
      VbglR0PhysHeapFree(v10);
      return v24;
    }
  }
  v35 = v21;
  kfree(v6);
  VbglR0PhysHeapFree(v10);
  return (unsigned int)-VBoxGuest_RTErrConvertToErrno(v35);
}
