__int64 __fastcall rtLogOutputPrefixed(__int64 a1, char *a2, size_t a3)
{
  size_t v3; // r12
  __int64 v4; // r14
  unsigned int v6; // r13d
  __int64 v7; // rcx
  __int64 v8; // rbp
  size_t v9; // rbx
  int v10; // ecx
  char *v11; // rbp
  int v12; // eax
  unsigned __int64 v13; // rax
  int v14; // edi
  unsigned __int64 v15; // rsi
  __int64 v16; // rcx
  __int64 v17; // rax
  char *v18; // rax
  __int64 v19; // rsi
  const char *v20; // rsi
  size_t v21; // rbx
  size_t v22; // rax
  _BYTE *v23; // rax
  size_t v24; // rax
  __int64 v25; // r13
  char *v26; // rdx
  __int64 v27; // rdx
  __int64 (__fastcall *v28)(__int64, char *, __int64, _QWORD); // r8
  char *v29; // rax
  unsigned __int64 v30; // rsi
  char *v31; // rax
  __int64 v32; // rax
  unsigned int v33; // eax
  size_t v34; // rbx
  const char *v35; // rsi
  char *v36; // rdx
  signed __int64 v38; // rax
  int v39; // esi
  __int64 v40; // rcx
  char *v41; // rax
  char *v42; // rax
  char *v43; // rax
  char *v49; // rax
  unsigned __int64 v50; // rsi
  char *v51; // rax
  unsigned __int64 v52; // rax
  char *v53; // rax
  unsigned __int64 v54; // rbx
  char *v55; // rax
  char *v56; // rax
  char *v57; // rax
  char *v58; // rax
  __int64 *v59; // rax
  char *v60; // rbp
  char *v61; // rax
  char *v62; // rax
  char *v63; // rbx
  __int64 v64; // rax
  char *v65; // rax
  __int64 v66; // [rsp+0h] [rbp-78h]
  __int64 v67; // [rsp+8h] [rbp-70h]
  int v68; // [rsp+10h] [rbp-68h]
  unsigned int v70; // [rsp+20h] [rbp-58h]
  char v71[8]; // [rsp+28h] [rbp-50h] BYREF
  _BYTE v72[12]; // [rsp+30h] [rbp-48h] BYREF
  unsigned int v73; // [rsp+3Ch] [rbp-3Ch]

  v3 = a3;
  v4 = *(_QWORD *)a1;
  if ( a3 )
  {
    v67 = 0;
    while ( 1 )
    {
      v6 = *(_DWORD *)(v4 + 49152);
      v7 = *(_QWORD *)(v4 + 49168);
      v8 = v6;
      v9 = 49151LL - v6;
      v66 = v7;
      if ( *(_BYTE *)(v7 + 40) )
        break;
      if ( !v9 )
      {
        rtlogFlush_isra_12(v4);
        v6 = *(_DWORD *)(v4 + 49152);
        v8 = v6;
        v9 = 49151LL - v6;
      }
LABEL_28:
      if ( v9 > v3 )
        v9 = v3;
      v23 = memchr(a2, 10, v9);
      if ( v23 )
      {
        v24 = v23 - a2;
        v9 = v24;
        if ( (*(_BYTE *)(v4 + 49160) & 0x10) == 0 )
        {
          v9 = v24 + 1;
          *(_BYTE *)(v66 + 40) = 1;
        }
        memcpy((void *)(v4 + v8), a2, v9);
        v25 = (unsigned int)v9 + v6;
        v3 -= v9;
        v67 += v9;
        *(_DWORD *)(v4 + 49152) = v25;
        if ( (*(_BYTE *)(v4 + 49160) & 0x10) != 0 && (unsigned int)(v25 + 2) <= 0xBFFF )
        {
          --v3;
          ++v9;
          ++v67;
          *(_WORD *)(v4 + v25) = 2573;
          *(_DWORD *)(v4 + 49152) = v25 + 2;
          *(_BYTE *)(v66 + 40) = 1;
        }
        if ( !v3 )
          return v67;
      }
      else
      {
        memcpy((void *)(v4 + v8), a2, v9);
        v3 -= v9;
        v67 += v9;
        *(_DWORD *)(v4 + 49152) = v9 + v6;
        if ( !v3 )
          return v67;
      }
      a2 += v9;
    }
    *(_BYTE *)(v7 + 40) = 0;
    if ( v9 <= 0x10F )
    {
      rtlogFlush_isra_12(v4);
      v6 = *(_DWORD *)(v4 + 49152);
      v8 = v6;
    }
    v10 = *(_DWORD *)(v4 + 49160);
    v11 = (char *)(v4 + v8);
    v68 = (int)v11;
    v12 = v10;
    if ( (v10 & 0x40000000) != 0 )
    {
      v38 = VBoxGuest_RTTimeNanoTS();
      v39 = *(_DWORD *)(v4 + 49160) & 0x80;
      if ( (*(_DWORD *)(v4 + 49160) & 0x40) != 0 )
      {
        v40 = s_u64LastTs_26497;
        s_u64LastTs_26497 = v38;
        v38 -= v40;
        if ( v38 < 0 )
          v38 = 0;
      }
      v41 = &v11[(int)VBoxGuest_RTStrFormatNumber(v11, v38, v39 == 0 ? 16 : 10, 16, 0, v39 == 0 ? 4 : 0)];
      *v41 = 32;
      v11 = v41 + 1;
      v10 = *(_DWORD *)(v4 + 49160);
      v12 = v10;
    }
    if ( (v10 & 0x20000000) != 0 )
    {
      v13 = __rdtsc();
      v14 = v10 & 0x80;
      v15 = v13;
      if ( (v10 & 0x40) != 0 )
      {
        v16 = s_u64LastTsc_26502;
        v15 = 0;
        s_u64LastTsc_26502 = v13;
        v17 = v13 - v16;
        if ( v17 >= 0 )
          v15 = v17;
      }
      v18 = &v11[(int)VBoxGuest_RTStrFormatNumber(v11, v15, v14 == 0 ? 16 : 10, 16, 0, v14 == 0 ? 4 : 0)];
      *v18 = 32;
      v11 = v18 + 1;
      v12 = *(_DWORD *)(v4 + 49160);
    }
    if ( (v12 & 0x10000000) != 0 )
    {
      v64 = VBoxGuest_RTTimeNanoTS();
      v65 = &v11[(int)VBoxGuest_RTStrFormatNumber(
                        v11,
                        (v64 - *(_QWORD *)(*(_QWORD *)(v4 + 49168) + 96LL)) / 0xF4240uLL,
                        0xAu,
                        9,
                        0,
                        4)];
      *v65 = 32;
      v11 = v65 + 1;
      v12 = *(_DWORD *)(v4 + 49160);
    }
    if ( (v12 & 0x8000000) != 0 )
    {
      v59 = (__int64 *)VBoxGuest_RTTimeNow(v71);
      VBoxGuest_RTTimeExplode((__int64)v72, v59);
      v60 = &v11[(int)VBoxGuest_RTStrFormatNumber(v11, v72[9], 0xAu, 2, 0, 4)];
      *v60 = 58;
      v61 = &v60[(int)VBoxGuest_RTStrFormatNumber(v60 + 1, v72[10], 0xAu, 2, 0, 4) + 1];
      *v61 = 58;
      v62 = &v61[(int)VBoxGuest_RTStrFormatNumber(v61 + 1, v72[11], 0xAu, 2, 0, 4) + 1];
      *v62 = 46;
      v63 = &v62[(int)VBoxGuest_RTStrFormatNumber(v62 + 1, v73 / 0x3E8, 0xAu, 6, 0, 4) + 1];
      *v63 = 32;
      v11 = v63 + 1;
      v12 = *(_DWORD *)(v4 + 49160);
    }
    if ( (v12 & 0x4000000) != 0 )
    {
      v54 = (VBoxGuest_RTTimeNanoTS() - *(_QWORD *)(*(_QWORD *)(v4 + 49168) + 96LL)) / 0x3E8uLL;
      v55 = &v11[(int)VBoxGuest_RTStrFormatNumber(v11, v54 / 0xD693A400, 0xAu, 2, 0, 4)];
      *v55 = 58;
      v56 = &v55[(int)VBoxGuest_RTStrFormatNumber(v55 + 1, v54 % 0xD693A400 / 0x3938700, 0xAu, 2, 0, 4) + 1];
      *v56 = 58;
      v70 = v54 % 0xD693A400 % 0x3938700;
      v57 = &v56[(int)VBoxGuest_RTStrFormatNumber(v56 + 1, v70 / 0xF4240, 0xAu, 2, 0, 4) + 1];
      *v57 = 46;
      v58 = &v57[(int)VBoxGuest_RTStrFormatNumber(v57 + 1, v70 % 0xF4240, 0xAu, 6, 0, 4) + 1];
      *v58 = 32;
      v11 = v58 + 1;
      v12 = *(_DWORD *)(v4 + 49160);
    }
    if ( (v12 & 0x20000) != 0 )
    {
      v50 = (unsigned int)VBoxGuest_RTProcSelf();
      v51 = &v11[(int)VBoxGuest_RTStrFormatNumber(v11, v50, 0x10u, 8, 0, 4)];
      *v51 = 32;
      v11 = v51 + 1;
      v12 = *(_DWORD *)(v4 + 49160);
      if ( (v12 & 0x400000) == 0 )
        goto LABEL_20;
    }
    else if ( (v12 & 0x400000) == 0 )
    {
      goto LABEL_20;
    }
    v52 = VBoxGuest_RTThreadNativeSelf();
    v53 = &v11[(int)VBoxGuest_RTStrFormatNumber(v11, v52, 0x10u, 16, 0, 4)];
    *v53 = 32;
    v11 = v53 + 1;
    v12 = *(_DWORD *)(v4 + 49160);
LABEL_20:
    if ( (v12 & 0x800000) == 0 )
      goto LABEL_43;
    v19 = *(_QWORD *)(v4 + 49168);
    if ( *(_BYTE *)(v19 + 104) )
    {
      v20 = (const char *)(v19 + 104);
      if ( !v20 )
      {
        v26 = v11;
        v21 = 0;
LABEL_40:
        v11 = v26;
        do
          *v11++ = 32;
        while ( (unsigned __int64)(&v11[v21 - 1] - v26) <= 7 );
        v12 = *(_DWORD *)(v4 + 49160);
LABEL_43:
        if ( (v12 & 0x10000) != 0 )
        {
          _RAX = 1;
          __asm { cpuid }
          v49 = &v11[(int)VBoxGuest_RTStrFormatNumber(v11, BYTE3(_RBX), 0x10u, 2, 0, 4)];
          *v49 = 32;
          v11 = v49 + 1;
          v12 = *(_DWORD *)(v4 + 49160);
        }
        if ( (v12 & 0x1000000) != 0 )
        {
          v27 = *(_QWORD *)(v4 + 49168);
          v28 = *(__int64 (__fastcall **)(__int64, char *, __int64, _QWORD))(v27 + 24);
          if ( v28 )
          {
            v29 = &v11[v28(v4, v11, 31, *(_QWORD *)(v27 + 32))];
            *v29 = 32;
            v11 = v29 + 1;
            v12 = *(_DWORD *)(v4 + 49160);
          }
        }
        if ( (v12 & 0x8000) != 0 )
        {
          *v11 = 63;
          v11 += 4;
          *(v11 - 3) = 47;
          *(v11 - 2) = 63;
          *(v11 - 1) = 32;
          v12 = *(_DWORD *)(v4 + 49160);
        }
        if ( (v12 & 0x40000) != 0 )
        {
          v43 = &v11[(int)VBoxGuest_RTStrFormatNumber(v11, *(unsigned int *)(a1 + 8), 0x10u, 8, 0, 4)];
          *v43 = 32;
          v11 = v43 + 1;
          v12 = *(_DWORD *)(v4 + 49160);
        }
        if ( (v12 & 0x80000) != 0 )
        {
          v42 = v11 + 9;
          do
            *v11++ = 32;
          while ( v11 != v42 );
          v12 = *(_DWORD *)(v4 + 49160);
        }
        if ( (v12 & 0x100000) != 0 )
        {
          v30 = *(unsigned int *)(a1 + 12);
          if ( (_DWORD)v30 == -1 )
          {
            *(_DWORD *)v11 = 538980653;
            v11 += 4;
          }
          else
          {
            v31 = &v11[(int)VBoxGuest_RTStrFormatNumber(v11, v30, 0x10u, 3, 0, 4)];
            *v31 = 32;
            v11 = v31 + 1;
          }
          v12 = *(_DWORD *)(v4 + 49160);
        }
        if ( (v12 & 0x200000) == 0 )
          goto LABEL_70;
        v32 = 0;
        if ( *(_DWORD *)(a1 + 12) != -1 )
          v32 = *(unsigned int *)(a1 + 12);
        v33 = *(_DWORD *)(a1 + 8) & *(_DWORD *)(v4 + 4 * v32 + 49188);
        if ( v33 == 128 )
        {
          v34 = 7;
          v35 = "level 4";
        }
        else if ( v33 <= 0x80 )
        {
          if ( v33 == 4 )
          {
            v34 = 4;
            v35 = "warn";
          }
          else
          {
            if ( v33 > 4 )
            {
              v34 = 7;
              v35 = "level 2";
              if ( v33 == 32 )
                goto LABEL_68;
              v35 = "level 3";
              if ( v33 == 64 )
                goto LABEL_68;
              v35 = "level 1";
              if ( v33 == 16 )
                goto LABEL_68;
              goto LABEL_87;
            }
            if ( v33 != 1 )
            {
              v34 = 8;
              v35 = "--------";
              if ( !v33 )
                goto LABEL_68;
              LOBYTE(v34) = 4;
              v35 = "flow";
              if ( v33 == 2 )
                goto LABEL_68;
              goto LABEL_87;
            }
            v34 = 7;
            v35 = "enabled";
          }
        }
        else if ( v33 == 2048 )
        {
          v34 = 7;
          v35 = "level 8";
        }
        else
        {
          if ( v33 <= 0x800 )
          {
            v34 = 7;
            v35 = "level 6";
            if ( v33 == 512 )
              goto LABEL_68;
            v35 = "level 7";
            if ( v33 == 1024 )
              goto LABEL_68;
            v35 = "level 5";
            if ( v33 == 256 )
              goto LABEL_68;
            goto LABEL_87;
          }
          if ( v33 == 0x2000 )
          {
            v34 = 8;
            v35 = "level 10";
          }
          else
          {
            if ( v33 > 0x2000 )
            {
              v34 = 8;
              v35 = "level 11";
              if ( v33 == 0x4000 )
                goto LABEL_68;
              v35 = "level 12";
              if ( v33 == 0x8000 )
                goto LABEL_68;
              goto LABEL_87;
            }
            v34 = 7;
            v35 = "level 9";
            if ( v33 != 4096 )
            {
LABEL_87:
              v34 = 8;
              v35 = "????????";
            }
          }
        }
LABEL_68:
        memcpy(v11, v35, v34);
        v36 = &v11[v34];
        v11 += v34;
        do
          *v11++ = 32;
        while ( (unsigned __int64)(&v11[v34 - 1] - v36) <= 7 );
LABEL_70:
        v6 += (_DWORD)v11 - v68;
        v8 = v6;
        *(_DWORD *)(v4 + 49152) = v6;
        v9 = 49151LL - v6;
        goto LABEL_28;
      }
      v21 = 16;
      v22 = strlen(v20);
      if ( v22 <= 0x10 )
        v21 = v22;
    }
    else
    {
      v21 = 2;
      v20 = "R0";
    }
    memcpy(v11, v20, v21);
    v26 = &v11[v21];
    goto LABEL_40;
  }
  *(_BYTE *)(v4 + *(unsigned int *)(v4 + 49152)) = 0;
  return 0;
}
