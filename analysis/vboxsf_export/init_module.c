// Alternative name is 'init'
__int64 __fastcall init_module(__int64 a1, unsigned __int64 a2, __int64 a3, __int64 a4)
{
  int v4; // ebp
  int v5; // ebx
  int HostFeatures; // ebx
  __int64 v7; // rax
  _DWORD *v8; // rax
  __int64 v9; // rbx
  int PhysAddr; // eax
  __int64 v11; // rdi
  int v12; // eax
  char v13; // al
  __int64 v14; // rax
  int v15; // ebp
  int v16; // eax
  unsigned int v17; // ebx
  __int64 v18; // rax
  __int64 v19; // rax
  __int64 v20; // rax
  __int64 DefaultInstance; // rax
  __int64 v22; // rax
  __int64 v24; // [rsp+0h] [rbp-18h]

  HIDWORD(v24) = HIDWORD(a4);
  g_SfHandleLock = 0;
  v4 = VbglR0SfInit(a1);
  if ( v4 >= 0 )
  {
    v5 = VbglR0SfConnect((__int64)&g_SfClient);
    if ( v5 < 0 )
    {
      DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
      if ( DefaultInstance )
        VBoxGuest_RTLogLoggerEx(DefaultInstance, 16, 337, "vboxsf: VbglR0SfConnect failed, rc=%Rrc\n", (unsigned int)v5);
      v17 = (v5 != -2900) - 112;
    }
    else
    {
      HostFeatures = VbglR0QueryHostFeatures(&g_fHostFeatures);
      if ( HostFeatures < 0 )
      {
        v7 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
        if ( v7 )
        {
          a2 = 16;
          VBoxGuest_RTLogLoggerEx(
            v7,
            16,
            337,
            "vboxsf: VbglR0QueryHostFeatures failed: rc=%Rrc (ignored)\n",
            (unsigned int)HostFeatures);
        }
        g_fHostFeatures = 0;
      }
      v8 = (_DWORD *)VbglR0PhysHeapAlloc(128, a2);
      v9 = (__int64)v8;
      if ( v8 )
      {
        *v8 = 128;
        v8[1] = (_DWORD)&unk_10001;
        v8[2] = 0;
        v8[3] = -225;
        v8[4] = 128;
        v8[5] = 0;
        PhysAddr = VbglR0PhysHeapGetPhysAddr((__int64)v8);
        v11 = *(_QWORD *)&algn_FA24[4];
        *(_BYTE *)(v9 + 28) = 0;
        *(_DWORD *)(v9 + 52) = 76;
        *(_DWORD *)(v9 + 24) = PhysAddr + 52;
        v12 = g_SfClient;
        a2 = v9;
        *(_DWORD *)(v9 + 56) = (_DWORD)&unk_10001;
        *(_DWORD *)(v9 + 60) = 63;
        *(_DWORD *)(v9 + 64) = -225;
        *(_DWORD *)(v9 + 68) = 0;
        *(_DWORD *)(v9 + 72) = 2;
        *(_DWORD *)(v9 + 76) = 0;
        *(_DWORD *)(v9 + 80) = -225;
        *(_DWORD *)(v9 + 84) = v12;
        *(_DWORD *)(v9 + 88) = 25;
        *(_DWORD *)(v9 + 92) = 2;
        *(_DWORD *)(v9 + 96) = 2;
        *(_QWORD *)(v9 + 100) = 0;
        *(_DWORD *)(v9 + 112) = 1;
        *(_DWORD *)(v9 + 116) = 0;
        if ( (int)VbglR0HGCMFastCall(v11, v9, 0x80u) < 0 || *(int *)(v9 + 80) < 0 )
        {
          v13 = g_fHostFeatures;
          *(_QWORD *)(v9 + 100) = 0;
          *(_DWORD *)(v9 + 116) = (v13 & 8) == 0 ? 20 : 24;
        }
        g_fSfFeatures = *(_QWORD *)(v9 + 100);
        g_uSfLastFunction = *(_DWORD *)(v9 + 116);
        VbglR0PhysHeapFree(v9, v9);
      }
      v14 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
      if ( v14 )
      {
        a2 = 16;
        LODWORD(v24) = g_uSfLastFunction;
        VBoxGuest_RTLogLoggerEx(
          v14,
          16,
          337,
          "vboxsf: g_fHostFeatures=%#x g_fSfFeatures=%#RX64 g_uSfLastFunction=%u\n",
          (unsigned int)g_fHostFeatures,
          g_fSfFeatures,
          v24);
      }
      v15 = VbglR0SfHostReqNoParmsSimple_constprop_7(16, a2);
      if ( v15 < 0 )
      {
        v17 = -71;
        v20 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
        if ( v20 )
          VBoxGuest_RTLogLoggerEx(v20, 16, 337, "vboxsf: VbglR0SfSetUtf8 failed, rc=%Rrc\n", (unsigned int)v15);
      }
      else
      {
        if ( !g_fFollowSymlinks )
        {
          v16 = VbglR0SfHostReqNoParmsSimple_constprop_7(20, a2);
          if ( v16 < 0 )
            printk(byte_C878, (unsigned int)v16);
        }
        v17 = register_filesystem(&g_vboxsf_fs_type);
        if ( !v17 )
        {
          printk(byte_C8B8);
          v18 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
          if ( v18 )
            VBoxGuest_RTLogLoggerEx(
              v18,
              16,
              337,
              "vboxsf: Successfully loaded version 6.1.36 r152435 on %s (LINUX_VERSION_CODE=%#x)\n",
              "4.4.146 SMP preempt mod_unload modversions ",
              263314);
          else
            return 0;
          return v17;
        }
        v19 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
        if ( v19 )
          VBoxGuest_RTLogLoggerEx(v19, 16, 337, "vboxsf: register_filesystem failed: rc=%d\n", v17);
      }
      VbglR0SfDisconnect((__int64)&g_SfClient);
    }
    VbglR0SfTerm();
    return v17;
  }
  v17 = -71;
  v22 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
  if ( v22 )
    VBoxGuest_RTLogLoggerEx(v22, 16, 337, "vboxsf: VbglR0SfInit failed, rc=%Rrc\n", (unsigned int)v4);
  return v17;
}
