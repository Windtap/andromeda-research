__int64 __fastcall VGDrvCommonInitDevExtResources(
        __int64 a1,
        unsigned __int16 a2,
        unsigned int *a3,
        unsigned int a4,
        int a5,
        int a6)
{
  __int64 DefaultInstance; // rax
  unsigned int *v13; // rsi
  int inited; // ebp
  __int64 v15; // rsi
  __int64 v16; // rdi
  _DWORD *v17; // rdi
  int v18; // eax
  __int64 v19; // r9
  _DWORD *v20; // rdi
  int v21; // ebp
  int v22; // ebp
  int v23; // ebp
  __int64 v24; // rax
  int v25; // r9d
  int v26; // ebp
  int v27; // ebp
  int v28; // ebp
  __int64 v30; // r14
  unsigned int v31; // r13d
  int v32; // r15d
  int v33; // eax
  __int64 v34; // r9
  int v35; // edx
  int v36; // r12d
  _DWORD *v37; // r12
  __int64 v38; // rdi
  _DWORD *v39; // rdi
  __int64 v40; // rax
  unsigned int v41; // r13d
  int v42; // edx
  int v43; // eax
  int v44; // eax
  __int64 v45; // rax
  int v46; // r9d
  int v47; // r8d
  const char *v48; // rcx
  __int64 v49; // rdi
  __int64 v50; // rax
  int v51; // r9d
  __int64 v52; // rax
  int v53; // r9d
  int v54; // r8d
  const char *v55; // rcx
  __int64 v56; // rax
  int v57; // r8d
  int v58; // r9d
  __int64 v59; // rax
  int v60; // r9d
  __int64 v61; // rax
  int v62; // r9d
  __int64 v63; // rcx
  __int64 v64; // rax
  int v65; // r9d
  __int64 v66; // rax
  __int64 v67; // rax
  int v68; // r9d
  __int64 v69; // rax
  int v70; // r9d
  __int64 v71; // rax
  int v72; // r9d
  unsigned int v73; // [rsp+0h] [rbp-98h]
  unsigned int v74; // [rsp+8h] [rbp-90h]
  __int64 v75; // [rsp+10h] [rbp-88h]
  char v76; // [rsp+10h] [rbp-88h]
  int v77; // [rsp+20h] [rbp-78h]
  __int64 v78; // [rsp+28h] [rbp-70h] BYREF
  _DWORD *v79; // [rsp+30h] [rbp-68h] BYREF
  _QWORD v80[12]; // [rsp+38h] [rbp-60h] BYREF

  if ( *(_DWORD *)a1 != 195939070 )
    return 4294967217LL;
  if ( !a3 )
    goto LABEL_6;
  if ( a3[1] != 1 || *a3 <= 0x1F || *a3 > a4 )
  {
    DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( DefaultInstance )
    {
      v74 = a4;
      v73 = *a3;
      VBoxGuest_RTLogLoggerEx(
        DefaultInstance,
        16,
        32,
        (unsigned int)"VGDrvCommonInitDevExtResources: Bogus VMMDev memory; u32Version=%RX32 (expected %RX32) u32Size=%RX"
                      "32 (expected <= %RX32)\n",
        a3[1],
        1);
    }
LABEL_6:
    v13 = *(unsigned int **)(a1 + 8);
    goto LABEL_7;
  }
  *(_QWORD *)(a1 + 8) = a3;
  v13 = a3;
LABEL_7:
  *(_WORD *)(a1 + 4) = a2;
  inited = VbglR0InitPrimary(a2, v13, a1 + 32);
  if ( inited < 0 )
  {
    v71 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( v71 )
      VBoxGuest_RTLogLoggerEx(
        v71,
        16,
        32,
        (unsigned int)"VGDrvCommonInitDevExtResources: VbglR0InitPrimary failed: rc=%Rrc\n",
        inited,
        v72);
    goto LABEL_58;
  }
  v15 = 28;
  v78 = 0;
  inited = VbglR0GRAlloc(&v78, 28, 41);
  if ( inited < 0 )
  {
    v49 = 2097168;
    v67 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( v67 )
    {
      v49 = v67;
      v15 = 16;
      VBoxGuest_RTLogLoggerEx(
        v67,
        16,
        32,
        (unsigned int)"VGDrvCommonInitDevExtResources: VbglR0GRAlloc failed: rc=%Rrc\n",
        inited,
        v68);
    }
    goto LABEL_57;
  }
  *(_QWORD *)(a1 + 48) = (unsigned int)VbglR0PhysHeapGetPhysAddr(v78);
  *(_QWORD *)(a1 + 40) = v78;
  inited = vgdrvReportGuestInfo(a5);
  if ( inited < 0 )
  {
    v69 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( v69 )
    {
      v15 = 16;
      VBoxGuest_RTLogLoggerEx(
        v69,
        16,
        32,
        (unsigned int)"VGDrvCommonInitDevExtResources: vgdrvReportGuestInfo failed: rc=%Rrc\n",
        inited,
        v70);
    }
    goto LABEL_56;
  }
  v16 = a6 | 2u;
  *(_DWORD *)(a1 + 216) = v16;
  inited = vgdrvResetEventFilterOnHost_isra_3(v16);
  if ( inited < 0 )
  {
    v45 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( !v45 )
      goto LABEL_55;
    v47 = inited;
    v48 = "VGDrvCommonInitDevExtResources: failed to set fixed event filter: rc=%Rrc\n";
    goto LABEL_54;
  }
  inited = vgdrvResetCapabilitiesOnHost_isra_4(v16, 28);
  if ( inited < 0 )
  {
    v45 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( !v45 )
    {
LABEL_55:
      *(_DWORD *)(a1 + 216) = 0;
LABEL_56:
      v49 = *(_QWORD *)(a1 + 40);
      VbglR0GRFree(v49);
LABEL_57:
      VbglR0TerminatePrimary(v49, v15);
LABEL_58:
      *(_WORD *)(a1 + 4) = -1;
      return (unsigned int)inited;
    }
    v47 = inited;
    v48 = "VGDrvCommonInitDevExtResources: failed to clear guest capabilities: rc=%Rrc\n";
LABEL_54:
    v15 = 16;
    VBoxGuest_RTLogLoggerEx(v45, 16, 32, (_DWORD)v48, v47, v46);
    goto LABEL_55;
  }
  inited = vgdrvResetMouseStatusOnHost_isra_5(v16, 28);
  if ( inited < 0 )
  {
    v45 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( !v45 )
      goto LABEL_55;
    v47 = inited;
    v48 = "VGDrvCommonInitDevExtResources: failed to clear mouse status: rc=%Rrc\n";
    goto LABEL_54;
  }
  if ( (int)VbglR0GRAlloc(&v79, 32, 20) >= 0 )
  {
    v17 = v79;
    v79[6] = 0;
    v17[7] = 0;
    v18 = VbglR0GRPerform(v17);
    v20 = v79;
    if ( v18 >= 0 )
    {
      v21 = v79[7];
      if ( v21 )
      {
        v30 = 0;
        v75 = 0;
        v31 = (v21 + 0x3FFFFF) & 0xFFC00000;
        while ( 1 )
        {
          v32 = v75;
          v33 = VBoxGuest_RTR0MemObjReserveKernelTag(
                  v80,
                  -1,
                  v31,
                  0x400000,
                  "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/VBoxGuest.c",
                  v19,
                  v73,
                  v74);
          v35 = 0x400000;
          v36 = v33;
          if ( v33 == -37 )
          {
            v36 = VBoxGuest_RTR0MemObjReserveKernelTag(
                    v80,
                    -1,
                    v31 + 0x400000,
                    4096,
                    "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/VBoxGuest.c",
                    v34,
                    v73,
                    v74);
            if ( v36 == -37 )
            {
              if ( !v30 )
              {
                v36 = VBoxGuest_RTR0MemObjEnterPhysTag(
                        v80,
                        4160749568LL,
                        (unsigned int)(v21 + 0x400000),
                        0,
                        "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/VBoxGuest.c");
                if ( v36 < 0 )
                {
                  v76 = 0;
                  goto LABEL_35;
                }
                v30 = v80[0];
              }
              v43 = VBoxGuest_RTR0MemObjMapKernelTag(
                      v80,
                      v30,
                      -1,
                      0x400000,
                      3,
                      "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/VBoxGuest.c");
              v35 = 0x400000;
              v36 = v43;
              if ( v43 == -37 )
              {
                v44 = VBoxGuest_RTR0MemObjMapKernelTag(
                        v80,
                        v30,
                        -1,
                        4096,
                        3,
                        "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/VBoxGuest.c");
                v35 = 4096;
                v36 = v44;
              }
            }
            else
            {
              v35 = 4096;
            }
          }
          if ( v36 < 0 )
            break;
          v37 = v79;
          v77 = v35;
          v38 = v80[0];
          v79[2] = 21;
          v37[3] = -225;
          v37[7] = v21;
          v37[6] = VBoxGuest_RTR0MemObjAddress(v38);
          if ( v77 == 4096 )
          {
            v42 = v79[6];
            v39 = v79;
            if ( (v42 & 0x3FFFFF) != 0 )
              v79[6] = (v42 + 0x3FFFFF) & 0xFFC00000;
          }
          else
          {
            v39 = v79;
          }
          v36 = VbglR0GRPerform(v39);
          if ( v36 >= 0 )
          {
            v40 = v30;
            v76 = 0;
            if ( !v30 )
              v40 = v80[0];
            *(_QWORD *)(a1 + 16) = v40;
            goto LABEL_35;
          }
          v63 = v75++;
          v80[v63 + 1] = v80[0];
          if ( v75 == 5 )
          {
            v76 = 0;
            v41 = 4;
            goto LABEL_38;
          }
        }
        v66 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
        if ( v66 )
          VBoxGuest_RTLogLoggerEx(
            v66,
            16,
            32,
            (unsigned int)"VBoxGuest: Failed to reserve memory for the hypervisor: rc=%Rrc (cbHypervisor=%#x uAlignment=%#x iTry=%u)\n",
            v36,
            v21);
        v76 = 1;
LABEL_35:
        v41 = v32 - 1;
        if ( !v32 )
          goto LABEL_39;
LABEL_38:
        while ( 1 )
        {
          VBoxGuest_RTR0MemObjFree(v80[v41 + 1], 0);
          if ( !v41 )
            break;
          --v41;
        }
LABEL_39:
        if ( v36 < 0 )
        {
          if ( v30 )
            VBoxGuest_RTR0MemObjFree(v30, 0);
          if ( !v76 )
          {
            v64 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
            if ( v64 )
              VBoxGuest_RTLogLoggerEx(
                v64,
                16,
                32,
                (unsigned int)"VBoxGuest: Warning: failed to reserve %#d of memory for guest mappings.\n",
                v21,
                v65);
          }
        }
        v20 = v79;
      }
    }
    VbglR0GRFree(v20);
  }
  if ( (int)vgdrvHeartbeatHostConfigure(a1, 0) < 0 )
    goto LABEL_24;
  v22 = vgdrvHeartbeatHostConfigure(a1, 1);
  if ( v22 < 0 )
  {
    v61 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( v61 )
      VBoxGuest_RTLogLoggerEx(
        v61,
        16,
        32,
        (unsigned int)"vgdrvHeartbeatInit: Failed to configure host for heartbeat checking: rc=%Rrc\n",
        v22,
        v62);
    goto LABEL_24;
  }
  v23 = VbglR0GRAlloc(a1 + 656, 24, 219);
  if ( v23 < 0 )
  {
    v59 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( v59 )
      VBoxGuest_RTLogLoggerEx(
        v59,
        16,
        32,
        (unsigned int)"vgdrvHeartbeatInit: VbglR0GRAlloc(VMMDevReq_GuestHeartbeat): %Rrc\n",
        v23,
        v60);
    goto LABEL_65;
  }
  v24 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
  if ( v24 )
    VBoxGuest_RTLogLoggerEx(
      v24,
      16,
      32,
      (unsigned int)"vgdrvHeartbeatInit: Setting up heartbeat to trigger every %RU64 milliseconds\n",
      *(_QWORD *)(a1 + 648) / 0xF4240uLL,
      v25);
  v26 = VBoxGuest_RTTimerCreateEx(a1 + 640, *(_QWORD *)(a1 + 648), 0, vgdrvHeartbeatTimerHandler, a1);
  if ( v26 < 0 )
  {
    v52 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( !v52 )
      goto LABEL_64;
    v54 = v26;
    v55 = "vgdrvHeartbeatInit: Failed to create heartbeat timer: %Rrc\n";
    goto LABEL_63;
  }
  v27 = VBoxGuest_RTTimerStart(*(_QWORD *)(a1 + 640), 0);
  if ( v27 < 0 )
  {
    v52 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( !v52 )
    {
LABEL_64:
      VbglR0GRFree(*(_QWORD *)(a1 + 656));
      *(_QWORD *)(a1 + 656) = 0;
LABEL_65:
      v56 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
      if ( v56 )
        VBoxGuest_RTLogLoggerEx(
          v56,
          16,
          32,
          (unsigned int)"vgdrvHeartbeatInit: Failed to set up the timer, guest heartbeat is disabled\n",
          v57,
          v58);
      vgdrvHeartbeatHostConfigure(a1, 0);
      goto LABEL_24;
    }
    v54 = v27;
    v55 = "vgdrvHeartbeatInit: Heartbeat timer failed to start, rc=%Rrc\n";
LABEL_63:
    VBoxGuest_RTLogLoggerEx(v52, 16, 32, (_DWORD)v55, v54, v53);
    goto LABEL_64;
  }
LABEL_24:
  v28 = vgdrvReportDriverStatus_constprop_15();
  if ( v28 < 0 )
  {
    v50 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
    if ( v50 )
      VBoxGuest_RTLogLoggerEx(
        v50,
        16,
        32,
        (unsigned int)"VGDrvCommonInitDevExtResources: VBoxReportGuestDriverStatus failed, rc=%Rrc\n",
        v28,
        v51);
  }
  *(_DWORD *)a1 = -889275714;
  return 0;
}
