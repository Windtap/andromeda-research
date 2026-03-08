__int64 __fastcall VbglR0HGCMInternalCall(
        __int64 a1,
        unsigned int a2,
        int a3,
        int a4,
        __int64 (__fastcall *a5)(unsigned int *, __int64, _QWORD),
        __int64 a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        unsigned int a15)
{
  bool v15; // bl
  unsigned __int16 v16; // ax
  __int64 v17; // rbp
  int *v18; // r13
  bool v19; // bp
  int v20; // r15d
  __int64 v21; // rbx
  __int64 v22; // r14
  int v23; // eax
  unsigned __int64 v24; // rdx
  int v25; // ecx
  int v26; // eax
  __int64 v27; // r11
  __int64 v28; // rax
  __int64 v29; // rdi
  bool v30; // zf
  int v31; // r10d
  int v32; // edx
  int v33; // eax
  int v34; // r12d
  double v35; // xmm4_8
  double v36; // xmm5_8
  unsigned int *v37; // r13
  int v38; // eax
  __int64 v39; // rdx
  int v40; // esi
  int v41; // eax
  unsigned int v42; // eax
  unsigned int v43; // r14d
  __int64 v44; // rbx
  unsigned int *v45; // rbp
  unsigned int v46; // eax
  __int64 v47; // kr08_8
  unsigned int v48; // eax
  unsigned int v49; // edx
  unsigned int v50; // edx
  unsigned int v51; // edi
  __int64 v52; // rcx
  __int64 v53; // rsi
  int v54; // eax
  __int64 v55; // rsi
  int v56; // edi
  unsigned int v57; // eax
  __int64 v58; // rdx
  __int64 DefaultInstance; // rax
  __int64 result; // rax
  unsigned int j; // ebx
  __int64 v62; // rax
  int v63; // eax
  int v64; // ecx
  unsigned __int64 v65; // rdx
  __int64 v66; // rsi
  char *v67; // r13
  __int64 v68; // rax
  unsigned __int64 v69; // r12
  unsigned __int64 v70; // r12
  unsigned int v71; // eax
  int v72; // eax
  unsigned __int64 i; // rbx
  unsigned int *v74; // r13
  int v75; // eax
  unsigned int *v76; // r14
  __int64 v77; // rax
  int v78; // edx
  __int64 v79; // rax
  unsigned int v80; // r12d
  int v81; // r15d
  __int64 v82; // r13
  unsigned int v83; // r12d
  int v84; // eax
  unsigned int v85; // r13d
  char *v86; // rax
  char *v87; // rsi
  __int64 v88; // rdi
  int v89; // r10d
  __int16 v90; // ax
  __int64 k; // rax
  unsigned int v92; // eax
  unsigned int v93; // eax
  __int64 v94; // rdx
  __int64 v95; // rsi
  int v96; // eax
  unsigned int v97; // eax
  size_t v98; // rdx
  unsigned int v99; // esi
  unsigned int v100; // r10d
  __int64 v101; // rdi
  __int64 v102; // rsi
  size_t v103; // r10
  void *v104; // rdi
  __int64 v105; // rax
  void *v106; // rax
  int v107; // r14d
  int v108; // eax
  __int64 v109; // rdi
  bool v110; // cc
  __int64 v111; // rax
  __int64 v112; // rax
  int v113; // eax
  unsigned __int64 v114; // r15
  __int64 v115; // rax
  __int64 v116; // rax
  __int64 v118; // [rsp+10h] [rbp-198h]
  int v119; // [rsp+10h] [rbp-198h]
  int v120; // [rsp+10h] [rbp-198h]
  __int64 v121; // [rsp+10h] [rbp-198h]
  unsigned int v123; // [rsp+20h] [rbp-188h]
  unsigned __int64 v125; // [rsp+28h] [rbp-180h]
  unsigned int *v126; // [rsp+28h] [rbp-180h]
  unsigned __int64 v127; // [rsp+28h] [rbp-180h]
  unsigned int v128; // [rsp+30h] [rbp-178h]
  unsigned __int64 v129; // [rsp+30h] [rbp-178h]
  bool v130; // [rsp+38h] [rbp-170h]
  __int64 v131; // [rsp+38h] [rbp-170h]
  __int64 v132; // [rsp+40h] [rbp-168h]
  __int64 v133; // [rsp+40h] [rbp-168h]
  char v134; // [rsp+40h] [rbp-168h]
  unsigned int n; // [rsp+48h] [rbp-160h]
  size_t na; // [rsp+48h] [rbp-160h]
  size_t nc; // [rsp+48h] [rbp-160h]
  size_t nb; // [rsp+48h] [rbp-160h]
  __int64 v139; // [rsp+50h] [rbp-158h]
  int v140; // [rsp+50h] [rbp-158h]
  __int64 v141; // [rsp+50h] [rbp-158h]
  __int64 v142; // [rsp+50h] [rbp-158h]
  bool v143; // [rsp+50h] [rbp-158h]
  int v144; // [rsp+58h] [rbp-150h]
  __int64 v145; // [rsp+58h] [rbp-150h]
  unsigned int *v148; // [rsp+70h] [rbp-138h] BYREF
  __int64 v149[38]; // [rsp+78h] [rbp-130h] BYREF

  v15 = !(a3 & 1);
  v16 = *(_WORD *)(a1 + 38);
  if ( a1 && a5 && v16 <= 0x20u && (a3 & 0xFFFFFFFE) != 0 || a2 <= 0x27 && a2 < 16 * (unsigned __int64)v16 )
    return 4294967294LL;
  v17 = a1 + 40;
  if ( v16 )
  {
    v18 = (int *)(a1 + 40);
    v132 = a1 + 40;
    v123 = 0;
    v19 = !(a3 & 1);
    v20 = 0;
    v21 = 0;
    v125 = 16LL * v16;
    v22 = a1 + 16LL * ((unsigned int)v16 - 1) + 56;
    while ( 1 )
    {
      v23 = *v18;
      switch ( *v18 )
      {
        case 1:
        case 2:
          goto LABEL_18;
        case 4:
        case 5:
        case 6:
          goto LABEL_8;
        case 7:
        case 8:
        case 9:
          if ( v19 )
            goto LABEL_53;
          if ( (unk_320F4 & 1) != 0 )
          {
LABEL_8:
            v24 = (unsigned int)v18[1];
            if ( !(_DWORD)v24 )
              goto LABEL_18;
            if ( v23 == 8 || (v25 = 3, v23 == 5) )
              v25 = 1;
            if ( v123 > 9 )
            {
LABEL_53:
              v34 = -2;
              goto LABEL_54;
            }
            if ( v19 )
            {
              if ( (unsigned int)v24 > 0x1800000 )
              {
LABEL_63:
                v34 = -54;
                goto LABEL_54;
              }
              if ( (unsigned int)v24 > 0x7F0 )
              {
                v143 = v23 != 6 && v23 != 9;
                nb = (unsigned int)v24;
                v26 = VBoxGuest_RTR0MemObjAllocPageTag((unsigned __int64)v149, (unsigned int)v24, 0);
                if ( v26 < 0 )
                  goto LABEL_214;
                if ( v143 )
                {
                  v112 = VBoxGuest_RTR0MemObjAddress(v149[0]);
                  v113 = VBoxGuest_RTR0MemUserCopyFrom(v112, *((_QWORD *)v18 + 1), nb);
                  if ( v113 < 0 )
                  {
                    v34 = v113;
                    VBoxGuest_RTR0MemObjFree(v149[0], 0, a7, a8, a9, a10, a11, a12, a13, a14);
                    goto LABEL_54;
                  }
                  goto LABEL_15;
                }
                v106 = (void *)VBoxGuest_RTR0MemObjAddress(v149[0]);
                memset(v106, 0, nb);
                v27 = 0;
              }
              else
              {
                v140 = v25;
                na = (unsigned int)v24;
                if ( v23 != 6 && v23 != 9 )
                {
                  v62 = VBoxGuest_RTMemAllocTag((unsigned int)v24);
                  if ( !v62 )
                    goto LABEL_219;
                  v144 = v140;
                  v141 = v62;
                  v63 = VBoxGuest_RTR0MemUserCopyFrom(v62, *((_QWORD *)v18 + 1), na);
                  v27 = v141;
                  v64 = v144;
                  if ( v63 < 0 )
                  {
LABEL_71:
                    v119 = v63;
                    VBoxGuest_RTMemFree(v27);
                    v34 = v119;
                    goto LABEL_54;
                  }
                }
                else
                {
                  v27 = (__int64)VBoxGuest_RTMemAllocZTag((unsigned int)v24);
                  v64 = v140;
                  if ( !v27 )
                  {
LABEL_219:
                    v34 = -8;
LABEL_54:
                    DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(0x860010u);
                    if ( DefaultInstance )
                      VBoxGuest_RTLogLoggerEx(
                        DefaultInstance,
                        16,
                        0x86u,
                        "VbglR0HGCMInternalCall: vbglR0HGCMInternalPreprocessCall failed. rc=%Rrc\n",
                        a7,
                        a8,
                        a9,
                        a10,
                        v35,
                        v36,
                        a13,
                        a14,
                        (unsigned int)v34);
                    goto LABEL_56;
                  }
                }
                v65 = na;
                nc = v27;
                v63 = VBoxGuest_RTR0MemObjLockKernelTag((unsigned __int64)v149, v27, v65, v64);
                v27 = nc;
                if ( v63 < 0 )
                  goto LABEL_71;
              }
            }
            else
            {
              if ( (unsigned int)v24 > 0x1000000 )
                goto LABEL_63;
              v26 = VBoxGuest_RTR0MemObjLockKernelTag((unsigned __int64)v149, *((_QWORD *)v18 + 1), v24, v25);
              if ( v26 < 0 )
              {
LABEL_214:
                v34 = v26;
                goto LABEL_54;
              }
LABEL_15:
              v27 = 0;
            }
            v28 = v123;
            v29 = v149[0];
            ++v123;
            v28 *= 24;
            v30 = (unk_320F4 & 1) == 0;
            *(_DWORD *)((char *)&v149[2] + v28) = v20;
            *(__int64 *)((char *)&v149[3] + v28) = v29;
            *(__int64 *)((char *)&v149[4] + v28) = v27;
            if ( !v30 )
              v21 += 8 * ((unsigned __int64)VBoxGuest_RTR0MemObjSize(v29) >> 12) + 8;
            goto LABEL_18;
          }
          if ( (unsigned int)v18[1] > 0x1000000 )
            goto LABEL_63;
LABEL_18:
          v18 += 4;
          ++v20;
          if ( v18 == (int *)v22 )
          {
LABEL_19:
            v31 = v21;
            v15 = v19;
            v17 = v132;
            v32 = v31;
            v33 = *(unsigned __int16 *)(a1 + 38);
            goto LABEL_20;
          }
          break;
        case 10:
        case 12:
          if ( v19 )
            goto LABEL_53;
          v50 = v18[1];
          if ( !v50 )
            goto LABEL_18;
          v51 = v18[2];
          if ( v50 > 0x1000000 )
            goto LABEL_63;
          if ( v51 < v125 )
            goto LABEL_53;
          if ( v51 > (unsigned __int64)a2 - 16 )
            goto LABEL_53;
          v52 = a1 + v51;
          v53 = *(unsigned __int16 *)(v52 + 6);
          v54 = (unsigned __int16)v53;
          v55 = 8 * v53 + 8;
          if ( a2 < (unsigned int)v55 + v51 )
            goto LABEL_53;
          v56 = *(unsigned __int16 *)(v52 + 4);
          if ( (unsigned __int16)v56 > 0xFFFu
            || v54 != (v50 + v56 + 4095) >> 12
            || (*(_DWORD *)v52 & 3) == 0
            || (*(_DWORD *)v52 & 0xFFFFFFFC) != 0 )
          {
            goto LABEL_53;
          }
          v57 = v54 - 1;
          while ( v57 != -1 )
          {
            v58 = v57--;
            if ( (*(_QWORD *)(v52 + 8 * v58 + 8) & 0xFFF0000000000FFFLL) != 0 )
              goto LABEL_53;
          }
          v18 += 4;
          v21 += v55;
          ++v20;
          if ( v18 == (int *)v22 )
            goto LABEL_19;
          continue;
        case 11:
          if ( v19 )
            goto LABEL_53;
          v48 = v18[2];
          if ( !v48 )
            goto LABEL_18;
          v49 = (unsigned int)v18[1] >> 8;
          if ( v48 > (unsigned int)&loc_10000
            || v48 > a2 - v125
            || v125 > v49
            || v49 > a2 - v48
            || (v18[1] & 3) == 0
            || (v18[1] & 0xFC) != 0 )
          {
            goto LABEL_53;
          }
          v18 += 4;
          ++v20;
          v21 += (v48 + 7) & 0xFFFFFFF8;
          if ( v18 == (int *)v22 )
            goto LABEL_19;
          continue;
        default:
          goto LABEL_53;
      }
    }
  }
  v32 = 0;
  v33 = 0;
  v123 = 0;
LABEL_20:
  n = v32 + 16 * v33 + 44;
  v34 = VbglR0GRAlloc(&v148, n, 63, a7, a8, a9, a10, a11, a12, a13, a14);
  if ( v34 < 0 )
    goto LABEL_56;
  v126 = v148;
  v37 = v148 + 11;
  v38 = *(unsigned __int16 *)(a1 + 38);
  v39 = (unsigned __int16)v38;
  v40 = 16 * v38 + 44;
  v41 = a4;
  if ( v15 && (a4 & 8) == 0 )
    v41 = 8;
  v148[5] = v41;
  v126[6] = 0;
  v126[7] = 0;
  v126[8] = *(_DWORD *)(a1 + 24);
  v42 = *(_DWORD *)(a1 + 28);
  v126[10] = v39;
  v126[9] = v42;
  if ( !(_DWORD)v39 )
  {
    v74 = v126;
    goto LABEL_91;
  }
  v130 = v15;
  v43 = v40;
  v139 = v17;
  v44 = v17;
  v128 = 0;
  v45 = v37;
  v118 = a1 + 16LL * (unsigned int)(v39 - 1) + 56;
  while ( 2 )
  {
    v46 = *(_DWORD *)v44;
LABEL_27:
    v47 = v39;
    v39 = v46;
    switch ( v46 )
    {
      case 1u:
      case 2u:
        *(_QWORD *)v45 = *(_QWORD *)v44;
        *((_QWORD *)v45 + 1) = *(_QWORD *)(v44 + 8);
        goto LABEL_97;
      case 4u:
      case 5u:
      case 6u:
        goto LABEL_75;
      case 7u:
      case 8u:
      case 9u:
        if ( (unk_320F4 & 1) != 0 )
        {
LABEL_75:
          if ( !*(_DWORD *)(v44 + 4) )
          {
            v39 = 5;
            if ( v46 != 8 )
            {
              LOBYTE(v39) = 6;
              if ( v46 != 9 )
              {
                LOBYTE(v39) = 4;
                if ( v46 != 7 )
                  v39 = v46;
              }
            }
            *v45 = v39;
            v45[1] = 0;
            *((_QWORD *)v45 + 1) = 0;
            goto LABEL_97;
          }
          v66 = v149[3 * v128 + 4];
          v133 = v149[3 * v128 + 3];
          if ( (unk_320F4 & 1) == 0 )
          {
            v39 = 5;
            if ( v46 != 8 )
            {
              LOBYTE(v39) = 6;
              if ( v46 != 9 )
              {
                LOBYTE(v39) = 4;
                if ( v46 != 7 )
                  v39 = v46;
              }
            }
            *v45 = v39;
            v45[1] = *(_DWORD *)(v44 + 4);
            if ( v130 )
            {
              v105 = v66;
              if ( !v66 )
                v105 = VBoxGuest_RTR0MemObjAddress(v133);
            }
            else
            {
              v105 = *(_QWORD *)(v44 + 8);
            }
            *((_QWORD *)v45 + 1) = v105;
            goto LABEL_89;
          }
          v67 = (char *)v126 + v43;
          v68 = VBoxGuest_RTR0MemObjSize(v149[3 * v128 + 3]);
          *v45 = 10;
          v69 = v68;
          LODWORD(v68) = *(_DWORD *)(v44 + 4);
          v45[2] = v43;
          v70 = v69 >> 12;
          v45[1] = v68;
          v71 = *(_DWORD *)v44;
          if ( *(_DWORD *)v44 != 6 )
          {
            if ( v71 <= 6 )
            {
              if ( v71 == 5 )
              {
LABEL_168:
                v72 = 1;
                goto LABEL_82;
              }
LABEL_167:
              v72 = 3;
              goto LABEL_82;
            }
            if ( v71 == 8 )
              goto LABEL_168;
            if ( v71 != 9 )
              goto LABEL_167;
          }
          v72 = 2;
LABEL_82:
          *(_DWORD *)v67 = v72;
          if ( v130 )
            *((_WORD *)v67 + 2) = v66 & 0xFFF;
          else
            *((_WORD *)v67 + 2) = *(_WORD *)(v44 + 8) & 0xFFF;
          *((_WORD *)v67 + 3) = v70;
          if ( v70 )
          {
            v145 = v44;
            for ( i = 0; i != v70; ++i )
              *(_QWORD *)&v67[8 * i + 8] = VBoxGuest_RTR0MemObjGetPagePhysAddr(v133, i);
            v44 = v145;
          }
          v43 += 8 * v70 + 8;
LABEL_89:
          ++v128;
          v44 += 16;
          v45 += 4;
          if ( v44 == v118 )
            goto LABEL_90;
          continue;
        }
        v39 = 5;
        *(_QWORD *)v45 = *(_QWORD *)v44;
        *((_QWORD *)v45 + 1) = *(_QWORD *)(v44 + 8);
        v92 = *(_DWORD *)v44;
        if ( *(_DWORD *)v44 != 8 )
        {
          LOBYTE(v39) = 6;
          if ( v92 != 9 )
          {
            LOBYTE(v39) = 4;
            if ( v92 != 7 )
              v39 = v92;
          }
        }
        *v45 = v39;
LABEL_97:
        while ( 1 )
        {
          v44 += 16;
          v45 += 4;
          if ( v44 == v118 )
            break;
          v46 = *(_DWORD *)v44;
          if ( *(_DWORD *)v44 <= 0xCu )
            goto LABEL_27;
LABEL_99:
          *v45 = 0;
        }
LABEL_90:
        v15 = v130;
        v17 = v139;
        v74 = v148;
LABEL_91:
        v75 = VbglR0GRPerform((__int64)v74);
        v34 = v75;
        if ( v75 < 0 )
        {
          v134 = 0;
          if ( v75 == v74[7] )
            v34 = 0;
        }
        else
        {
          v134 = 0;
          if ( v75 != 2903 )
          {
LABEL_93:
            v131 = (__int64)v148;
            v76 = v148 + 11;
            v77 = *(unsigned __int16 *)(a1 + 38);
            v78 = (unsigned __int16)v77;
            *(_DWORD *)(a1 + 12) = v148[7];
            if ( (_WORD)v77 )
            {
              v79 = 16 * v77;
              v120 = v34;
              v80 = 0;
              v129 = v79 + 44;
              v81 = 0;
              v127 = v79 + 40;
              v82 = a1 + 16LL * (unsigned int)(v78 - 1) + 56;
              while ( 2 )
              {
                switch ( *(_DWORD *)v17 )
                {
                  case 1:
                  case 2:
                    *(_QWORD *)v17 = *(_QWORD *)v76;
                    *(_QWORD *)(v17 + 8) = *((_QWORD *)v76 + 1);
                    goto LABEL_119;
                  case 4:
                  case 6:
                    goto LABEL_124;
                  case 5:
                  case 8:
                    if ( v15 && v123 > v80 )
                      v80 += LODWORD(v149[3 * v80 + 2]) == v81;
                    goto LABEL_118;
                  case 7:
                  case 9:
                    if ( (unk_320F4 & 1) == 0 )
                      goto LABEL_118;
LABEL_124:
                    v93 = v76[1];
                    if ( !v15 )
                      goto LABEL_132;
                    LODWORD(v94) = v76[1];
                    if ( *(_DWORD *)(v17 + 4) <= v93 )
                      LODWORD(v94) = *(_DWORD *)(v17 + 4);
                    v94 = (unsigned int)v94;
                    if ( (_DWORD)v94 )
                    {
                      v95 = v149[3 * v80 + 4];
                      if ( !v95 )
                      {
                        v142 = (unsigned int)v94;
                        v95 = VBoxGuest_RTR0MemObjAddress(v149[3 * v80 + 3]);
                        v94 = v142;
                      }
                      v96 = VBoxGuest_RTR0MemUserCopyTo(*(_QWORD *)(v17 + 8), v95, v94);
                      if ( v96 < 0 )
                      {
                        v34 = v96;
                        goto LABEL_121;
                      }
                      v93 = v76[1];
                      ++v80;
                    }
                    else if ( v123 > v80 )
                    {
                      v80 += v81 == LODWORD(v149[3 * v80 + 2]);
                    }
LABEL_132:
                    *(_DWORD *)(v17 + 4) = v93;
                    goto LABEL_119;
                  case 0xA:
                  case 0xC:
LABEL_118:
                    *(_DWORD *)(v17 + 4) = v76[1];
                    goto LABEL_119;
                  case 0xB:
                    v97 = v76[2];
                    v98 = *(unsigned int *)(v17 + 8);
                    *(_DWORD *)(v17 + 8) = v97;
                    if ( !v97 || (*(_BYTE *)(v17 + 4) & 2) == 0 )
                      goto LABEL_119;
                    v99 = *(_DWORD *)(v17 + 4) >> 8;
                    v100 = v76[1] >> 8;
                    if ( a2 <= v99 )
                      goto LABEL_212;
                    v101 = v99;
                    if ( v99 < v127 )
                      goto LABEL_212;
                    if ( (unsigned int)v98 > a2 - v99 )
                      goto LABEL_212;
                    if ( a2 <= v100 )
                      goto LABEL_212;
                    v102 = v100;
                    if ( v100 < v129 )
                      goto LABEL_212;
                    v103 = n - v100;
                    if ( v97 <= (unsigned int)v103 )
                    {
                      v103 = v97;
                    }
                    else if ( v120 >= 0 )
                    {
LABEL_212:
                      v34 = -226;
                      goto LABEL_121;
                    }
                    v104 = (void *)(a1 + v101);
                    if ( (unsigned int)v103 <= (unsigned int)v98 )
                      v98 = v103;
                    memcpy(v104, (const void *)(v131 + v102), v98);
LABEL_119:
                    v17 += 16;
                    ++v81;
                    v76 += 4;
                    if ( v17 != v82 )
                      continue;
                    v34 = v120;
                    break;
                  default:
                    v120 = -228;
                    goto LABEL_119;
                }
                break;
              }
            }
            goto LABEL_121;
          }
          v34 = a5(v74, a6, a15);
          if ( (v74[6] & 1) != 0 )
          {
            v34 = 0;
            goto LABEL_93;
          }
          v107 = VbglR0GRAlloc(v149, 0x1Cu, 65, a7, a8, a9, a10, v35, v36, a13, a14);
          if ( v107 >= 0 )
          {
            v108 = 0;
            v109 = v149[0];
            if ( v74 && v74 != (unsigned int *)&loc_28 && (*(_BYTE *)(v74 - 8) & 1) != 0 )
              v108 = *(_DWORD *)(*((_QWORD *)v74 - 1) + 8LL) + (_DWORD)v74 - *((_QWORD *)v74 - 1);
            *(_DWORD *)(v149[0] + 24) = v108;
            v107 = VbglR0GRPerform(v109);
            VbglR0GRFree(v149[0]);
          }
          if ( v107 == -12 )
          {
            v74[6] |= 2u;
            v74[2] = 64;
            v107 = VbglR0GRPerform((__int64)v74);
            if ( v107 == -2 )
            {
              v107 = -78;
              goto LABEL_182;
            }
            if ( v34 >= 0 )
            {
              v34 = -39;
              VBoxGuest_RTThreadSleep(1);
            }
          }
          else
          {
LABEL_182:
            if ( v34 >= 0 )
              v34 = -39;
          }
          if ( v107 < 0 )
          {
            v121 = VBoxGuest_RTTimeSystemMilliTS();
            if ( v107 == -363 || (v114 = 2000, v107 == -78) )
              v114 = 500;
            if ( v107 != -78 )
            {
              v110 = (unsigned int)s_cErrors_22165++ <= 0x1F;
              if ( v110 )
              {
                v115 = VBoxGuest_RTLogRelGetDefaultInstanceEx(0x860010u);
                if ( v115 )
                  VBoxGuest_RTLogLoggerEx(
                    v115,
                    16,
                    0x86u,
                    "vbglR0HGCMInternalDoCall: Failed to cancel the HGCM call on %Rrc: rc2=%Rrc\n",
                    a7,
                    a8,
                    a9,
                    a10,
                    v35,
                    v36,
                    a13,
                    a14,
                    (unsigned int)v34,
                    (unsigned int)v107);
              }
            }
            do
            {
              if ( (v74[6] & 1) != 0 )
                break;
              VBoxGuest_RTThreadSleep(1);
            }
            while ( VBoxGuest_RTTimeSystemMilliTS() - v121 < v114 );
            if ( (v74[6] & 1) != 0 )
            {
              v134 = 0;
              v34 = 0;
              goto LABEL_93;
            }
            v116 = VBoxGuest_RTLogRelGetDefaultInstanceEx(0x860010u);
            v134 = 1;
            if ( v116 )
              VBoxGuest_RTLogLoggerEx(
                v116,
                16,
                0x86u,
                "vbglR0HGCMInternalDoCall: Leaking %u bytes. Pending call to %u with %u parms. (rc2=%Rrc)\n",
                a7,
                a8,
                a9,
                a10,
                v35,
                v36,
                a13,
                a14,
                *v74,
                v74[9],
                v74[10],
                v107);
          }
          else
          {
            v74[6] |= 2u;
            v134 = 0;
          }
        }
        if ( v34 >= 0 )
          goto LABEL_93;
        if ( (unsigned int)(v34 + 40) > 1 )
        {
          v110 = (unsigned int)s_cErrors_22222++ <= 0x1F;
          if ( v110 )
          {
            v111 = VBoxGuest_RTLogRelGetDefaultInstanceEx(0x860010u);
            if ( v111 )
              VBoxGuest_RTLogLoggerEx(
                v111,
                16,
                0x86u,
                "VbglR0HGCMInternalCall: vbglR0HGCMInternalDoCall failed. rc=%Rrc\n",
                a7,
                a8,
                a9,
                a10,
                v35,
                v36,
                a13,
                a14,
                (unsigned int)v34);
          }
        }
LABEL_121:
        if ( !v134 )
          VbglR0GRFree((__int64)v148);
LABEL_56:
        result = (unsigned int)v34;
        if ( v123 )
        {
          for ( j = v123 - 1; ; --j )
          {
            VBoxGuest_RTR0MemObjFree(v149[3 * j + 3], 0, a7, a8, a9, a10, v35, v36, a13, a14);
            VBoxGuest_RTMemFree(v149[3 * j + 4]);
            if ( !j )
              break;
          }
          return (unsigned int)v34;
        }
        return result;
      case 0xAu:
      case 0xCu:
        *v45 = v46;
        v45[1] = *(_DWORD *)(v44 + 4);
        if ( *(_DWORD *)(v44 + 4) )
        {
          v87 = (char *)v126 + v43;
          v88 = a1 + *(unsigned int *)(v44 + 8);
          v89 = *(unsigned __int16 *)(v88 + 6);
          v45[2] = v43;
          *(_DWORD *)v87 = *(_DWORD *)v88;
          v90 = *(_WORD *)(v88 + 4);
          *((_WORD *)v87 + 3) = v89;
          *((_WORD *)v87 + 2) = v90;
          for ( k = 0; (unsigned __int16)v89 > (unsigned int)k; *(_QWORD *)&v87[8 * k++ + 8] = v39 )
            v39 = *(_QWORD *)(v88 + 8 * k + 8);
          v43 += 8 * v89 + 8;
        }
        else
        {
          v45[2] = 0;
        }
        goto LABEL_97;
      case 0xBu:
        v83 = *(_DWORD *)(v44 + 8);
        *v45 = 11;
        v84 = *((unsigned __int8 *)v45 + 4);
        v39 = v43 << 8;
        v45[2] = v83;
        v45[1] = v39 | v84;
        if ( v83 )
        {
          if ( (*(_BYTE *)(v44 + 4) & 1) != 0 )
          {
            v85 = (v83 + 7) & 0xFFFFFFF8;
            v86 = (char *)memcpy((char *)v126 + v43, (const void *)((*(_DWORD *)(v44 + 4) >> 8) + a1), v83);
            if ( v83 != v85 )
              memset(&v86[v83], 0, v85 - v83);
          }
          else
          {
            v85 = (v83 + 7) & 0xFFFFFFF8;
            memset((char *)v126 + v43, 0, v85);
          }
          v43 += v85;
        }
        goto LABEL_97;
      default:
        v39 = v47;
        goto LABEL_99;
    }
  }
}
