__int64 __fastcall vbsf_read_super_26(__int64 a1, __int64 a2, char a3)
{
  unsigned int v4; // ebx
  __int64 DefaultInstance; // rax
  const char *v6; // rcx
  const void *v8; // r13
  unsigned __int64 v10; // r15
  __int64 v11; // rax
  const char *v12; // rcx
  void *v13; // rax
  __int64 v14; // r12
  __int64 v15; // rax
  bool v16; // zf
  _BYTE *v17; // rsi
  __int64 v18; // rcx
  const char *v19; // rdi
  __int64 nls; // rax
  __int64 v21; // rax
  __int64 v22; // rdx
  _DWORD *v23; // rax
  _DWORD *v24; // r15
  int PhysAddr; // eax
  int v26; // eax
  int v27; // eax
  int v28; // eax
  signed __int64 v29; // rcx
  signed __int64 v30; // r13
  int v31; // r14d
  __int64 v32; // rax
  int v33; // eax
  __int64 v34; // rdi
  __int64 v35; // r13
  __int64 v36; // rax
  unsigned int v37; // r8d
  __int64 v38; // r15
  __int64 v39; // rax
  char v40; // r8
  __int64 v41; // rax
  __int64 v42; // r14
  __int64 root; // rax
  __int64 v44; // rax
  __int64 v45; // rax
  __int64 v46; // rax
  unsigned int v47; // ebp
  __int64 v48; // rdi
  __int64 v49; // rax
  unsigned __int16 *v50; // [rsp+0h] [rbp-B0h]
  bool v51; // [rsp+0h] [rbp-B0h]
  bool v52; // [rsp+8h] [rbp-A8h]
  __int64 v53; // [rsp+8h] [rbp-A8h]
  const char *v54; // [rsp+10h] [rbp-A0h]
  __int64 v55; // [rsp+10h] [rbp-A0h]
  unsigned int v56; // [rsp+10h] [rbp-A0h]
  unsigned int v57; // [rsp+10h] [rbp-A0h]
  _BYTE v58[140]; // [rsp+24h] [rbp-8Ch] BYREF

  if ( !a2 )
  {
    v4 = -22;
    DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
    v6 = "vboxsf: No mount data. Is mount.vboxsf installed (typically in /sbin)?\n";
    if ( !DefaultInstance )
      goto LABEL_6;
    goto LABEL_5;
  }
  v4 = a3 & 0x20;
  if ( (a3 & 0x20) == 0 )
  {
    v8 = (const void *)(a2 + 8);
    v10 = VBoxGuest_RTStrNLen(a2 + 8, 256);
    if ( v10 > 0xFF )
    {
      v11 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
      v12 = "vboxsf: Specified shared folder name is not zero terminated!\n";
      if ( !v11 )
      {
LABEL_11:
        v4 = -22;
        goto LABEL_6;
      }
LABEL_10:
      VBoxGuest_RTLogLoggerEx(v11, 16, 337, v12);
      goto LABEL_11;
    }
    v54 = (const char *)(a2 + 264);
    if ( (unsigned __int64)VBoxGuest_RTStrNLen(a2 + 264, 32) > 0x1F )
    {
      v11 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
      if ( !v11 )
        goto LABEL_11;
      v12 = "vboxsf: Specified nls name is not zero terminated!\n";
      goto LABEL_10;
    }
    v50 = (unsigned __int16 *)_kmalloc(v10 + 5, 37748928);
    v13 = (void *)kmem_cache_alloc_trace(kmalloc_caches[10], 37748928, 824);
    v14 = (__int64)v13;
    v52 = v13 != 0;
    if ( !v50 || !v13 )
    {
      v15 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
      if ( v15 )
        VBoxGuest_RTLogLoggerEx(v15, 16, 337, "vboxsf: Could not allocate memory for super info!\n");
      v4 = -12;
      if ( !v50 )
        goto LABEL_19;
      goto LABEL_18;
    }
    memset(v13, 0, 0x338u);
    v50[1] = v10;
    *v50 = v10 + 1;
    memcpy(v50 + 2, v8, v10 + 1);
    *(_BYTE *)(v14 + 16) = 1;
    v16 = *(_BYTE *)(a2 + 264) == 0;
    if ( !*(_BYTE *)(a2 + 264) )
      goto LABEL_32;
    v17 = (_BYTE *)(a2 + 264);
    v18 = 5;
    v19 = "utf8";
    do
    {
      if ( !v18 )
        break;
      v16 = *v17++ == *v19++;
      --v18;
    }
    while ( v16 );
    if ( v16 )
    {
LABEL_32:
      *(_QWORD *)(v14 + 8) = 0;
    }
    else
    {
      *(_BYTE *)(v14 + 16) = 0;
      nls = load_nls(v54, v17);
      *(_QWORD *)(v14 + 8) = nls;
      if ( !nls )
      {
        v21 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
        if ( v21 )
          VBoxGuest_RTLogLoggerEx(v21, 16, 337, "vboxsf: Failed to load nls '%s'!\n", v54);
        v4 = -22;
LABEL_18:
        kfree(v50);
LABEL_19:
        if ( v52 )
          kfree(v14);
        goto LABEL_6;
      }
    }
    v22 = 0x77FF80000000LL;
    if ( (unsigned __int64)v50 >= 0xFFFFFFFF80000000LL )
      v22 = phys_base;
    v55 = v22;
    v23 = (_DWORD *)VbglR0PhysHeapAlloc(176);
    v24 = v23;
    if ( v23 )
    {
      *v23 = 176;
      v23[1] = (_DWORD)&unk_10001;
      v23[2] = 0;
      v23[3] = -225;
      v23[4] = 176;
      v23[5] = 0;
      PhysAddr = VbglR0PhysHeapGetPhysAddr(v23);
      *((_BYTE *)v24 + 28) = 0;
      v24[13] = 124;
      v24[6] = PhysAddr + 52;
      v16 = (g_fHostFeatures & 4) == 0;
      v26 = g_SfClient;
      v24[14] = (_DWORD)&unk_10001;
      v24[15] = 63;
      v24[16] = -225;
      v24[17] = 0;
      v24[18] = 2;
      v24[19] = 0;
      v24[20] = -225;
      v24[21] = v26;
      v24[22] = 17;
      v24[23] = 4;
      v24[28] = 1;
      v24[29] = -1;
      v24[32] = 1;
      v24[33] = 47;
      v24[36] = 1;
      v24[37] = 1;
      if ( v16 )
      {
        v24[24] = 5;
        v27 = *v50;
        *((_QWORD *)v24 + 13) = v50;
        v24[25] = v27 + 4;
      }
      else
      {
        v24[24] = 10;
        v33 = *v50;
        v24[26] = 108;
        v24[40] = 3;
        *((_WORD *)v24 + 83) = 1;
        v24[25] = v33 + 4;
        *((_QWORD *)v24 + 21) = ((unsigned __int64)v50 + v55 + 0x80000000LL) & 0xFFFFFFFFFFFFF000LL;
        *((_WORD *)v24 + 82) = ((_WORD)v50 + v55) & 0xFFF;
      }
      v28 = VbglR0HGCMFastCall(*(_QWORD *)&algn_FA24[4], v24, 176);
      if ( v28 >= 0 )
      {
        v28 = v24[20];
        if ( v28 >= 0 )
        {
          *(_DWORD *)v14 = v24[29];
          VbglR0PhysHeapFree(v24);
          kfree(v50);
          vbsf_super_info_copy_remount_options(v14, a2);
          *(_QWORD *)(a1 + 96) = 64206;
          *(_QWORD *)(a1 + 24) = 1024;
          *(_QWORD *)(a1 + 32) = 0x7FFFFFFFFFFFFFFFLL;
          *(_DWORD *)(a1 + 1136) = 1;
          *(_QWORD *)(a1 + 48) = &g_vbsf_super_ops;
          *(_QWORD *)(a1 + 1200) = vbsf_dentry_ops;
          v29 = _InterlockedExchangeAdd64(&s_u64Sequence_45080, 1u);
          *(_QWORD *)(v14 + 112) = 0;
          v53 = v14 + 96;
          *(_DWORD *)(v14 + 120) = 0;
          v30 = v29 + 1;
          bdi_set_max_ratio(v14 + 96, 1);
          v31 = bdi_init(v14 + 96);
          if ( v31 || (v31 = bdi_register(v53, 0, "vboxsf-%llu", v30)) != 0 )
          {
            v32 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
            if ( v32 )
              VBoxGuest_RTLogLoggerEx(
                v32,
                16,
                337,
                "vboxsf: backing device information initialization failed: %d\n",
                v31);
            goto LABEL_43;
          }
          v34 = kmalloc_caches[1];
          *(_QWORD *)(a1 + 216) = v53;
          v35 = kmem_cache_alloc_trace(v34, 37748928, 72);
          v36 = kmem_cache_alloc_trace(kmalloc_caches[3], 37748928, 7);
          v38 = v36;
          v51 = v36 != 0;
          if ( v36 && v35 )
          {
            *(_QWORD *)v35 = v36;
            *(_QWORD *)(v35 + 56) = v35 + 56;
            *(_QWORD *)(v35 + 64) = v35 + 56;
            *(_QWORD *)(v35 + 48) = -1;
            *(_BYTE *)(v35 + 8) = 0;
            *(_WORD *)(v36 + 2) = 1;
            *(_WORD *)v36 = 2;
            *(_BYTE *)(v36 + 4) = 47;
            *(_BYTE *)(v36 + 5) = 0;
            v31 = vbsf_stat("vbsf_create_root_inode", v14, *(_QWORD *)v35, v58, 0);
            if ( v31 )
            {
              v44 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
              if ( v44 )
                VBoxGuest_RTLogLoggerEx(v44, 16, 337, "vboxsf: could not stat root of share: %d\n", v31);
            }
            else
            {
              v41 = iget_locked(a1, 1);
              v42 = v41;
              if ( v41 )
              {
                vbsf_init_inode(v41, v35, v58, v14);
                *(_QWORD *)(v42 + 552) = v35;
                unlock_new_inode(v42);
                root = d_make_root(v42);
                *(_QWORD *)(a1 + 104) = root;
                if ( root )
                {
                  *(_QWORD *)(a1 + 1120) = v14;
                  return v4;
                }
                v46 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
                if ( v46 )
                  VBoxGuest_RTLogLoggerEx(v46, 16, 337, "vboxsf: d_make_root failed!\n");
                v31 = -12;
                goto LABEL_55;
              }
              v31 = -12;
              v45 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
              if ( v45 )
                VBoxGuest_RTLogLoggerEx(v45, 16, 337, "vboxsf: failed to allocate root inode!\n");
            }
          }
          else
          {
            LOBYTE(v37) = v35 != 0;
            v56 = v37;
            v39 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
            v40 = v56;
            if ( v39 )
            {
              VBoxGuest_RTLogLoggerEx(v39, 16, 337, "vboxsf: Could not allocate memory for root inode info!\n", v56);
              v40 = v56;
            }
            v31 = -12;
            if ( !v40 )
              goto LABEL_53;
          }
          kfree(v35);
LABEL_53:
          if ( v51 )
            kfree(v38);
LABEL_55:
          bdi_destroy(v53);
          *(_QWORD *)(a1 + 216) = &noop_backing_dev_info;
LABEL_43:
          v4 = v31;
          vbsf_super_info_free((int *)v14);
          goto LABEL_6;
        }
      }
      *(_DWORD *)v14 = -1;
      v57 = v28;
      VbglR0PhysHeapFree(v24);
      if ( v57 == -102 )
      {
        v4 = -6;
        v49 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
        if ( v49 )
          VBoxGuest_RTLogLoggerEx(
            v49,
            16,
            337,
            "vboxsf: SHFL_FN_MAP_FOLDER failed for '%s': share not found\n",
            (const char *)v8);
        goto LABEL_71;
      }
      v47 = v57;
    }
    else
    {
      *(_DWORD *)v14 = -1;
      v47 = -8;
    }
    v4 = -71;
    v48 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
    if ( v48 )
      VBoxGuest_RTLogLoggerEx(v48, 16, 337, "vboxsf: SHFL_FN_MAP_FOLDER failed for '%s': %Rrc\n", v8, v47);
LABEL_71:
    if ( *(_QWORD *)(v14 + 8) )
      unload_nls();
    goto LABEL_18;
  }
  v4 = -38;
  DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
  if ( DefaultInstance )
  {
    v6 = "vboxsf: Remounting is not supported!\n";
LABEL_5:
    VBoxGuest_RTLogLoggerEx(DefaultInstance, 16, 337, v6);
  }
LABEL_6:
  printk(&unk_C0C4, v4);
  return v4;
}
