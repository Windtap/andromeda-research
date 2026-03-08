__int64 __fastcall vbsf_dir_iterate(_QWORD *a1, __int64 a2)
{
  __int64 v3; // rbx
  __int64 v4; // rbp
  __int64 v5; // r13
  unsigned int v6; // eax
  __int64 v7; // rdx
  __int64 v8; // r15
  __int64 v9; // r12
  unsigned __int16 v10; // cx
  unsigned __int16 v11; // ax
  __int64 v12; // rbx
  __int64 v13; // rdx
  unsigned int v14; // eax
  unsigned int v15; // r8d
  __int64 v16; // rsi
  unsigned int v18; // eax
  unsigned int v19; // eax
  unsigned int more_isra_5; // r12d
  unsigned int (__fastcall *v21)(__int64, const char *, __int64, _QWORD, __int64, __int64); // r13
  __int64 v22; // rbp
  __int64 v23; // rdi
  __int64 v24; // rbp
  __int64 DefaultInstance; // rax
  __int64 v26; // rax
  __int64 v27; // rax
  __int64 v28; // rax
  __int64 v29; // rax
  __int64 v30; // rax
  __int64 v31; // [rsp+10h] [rbp-68h]
  unsigned int v32; // [rsp+10h] [rbp-68h]
  __int64 v33; // [rsp+18h] [rbp-60h]
  __int64 v35; // [rsp+28h] [rbp-50h]
  __int64 v36; // [rsp+30h] [rbp-48h]
  unsigned int v37; // [rsp+38h] [rbp-40h]
  unsigned int v38; // [rsp+3Ch] [rbp-3Ch]

  v3 = a1[26];
  v4 = *(_QWORD *)(a2 + 8);
  v31 = *(_QWORD *)(*(_QWORD *)(a1[3] + 104LL) + 1120LL);
  v36 = v3 + 32;
  v38 = down_interruptible(v3 + 32);
  if ( v38 )
    return (unsigned int)-512;
  v5 = *(_QWORD *)(v3 + 80);
  if ( v5 != v4 )
  {
    if ( v4 < v5 )
    {
      v5 = 0;
      more_isra_5 = vbsf_dir_read_more_isra_5(v3, (int *)v31, (_DWORD *)(v31 + 48), 1);
      if ( more_isra_5 )
      {
LABEL_55:
        up(v36);
        return more_isra_5;
      }
    }
    while ( v4 > v5 )
    {
      v6 = *(_DWORD *)(v3 + 76);
      if ( v4 - v5 >= (unsigned __int64)v6 )
      {
        v5 += v6;
        *(_DWORD *)(v3 + 76) = 0;
        *(_QWORD *)(v3 + 80) = v5;
        v18 = vbsf_dir_read_more_isra_5(v3, (int *)v31, (_DWORD *)(v31 + 48), 0);
        if ( v18 || !*(_DWORD *)(v3 + 76) )
        {
          v32 = v18;
          up(v36);
          return v32;
        }
      }
      else
      {
        v7 = *(_QWORD *)(v3 + 88);
        while ( v6 == 1
             || v7 + (unsigned __int64)*(unsigned __int16 *)(v7 + 124) + 126 - *(_QWORD *)(v3 + 64) <= (unsigned __int64)*(unsigned int *)(v3 + 72) - 126 )
        {
          ++v5;
          *(_DWORD *)(v3 + 76) = --v6;
          *(_QWORD *)(v3 + 80) = v5;
          if ( v4 >= v5 )
            goto LABEL_9;
        }
        DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
        if ( DefaultInstance )
          VBoxGuest_RTLogLoggerEx(
            DefaultInstance,
            16,
            337,
            "AssertLogRel %s(%d) %s: %s\n",
            "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxsf/dirops.c",
            391,
            "vbsf_dir_iterate",
            "cEntriesLeft == 1 || (uintptr_t)pEntry - (uintptr_t)sf_d->pBuf <= sf_d->cbValid - RT_UOFFSETOF(SHFLDIRINFO, name.String)");
        *(_DWORD *)(v3 + 76) = 0;
      }
LABEL_9:
      ;
    }
  }
  if ( v4 > 1 )
    goto LABEL_11;
  if ( v4 )
  {
    if ( v4 != 1 )
    {
LABEL_11:
      v35 = v3;
      LODWORD(v8) = *(_DWORD *)(v3 + 76);
      while ( 1 )
      {
        v37 = *(_DWORD *)(v35 + 72);
        if ( !(_DWORD)v8 )
        {
          v19 = vbsf_dir_read_more_isra_5(v35, (int *)v31, (_DWORD *)(v31 + 48), 0);
          if ( v19 )
          {
            more_isra_5 = v19;
            goto LABEL_55;
          }
          LODWORD(v8) = *(_DWORD *)(v35 + 76);
          if ( !(_DWORD)v8 )
            goto LABEL_31;
          v37 = *(_DWORD *)(v35 + 72);
        }
        v9 = *(_QWORD *)(v35 + 88);
        v33 = *(_QWORD *)(v35 + 64);
        while ( v37 >= (unsigned __int64)(v9 - v33 + 126) )
        {
          v10 = *(_WORD *)(v9 + 122);
          v11 = *(_WORD *)(v9 + 124);
          v12 = v10 + 126LL;
          if ( v37 < (unsigned __int64)(v12 + v9 - v33) )
          {
            v27 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
            if ( v27 )
              VBoxGuest_RTLogLoggerEx(
                v27,
                16,
                337,
                "AssertLogRel %s(%d) %s: %s\n",
                "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxsf/dirops.c",
                493,
                "vbsf_dir_iterate",
                "offEntryInBuf + RT_UOFFSETOF(SHFLDIRINFO, name.String) + cbSrcName <= cbValid");
            goto LABEL_66;
          }
          if ( v10 <= v11 )
          {
            v26 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
            if ( v26 )
              VBoxGuest_RTLogLoggerEx(
                v26,
                16,
                337,
                "AssertLogRel %s(%d) %s: %s\n",
                "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxsf/dirops.c",
                494,
                "vbsf_dir_iterate",
                "cchSrcName < cbSrcName");
            goto LABEL_66;
          }
          v13 = v11;
          if ( *(_BYTE *)(v9 + v11 + 126) )
          {
            v28 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
            if ( v28 )
              VBoxGuest_RTLogLoggerEx(
                v28,
                16,
                337,
                "AssertLogRel %s(%d) %s: %s\n",
                "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxsf/dirops.c",
                495,
                "vbsf_dir_iterate",
                "pEntry->name.String.ach[cchSrcName] == '\\0'");
LABEL_66:
            v8 = (unsigned int)v8;
            goto LABEL_47;
          }
          if ( v11 > 2u || *(_BYTE *)(v9 + 126) != 46 || v11 == 2 && *(_BYTE *)(v9 + 127) != 46 )
          {
            v14 = *(_DWORD *)(v9 + 48) & 0xF000;
            if ( v14 == 24576 )
            {
              v15 = 6;
              goto LABEL_28;
            }
            if ( v14 <= 0x6000 )
            {
              v15 = 2;
              if ( v14 == 0x2000 || (LOBYTE(v15) = 4, v14 == 0x4000) || (LOBYTE(v15) = 1, v14 == 4096) )
              {
LABEL_28:
                v16 = v9 + 126;
                if ( *(_BYTE *)(v31 + 16) )
                {
                  if ( (*(unsigned int (__fastcall **)(__int64, __int64, __int64, _QWORD, __int64, _QWORD))a2)(
                         a2,
                         v16,
                         v13,
                         *(_QWORD *)(a2 + 8),
                         v4 + 48879,
                         v15) )
                  {
                    goto LABEL_30;
                  }
                }
                else if ( !(unsigned __int8)vbsf_dir_emit_nls(a2, v16, v13, v4 + 48879, v15, v31) )
                {
LABEL_30:
                  *(_DWORD *)(v35 + 76) = v8;
                  *(_QWORD *)(v35 + 88) = v9;
                  *(_QWORD *)(v35 + 80) = v4;
                  goto LABEL_31;
                }
                goto LABEL_15;
              }
            }
            else
            {
              v15 = 10;
              if ( v14 == 40960 )
                goto LABEL_28;
              if ( v14 <= 0xA000 )
              {
                LOBYTE(v15) = 8;
                if ( v14 == 0x8000 )
                  goto LABEL_28;
              }
              else
              {
                v15 = 12;
                if ( v14 == 49152 )
                  goto LABEL_28;
                LOBYTE(v15) = 14;
                if ( v14 == 57344 )
                  goto LABEL_28;
              }
            }
            v15 = 0;
            goto LABEL_28;
          }
LABEL_15:
          ++v4;
          v9 += v12;
          LODWORD(v8) = v8 - 1;
          a1[14] = v4;
          *(_QWORD *)(a2 + 8) = v4;
          if ( !(_DWORD)v8 )
          {
            v8 = 0;
            goto LABEL_47;
          }
        }
        v29 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
        if ( v29 )
          VBoxGuest_RTLogLoggerEx(
            v29,
            16,
            337,
            "AssertLogRel %s(%d) %s: %s\n",
            "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxsf/dirops.c",
            490,
            "vbsf_dir_iterate",
            "offEntryInBuf + RT_UOFFSETOF(SHFLDIRINFO, name.String) <= cbValid");
        v30 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
        if ( !v30 )
          goto LABEL_66;
        v8 = (unsigned int)v8;
        VBoxGuest_RTLogLoggerEx(v30, 16, 337, "%#llx + %#x vs %#x\n", v9 - v33, 126, v37);
LABEL_47:
        *(_QWORD *)(v35 + 80) = v4 + v8;
        LODWORD(v8) = 0;
        *(_QWORD *)(v35 + 88) = v33;
        *(_DWORD *)(v35 + 76) = 0;
      }
    }
  }
  else
  {
    if ( (*(unsigned int (__fastcall **)(__int64, const char *, __int64, _QWORD, _QWORD, __int64))a2)(
           a2,
           ".",
           1,
           *(_QWORD *)(a2 + 8),
           *(_QWORD *)(*(_QWORD *)(a1[3] + 48LL) + 64LL),
           4) )
    {
      goto LABEL_31;
    }
    *(_QWORD *)(v3 + 80) = 1;
    *(_QWORD *)(a2 + 8) = 1;
    a1[14] = 1;
  }
  v21 = *(unsigned int (__fastcall **)(__int64, const char *, __int64, _QWORD, __int64, __int64))a2;
  v22 = a1[3];
  raw_spin_lock(v22 + 88);
  v23 = v22 + 88;
  v24 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v22 + 24) + 48LL) + 64LL);
  raw_spin_unlock(v23);
  if ( !v21(a2, "..", 2, *(_QWORD *)(a2 + 8), v24, 4) )
  {
    *(_QWORD *)(v3 + 80) = 2;
    v4 = 2;
    *(_QWORD *)(a2 + 8) = 2;
    a1[14] = 2;
    goto LABEL_11;
  }
LABEL_31:
  up(v36);
  return v38;
}
