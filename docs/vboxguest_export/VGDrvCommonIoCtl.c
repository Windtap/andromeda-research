__int64 __fastcall VGDrvCommonIoCtl(
        unsigned __int64 a1,
        __int64 a2,
        __int64 a3,
        _DWORD *a4,
        unsigned __int64 a5,
        int a6)
{
  unsigned int v8; // r12d
  unsigned int v9; // ecx
  unsigned __int64 v10; // rdx
  unsigned int i; // edx
  __int64 v12; // rcx
  unsigned int v13; // r13d
  __int64 v14; // rax
  unsigned int v15; // r14d
  int v16; // ebp
  __int64 DefaultInstance; // rax
  int v19; // eax
  int v20; // eax
  _DWORD *v21; // rdi
  void *v22; // r13
  void *v23; // rdi
  unsigned int v24; // r15d
  int v25; // edx
  char v26; // al
  __int64 v27; // rax
  __int64 v28; // rax
  unsigned int v29; // r13d
  unsigned int v30; // r12d
  __int64 v32; // rax
  int v33; // eax
  __int64 v34; // r10
  int v35; // r15d
  __int64 v36; // rax
  __int64 v37; // rax
  __int64 v38; // rax
  int v39; // eax
  int v40; // eax
  int v41; // ebp
  int v42; // edx
  int v43; // ecx
  int v44; // r8d
  int v45; // r9d
  int v46; // r13d
  int v47; // eax
  __int64 v48; // r10
  __int64 v49; // rax
  unsigned int v50; // eax
  unsigned int v51; // edx
  int v52; // ebp
  __int64 v53; // rax
  void *v54; // rax
  __int64 v55; // rdi
  int v56; // eax
  __int64 v57; // r10
  __int64 v58; // rax
  unsigned int v59; // eax
  unsigned int v60; // edx
  __int64 v61; // rax
  _DWORD *v62; // rdi
  __int64 v63; // rax
  __int64 v64; // rax
  int v65; // r9d
  unsigned int v66; // r8d
  const char *v67; // rcx
  int v68; // edx
  int v69; // edx
  int v70; // edx
  unsigned int v71; // r12d
  unsigned int k; // eax
  __int64 v73; // r13
  __int64 v74; // rax
  int AllowedEventMaskForSession; // eax
  int v76; // eax
  __int64 v77; // rdi
  int v78; // eax
  int v79; // eax
  __int64 v80; // r10
  __int64 v81; // rdi
  int v82; // eax
  unsigned int v83; // r13d
  __int64 v84; // rax
  int v85; // eax
  unsigned int v86; // ebp
  unsigned int v87; // r14d
  int v88; // eax
  int v89; // eax
  int v90; // eax
  __int64 v91; // rax
  int v92; // r8d
  int v93; // r9d
  __int64 v94; // r10
  __int64 v95; // rax
  unsigned int v96; // eax
  char v97; // r12
  __int64 v98; // rax
  __int64 v99; // rax
  __int64 v100; // rax
  unsigned int v101; // r14d
  _QWORD *v102; // r15
  __int64 v103; // r13
  __int64 v104; // rdi
  __int64 v105; // rax
  int v106; // eax
  _DWORD *v107; // rsi
  int v108; // eax
  __int64 v109; // r10
  int v110; // eax
  int v111; // eax
  __int64 v112; // rax
  unsigned int j; // eax
  __int64 v114; // rcx
  __int64 v115; // rax
  __int64 v116; // rax
  __int64 v117; // r15
  __int64 v118; // r10
  int v119; // r14d
  int v120; // r14d
  __int64 v121; // rax
  _QWORD *v122; // rdx
  __int64 v123; // rdi
  int v124; // eax
  int v125; // eax
  int v126; // r12d
  __int64 v127; // rax
  _QWORD *v128; // rdx
  int v129; // ebp
  __int64 v130; // rdi
  __int64 v131; // rax
  int v132; // r8d
  int v133; // r9d
  __int64 v134; // rax
  int v135; // r9d
  __int64 v136; // rax
  __int64 v137; // rax
  int v138; // r8d
  int v139; // r9d
  __int64 v140; // [rsp+10h] [rbp-50h]
  __int64 v141; // [rsp+10h] [rbp-50h]
  __int64 v142; // [rsp+10h] [rbp-50h]
  __int64 v143; // [rsp+10h] [rbp-50h]
  __int64 v144; // [rsp+10h] [rbp-50h]
  __int64 v145; // [rsp+10h] [rbp-50h]
  __int64 v146; // [rsp+10h] [rbp-50h]
  __int64 v147; // [rsp+10h] [rbp-50h]
  __int64 v148; // [rsp+10h] [rbp-50h]
  __int64 v149; // [rsp+10h] [rbp-50h]
  __int64 v150; // [rsp+18h] [rbp-48h]
  __int64 v151; // [rsp+18h] [rbp-48h]
  __int64 v152; // [rsp+20h] [rbp-40h] BYREF
  void *dest[7]; // [rsp+28h] [rbp-38h] BYREF

  if ( a5 <= 0x17 )
    return 4294967294LL;
  if ( !a4[4] )
    a4[4] = *a4;
  if ( a4[1] != (_DWORD)&loc_10001 )
    return 4294967294LL;
  v8 = *a4;
  if ( *a4 <= 0x17u )
    return 4294967294LL;
  if ( a5 < v8 )
    return 4294967294LL;
  v9 = a4[4];
  if ( v9 <= 0x17 )
    return 4294967294LL;
  if ( a5 < v9 )
    return 4294967294LL;
  if ( (unsigned __int64)(a3 + 0x200000) <= 0x200FFF )
    return 4294967294LL;
  v10 = a3 & 0xFF00000000000000LL;
  if ( (a3 & 0xFF00000000000000LL) != 0 && v10 != 0xFF00000000000000LL )
    return 4294967294LL;
  if ( (unsigned __int64)(unsigned __int8)a1 - 2 <= 1 )
  {
    v13 = a4[2];
    if ( v13 && v8 == v9 )
    {
      v14 = v13 - 1;
      if ( (unsigned int)v14 > 0xDD || (v15 = (unsigned __int16)CSWTCH_80[v14], v8 >= v15) )
      {
        v19 = VbglGR0Verify(a4, a5);
        if ( v19 < 0 )
        {
LABEL_275:
          v16 = v19;
        }
        else
        {
          switch ( v13 )
          {
            case 1u:
            case 2u:
            case 3u:
            case 4u:
            case 5u:
            case 0xAu:
            case 0x1Eu:
            case 0x29u:
            case 0x2Au:
            case 0x33u:
            case 0x34u:
            case 0x35u:
            case 0x36u:
            case 0x39u:
            case 0x3Bu:
            case 0x46u:
            case 0x47u:
            case 0x48u:
            case 0x49u:
            case 0x50u:
            case 0x51u:
            case 0x96u:
            case 0xC8u:
            case 0xD9u:
            case 0xDEu:
              goto LABEL_48;
            case 0x14u:
            case 0x15u:
            case 0x16u:
            case 0x17u:
            case 0x32u:
            case 0x3Au:
            case 0x6Fu:
            case 0x71u:
              goto LABEL_106;
            case 0x37u:
              v39 = a4[6];
              if ( v39 == 100 )
                goto LABEL_47;
              if ( v39 != 2147483646 && v39 != 20 )
                goto LABEL_48;
LABEL_106:
              if ( *(_QWORD *)(a3 + 24) == -1 )
              {
LABEL_48:
                v19 = VbglR0GRAlloc(dest, v8, v13);
                if ( v19 < 0 )
                  goto LABEL_275;
                memcpy(dest[0], a4, v8);
                v21 = dest[0];
                *((_DWORD *)dest[0] + 4) = 0;
                v21[5] = *(_DWORD *)(a3 + 16);
                if ( v13 == 1 )
                  *(_DWORD *)(a3 + 296) = *(_DWORD *)(a2 + 124);
                v16 = VbglR0GRPerform(v21);
                if ( v16 < 0 )
                {
                  v23 = dest[0];
                }
                else
                {
                  v22 = dest[0];
                  if ( *((int *)dest[0] + 3) < 0 )
                  {
                    v23 = dest[0];
                    v16 = *((_DWORD *)dest[0] + 3);
                  }
                  else
                  {
                    memcpy(a4, dest[0], v8);
                    a4[4] = v8;
                    v23 = v22;
                  }
                }
                VbglR0GRFree(v23);
              }
              else
              {
LABEL_107:
                v16 = -10;
              }
              break;
            case 0x4Au:
            case 0x64u:
            case 0x65u:
            case 0x6Eu:
            case 0x70u:
            case 0xD2u:
            case 0xD3u:
            case 0xD4u:
            case 0xD5u:
            case 0xD6u:
            case 0xD7u:
            case 0xD8u:
            case 0xDAu:
LABEL_47:
              if ( !*(_BYTE *)(a3 + 317) )
                goto LABEL_48;
              goto LABEL_107;
            default:
              goto LABEL_107;
          }
        }
      }
      else
      {
        v16 = -2;
        DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
        if ( DefaultInstance )
          VBoxGuest_RTLogLoggerEx(
            DefaultInstance,
            16,
            32,
            (unsigned int)"VBOXGUEST_IOCTL_VMMREQUEST: invalid hdr size %#x, expected >= %#x; type=%#x!!\n",
            v8,
            v15);
      }
      goto LABEL_39;
    }
    goto LABEL_108;
  }
  if ( a4[2] )
    return 4294967294LL;
  if ( (unsigned __int8)a1 == 9 )
  {
    if ( v9 != 24 )
      goto LABEL_108;
    v24 = v8 - 24;
    if ( *(_BYTE *)(a2 + 156) )
    {
      VBoxGuest_RTLogBackdoorPrintf((unsigned int)"%.*s", v24, (_DWORD)a4 + 24, 24, a5, a6);
    }
    else if ( !*(_BYTE *)(a3 + 317) )
    {
      v36 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
      if ( v36 )
        VBoxGuest_RTLogLoggerEx(v36, 16, 32, (unsigned int)"%.*s", v24, (_DWORD)a4 + 24);
    }
    goto LABEL_58;
  }
  if ( a1 != 3224655421 )
  {
    if ( (unsigned __int64)(unsigned __int8)a1 - 6 <= 1 )
    {
      if ( v8 <= 0x27 || v8 != v9 )
        goto LABEL_108;
      v26 = 1;
      if ( !*((_BYTE *)a4 + 36) )
        v26 = *(_QWORD *)(a3 + 24) != -1;
      v20 = vgdrvIoCtl_HGCMCallInner_constprop_14(a2, a3, (__int64)a4, a4[8], v26, (unsigned __int8)a1 == 6, 0, a5);
      goto LABEL_46;
    }
    if ( (unsigned __int8)a1 == 8 )
    {
      if ( *(_QWORD *)(a3 + 24) != -1 )
        goto LABEL_111;
      if ( v8 <= 0x27 || v8 != v9 )
        goto LABEL_108;
      v20 = vgdrvIoCtl_HGCMCallInner_constprop_14(a2, a3, (__int64)a4, a4[8], *((_BYTE *)a4 + 36), 0, 1, a5);
      goto LABEL_46;
    }
    if ( a1 != 3223344657 )
    {
      if ( a1 > 0xC0205611 )
      {
        if ( a1 == 3223868944 )
        {
          if ( *(_QWORD *)(a3 + 24) == -1 )
          {
            if ( v8 == 40 && v9 == 24 )
            {
              VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a2 + 24));
              *(_QWORD *)(a2 + 200) = *((_QWORD *)a4 + 3);
              v55 = *(_QWORD *)(a2 + 24);
              *(_QWORD *)(a2 + 208) = *((_QWORD *)a4 + 4);
              VBoxGuest_RTSpinlockRelease(v55);
              a4[3] = 0;
              return 0;
            }
            goto LABEL_108;
          }
          goto LABEL_111;
        }
        if ( a1 > 0xC0285610 )
        {
          if ( a1 != 3224131072 )
          {
            if ( a1 > 0xC02C5600 )
            {
              if ( a1 != 3224917567 )
              {
                if ( a1 == 3231471108 )
                {
                  if ( v8 == 156 && v9 == 28 )
                  {
                    LODWORD(dest[0]) = 0;
                    v8 = VbglR0HGCMInternalConnect(a4 + 6);
                    if ( (v8 & 0x80000000) != 0 )
                    {
LABEL_32:
                      a4[6] = dest[0];
                    }
                    else
                    {
                      VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a2 + 128));
                      for ( i = 0; i != 64; ++i )
                      {
                        v12 = i + 8LL;
                        if ( !*(_DWORD *)(a3 + 4 * v12 + 8) )
                        {
                          *(_DWORD *)(a3 + 4 * v12 + 8) = dest[0];
                          VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a2 + 128));
                          goto LABEL_32;
                        }
                      }
                      VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a2 + 128));
                      v91 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
                      v94 = a2;
                      if ( v91 )
                      {
                        if ( (unsigned int)s_LogRelMaxIt_cLogged_9359 <= 0x1F )
                        {
                          ++s_LogRelMaxIt_cLogged_9359;
                          VBoxGuest_RTLogLoggerEx(
                            v91,
                            16,
                            32,
                            (unsigned int)"VBOXGUEST_IOCTL_HGCM_CONNECT: too many HGCMConnect calls for one session!\n",
                            v92,
                            v93);
                          v94 = a2;
                        }
                      }
                      v8 = -106;
                      VbglR0HGCMInternalDisconnect(
                        LODWORD(dest[0]),
                        *(unsigned int *)(a3 + 16),
                        vgdrvHgcmAsyncWaitCallback,
                        v94,
                        0xFFFFFFFFLL);
                      a4[6] = 0;
                    }
                    goto LABEL_102;
                  }
                  goto LABEL_108;
                }
                goto LABEL_90;
              }
              if ( *(_QWORD *)(a3 + 24) == -1 )
              {
                if ( v8 == 40 && v9 == 56 )
                {
                  if ( a4[6] != 1437224282 )
                  {
                    v16 = -2;
                    v74 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
                    if ( v74 )
                      VBoxGuest_RTLogLoggerEx(
                        v74,
                        16,
                        32,
                        (unsigned int)"VBGL_IOCTL_IDC_CONNECT: u32MagicCookie=%#x expected %#x!\n",
                        a4[6],
                        1437224282);
                    goto LABEL_39;
                  }
                  v59 = a4[8];
                  v60 = a4[7];
                  if ( v59 <= v60 && HIWORD(v59) == HIWORD(v60) )
                  {
                    if ( v59 <= (unsigned int)&loc_10000 && HIWORD(v59) == 1 )
                    {
                      *((_QWORD *)a4 + 3) = a3;
                      v16 = 0;
                      a4[8] = (_DWORD)&loc_10000;
                      a4[9] = (_DWORD)&loc_10000;
                      a4[10] = (_DWORD)&unk_25373;
                      a4[11] = 0;
                      *((_QWORD *)a4 + 6) = 0;
                      goto LABEL_39;
                    }
                    v16 = -11;
                    v100 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
                    if ( v100 )
                      VBoxGuest_RTLogLoggerEx(
                        v100,
                        16,
                        32,
                        (unsigned int)"VBGL_IOCTL_IDC_CONNECT: Version mismatch. Requested: %#x  Min: %#x  Current: %#x\n",
                        a4[7],
                        a4[8]);
                  }
                  else
                  {
                    v16 = -2;
                    v61 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
                    if ( v61 )
                      VBoxGuest_RTLogLoggerEx(
                        v61,
                        16,
                        32,
                        (unsigned int)"VBGL_IOCTL_IDC_CONNECT: uMinVersion=%#x uMaxVersion=%#x doesn't match!\n",
                        a4[8],
                        a4[7]);
                  }
                  *((_QWORD *)a4 + 3) = 0;
                  a4[8] = -1;
                  a4[9] = (_DWORD)&loc_10000;
                  a4[10] = (_DWORD)&unk_25373;
                  a4[11] = 0;
                  *((_QWORD *)a4 + 6) = 0;
LABEL_39:
                  a4[3] = v16;
                  return 0;
                }
LABEL_108:
                a4[3] = -2;
                return 4294967294LL;
              }
LABEL_111:
              a4[3] = -10;
              return 4294967286LL;
            }
            if ( a1 == 3223868946 )
            {
              if ( v8 != 40 || v9 != 24 )
                goto LABEL_108;
              v46 = -2;
              if ( (*((_QWORD *)a4 + 4) & 0xFFFFFFFFFFFFFFLL) != 0 )
              {
LABEL_123:
                a4[3] = v46;
                return 0;
              }
              v47 = VBoxGuest_RTSemFastMutexRequest(*(_QWORD *)(a2 + 160));
              if ( v47 < 0 )
              {
                v46 = v47;
                goto LABEL_123;
              }
              v48 = a2;
              LOBYTE(v46) = -10;
              if ( *(_BYTE *)(a2 + 176) )
              {
LABEL_122:
                VBoxGuest_RTSemFastMutexRelease(*(_QWORD *)(v48 + 160));
                goto LABEL_123;
              }
              v49 = *(_QWORD *)(a2 + 184);
              if ( a3 != v49 )
              {
                if ( v49 )
                  goto LABEL_122;
                *(_QWORD *)(a2 + 184) = a3;
              }
              v97 = *((_BYTE *)a4 + 39);
              v145 = *((_QWORD *)a4 + 3);
              if ( v97 )
              {
                v98 = *(unsigned int *)(a2 + 172);
                if ( *(_DWORD *)(a2 + 168) > (unsigned int)(v98 - 1) || !(_DWORD)v98 )
                {
                  v99 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
                  v48 = a2;
                  if ( v99 )
                  {
                    v46 = -2;
                    VBoxGuest_RTLogLoggerEx(
                      v99,
                      16,
                      32,
                      (unsigned int)"vgdrvSetBalloonSizeFromUser: cannot inflate balloon, already have %u chunks (max=%u)\n",
                      *(_DWORD *)(a2 + 168),
                      *(_DWORD *)(a2 + 172));
                    v48 = a2;
                    goto LABEL_122;
                  }
LABEL_317:
                  v46 = -2;
                  goto LABEL_122;
                }
                if ( *(_QWORD *)(a2 + 192) )
                {
LABEL_247:
                  v101 = 0;
                  v102 = 0;
                  while ( 1 )
                  {
                    if ( v102 || !v97 )
                    {
                      v103 = 8LL * v101;
                      v104 = *(_QWORD *)(*(_QWORD *)(v48 + 192) + v103);
                    }
                    else
                    {
                      v103 = 8LL * v101;
                      v102 = (_QWORD *)(*(_QWORD *)(v48 + 192) + v103);
                      v104 = *v102;
                      if ( *v102 )
                        v102 = 0;
                    }
                    v151 = v48;
                    v105 = VBoxGuest_RTR0MemObjAddressR3(v104);
                    v48 = v151;
                    if ( v145 == v105 )
                      break;
                    if ( ++v101 >= *(_DWORD *)(v151 + 172) )
                    {
                      if ( !v102 )
                        goto LABEL_268;
                      goto LABEL_257;
                    }
                  }
                  if ( v97 )
                  {
                    v46 = -105;
                    goto LABEL_122;
                  }
                  v102 = (_QWORD *)(*(_QWORD *)(v151 + 192) + v103);
                  if ( !v102 )
                    goto LABEL_267;
LABEL_257:
                  v106 = VbglR0GRAlloc(dest, 2080, 113);
                  v48 = v151;
                  v46 = v106;
                  if ( v106 >= 0 )
                  {
                    v107 = dest[0];
                    *((_DWORD *)dest[0] + 5) = *(_DWORD *)(a3 + 16);
                    if ( v97 )
                    {
                      v108 = VBoxGuest_RTR0MemObjLockUserTag(
                               v102,
                               v145,
                               0x100000,
                               3,
                               -1,
                               "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/VBoxGuest.c");
                      v109 = v151;
                      v46 = v108;
                      if ( v108 >= 0 )
                      {
                        v110 = vgdrvBalloonInflate(v102, (_DWORD *)dest[0]);
                        v109 = v151;
                        v46 = v110;
                        if ( v110 < 0 )
                        {
                          VBoxGuest_RTR0MemObjFree(*v102, 1);
                          *v102 = 0;
                          v109 = v151;
                        }
                        else
                        {
                          ++*(_DWORD *)(v151 + 168);
                        }
                      }
                    }
                    else
                    {
                      v111 = vgdrvBalloonDeflate(v102, v107);
                      v109 = v151;
                      v46 = v111;
                      if ( v111 >= 0 )
                        --*(_DWORD *)(v151 + 168);
                    }
                    v146 = v109;
                    VbglR0GRFree(dest[0]);
                    v48 = v146;
                  }
                  goto LABEL_122;
                }
                v112 = VBoxGuest_RTMemAllocTag(
                         8 * v98,
                         "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/VBoxGuest.c");
                v48 = a2;
                *(_QWORD *)(a2 + 192) = v112;
                if ( !v112 )
                {
                  v131 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
                  v48 = a2;
                  if ( v131 )
                  {
                    VBoxGuest_RTLogLoggerEx(
                      v131,
                      16,
                      32,
                      (unsigned int)"vgdrvSetBalloonSizeFromUser: no memory for paMemObj!\n",
                      v132,
                      v133);
                    v46 = -8;
                    v48 = a2;
                    goto LABEL_122;
                  }
                  goto LABEL_269;
                }
                for ( j = 0; j < *(_DWORD *)(a2 + 172); ++j )
                {
                  v114 = j;
                  *(_QWORD *)(*(_QWORD *)(a2 + 192) + 8 * v114) = 0;
                }
              }
              else if ( !*(_DWORD *)(a2 + 168) )
              {
                goto LABEL_317;
              }
              if ( *(_DWORD *)(v48 + 172) )
                goto LABEL_247;
LABEL_268:
              if ( !v97 )
              {
LABEL_267:
                v46 = -78;
                goto LABEL_122;
              }
LABEL_269:
              v46 = -8;
              goto LABEL_122;
            }
LABEL_90:
            v37 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
            if ( v37 )
              VBoxGuest_RTLogLoggerEx(
                v37,
                16,
                32,
                (unsigned int)"VGDrvCommonIoCtl: Unknown request iFunction=%#x (stripped %#x) cbReq=%#x\n",
                a1,
                (unsigned __int8)a1);
            a4[3] = -37;
            return 4294967259LL;
          }
          if ( v8 != 40 || v9 != 44 )
            goto LABEL_108;
          v50 = a4[7];
          v51 = a4[6];
          if ( v50 <= v51 && HIWORD(v50) == HIWORD(v51) )
          {
            if ( v50 <= (unsigned int)&loc_10000 && HIWORD(v50) == 1 )
            {
              v52 = 0;
              v54 = &loc_10000;
              goto LABEL_131;
            }
            v52 = -11;
            v95 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
            if ( v95 )
              VBoxGuest_RTLogLoggerEx(
                v95,
                16,
                32,
                (unsigned int)"VBGL_IOCTL_DRIVER_VERSION_INFO: Version mismatch. Requested: %#x  Min: %#x  Current: %#x\n",
                a4[6],
                a4[7]);
          }
          else
          {
            v52 = -2;
            v53 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
            if ( v53 )
              VBoxGuest_RTLogLoggerEx(
                v53,
                16,
                32,
                (unsigned int)"VBGL_IOCTL_DRIVER_VERSION_INFO: uMinVersion=%#x uMaxVersion=%#x doesn't match!\n",
                a4[7],
                a4[6]);
          }
          LODWORD(v54) = -1;
LABEL_131:
          a4[6] = (_DWORD)v54;
          a4[7] = (_DWORD)&loc_10000;
          a4[8] = (_DWORD)&unk_25373;
          a4[9] = 0;
          a4[10] = 0;
          a4[3] = v52;
          return 0;
        }
        if ( a1 != 3223606797 )
        {
          if ( a1 != 3223868929 )
          {
            if ( a1 != 3223344702 )
              goto LABEL_90;
            if ( *(_QWORD *)(a3 + 24) != -1 )
              goto LABEL_111;
            if ( v8 != 32 || v9 != 24 )
              goto LABEL_108;
            if ( a3 == *((_QWORD *)a4 + 3) )
            {
              LOBYTE(v8) = 0;
              VGDrvCommonCloseSession(a2, a3);
            }
            else
            {
              v8 = -2;
              v38 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
              if ( v38 )
                VBoxGuest_RTLogLoggerEx(
                  v38,
                  16,
                  32,
                  (unsigned int)"VBGL_IOCTL_IDC_DISCONNECT: In.pvSession=%p is not equal to pSession=%p!\n",
                  *((_QWORD *)a4 + 3),
                  a3);
            }
LABEL_102:
            a4[3] = v8;
            return 0;
          }
          if ( *(_QWORD *)(a3 + 24) != -1 )
            goto LABEL_111;
          if ( v8 != 24 || v9 != 40 )
            goto LABEL_108;
          *((_WORD *)a4 + 16) = *(_WORD *)(a2 + 4);
          v63 = *(_QWORD *)(a2 + 8);
          *((_WORD *)a4 + 18) = 0;
          *((_WORD *)a4 + 19) = 0;
          *((_QWORD *)a4 + 3) = v63;
          *((_WORD *)a4 + 17) = 0;
LABEL_58:
          a4[3] = 0;
          return 0;
        }
        if ( v8 != 36 || v9 != 24 )
          goto LABEL_108;
        v16 = vgdrvAcquireSessionCapabilities(a2, a3, a4[7], a4[8], a4[6], 0);
        if ( v16 >= 0 )
          goto LABEL_39;
        v64 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
        if ( !v64 )
          goto LABEL_39;
        v66 = v16;
        v67 = "VBGL_IOCTL_ACQUIRE_GUEST_CAPABILITIES failed rc=%Rrc\n";
LABEL_167:
        VBoxGuest_RTLogLoggerEx(v64, 16, 32, (_DWORD)v67, v66, v65);
        goto LABEL_39;
      }
      v27 = 3223082515LL;
      if ( a1 == 3223082515 )
      {
        if ( v8 != 28 || v9 != 24 )
          goto LABEL_108;
        dest[0] = 0;
        v8 = VbglR0GRAlloc(dest, 28, 218);
        if ( (v8 & 0x80000000) == 0 )
        {
          v62 = dest[0];
          *((_DWORD *)dest[0] + 5) = *(_DWORD *)(a3 + 16);
          v62[6] = a4[6];
          v8 = VbglR0GRPerform(v62);
          VbglR0GRFree(dest[0]);
        }
        goto LABEL_102;
      }
      if ( a1 <= 0xC01C5613 )
      {
        LOBYTE(v27) = 5;
        if ( a1 == v27 )
        {
          if ( v8 != 28 || v9 != 24 )
            goto LABEL_108;
          v71 = a4[6];
          VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a2 + 128));
          for ( k = 0; k != 64; ++k )
          {
            if ( v71 == *(_DWORD *)(a3 + 4 * (k + 8LL) + 8) )
            {
              v73 = a3 + 4LL * k;
              *(_DWORD *)(v73 + 40) = -1;
              VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a2 + 128));
              v16 = VbglR0HGCMInternalDisconnect(
                      v71,
                      *(unsigned int *)(a3 + 16),
                      vgdrvHgcmAsyncWaitCallback,
                      a2,
                      0xFFFFFFFFLL);
              VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a2 + 128));
              if ( *(_DWORD *)(v73 + 40) == -1 )
              {
                v96 = 0;
                if ( v16 < 0 )
                  v96 = v71;
                *(_DWORD *)(v73 + 40) = v96;
              }
              VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a2 + 128));
              goto LABEL_39;
            }
          }
          VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a2 + 128));
          v64 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
          if ( !v64 )
          {
            v16 = -4;
            goto LABEL_39;
          }
          v16 = -4;
          if ( (unsigned int)s_LogRelMaxIt_cLogged_9372 > 0x1F )
            goto LABEL_39;
          v66 = v71;
          v67 = "VBOXGUEST_IOCTL_HGCM_DISCONNECT: idClient=%RX32\n";
          ++s_LogRelMaxIt_cLogged_9372;
          goto LABEL_167;
        }
        LOBYTE(v27) = 15;
        if ( a1 != v27 )
        {
          if ( a1 == 3222820363 )
          {
            if ( v8 == 24 && v9 == 24 )
            {
              a4[3] = vgdrvIoCtl_CancelAllWaitEvents(a2, a3);
              return 0;
            }
            goto LABEL_108;
          }
          goto LABEL_90;
        }
        if ( v8 != 28 || v9 != 24 )
          goto LABEL_108;
        v70 = a4[6];
        v20 = -2;
        if ( (v70 & 0xFFFFFFEA) == 0 )
          v20 = vgdrvSetSessionMouseStatus(a2, a3, v70, ~v70, 0);
      }
      else
      {
        v28 = 3223344652LL;
        if ( a1 == 3223344652 )
        {
          if ( v8 != 32 || v9 != 24 )
            goto LABEL_108;
          v20 = -2;
          v69 = a4[6];
          if ( ((v69 | a4[7]) & 0xFFFFF800) == 0 )
            v20 = vgdrvSetSessionEventFilter(a2, a3, v69, a4[7], 0);
        }
        else
        {
          LOBYTE(v28) = 14;
          if ( a1 != v28 )
          {
            LOBYTE(v28) = 10;
            if ( a1 != v28 )
              goto LABEL_90;
            if ( v8 != 32 || v9 != 28 )
              goto LABEL_108;
            v32 = *(_QWORD *)(a3 + 24);
            v29 = a4[6];
            a4[6] = 0;
            v30 = a4[7];
            v150 = v32;
            if ( !_BitScanForward((unsigned int *)&v32, v30) )
              v33 = 0;
            else
              v33 = v32 + 1;
            if ( v33 - 1 < 0 )
            {
              v16 = -2;
              v64 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
              if ( !v64 )
                goto LABEL_39;
              v66 = v30;
              v67 = "VBOXGUEST_IOCTL_WAITEVENT: Invalid input mask %#x!!\n";
            }
            else
            {
              VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a2 + 24));
              v34 = a2;
              v35 = v30 & *(_DWORD *)(a2 + 120);
              if ( ((unsigned __int8)v30 & *(_BYTE *)(a2 + 120) & 0x24) != 0 )
              {
                AllowedEventMaskForSession = vgdrvGetAllowedEventMaskForSession(a2, a3);
                v34 = a2;
                v35 &= AllowedEventMaskForSession;
              }
              if ( v35 || *(_BYTE *)(a3 + 316) )
              {
                _InterlockedAnd((volatile signed __int32 *)(v34 + 120), ~v35);
                VBoxGuest_RTSpinlockRelease(*(_QWORD *)(v34 + 24));
                a4[6] = v35;
                *(_BYTE *)(a3 + 316) = 0;
                v16 = 0;
                goto LABEL_39;
              }
              v147 = v34;
              VBoxGuest_RTSpinlockRelease(*(_QWORD *)(v34 + 24));
              if ( !v29 )
                goto LABEL_287;
              v116 = vgdrvWaitAlloc((_QWORD *)v147, a3);
              v117 = v116;
              if ( !v116 )
              {
                v16 = -8;
                goto LABEL_39;
              }
              *(_DWORD *)(v116 + 16) = v30;
              VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(v147 + 24));
              v118 = v147;
              **(_QWORD **)(v147 + 64) = v117;
              *(_QWORD *)(v117 + 8) = *(_QWORD *)(v147 + 64);
              *(_QWORD *)v117 = v147 + 56;
              v119 = *(_DWORD *)(v147 + 120);
              *(_QWORD *)(v147 + 64) = v117;
              v120 = v30 & v119;
              if ( (v120 & 0x24) != 0 )
              {
                v124 = vgdrvGetAllowedEventMaskForSession(v147, a3);
                v118 = v147;
                v120 &= v124;
              }
              if ( v120 || *(_BYTE *)(a3 + 316) )
              {
                _InterlockedAnd((volatile signed __int32 *)(v118 + 120), ~v120);
                v148 = v118;
                VBoxGuest_RTSpinlockRelease(*(_QWORD *)(v118 + 24));
                a4[6] = v120;
                *(_BYTE *)(a3 + 316) = 0;
                v16 = 0;
                VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(v148 + 24));
                v121 = *(_QWORD *)v117;
                *(_DWORD *)(v117 + 16) = 0;
                v122 = *(_QWORD **)(v117 + 8);
                *(_DWORD *)(v117 + 20) = 0;
                *(_QWORD *)(v117 + 40) = 0;
                *v122 = v121;
                *(_QWORD *)(v121 + 8) = v122;
                *(_QWORD *)v117 = 0;
                *(_QWORD *)(v117 + 8) = 0;
                **(_QWORD **)(v148 + 112) = v117;
                *(_QWORD *)(v117 + 8) = *(_QWORD *)(v148 + 112);
                *(_QWORD *)v117 = v148 + 104;
                v123 = *(_QWORD *)(v148 + 24);
                *(_QWORD *)(v148 + 112) = v117;
                VBoxGuest_RTSpinlockRelease(v123);
                goto LABEL_39;
              }
              v149 = v118;
              VBoxGuest_RTSpinlockRelease(*(_QWORD *)(v118 + 24));
              if ( v150 == -1 )
                v125 = VBoxGuest_RTSemEventMultiWait(*(_QWORD *)(v117 + 24), v29);
              else
                v125 = VBoxGuest_RTSemEventMultiWaitNoResume(*(_QWORD *)(v117 + 24), v29);
              v126 = v125;
              v16 = -363;
              if ( v125 == -363 )
                goto LABEL_39;
              VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(v149 + 24));
              v127 = *(_QWORD *)v117;
              *(_DWORD *)(v117 + 16) = 0;
              v128 = *(_QWORD **)(v117 + 8);
              *(_QWORD *)(v117 + 40) = 0;
              v129 = *(_DWORD *)(v117 + 20);
              *(_DWORD *)(v117 + 20) = 0;
              *v128 = v127;
              *(_QWORD *)(v127 + 8) = v128;
              *(_QWORD *)v117 = 0;
              *(_QWORD *)(v117 + 8) = 0;
              **(_QWORD **)(v149 + 112) = v117;
              *(_QWORD *)(v117 + 8) = *(_QWORD *)(v149 + 112);
              *(_QWORD *)v117 = v149 + 104;
              v130 = *(_QWORD *)(v149 + 24);
              *(_QWORD *)(v149 + 112) = v117;
              VBoxGuest_RTSpinlockRelease(v130);
              if ( (unsigned int)(v129 - 1) <= 0xFFFFFFFD )
              {
                a4[6] = v129;
                v16 = 0;
                goto LABEL_39;
              }
              if ( v126 == -39 || v129 == -1 )
              {
                v16 = -39;
                goto LABEL_39;
              }
              if ( v126 == -40 )
              {
LABEL_287:
                v16 = -40;
                goto LABEL_39;
              }
              if ( v126 < 0 )
              {
                v16 = v126;
                goto LABEL_39;
              }
              v16 = -225;
              v64 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
              if ( !v64 || (unsigned int)s_LogRelMaxIt_cLogged_9212 > 0x1F )
                goto LABEL_39;
              v66 = v126;
              v67 = "VBOXGUEST_IOCTL_WAITEVENT: returns %Rrc but no events!\n";
              ++s_LogRelMaxIt_cLogged_9212;
            }
            goto LABEL_167;
          }
          if ( v8 != 32 || (v9 & 0xFFFFFFDF) != 0 )
            goto LABEL_108;
          v20 = -2;
          v68 = a4[6];
          if ( ((v68 | a4[7]) & 0xFFFFFFF8) == 0 )
            v20 = vgdrvSetSessionCapabilities(a2, a3, v68, a4[7], a4 + 6, a4 + 7, 0);
        }
      }
LABEL_46:
      a4[3] = v20;
      return 0;
    }
    if ( v8 != 24 || v9 != 32 )
      goto LABEL_108;
    v56 = VBoxGuest_RTSemFastMutexRequest(*(_QWORD *)(a2 + 160));
    if ( v56 < 0 )
    {
      v8 = v56;
      goto LABEL_102;
    }
    v57 = a2;
    v58 = *(_QWORD *)(a2 + 184);
    if ( a3 != v58 )
    {
      v8 = -10;
      if ( v58 )
      {
LABEL_141:
        VBoxGuest_RTSemFastMutexRelease(*(_QWORD *)(v57 + 160));
        goto LABEL_102;
      }
      *(_QWORD *)(a2 + 184) = a3;
    }
    v76 = VbglR0GRAlloc(&v152, 36, 111);
    v57 = a2;
    v8 = v76;
    if ( v76 < 0 )
      goto LABEL_141;
    v77 = v152;
    v78 = *(_DWORD *)(a3 + 16);
    *(_DWORD *)(v152 + 32) = 64;
    *(_DWORD *)(v77 + 20) = v78;
    v79 = VbglR0GRPerform(v77);
    v80 = a2;
    v8 = v79;
    if ( v79 < 0 )
    {
      v134 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
      v80 = a2;
      if ( v134 )
      {
        VBoxGuest_RTLogLoggerEx(
          v134,
          16,
          32,
          (unsigned int)"VBGL_IOCTL_CHECK_BALLOON: VbglR0GRPerform failed. rc=%Rrc\n",
          v8,
          v135);
        v81 = v152;
        v80 = a2;
      }
      else
      {
        v81 = v152;
      }
LABEL_210:
      v143 = v80;
      VbglR0GRFree(v81);
      v57 = v143;
      goto LABEL_141;
    }
    v81 = v152;
    *(_DWORD *)(a2 + 172) = *(_DWORD *)(v152 + 28);
    v82 = *(_DWORD *)(v81 + 24);
    *((_BYTE *)a4 + 28) = 0;
    *((_BYTE *)a4 + 29) = 0;
    *((_BYTE *)a4 + 30) = 0;
    *((_BYTE *)a4 + 31) = 0;
    a4[6] = v82;
    v83 = *(_DWORD *)(v81 + 24);
    if ( *(_BYTE *)(a2 + 176) )
    {
      v84 = *(unsigned int *)(a2 + 172);
      if ( v83 > (unsigned int)v84 )
      {
        v115 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
        v80 = a2;
        if ( v115 )
        {
          v8 = -2;
          VBoxGuest_RTLogLoggerEx(
            v115,
            16,
            32,
            (unsigned int)"vgdrvSetBalloonSizeKernel: illegal balloon size %u (max=%u)\n",
            v83,
            *(_DWORD *)(a2 + 172));
          v81 = v152;
          v80 = a2;
          goto LABEL_206;
        }
        v8 = -2;
      }
      else
      {
        if ( v83 == (_DWORD)v84 )
        {
          v8 = 0;
          goto LABEL_206;
        }
        if ( v83 > *(_DWORD *)(a2 + 168) && !*(_QWORD *)(a2 + 192) )
        {
          v136 = VBoxGuest_RTMemAllocZTag(
                   8 * v84,
                   "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/VBoxGuest.c");
          v80 = a2;
          *(_QWORD *)(a2 + 192) = v136;
          if ( !v136 )
          {
            v137 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
            v80 = a2;
            v8 = -8;
            if ( v137 )
            {
              VBoxGuest_RTLogLoggerEx(
                v137,
                16,
                32,
                (unsigned int)"vgdrvSetBalloonSizeKernel: no memory for paMemObj!\n",
                v138,
                v139);
              v81 = v152;
              v80 = a2;
            }
            else
            {
              v81 = v152;
            }
LABEL_206:
            if ( v8 == -73 || v8 == -8 )
            {
              v8 = 0;
            }
            else if ( v8 == -26 )
            {
              v8 = 0;
            }
            goto LABEL_210;
          }
        }
        v140 = v80;
        v85 = VbglR0GRAlloc(dest, 2080, 113);
        v80 = v140;
        v8 = v85;
        if ( v85 >= 0 )
        {
          v86 = *(_DWORD *)(v140 + 168);
          if ( v83 > v86 )
          {
            while ( 1 )
            {
              v144 = v80;
              v89 = VBoxGuest_RTR0MemObjAllocPhysNCTag(
                      *(_QWORD *)(v80 + 192) + 8LL * v86,
                      0x100000,
                      -1,
                      "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/VBoxGuest.c");
              v80 = v144;
              v8 = v89;
              if ( v89 < 0 )
                break;
              v90 = vgdrvBalloonInflate((_QWORD *)(*(_QWORD *)(v144 + 192) + 8LL * v86), (_DWORD *)dest[0]);
              v80 = v144;
              v8 = v90;
              if ( v90 < 0 )
              {
                VBoxGuest_RTR0MemObjFree(*(_QWORD *)(*(_QWORD *)(v144 + 192) + 8LL * v86), 1);
                v80 = v144;
                *(_QWORD *)(*(_QWORD *)(v144 + 192) + 8LL * v86) = 0;
                goto LABEL_204;
              }
              ++*(_DWORD *)(v144 + 168);
              if ( v83 <= ++v86 )
                goto LABEL_204;
            }
            if ( v89 == -37 )
            {
              *(_BYTE *)(v144 + 176) = 0;
              v8 = 0;
            }
          }
          else
          {
            v87 = v86 - 1;
            if ( v83 < v86 )
            {
              while ( 1 )
              {
                v141 = v80;
                v88 = vgdrvBalloonDeflate((_QWORD *)(*(_QWORD *)(v80 + 192) + 8LL * v87), (_DWORD *)dest[0]);
                v80 = v141;
                v8 = v88;
                if ( v88 < 0 )
                  break;
                --*(_DWORD *)(v141 + 168);
                if ( v83 >= v87 )
                  break;
                --v87;
              }
            }
          }
LABEL_204:
          v142 = v80;
          VbglR0GRFree(dest[0]);
          v81 = v152;
          v80 = v142;
          goto LABEL_205;
        }
      }
      v81 = v152;
      goto LABEL_206;
    }
    v8 = 0;
LABEL_205:
    *((_BYTE *)a4 + 28) = *(_BYTE *)(v80 + 176) ^ 1;
    goto LABEL_206;
  }
  if ( *(_QWORD *)(a3 + 24) != -1 )
    goto LABEL_111;
  if ( a5 <= 0x5F )
    goto LABEL_108;
  if ( *((_BYTE *)a4 + 28) )
  {
    v25 = -12;
  }
  else
  {
    __outdword(*(_WORD *)(a2 + 4), a4[6]);
    v25 = a4[16];
    if ( v25 == 2903 )
    {
      v40 = vgdrvHgcmAsyncWaitCallbackWorker((__int64)(a4 + 13), a2, 0, 0xFFFFFFFF);
      v25 = 0;
      v41 = v40;
      if ( (a4[19] & 1) == 0 )
      {
        VBoxGuest_RTAssertMsg1Weak(
          0,
          2888,
          "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/VBoxGuest.c",
          "vgdrvIoCtl_HGCMFastCall");
        VBoxGuest_RTAssertMsg2Weak((unsigned int)"rc=%Rrc\n", v41, v42, v43, v44, v45);
        VBoxGuest_RTAssertShouldPanic();
        __debugbreak();
      }
    }
  }
  a4[3] = v25;
  return 0;
}
