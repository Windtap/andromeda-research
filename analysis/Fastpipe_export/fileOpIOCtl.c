__int64 __fastcall fileOpIOCtl(const void **a1, unsigned int a2, __int64 a3)
{
  const void **v3; // r12
  __int64 v4; // rbp
  __int64 v5; // rbx
  int v6; // edx
  int v8; // edx
  _DWORD *v9; // rax
  int v10; // ebx
  const char *v11; // rsi
  int v12; // ebp
  __int64 v13; // rcx
  _DWORD *v14; // r14
  signed int v15; // ebp
  unsigned int v16; // r13d
  __int64 v17; // rax
  __int64 v18; // rdx
  __int64 v19; // rbx
  unsigned __int64 v20; // r14
  int v21; // edx
  _DWORD *v22; // rbp
  int v23; // ebx
  int v24; // edx
  int v25; // edx
  _DWORD *v26; // r13
  int v27; // r14d
  __int64 v28; // rdx
  int v29; // r13d
  __int64 v30; // rbx
  __int64 v31; // rdx
  int v32; // edx
  _DWORD *v33; // rax
  int v34; // ebp
  __int64 v35; // rax
  _DWORD *v36; // rbx
  int v37; // edx
  int v38; // ebp
  const void *v39; // rcx
  unsigned __int64 v40; // rax
  unsigned __int64 v41; // rax
  int v42; // ebx
  int v43; // r13d
  int v44; // r15d
  __int64 v45; // rdx
  __int64 v46; // rsi
  int v47; // ebp
  __int64 v48; // r9
  __int64 v49; // rdx
  __int64 v50; // rsi
  int v51; // eax
  __int64 v52; // r15
  __int64 v53; // r14
  int v54; // r15d
  __int64 v55; // rdi
  _DWORD *v56; // rax
  int v57; // ebx
  __int64 v58; // rax
  _DWORD *v59; // rbx
  signed int v60; // r10d
  __int64 v61; // r13
  int v62; // edi
  int v63; // ebx
  __int64 v64; // rsi
  int i; // eax
  _DWORD *v66; // rax
  int v67; // r14d
  int v68; // ebp
  int v69; // r15d
  __int64 v70; // rbx
  __int64 v71; // rdx
  __int64 v72; // rsi
  int v73; // r12d
  __int64 v74; // r8
  __int64 v75; // rdx
  __int64 v76; // rsi
  int v77; // eax
  __int64 v78; // r15
  __int64 v79; // rbx
  const void *v80; // rdx
  unsigned __int64 v81; // rax
  int v82; // ecx
  int v83; // ecx
  signed int v84; // r14d
  int v85; // r11d
  __int64 v86; // rax
  int v87; // r10d
  __int64 v88; // rdx
  __int64 v89; // rcx
  int v90; // eax
  unsigned __int64 v91; // rax
  const void *v92; // rcx
  unsigned __int64 v93; // rax
  const void *v94; // rcx
  unsigned __int64 v95; // rax
  const void *v96; // rcx
  unsigned __int64 v97; // rax
  unsigned __int64 v98; // rax
  int v99; // esi
  unsigned __int64 v100; // rax
  unsigned __int64 v101; // rax
  unsigned __int64 v102; // rax
  const void *v103; // rcx
  unsigned __int64 v104; // rax
  unsigned __int64 v105; // rax
  unsigned __int64 v106; // rdx
  unsigned __int32 v107; // [rsp+10h] [rbp-B8h]
  unsigned __int64 v108; // [rsp+10h] [rbp-B8h]
  __int64 v109; // [rsp+18h] [rbp-B0h]
  __int64 v110; // [rsp+20h] [rbp-A8h]
  signed int v111; // [rsp+20h] [rbp-A8h]
  int v112; // [rsp+2Ch] [rbp-9Ch]
  __int64 v113; // [rsp+34h] [rbp-94h] BYREF
  int v114; // [rsp+3Ch] [rbp-8Ch]
  __int64 v115; // [rsp+40h] [rbp-88h] BYREF
  _BYTE v116[12]; // [rsp+48h] [rbp-80h]
  char dest[64]; // [rsp+54h] [rbp-74h] BYREF
  int v118; // [rsp+94h] [rbp-34h]

  v3 = a1;
  v4 = a3;
  if ( a2 == -2147194775 )
  {
    _get_user_4();
    v26 = a1[26];
    v27 = v25;
    if ( !v26 )
    {
      printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", "ioCtrlRequestRingBuffer", "pPipeData != NULL");
      dump_stack();
      if ( (unsigned int)(v27 - 1) <= 0x3FE )
        return -1;
      goto LABEL_114;
    }
    if ( (unsigned int)(v25 - 1) > 0x3FE )
      goto LABEL_114;
    if ( *v26 == 1 )
    {
      v28 = g_pPipeMem;
      if ( *(_DWORD *)(g_pPipeMem + 48LL * v27 + 36) )
      {
        printk(
          "fastpipe: assert!!!!!!!!!!!! [%s] %s\n",
          "ioCtrlRequestRingBuffer",
          "g_pPipeMem->arPipe[nPipeId].requestRingBufResultReady == 0");
        dump_stack();
        v28 = g_pPipeMem;
      }
      *(_DWORD *)(48LL * v27 + v28 + 36) = 0;
      __outdword(g_IOPortBase, ((v27 & 0xFFF) << 8) | 5);
      v29 = v26[4];
      my_wait_event_constprop_6(v27, v29, (__int64 (__fastcall *)(_QWORD))my_condition_ring_buffer);
      v30 = g_pPipeMem + 48LL * v27;
      if ( v29 == *(_DWORD *)(v30 + 44) )
      {
        if ( *(_DWORD *)(v30 + 40) == 1 )
        {
          v31 = g_pPipeMem;
          v5 = 0;
        }
        else
        {
          v5 = 0;
          printk(
            "fastpipe: assert!!!!!!!!!!!! [%s] %s\n",
            "ioCtrlRequestRingBuffer",
            "g_pPipeMem->arPipe[nPipeId].state == eUsing");
          dump_stack();
          v31 = g_pPipeMem;
        }
      }
      else
      {
        v104 = __readgsqword((unsigned int)&current_task);
        v5 = -1;
        printk(
          "fastpipe: ioCtrlRequestRingBuffer: pipe closed: pFilp=%p pSession=%p pid=%d %s\n",
          a1,
          a1[26],
          *(_DWORD *)(v104 + 1936),
          (const char *)(v104 + 2368));
        v31 = g_pPipeMem;
      }
      *(_DWORD *)(v31 + 48LL * v27 + 36) = 0;
      return v5;
    }
    return -1;
  }
  if ( a2 <= 0x80046869 )
  {
    if ( a2 != -2147194778 )
    {
      if ( a2 > 0x80046866 )
      {
        if ( a2 == -2147194777 )
        {
          _get_user_4();
          if ( (unsigned int)(v24 - 1) <= 0x3FE )
          {
            __outdword(g_IOPortBase, ((v24 & 0xFFF) << 8) | 3);
            return 0;
          }
        }
        else
        {
          _get_user_4();
          if ( (unsigned int)(v6 - 1) <= 0x3FE )
          {
            __outdword(g_IOPortBase, ((v6 & 0xFFF) << 8) | 4);
            return 0;
          }
        }
        goto LABEL_114;
      }
      if ( a2 == 26730 )
      {
        __outdword(g_IOPortBase, 6u);
        return 0;
      }
      if ( a2 != -2147194779 )
        goto LABEL_8;
      _get_user_4();
      v9 = a1[26];
      v10 = v8;
      v11 = "ioCtrlWaitRecvEnable";
      if ( v9 )
      {
        if ( (unsigned int)(v8 - 1) <= 0x3FE )
        {
          if ( *v9 == 1 )
          {
            v12 = v9[4];
            my_wait_event_constprop_6(v8, v12, (__int64 (__fastcall *)(_QWORD))my_condition_recv_enable);
            v13 = g_pPipeMem + 48LL * v10;
            if ( v12 == *(_DWORD *)(v13 + 44) )
            {
              v5 = 0;
              if ( *(_DWORD *)(v13 + 40) != 1 )
              {
                printk(
                  "fastpipe: assert!!!!!!!!!!!! [%s] %s\n",
                  "ioCtrlWaitRecvEnable",
                  "g_pPipeMem->arPipe[nPipeId].state == eUsing");
                dump_stack();
              }
            }
            else
            {
              v101 = __readgsqword((unsigned int)&current_task);
              v5 = -1;
              printk(
                "fastpipe: ioCtrlWaitRecvEnable: pipe closed: pFilp=%p pSession=%p pid=%d %s\n",
                a1,
                a1[26],
                *(_DWORD *)(v101 + 1936),
                (const char *)(v101 + 2368));
            }
            return v5;
          }
          return -1;
        }
LABEL_114:
        printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", "checkValid", "nPipeId > 0 && nPipeId < MAX_PIPE_COUNT");
        dump_stack();
        return -1;
      }
LABEL_163:
      printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", v11, "pPipeData != NULL");
      dump_stack();
      if ( (unsigned int)(v10 - 1) <= 0x3FE )
        return -1;
      goto LABEL_114;
    }
    _get_user_4();
    v33 = a1[26];
    v10 = v32;
    if ( !v33 )
    {
      v11 = "ioCtrlWaitSendEnable";
      goto LABEL_163;
    }
    if ( (unsigned int)(v32 - 1) > 0x3FE )
      goto LABEL_114;
    if ( *v33 == 1 )
    {
      v34 = v33[4];
      my_wait_event_constprop_6(v32, v34, (__int64 (__fastcall *)(_QWORD))my_condition_send_enable);
      v35 = g_pPipeMem + 48LL * v10;
      if ( v34 == *(_DWORD *)(v35 + 44) )
      {
        v5 = 0;
        if ( *(_DWORD *)(v35 + 40) != 1 )
        {
          printk(
            "fastpipe: assert!!!!!!!!!!!! [%s] %s\n",
            "ioCtrlWaitSendEnable",
            "g_pPipeMem->arPipe[nPipeId].state == eUsing");
          dump_stack();
        }
      }
      else
      {
        v102 = __readgsqword((unsigned int)&current_task);
        v5 = -1;
        printk(
          "fastpipe: ioCtrlWaitSendEnable: pipe closed: pFilp=%p pSession=%p pid=%d %s\n",
          a1,
          a1[26],
          *(_DWORD *)(v102 + 1936),
          (const char *)(v102 + 2368));
      }
      return v5;
    }
    return -1;
  }
  if ( a2 == -2146932627 )
  {
    v115 = 0;
    copy_from_user(&v115, a3, 8);
    v14 = a1[26];
    if ( v14 )
    {
      if ( *v14 == 1 )
      {
        v15 = (unsigned __int8)v115;
        v16 = (unsigned __int8)v115 + BYTE1(v115);
        if ( v16 > 8 )
        {
          v106 = __readgsqword((unsigned int)&current_task);
          v5 = 0;
          printk(
            "fastpipe: ioCtrlFreeFixDma u64DmaId invalid! 0x%llx pFilp=%p pSession=%p pid=%d %s\n",
            v115,
            a1,
            a1[26],
            *(_DWORD *)(v106 + 1936),
            (const char *)(v106 + 2368));
          return v5;
        }
        if ( (unsigned __int8)v115 < v16 )
        {
          do
          {
            v17 = g_pPipeMem;
            if ( *(int *)(g_pPipeMem + 8 * (v15 + 22572LL) + 8) <= 0 )
            {
              printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", "ioCtrlFreeFixDma", "g_pPipeMem->block[i].nOwnerId > 0");
              dump_stack();
              v17 = g_pPipeMem;
            }
            if ( *(_DWORD *)(v17 + 8 * (v15 + 22572LL) + 8) != v14[2] )
            {
              printk(
                "fastpipe: assert!!!!!!!!!!!! [%s] %s\n",
                "ioCtrlFreeFixDma",
                "g_pPipeMem->block[i].nOwnerId == pPipeData->fast.nReadPipeId");
              dump_stack();
              v17 = g_pPipeMem;
            }
            v18 = v17 + 8LL * v15;
            if ( *(int *)(v18 + 180584) > 0 && *(_DWORD *)(v18 + 180584) == v14[2] )
              _InterlockedExchange((volatile __int32 *)(v17 + 8LL * v15 + 180584), 0);
            ++v15;
          }
          while ( v15 < v16 );
        }
        return 0;
      }
    }
    else
    {
      printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", "ioCtrlFreeFixDma", "pPipeData != NULL");
      dump_stack();
    }
    v97 = __readgsqword((unsigned int)&current_task);
    v5 = -1;
    printk(
      "fastpipe: ioCtrlFreeFixDma type error: u64DmaId=0x%llx pFilp=%p pSession=%p pid=%d %s\n",
      v115,
      a1,
      v14,
      *(_DWORD *)(v97 + 1936),
      (const char *)(v97 + 2368));
    return v5;
  }
  if ( a2 <= 0x8008686D )
  {
    if ( a2 != -2147194773 )
    {
      if ( a2 != -2147194769 )
        goto LABEL_8;
      _get_user_4();
      v22 = a1[26];
      v23 = v21;
      if ( v22 )
      {
        if ( *v22 == 3 )
        {
          if ( v21 == -1 )
          {
            v100 = __readgsqword((unsigned int)&current_task);
            v5 = -1;
            printk(
              "fastpipe: ioCtrlAllocBlob uBlobId invalid: pFilp=%p pSession=%p pid=%d %s\n",
              a1,
              a1[26],
              *(_DWORD *)(v100 + 1936),
              (const char *)(v100 + 2368));
          }
          else
          {
            LODWORD(v115) = v21;
            v5 = 0;
            sendSerialCallToHost(1002, &v115, 4, 0, 0, 0);
          }
          return v5;
        }
      }
      else
      {
        printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", "ioCtrlFreeDyncBlob", "pPipeData != NULL");
        dump_stack();
      }
      v98 = __readgsqword((unsigned int)&current_task);
      v99 = v23;
      v5 = -1;
      printk(
        "fastpipe: ioCtrlFreeDyncBlob type error: uBlobId=%u pFilp=%p pSession=%p pid=%d %s\n",
        v99,
        a1,
        v22,
        *(_DWORD *)(v98 + 1936),
        (const char *)(v98 + 2368));
      return v5;
    }
    _get_user_4();
    v36 = a1[26];
    v38 = v37;
    if ( v36 )
    {
      printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", "ioCtrlHostRefCountBind", "pPipeData == NULL");
      dump_stack();
    }
    else
    {
      v66 = (_DWORD *)kmem_cache_alloc_trace(kmalloc_caches[5], 37781696, 24);
      *v66 = 2;
      v36 = v66;
      a1[26] = v66;
    }
    if ( *v36 == 2 )
    {
      v36[2] = v38;
      v39 = v36;
      v40 = __readgsqword((unsigned int)&current_task);
      v5 = 0;
      printk(
        "fastpipe: refcount bind: host-handle=%u pFilp=%p pSession=%p pid=%d %s\n",
        v38,
        a1,
        v39,
        *(_DWORD *)(v40 + 1936),
        (const char *)(v40 + 2368));
    }
    else
    {
      v91 = __readgsqword((unsigned int)&current_task);
      v92 = v36;
      v5 = -1;
      printk(
        "fastpipe: refcount bind type error: host-handle=%u pFilp=%p pSession=%p pid=%d %s\n",
        v38,
        a1,
        v92,
        *(_DWORD *)(v91 + 1936),
        (const char *)(v91 + 2368));
    }
  }
  else
  {
    if ( a2 == -1072928658 )
    {
      v114 = 0;
      v113 = -1;
      copy_from_user(&v113, a3, 12);
      v19 = (__int64)a1[26];
      if ( (v19
         || (v19 = kmem_cache_alloc_trace(kmalloc_caches[5], 37781696, 24),
             *(_DWORD *)v19 = 3,
             *(_QWORD *)(v19 + 8) = _InterlockedIncrement64(&g_u64GuestFDBase),
             (a1[26] = (const void *)v19) != 0))
        && *(_DWORD *)v19 == 3 )
      {
        *(_DWORD *)v116 = 4096;
        v20 = __readgsqword((unsigned int)&current_task);
        v115 = v113;
        *(_QWORD *)&v116[4] = *(_QWORD *)(v19 + 8);
        strncpy(dest, (const char *)(v20 + 2368), 0x40u);
        dest[63] = 0;
        v118 = -1;
        sendSerialCallToHost(1000, &v115, 88, &v115, 88, 0);
        v114 = v118;
        if ( v118 == -1 )
        {
          v103 = (const void *)v19;
          v5 = -1;
          printk(
            "fastpipe: ioCtrlAllocBlob register error : uSize=%u pFilp=%p pSession=%p pid=%d %s\n",
            HIDWORD(v113),
            a1,
            v103,
            *(_DWORD *)(v20 + 1936),
            (const char *)(v20 + 2368));
        }
        else
        {
          v5 = 0;
        }
        copy_to_user(v4, &v113, 12);
      }
      else
      {
        v95 = __readgsqword((unsigned int)&current_task);
        v96 = (const void *)v19;
        v5 = -1;
        printk(
          "fastpipe: ioCtrlAllocBlob type error: uSize=%u pFilp=%p pSession=%p pid=%d %s\n",
          HIDWORD(v113),
          a1,
          v96,
          *(_DWORD *)(v95 + 1936),
          (const char *)(v95 + 2368));
      }
      return v5;
    }
    if ( a2 == -1072666516 )
    {
      v115 = 0xFFFFFFFFLL;
      *(_QWORD *)v116 = -1;
      copy_from_user(&v115, a3, 16);
      v59 = a1[26];
      if ( v59 )
      {
        if ( *v59 == 1 )
        {
          v60 = 1;
          v61 = (unsigned int)v59[2];
          if ( (_DWORD)v115 )
            v60 = (unsigned int)(v115 + 0x1FFFFF) >> 21;
          v62 = 1;
          while ( 1 )
          {
            v63 = v62 - 1;
            v64 = v62 - 1;
            if ( !*(_DWORD *)(g_pPipeMem + 8 * (v64 + 22572) + 8) )
            {
              for ( i = v62; i != 8 && !*(_DWORD *)(g_pPipeMem + 8 * (i + 22572LL) + 8); ++i )
                ;
              if ( (unsigned int)v115 <= (i - v63) << 21 )
                break;
            }
            if ( ++v62 == 9 )
            {
              if ( v60 )
              {
LABEL_110:
                v5 = -1;
                goto LABEL_111;
              }
              *(_QWORD *)v116 = -1;
LABEL_118:
              v5 = 0;
              goto LABEL_111;
            }
          }
          if ( v60 <= 0
            || _InterlockedCompareExchange((volatile signed __int32 *)(g_pPipeMem + 8LL * v63 + 180584), v61, 0) )
          {
            v84 = 0;
          }
          else
          {
            v83 = v62 - 1;
            v84 = 0;
            do
            {
              ++v84;
              ++v83;
            }
            while ( v84 < v60
                 && v83 <= 7
                 && !_InterlockedCompareExchange((volatile signed __int32 *)(g_pPipeMem + 8LL * v83 + 180584), v61, 0) );
          }
          if ( v60 != v84 )
          {
            v85 = v63 + v84;
            if ( v63 < v63 + v84 )
            {
              v108 = __readgsqword((unsigned int)&current_task);
              while ( 1 )
              {
                if ( (_DWORD)v61 != _InterlockedCompareExchange(
                                      (volatile signed __int32 *)(g_pPipeMem + 8 * v64 + 180584),
                                      0,
                                      v61) )
                {
                  v112 = v85;
                  v111 = v60;
                  printk(
                    "fastpipe: ioCtrlAllocFixDma revert error! nReqCount=%d nCountSucess=%d pFilp=%p pSession=%p pid=%d %s\n",
                    v60,
                    v84,
                    v3,
                    v3[26],
                    *(_DWORD *)(v108 + 1936),
                    (const char *)(v108 + 2368));
                  v85 = v112;
                  v60 = v111;
                }
                if ( ++v63 >= v85 )
                  break;
                v64 = v63;
              }
            }
            goto LABEL_110;
          }
          v86 = v60;
          v87 = v63 + v60;
          *(_QWORD *)v116 = v63 | (v61 << 32) | (v86 << 8);
          if ( v63 >= v87 )
            goto LABEL_118;
          v88 = g_pPipeMem;
          v89 = v63;
          v90 = v115;
          while ( 1 )
          {
            ++v63;
            *(_DWORD *)(v88 + 8 * (v89 + 22572) + 12) = v90;
            if ( v63 == v87 )
              break;
            v89 = v63;
          }
          v5 = 0;
LABEL_111:
          copy_to_user(v4, &v115, 16);
          return v5;
        }
      }
      else
      {
        printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", "ioCtrlAllocFixDma", "pPipeData != NULL");
        dump_stack();
      }
      v93 = __readgsqword((unsigned int)&current_task);
      v94 = v59;
      v5 = -1;
      printk(
        "fastpipe: ioCtrlAllocFixDma type error: uSize=%u pFilp=%p pSession=%p pid=%d %s\n",
        v115,
        a1,
        v94,
        *(_DWORD *)(v93 + 1936),
        (const char *)(v93 + 2368));
      return v5;
    }
    if ( a2 != -1072928668 )
    {
LABEL_8:
      v5 = -22;
      printk(
        "fileOpIOCtl: unknown uCmd=0x%x type=%d(%c) dir=%d nr=%d size=%d\n",
        a2,
        BYTE1(a2),
        BYTE1(a2),
        a2 >> 30,
        (unsigned __int8)a2,
        HIWORD(a2) & 0x3FFF);
      printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", "fileOpIOCtl", "0");
      dump_stack();
      return v5;
    }
    v41 = __readgsqword((unsigned int)&current_task);
    printk(
      "fastpipe: ioCtlConnect: pFilp=%p pSession=%p pid=%d %s\n",
      a1,
      a1[26],
      *(_DWORD *)(v41 + 1936),
      (const char *)(v41 + 2368));
    if ( a1[26] )
    {
      printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", "ioCtlConnect", "pFilp->private_data == 0");
      dump_stack();
    }
    v115 = 0;
    *(_DWORD *)v116 = 0;
    copy_from_user(&v115, v4, 12);
    if ( !(_DWORD)v115 )
    {
      printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", "ioCtlConnect", "connect_info.nTypeId != 0");
      dump_stack();
    }
    if ( s_nFindPos_35775 + 1 <= 1023 )
    {
      v42 = s_nFindPos_35775 + 3;
      v107 = 0;
      v43 = 0;
      v44 = s_nFindPos_35775 + 1;
      v109 = v4;
      while ( 1 )
      {
        v45 = 48LL * (v42 - 3);
        if ( _InterlockedExchange((volatile __int32 *)(g_pPipeMem + v45 + 8), 1) )
        {
          v44 = v42;
          if ( v42 > 1023 )
          {
            v4 = v109;
            if ( s_nFindPos_35775 > 3 )
              goto LABEL_122;
            goto LABEL_142;
          }
        }
        else
        {
          v46 = 48LL * v44;
          v47 = 0;
          if ( !_InterlockedExchange((volatile __int32 *)(g_pPipeMem + v46 + 8), 1) )
          {
            v48 = g_pPipeMem;
            if ( !*(_DWORD *)(g_pPipeMem + v45 + 40) )
            {
              v48 = g_pPipeMem;
              if ( !*(_DWORD *)(g_pPipeMem + v46 + 40) )
              {
                v48 = g_pPipeMem;
                v43 = v44;
                v107 = _InterlockedExchangeAdd(&g_nStateCookieBase, 0xAu) + 10;
                v47 = v42 - 3;
                v49 = g_pPipeMem + v45;
                v50 = g_pPipeMem + v46;
                *(_DWORD *)(v49 + 40) = 1;
                *(_DWORD *)(v49 + 20) = 0;
                *(_DWORD *)(v49 + 16) = 0;
                *(_DWORD *)(v49 + 24) = 0;
                *(_DWORD *)(v49 + 28) = 0;
                *(_DWORD *)(v49 + 32) = 0;
                *(_DWORD *)(v49 + 36) = 0;
                *(_QWORD *)(v49 + 44) = v107;
                v51 = v115;
                *(_DWORD *)(v49 + 52) = v115;
                *(_DWORD *)(v50 + 40) = 1;
                *(_DWORD *)(v50 + 20) = 0;
                *(_DWORD *)(v50 + 16) = 0;
                *(_DWORD *)(v50 + 24) = 0;
                *(_DWORD *)(v50 + 28) = 0;
                *(_DWORD *)(v50 + 32) = 0;
                *(_DWORD *)(v50 + 36) = 0;
                *(_QWORD *)(v50 + 44) = v107;
                *(_DWORD *)(v50 + 52) = v51;
              }
            }
            v52 = v48 + 48LL * v44;
            if ( *(_DWORD *)(v52 + 8) != 1 )
            {
              printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", "PipeUnlock", "pPipe->mainLock == 1");
              dump_stack();
            }
            _InterlockedExchange((volatile __int32 *)(v52 + 8), 0);
          }
          v53 = g_pPipeMem + 48LL * (v42 - 3);
          if ( *(_DWORD *)(v53 + 8) != 1 )
          {
            printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", "PipeUnlock", "pPipe->mainLock == 1");
            dump_stack();
          }
          _InterlockedExchange((volatile __int32 *)(v53 + 8), 0);
          v44 = v42;
          if ( v42 > 1023 )
          {
            v54 = v47;
            v4 = v109;
            if ( s_nFindPos_35775 <= 3 )
            {
LABEL_141:
              if ( !v54 )
                goto LABEL_142;
            }
            else if ( !v54 )
            {
LABEL_122:
              v110 = v4;
              v67 = 4;
              v68 = 3;
              while ( 1 )
              {
                v69 = v67 - 2;
                if ( v43 )
                {
                  printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", "ioCtlConnect", "nWritePipeId == 0");
                  dump_stack();
                }
                v70 = v69;
                v71 = 48LL * v69;
                if ( _InterlockedExchange((volatile __int32 *)(g_pPipeMem + v71 + 8), 1) )
                {
                  v68 = v67 + 1;
                  if ( s_nFindPos_35775 <= v67 + 1 )
                  {
                    v3 = a1;
                    v4 = v110;
                    goto LABEL_142;
                  }
                }
                else
                {
                  v72 = 48LL * v68;
                  v73 = 0;
                  if ( !_InterlockedExchange((volatile __int32 *)(g_pPipeMem + v72 + 8), 1) )
                  {
                    v74 = g_pPipeMem;
                    if ( !*(_DWORD *)(g_pPipeMem + v71 + 40) )
                    {
                      v74 = g_pPipeMem;
                      if ( !*(_DWORD *)(g_pPipeMem + v72 + 40) )
                      {
                        v74 = g_pPipeMem;
                        v43 = v68;
                        v107 = _InterlockedExchangeAdd(&g_nStateCookieBase, 0xAu) + 10;
                        v73 = v67 - 2;
                        v75 = g_pPipeMem + v71;
                        v76 = g_pPipeMem + v72;
                        *(_DWORD *)(v75 + 40) = 1;
                        *(_DWORD *)(v75 + 20) = 0;
                        *(_DWORD *)(v75 + 16) = 0;
                        *(_DWORD *)(v75 + 24) = 0;
                        *(_DWORD *)(v75 + 28) = 0;
                        *(_DWORD *)(v75 + 32) = 0;
                        *(_DWORD *)(v75 + 36) = 0;
                        *(_QWORD *)(v75 + 44) = v107;
                        v77 = v115;
                        *(_DWORD *)(v75 + 52) = v115;
                        *(_DWORD *)(v76 + 40) = 1;
                        *(_DWORD *)(v76 + 20) = 0;
                        *(_DWORD *)(v76 + 16) = 0;
                        *(_DWORD *)(v76 + 24) = 0;
                        *(_DWORD *)(v76 + 28) = 0;
                        *(_DWORD *)(v76 + 32) = 0;
                        *(_DWORD *)(v76 + 36) = 0;
                        *(_QWORD *)(v76 + 44) = v107;
                        *(_DWORD *)(v76 + 52) = v77;
                      }
                    }
                    v78 = v74 + 48LL * v68;
                    if ( *(_DWORD *)(v78 + 8) != 1 )
                    {
                      printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", "PipeUnlock", "pPipe->mainLock == 1");
                      dump_stack();
                    }
                    _InterlockedExchange((volatile __int32 *)(v78 + 8), 0);
                  }
                  v79 = g_pPipeMem + 48 * v70;
                  if ( *(_DWORD *)(v79 + 8) != 1 )
                  {
                    printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", "PipeUnlock", "pPipe->mainLock == 1");
                    dump_stack();
                  }
                  _InterlockedExchange((volatile __int32 *)(v79 + 8), 0);
                  v68 = v67 + 1;
                  if ( s_nFindPos_35775 <= v67 + 1 )
                  {
                    v54 = v73;
                    v4 = v110;
                    v3 = a1;
                    goto LABEL_141;
                  }
                  if ( v73 )
                  {
                    v54 = v73;
                    v4 = v110;
                    v3 = a1;
                    goto LABEL_92;
                  }
                }
                v67 += 2;
              }
            }
            goto LABEL_92;
          }
          if ( v47 )
          {
            v54 = v47;
            v4 = v109;
LABEL_92:
            v55 = kmalloc_caches[5];
            s_nFindPos_35775 = v54 + 2;
            v56 = (_DWORD *)kmem_cache_alloc_trace(v55, 37781696, 24);
            v57 = v107;
            *v56 = 1;
            v56[2] = v54;
            v56[3] = v43;
            v56[4] = v107;
            v3[26] = v56;
            __outdword(g_IOPortBase, ((v43 & 0xFFF) << 8) | (v54 << 20) | 1);
            my_wait_event_constprop_6(v54, v57, (__int64 (__fastcall *)(_QWORD))my_condition_connect);
            v58 = g_pPipeMem + 48LL * v54;
            if ( v57 == *(_DWORD *)(v58 + 44) )
            {
              v5 = 0;
              if ( *(_DWORD *)(v58 + 40) != 1 )
              {
                printk(
                  "fastpipe: assert!!!!!!!!!!!! [%s] %s\n",
                  "ioCtlConnect",
                  "g_pPipeMem->arPipe[nReadPipeId].state == eUsing");
                dump_stack();
              }
            }
            else
            {
              if ( *(_DWORD *)(48LL * v54 + g_pPipeMem + 40) != 2 )
              {
                printk(
                  "fastpipe: assert!!!!!!!!!!!! [%s] %s\n",
                  "ioCtlConnect",
                  "g_pPipeMem->arPipe[nReadPipeId].state == eClosing");
                dump_stack();
              }
              v105 = __readgsqword((unsigned int)&current_task);
              v5 = -1;
              printk(
                "fastpipe: ioCtlConnect: pipe closing: pFilp=%p pSession=%p pid=%d %s\n",
                v3,
                v3[26],
                *(_DWORD *)(v105 + 1936),
                (const char *)(v105 + 2368));
            }
            goto LABEL_95;
          }
        }
        if ( v43 )
        {
          printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", "ioCtlConnect", "nWritePipeId == 0");
          dump_stack();
        }
        v42 += 2;
      }
    }
    if ( s_nFindPos_35775 > 3 )
    {
      v107 = 0;
      v43 = 0;
      goto LABEL_122;
    }
    v43 = 0;
LABEL_142:
    v5 = -1;
    v54 = 0;
    printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", "ioCtlConnect", "nReadPipeId != 0");
    dump_stack();
    v80 = v3[26];
    v81 = __readgsqword((unsigned int)&current_task);
    v82 = *(_DWORD *)(v81 + 1936);
    s_nFindPos_35775 = 2;
    printk(
      "fastpipe: ioCtlConnect: failed!!! pipe count is too much: pFilp=%p pSession=%p pid=%d %s\n",
      v3,
      v80,
      v82,
      (const char *)(v81 + 2368));
LABEL_95:
    HIDWORD(v115) = v54;
    *(_DWORD *)v116 = v43;
    copy_to_user(v4, &v115, 12);
  }
  return v5;
}
