__int64 __fastcall rtstrFormatRt(
        __int64 (__fastcall *a1)(__int64, unsigned __int64, unsigned __int64),
        __int64 a2,
        __int64 *a3,
        unsigned __int64 a4,
        int a5,
        int a6,
        unsigned int a7,
        char a8)
{
  _BYTE *v9; // r12
  __int64 v10; // rbp
  __int64 result; // rax
  __int64 (__fastcall *v12)(__int64, unsigned __int64, unsigned __int64); // r15
  __int64 v13; // r14
  unsigned int v14; // eax
  _DWORD *v15; // rdx
  _BYTE *v16; // rax
  __int64 v17; // r9
  const char *v18; // r8
  const char *v19; // rbp
  char v20; // al
  int v21; // r12d
  int v22; // r14d
  int v23; // ebx
  __int64 v24; // rbp
  char *v25; // r13
  int v26; // eax
  unsigned int v27; // eax
  unsigned __int64 *v28; // rdx
  unsigned __int64 v29; // rax
  char v30; // al
  unsigned int v31; // edx
  unsigned __int64 *v32; // rax
  unsigned __int64 v33; // rbp
  _WORD *v34; // rax
  int v35; // r12d
  int v36; // r13d
  __int64 v37; // rbx
  int v38; // ebp
  int v39; // ebp
  unsigned int v40; // eax
  unsigned __int64 *v41; // rdx
  unsigned __int64 v42; // rsi
  char v43; // al
  unsigned __int64 v44; // rdx
  int v45; // edi
  char v46; // al
  char *v47; // rcx
  bool v48; // zf
  char v49; // bp
  unsigned int v50; // eax
  unsigned __int8 **v51; // rdx
  int v52; // eax
  unsigned __int8 *v53; // r12
  unsigned int v54; // edx
  __int64 *v55; // rax
  char *v56; // rax
  char v57; // al
  int v58; // eax
  int v59; // ebx
  __int64 v60; // r13
  int v61; // ebp
  const char *v62; // r9
  __int64 v63; // rbx
  __int64 v64; // rcx
  __int64 v65; // r8
  __int64 v66; // r9
  __int64 v67; // r13
  int v68; // r9d
  const char *v69; // r8
  _BYTE *v70; // rbx
  const char *v71; // rsi
  __int64 v72; // rax
  char v73; // dl
  __int64 v74; // rdx
  unsigned int v75; // edx
  __int64 *v76; // rax
  __int64 v77; // rbx
  unsigned int v78; // eax
  int v79; // eax
  __int64 v80; // rax
  int v81; // edx
  __int64 v82; // rbp
  __int64 v83; // rax
  int v84; // r13d
  int v85; // r13d
  int v86; // r13d
  int v87; // r13d
  int v88; // r13d
  int v89; // r13d
  int v90; // r13d
  int v91; // r13d
  int v92; // r13d
  int v93; // r13d
  const char *v94; // rsi
  __int64 v95; // r13
  int v96; // eax
  __int64 v97; // r8
  unsigned int v98; // r9d
  __int64 v99; // r9
  unsigned __int64 v100; // rcx
  char v101; // al
  unsigned int v102; // edx
  unsigned __int64 *v103; // rax
  unsigned int v104; // eax
  __int64 v105; // rdx
  unsigned __int64 v106; // rdx
  int v107; // r9d
  unsigned int v108; // ebx
  unsigned int v109; // r9d
  unsigned int v110; // ebx
  unsigned int v111; // r9d
  unsigned int v112; // ebx
  unsigned int v113; // eax
  unsigned __int64 *v114; // rdx
  char v115; // al
  char v116; // r11
  unsigned int v117; // eax
  unsigned __int64 *v118; // rdx
  unsigned __int64 v119; // rdx
  int v120; // eax
  int v121; // ebx
  unsigned __int64 *v122; // rax
  unsigned int v123; // ecx
  __int64 v124; // r13
  __int64 v125; // rbx
  unsigned int v126; // edx
  __int64 v127; // rax
  unsigned int v128; // edx
  __int64 v129; // rax
  unsigned int v130; // edx
  _DWORD *v131; // rax
  unsigned int v132; // edx
  _DWORD *v133; // rax
  unsigned int v134; // edx
  _DWORD *v135; // rax
  unsigned __int64 *v136; // rax
  __int64 v137; // rcx
  int v138; // r12d
  const char *v139; // rsi
  __int64 v140; // rax
  unsigned __int8 *v141; // rbp
  __int64 v142; // r12
  int v143; // r9d
  int v144; // eax
  int v145; // edi
  unsigned __int8 *v146; // rax
  const char *v147; // r9
  __int64 v148; // r13
  __int64 v149; // rcx
  __int64 v150; // rbx
  __int64 v151; // r8
  __int64 v152; // r9
  int v153; // r9d
  const char *v154; // r8
  _BYTE *v155; // r13
  const char *v156; // rsi
  unsigned int v157; // edx
  int *v158; // rax
  unsigned int v159; // edx
  int *v160; // rax
  unsigned int v161; // edx
  int *v162; // rax
  __int64 v163; // rsi
  char *v164; // r10
  __int64 v165; // rax
  char *v166; // r10
  char v167; // r11
  char v168; // dl
  __int64 v169; // r13
  __int64 v170; // rax
  unsigned int v171; // edx
  __int64 *v172; // rax
  unsigned int v173; // eax
  int v174; // eax
  __int64 v175; // rax
  __int64 v176; // rax
  int v177; // r13d
  int v178; // r13d
  int v179; // r13d
  int v180; // r13d
  int v181; // r13d
  int v182; // r13d
  int v183; // r13d
  int v184; // r13d
  int v185; // r13d
  int v186; // r13d
  int v187; // r13d
  int v188; // r13d
  int v189; // r13d
  int v190; // r13d
  int v191; // r13d
  int v192; // r13d
  const char *v193; // [rsp+0h] [rbp-128h]
  int v194; // [rsp+0h] [rbp-128h]
  unsigned __int8 *v195; // [rsp+8h] [rbp-120h]
  unsigned __int8 *v196; // [rsp+8h] [rbp-120h]
  int v197; // [rsp+10h] [rbp-118h]
  int v198; // [rsp+10h] [rbp-118h]
  _WORD *v201; // [rsp+50h] [rbp-D8h]
  int v202; // [rsp+50h] [rbp-D8h]
  int v203; // [rsp+50h] [rbp-D8h]
  unsigned int v205; // [rsp+50h] [rbp-D8h]
  char v206; // [rsp+50h] [rbp-D8h]
  char *v207; // [rsp+50h] [rbp-D8h]
  char *s1; // [rsp+58h] [rbp-D0h]
  int s1a; // [rsp+58h] [rbp-D0h]
  int s1b; // [rsp+58h] [rbp-D0h]
  size_t v211; // [rsp+60h] [rbp-C8h]
  int v212; // [rsp+60h] [rbp-C8h]
  char *v213; // [rsp+60h] [rbp-C8h]
  char v214; // [rsp+60h] [rbp-C8h]
  __int64 v215; // [rsp+68h] [rbp-C0h]
  int v216; // [rsp+68h] [rbp-C0h]
  int v217; // [rsp+68h] [rbp-C0h]
  unsigned __int8 *v218; // [rsp+70h] [rbp-B8h]
  int v219; // [rsp+78h] [rbp-B0h]
  __int64 v220; // [rsp+78h] [rbp-B0h]
  size_t na; // [rsp+80h] [rbp-A8h]
  unsigned __int8 *v224; // [rsp+88h] [rbp-A0h]
  int v225; // [rsp+90h] [rbp-98h]
  int v226; // [rsp+90h] [rbp-98h]
  int v227; // [rsp+90h] [rbp-98h]
  int v228; // [rsp+94h] [rbp-94h]
  unsigned __int64 v229; // [rsp+98h] [rbp-90h]
  unsigned __int16 v230; // [rsp+A0h] [rbp-88h]
  _BYTE dest[4]; // [rsp+A8h] [rbp-80h] BYREF
  char v232; // [rsp+ACh] [rbp-7Ch]
  _BYTE v233[123]; // [rsp+ADh] [rbp-7Bh] BYREF

  v9 = (_BYTE *)*a3;
  v225 = a5;
  v10 = *a3 + 1;
  *a3 = v10;
  if ( *v9 != 82 )
    return 0;
  *a3 = (__int64)(v9 + 2);
  v215 = (__int64)(v9 + 2);
  v12 = a1;
  v13 = a2;
  switch ( v9[1] )
  {
    case 'A':
      v19 = v9 + 2;
      do
      {
        v20 = *v19++;
        if ( !v20 )
          return 0;
      }
      while ( v20 != 91 );
      if ( !*v19 )
        return 0;
      if ( *v19 != 93 )
      {
        v72 = 0;
        while ( 1 )
        {
          v73 = v19[++v72];
          if ( !v73 )
            return 0;
          if ( v73 == 93 )
          {
            v74 = v72 + 1;
            goto LABEL_132;
          }
        }
      }
      v74 = 1;
      v72 = 0;
LABEL_132:
      *a3 = (__int64)&v19[v74];
      if ( &v19[-v215] != (_BYTE *)&loc_1 + 3 || v9[2] != 120 || v9[3] != 56 || v9[4] != 54 || v72 != 3 )
        return 0;
      if ( !strncmp("cr0", v19, 3u) )
      {
        v75 = *(_DWORD *)a4;
        if ( *(_DWORD *)a4 >= 0x30u )
        {
          v76 = *(__int64 **)(a4 + 8);
          *(_QWORD *)(a4 + 8) = v76 + 1;
        }
        else
        {
          v76 = (__int64 *)(*(_QWORD *)(a4 + 16) + v75);
          *(_DWORD *)a4 = v75 + 8;
        }
        v77 = *v76;
        v78 = a7;
        BYTE1(v78) = BYTE1(a7) | 0x40;
        v205 = v78;
        v79 = VBoxGuest_RTStrFormatNumber(dest, v77, 16, 8, 0xFFFFFFFFLL, a7 | 0x4004);
        v80 = a1(a2, (unsigned __int64)dest, v79);
        v81 = 0;
        v82 = v80;
        if ( (v77 & 1) != 0 )
        {
          v83 = a1(a2, (unsigned __int64)"{PE", 3u);
          v77 = (unsigned int)v77 & 0xFFFFFFFE;
          v81 = 1;
          v82 += v83;
        }
        if ( (v77 & 2) != 0 )
        {
          v84 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",MP", 3u);
          else
            v82 += a1(a2, (unsigned __int64)"{MP", 3u);
          v77 = (unsigned int)v77 & 0xFFFFFFFD;
          v81 = v84;
        }
        if ( (v77 & 4) != 0 )
        {
          v85 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",EM", 3u);
          else
            v82 += a1(a2, (unsigned __int64)"{EM", 3u);
          v77 = (unsigned int)v77 & 0xFFFFFFFB;
          v81 = v85;
        }
        if ( (v77 & 8) != 0 )
        {
          v86 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",DE", 3u);
          else
            v82 += a1(a2, (unsigned __int64)"{DE", 3u);
          v77 = (unsigned int)v77 & 0xFFFFFFF7;
          v81 = v86;
        }
        if ( (v77 & 0x10) != 0 )
        {
          v87 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",ET", 3u);
          else
            v82 += a1(a2, (unsigned __int64)"{ET", 3u);
          v77 = (unsigned int)v77 & 0xFFFFFFEF;
          v81 = v87;
        }
        if ( (v77 & 0x20) != 0 )
        {
          v88 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",NE", 3u);
          else
            v82 += a1(a2, (unsigned __int64)"{NE", 3u);
          v77 = (unsigned int)v77 & 0xFFFFFFDF;
          v81 = v88;
        }
        if ( (v77 & 0x10000) != 0 )
        {
          v89 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",WP", 3u);
          else
            v82 += a1(a2, (unsigned __int64)"{WP", 3u);
          v77 = (unsigned int)v77 & 0xFFFEFFFF;
          v81 = v89;
        }
        if ( (v77 & 0x40000) != 0 )
        {
          v90 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",AM", 3u);
          else
            v82 += a1(a2, (unsigned __int64)"{AM", 3u);
          v77 = (unsigned int)v77 & 0xFFFBFFFF;
          v81 = v90;
        }
        if ( (v77 & 0x20000000) != 0 )
        {
          v91 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",NW", 3u);
          else
            v82 += a1(a2, (unsigned __int64)"{NW", 3u);
          v77 = (unsigned int)v77 & 0xDFFFFFFF;
          v81 = v91;
        }
        if ( (v77 & 0x40000000) != 0 )
        {
          v92 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",CD", 3u);
          else
            v82 += a1(a2, (unsigned __int64)"{CD", 3u);
          v77 = (unsigned int)v77 & 0xBFFFFFFF;
          v81 = v92;
        }
        if ( (int)v77 < 0 )
        {
          v93 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",PG", 3u);
          else
            v82 += a1(a2, (unsigned __int64)"{PG", 3u);
          v77 &= 0x7FFFFFFFu;
          v81 = v93;
        }
        goto LABEL_182;
      }
      if ( !strncmp("cr4", v19, 3u) )
      {
        v171 = *(_DWORD *)a4;
        if ( *(_DWORD *)a4 >= 0x30u )
        {
          v172 = *(__int64 **)(a4 + 8);
          *(_QWORD *)(a4 + 8) = v172 + 1;
        }
        else
        {
          v172 = (__int64 *)(*(_QWORD *)(a4 + 16) + v171);
          *(_DWORD *)a4 = v171 + 8;
        }
        v77 = *v172;
        v173 = a7;
        BYTE1(v173) = BYTE1(a7) | 0x40;
        v205 = v173;
        v174 = VBoxGuest_RTStrFormatNumber(dest, v77, 16, 8, 0xFFFFFFFFLL, a7 | 0x4004);
        v175 = a1(a2, (unsigned __int64)dest, v174);
        v81 = 0;
        v82 = v175;
        if ( (v77 & 1) != 0 )
        {
          v176 = a1(a2, (unsigned __int64)"{VME", 4u);
          v77 = (unsigned int)v77 & 0xFFFFFFFE;
          v81 = 1;
          v82 += v176;
        }
        if ( (v77 & 2) != 0 )
        {
          v177 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",PVI", 4u);
          else
            v82 += a1(a2, (unsigned __int64)"{PVI", 4u);
          v77 = (unsigned int)v77 & 0xFFFFFFFD;
          v81 = v177;
        }
        if ( (v77 & 4) != 0 )
        {
          v178 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",TSD", 4u);
          else
            v82 += a1(a2, (unsigned __int64)"{TSD", 4u);
          v77 = (unsigned int)v77 & 0xFFFFFFFB;
          v81 = v178;
        }
        if ( (v77 & 8) != 0 )
        {
          v179 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",DE", 3u);
          else
            v82 += a1(a2, (unsigned __int64)"{DE", 3u);
          v77 = (unsigned int)v77 & 0xFFFFFFF7;
          v81 = v179;
        }
        if ( (v77 & 0x10) != 0 )
        {
          v180 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",PSE", 4u);
          else
            v82 += a1(a2, (unsigned __int64)"{PSE", 4u);
          v77 = (unsigned int)v77 & 0xFFFFFFEF;
          v81 = v180;
        }
        if ( (v77 & 0x20) != 0 )
        {
          v181 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",PAE", 4u);
          else
            v82 += a1(a2, (unsigned __int64)"{PAE", 4u);
          v77 = (unsigned int)v77 & 0xFFFFFFDF;
          v81 = v181;
        }
        if ( (v77 & 0x40) != 0 )
        {
          v182 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",MCE", 4u);
          else
            v82 += a1(a2, (unsigned __int64)"{MCE", 4u);
          v77 = (unsigned int)v77 & 0xFFFFFFBF;
          v81 = v182;
        }
        if ( (v77 & 0x80u) != 0LL )
        {
          v183 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",PGE", 4u);
          else
            v82 += a1(a2, (unsigned __int64)"{PGE", 4u);
          v77 = (unsigned int)v77 & 0xFFFFFF7F;
          v81 = v183;
        }
        if ( (v77 & 0x100) != 0 )
        {
          v184 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",PCE", 4u);
          else
            v82 += a1(a2, (unsigned __int64)"{PCE", 4u);
          v77 = (unsigned int)v77 & 0xFFFFFEFF;
          v81 = v184;
        }
        if ( (v77 & 0x200) != 0 )
        {
          v185 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",OSFXSR", 7u);
          else
            v82 += a1(a2, (unsigned __int64)"{OSFXSR", 7u);
          v77 = (unsigned int)v77 & 0xFFFFFDFF;
          v81 = v185;
        }
        if ( (v77 & 0x400) != 0 )
        {
          v186 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",OSXMMEEXCPT", 12u);
          else
            v82 += a1(a2, (unsigned __int64)"{OSXMMEEXCPT", 12u);
          v77 = (unsigned int)v77 & 0xFFFFFBFF;
          v81 = v186;
        }
        if ( (v77 & 0x2000) != 0 )
        {
          v187 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",VMXE", 5u);
          else
            v82 += a1(a2, (unsigned __int64)"{VMXE", 5u);
          v77 = (unsigned int)v77 & 0xFFFFDFFF;
          v81 = v187;
        }
        if ( (v77 & 0x4000) != 0 )
        {
          v188 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",SMXE", 5u);
          else
            v82 += a1(a2, (unsigned __int64)"{SMXE", 5u);
          v77 = (unsigned int)v77 & 0xFFFFBFFF;
          v81 = v188;
        }
        if ( (v77 & 0x20000) != 0 )
        {
          v189 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",PCIDE", 6u);
          else
            v82 += a1(a2, (unsigned __int64)"{PCIDE", 6u);
          v77 = (unsigned int)v77 & 0xFFFDFFFF;
          v81 = v189;
        }
        if ( (v77 & 0x40000) != 0 )
        {
          v190 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",OSXSAVE", 8u);
          else
            v82 += a1(a2, (unsigned __int64)"{OSXSAVE", 8u);
          v77 = (unsigned int)v77 & 0xFFFBFFFF;
          v81 = v190;
        }
        if ( (v77 & 0x100000) != 0 )
        {
          v191 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",SMEP", 5u);
          else
            v82 += a1(a2, (unsigned __int64)"{SMEP", 5u);
          v77 = (unsigned int)v77 & 0xFFEFFFFF;
          v81 = v191;
        }
        if ( (v77 & 0x200000) != 0 )
        {
          v192 = v81 + 1;
          if ( v81 )
            v82 += a1(a2, (unsigned __int64)",SMAP", 5u);
          else
            v82 += a1(a2, (unsigned __int64)"{SMAP", 5u);
          v77 = (unsigned int)v77 & 0xFFDFFFFF;
          if ( !(_DWORD)v77 )
            return v82 + a1(v13, (unsigned __int64)"}", 1u);
          v81 = v192;
          goto LABEL_183;
        }
LABEL_182:
        if ( !v77 )
        {
          result = v82;
          if ( !v81 )
            return result;
          return v82 + a1(v13, (unsigned __int64)"}", 1u);
        }
LABEL_183:
        v94 = ",unkn=";
        if ( !v81 )
          v94 = "{unkn=";
        v95 = a1(v13, (unsigned __int64)v94, 6u);
        v96 = VBoxGuest_RTStrFormatNumber(dest, v77, 16, 1, 0xFFFFFFFFLL, v205);
        v82 += v95 + a1(v13, (unsigned __int64)dest, v96);
        return v82 + a1(v13, (unsigned __int64)"}", 1u);
      }
      return 0;
    case 'C':
    case 'G':
    case 'H':
    case 'I':
    case 'K':
    case 'R':
    case 'T':
    case 'U':
    case 'X':
      v21 = 0;
      v22 = 31;
      v23 = 61;
      s1 = (char *)v10;
      while ( 2 )
      {
        v24 = v22;
        v25 = &s_aTypes_6697[24 * v22];
        v211 = (unsigned __int8)*v25;
        v26 = strncmp(s1, v25 + 1, v211);
        if ( !v26 )
        {
          v97 = v22;
          v98 = (unsigned __int16)word_23274[12 * v22];
          v229 = 0;
          v230 = 0;
          LODWORD(v13) = a2;
          v99 = a7 | v98;
          v100 = a4;
          LODWORD(v12) = (_DWORD)a1;
          *a3 = v215 + v211 - 1;
          if ( (v99 & 0x10) != 0 )
          {
            v101 = v25[11];
            if ( v101 == 2 )
            {
              v159 = *(_DWORD *)a4;
              if ( *(_DWORD *)a4 >= 0x30u )
              {
                v160 = *(int **)(a4 + 8);
                *(_QWORD *)(a4 + 8) = v160 + 2;
              }
              else
              {
                v160 = (int *)(*(_QWORD *)(a4 + 16) + v159);
                *(_DWORD *)a4 = v159 + 8;
              }
              v99 = (unsigned int)v99 | 0x1000;
              v229 = *v160;
            }
            else if ( (unsigned __int8)v101 <= 2u )
            {
              if ( v101 == 1 )
              {
                v157 = *(_DWORD *)a4;
                if ( *(_DWORD *)a4 >= 0x30u )
                {
                  v158 = *(int **)(a4 + 8);
                  *(_QWORD *)(a4 + 8) = v158 + 2;
                }
                else
                {
                  v158 = (int *)(*(_QWORD *)(a4 + 16) + v157);
                  *(_DWORD *)a4 = v157 + 8;
                }
                v99 = (unsigned int)v99 | 0x800;
                v229 = *v158;
              }
            }
            else if ( v101 == 4 )
            {
              v161 = *(_DWORD *)a4;
              if ( *(_DWORD *)a4 >= 0x30u )
              {
                v162 = *(int **)(a4 + 8);
                *(_QWORD *)(a4 + 8) = v162 + 2;
              }
              else
              {
                v162 = (int *)(*(_QWORD *)(a4 + 16) + v161);
                *(_DWORD *)a4 = v161 + 8;
              }
              v99 = (unsigned int)v99 | 0x2000;
              v229 = *v162;
            }
            else if ( v101 == 8 )
            {
LABEL_193:
              v102 = *(_DWORD *)a4;
              if ( *(_DWORD *)a4 >= 0x30u )
              {
                v103 = *(unsigned __int64 **)(a4 + 8);
                *(_QWORD *)(a4 + 8) = v103 + 1;
              }
              else
              {
                v103 = (unsigned __int64 *)(*(_QWORD *)(a4 + 16) + v102);
                *(_DWORD *)a4 = v102 + 8;
              }
              v99 = (unsigned int)v99 | 0x4000;
              v229 = *v103;
            }
          }
          else
          {
            switch ( v25[11] )
            {
              case 1:
                v134 = *(_DWORD *)a4;
                if ( *(_DWORD *)a4 >= 0x30u )
                {
                  v135 = *(_DWORD **)(a4 + 8);
                  *(_QWORD *)(a4 + 8) = v135 + 2;
                }
                else
                {
                  v135 = (_DWORD *)(*(_QWORD *)(a4 + 16) + v134);
                  *(_DWORD *)a4 = v134 + 8;
                }
                v99 = (unsigned int)v99 | 0x800;
                LOBYTE(v229) = *v135;
                break;
              case 2:
                v132 = *(_DWORD *)a4;
                if ( *(_DWORD *)a4 >= 0x30u )
                {
                  v133 = *(_DWORD **)(a4 + 8);
                  *(_QWORD *)(a4 + 8) = v133 + 2;
                }
                else
                {
                  v133 = (_DWORD *)(*(_QWORD *)(a4 + 16) + v132);
                  *(_DWORD *)a4 = v132 + 8;
                }
                v99 = (unsigned int)v99 | 0x1000;
                LOWORD(v229) = *v133;
                break;
              case 4:
                v130 = *(_DWORD *)a4;
                if ( *(_DWORD *)a4 >= 0x30u )
                {
                  v131 = *(_DWORD **)(a4 + 8);
                  *(_QWORD *)(a4 + 8) = v131 + 2;
                }
                else
                {
                  v131 = (_DWORD *)(*(_QWORD *)(a4 + 16) + v130);
                  *(_DWORD *)a4 = v130 + 8;
                }
                v99 = (unsigned int)v99 | 0x2000;
                LODWORD(v229) = *v131;
                break;
              case 6:
                v128 = *(_DWORD *)a4;
                if ( *(_DWORD *)a4 >= 0x30u )
                {
                  v129 = *(_QWORD *)(a4 + 8);
                  *(_QWORD *)(a4 + 8) = v129 + 8;
                }
                else
                {
                  v129 = *(_QWORD *)(a4 + 16) + v128;
                  *(_DWORD *)a4 = v128 + 8;
                }
                LODWORD(v229) = *(_DWORD *)v129;
                WORD2(v229) = *(_WORD *)(v129 + 4);
                break;
              case 8:
                goto LABEL_193;
              case 10:
                v126 = *(_DWORD *)a4;
                if ( *(_DWORD *)a4 >= 0x28u )
                {
                  v127 = *(_QWORD *)(a4 + 8);
                  *(_QWORD *)(a4 + 8) = v127 + 16;
                }
                else
                {
                  v127 = *(_QWORD *)(a4 + 16) + v126;
                  *(_DWORD *)a4 = v126 + 16;
                }
                v229 = *(_QWORD *)v127;
                v230 = *(_WORD *)(v127 + 8);
                break;
              default:
                break;
            }
          }
          if ( (v99 & 0x400) != 0 )
          {
            v140 = rtStrFormatKernelAddress(dest, 80, v229, (unsigned int)v225, (unsigned int)a6);
            return a1(a2, (unsigned __int64)dest, v140);
          }
          else
          {
            switch ( *((_DWORD *)&unk_23270 + 6 * v24) )
            {
              case 0:
                goto LABEL_200;
              case 1:
                if ( v225 < 0 )
                {
                  v104 = v99;
                  v99 = (unsigned int)v99 | 4;
                  v225 = ((v104 >> 2) & 2) + 2 * (unsigned __int8)byte_2326B[24 * v24];
                }
LABEL_200:
                v105 = (int)VBoxGuest_RTStrFormatNumber(
                              dest,
                              v229,
                              (unsigned __int8)byte_2326C[24 * v24],
                              (unsigned int)v225,
                              (unsigned int)a6,
                              v99);
                return a1(a2, (unsigned __int64)dest, v105);
              case 2:
                LODWORD(v17) = v229;
                if ( v229 == 1 )
                  return ((__int64 (__fastcall *)(__int64, const char *, __int64, unsigned __int64, __int64))a1)(
                           a2,
                           "true ",
                           5,
                           a4,
                           v97);
                if ( !v229 )
                  return ((__int64 (__fastcall *)(__int64, const char *, __int64, unsigned __int64, __int64))a1)(
                           a2,
                           "false",
                           5,
                           a4,
                           v97);
                v18 = "!%lld!";
                return VBoxGuest_RTStrFormat((_DWORD)v12, v13, 0, 0, (_DWORD)v18, v17);
              case 3:
                v112 = v99 & 0xFFFF046F;
                BYTE1(v112) = ((unsigned __int16)(v99 & 0x46F) >> 8) | 0x10;
                VBoxGuest_RTStrFormatNumber(dest, WORD1(v229), 16, 4, 0xFFFFFFFFLL, v112);
                v232 = 58;
                VBoxGuest_RTStrFormatNumber(v233, (unsigned __int16)v229, 16, 4, 0xFFFFFFFFLL, v112);
                v105 = 9;
                return a1(a2, (unsigned __int64)dest, v105);
              case 4:
                v110 = v99 & 0xFFFF046F;
                v111 = v110;
                BYTE1(v110) |= 0x20u;
                VBoxGuest_RTStrFormatNumber(dest, WORD2(v229), 16, 4, 0xFFFFFFFFLL, v111 | 0x1000);
                v232 = 58;
                VBoxGuest_RTStrFormatNumber(v233, (unsigned int)v229, 16, 8, 0xFFFFFFFFLL, v110);
                v105 = 13;
                return a1(a2, (unsigned __int64)dest, v105);
              case 5:
                v108 = v99 & 0xFFFF046F;
                v109 = v108;
                BYTE1(v108) |= 0x40u;
                VBoxGuest_RTStrFormatNumber(dest, v230, 16, 4, 0xFFFFFFFFLL, v109 | 0x1000);
                v232 = 58;
                VBoxGuest_RTStrFormatNumber(v233, v229, 16, 16, 0xFFFFFFFFLL, v108);
                v105 = 21;
                return a1(a2, (unsigned __int64)dest, v105);
              case 6:
                v107 = (unsigned __int8)v229;
                return VBoxGuest_RTStrFormat((_DWORD)a1, a2, 0, 0, (unsigned int)"%u.%u.%u.%u", v107);
              case 7:
                v106 = v229;
                if ( v229 + 0x200000 > 0x200FFF )
                {
                  v100 = v229 & 0xFF00000000000000LL;
                  if ( (v229 & 0xFF00000000000000LL) == 0 || v100 == 0xFF00000000000000LL )
                    return rtstrFormatIPv6(a1, a2, v106, v100, v97);
                }
                return ((__int64 (__fastcall *)(__int64, const char *, __int64, unsigned __int64, __int64))a1)(
                         a2,
                         "<NULL>",
                         6,
                         v100,
                         v97);
              case 8:
                if ( v229 + 0x200000 > 0x200FFF )
                {
                  v100 = v229 & 0xFF00000000000000LL;
                  if ( (v229 & 0xFF00000000000000LL) == 0 || v100 == 0xFF00000000000000LL )
                    return VBoxGuest_RTStrFormat(
                             (_DWORD)a1,
                             a2,
                             0,
                             0,
                             (unsigned int)"%02x:%02x:%02x:%02x:%02x:%02x",
                             *(unsigned __int8 *)v229);
                }
                return ((__int64 (__fastcall *)(__int64, const char *, __int64, unsigned __int64, __int64))a1)(
                         a2,
                         "<NULL>",
                         6,
                         v100,
                         v97);
              case 9:
                v106 = v229;
                if ( v229 + 0x200000 <= 0x200FFF )
                  return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD))a1)(
                           a2,
                           "<NULL>",
                           6,
                           v100,
                           v97);
                v100 = v229 & 0xFF00000000000000LL;
                if ( (v229 & 0xFF00000000000000LL) != 0 && v100 != 0xFF00000000000000LL )
                  return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD))a1)(
                           a2,
                           "<NULL>",
                           6,
                           v100,
                           v97);
                LODWORD(v17) = *(_DWORD *)(v229 + 16);
                if ( (_DWORD)v17 == 2 )
                {
                  if ( *(_DWORD *)(v229 + 20) == -1 )
                    return rtstrFormatIPv6(a1, a2, v106, v100, v97);
                  else
                    return VBoxGuest_RTStrFormat((_DWORD)a1, a2, 0, 0, (unsigned int)"[%RTnaipv6]:%u", v229);
                }
                if ( (_DWORD)v17 == 4 )
                  return VBoxGuest_RTStrFormat(
                           (_DWORD)a1,
                           a2,
                           0,
                           0,
                           (unsigned int)"%02x:%02x:%02x:%02x:%02x:%02x",
                           *(unsigned __int8 *)v229);
                v18 = "unsupported-netaddr-type=%u";
                if ( (_DWORD)v17 == 1 )
                {
                  v107 = *(unsigned __int8 *)v229;
                  if ( *(_DWORD *)(v229 + 20) == -1 )
                    return VBoxGuest_RTStrFormat((_DWORD)a1, a2, 0, 0, (unsigned int)"%u.%u.%u.%u", v107);
                  else
                    return VBoxGuest_RTStrFormat((_DWORD)a1, a2, 0, 0, (unsigned int)"%u.%u.%u.%u:%u", v107);
                }
                break;
              case 0xA:
                if ( v229 + 0x200000 > 0x200FFF
                  && ((v100 = v229 & 0xFF00000000000000LL, (v229 & 0xFF00000000000000LL) == 0)
                   || v100 == 0xFF00000000000000LL) )
                {
                  return VBoxGuest_RTStrFormat(
                           (_DWORD)a1,
                           a2,
                           0,
                           0,
                           (unsigned int)"%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x",
                           *(_DWORD *)v229);
                }
                else
                {
                  return ((__int64 (__fastcall *)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD))a1)(
                           a2,
                           "<NULL>",
                           6,
                           v100,
                           v97);
                }
              default:
                return 0;
            }
            return VBoxGuest_RTStrFormat((_DWORD)v12, v13, 0, 0, (_DWORD)v18, v17);
          }
        }
        if ( v23 != v21 )
        {
          if ( v26 >= 0 )
            v21 = v22 + 1;
          else
            v23 = v22 - 1;
          if ( v21 <= v23 )
          {
            v22 = (v23 - v21) / 2 + v21;
            continue;
          }
        }
        return 0;
      }
    case 'D':
      if ( strncmp(v9 + 1, "Dtimespec", 9u) )
        return 0;
      *a3 = (__int64)(v9 + 10);
      v27 = *(_DWORD *)a4;
      if ( *(_DWORD *)a4 >= 0x30u )
      {
        v28 = *(unsigned __int64 **)(a4 + 8);
        *(_QWORD *)(a4 + 8) = v28 + 1;
      }
      else
      {
        v28 = (unsigned __int64 *)(*(_QWORD *)(a4 + 16) + v27);
        *(_DWORD *)a4 = v27 + 8;
      }
      v29 = *v28;
      if ( *v28 + 0x200000 <= 0x200FFF
        || (v29 & 0xFF00000000000000LL) != 0 && (v29 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
      {
        return a1(v13, (unsigned __int64)"<null>", 6u);
      }
      v17 = *(_QWORD *)v29;
      v18 = "%'lld ns";
      return VBoxGuest_RTStrFormat((_DWORD)v12, v13, 0, 0, (_DWORD)v18, v17);
    case 'b':
      *a3 = (__int64)(v9 + 3);
      v30 = v9[2];
      if ( v30 == 110 )
      {
        v113 = *(_DWORD *)a4;
        if ( *(_DWORD *)a4 >= 0x30u )
        {
          v114 = *(unsigned __int64 **)(a4 + 8);
          *(_QWORD *)(a4 + 8) = v114 + 1;
        }
        else
        {
          v114 = (unsigned __int64 *)(*(_QWORD *)(a4 + 16) + v113);
          *(_DWORD *)a4 = v113 + 8;
        }
        v44 = *v114;
        if ( v44 + 0x200000 > 0x200FFF
          && ((v44 & 0xFF00000000000000LL) == 0 || (v44 & 0xFF00000000000000LL) == 0xFF00000000000000LL) )
        {
          v115 = *(_BYTE *)v44;
          v42 = v44;
          if ( !*(_BYTE *)v44 )
            return v12(v13, v42, v44 - v42);
          while ( 1 )
          {
            if ( v115 == 47 )
            {
              do
              {
                if ( !*(_BYTE *)++v44 )
                  return v12(v13, v42, v44 - v42);
              }
              while ( *(_BYTE *)v44 == 47 );
              v42 = v44;
            }
            v115 = *(_BYTE *)++v44;
            if ( !v115 )
              return v12(v13, v42, v44 - v42);
          }
        }
        return a1(v13, (unsigned __int64)"<null>", 6u);
      }
      if ( v30 != 115 || a8 != 108 )
        return 0;
      v31 = *(_DWORD *)a4;
      if ( *(_DWORD *)a4 >= 0x30u )
      {
        v32 = *(unsigned __int64 **)(a4 + 8);
        *(_QWORD *)(a4 + 8) = v32 + 1;
      }
      else
      {
        v32 = (unsigned __int64 *)(*(_QWORD *)(a4 + 16) + v31);
        *(_DWORD *)a4 = v31 + 8;
      }
      v33 = *v32;
      if ( *v32 + 0x200000 <= 0x200FFF
        || (v33 & 0xFF00000000000000LL) != 0 && (v33 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
      {
        v36 = 5;
        v33 = (unsigned __int64)&s_wszBigNull_6774;
        v35 = 6;
      }
      else if ( a6 > 0 && *(_WORD *)v33 )
      {
        v34 = (_WORD *)(v33 + 2);
        v35 = 0;
        do
        {
          if ( ++v35 == a6 )
            break;
          ++v34;
        }
        while ( *(v34 - 1) );
        v36 = v35 - 1;
      }
      else
      {
        v36 = -1;
        v35 = 0;
      }
      v37 = 0;
      if ( (a7 & 2) == 0 )
      {
        v225 = a5 - 1;
        if ( v35 <= a5 - 1 )
        {
          v201 = (_WORD *)v33;
          v38 = a5 - 1;
          do
          {
            --v38;
            v37 += a1(a2, (unsigned __int64)" ", 1u);
          }
          while ( v35 <= v38 );
          v225 = v38;
          v33 = (unsigned __int64)v201;
        }
      }
      v202 = v225 - v35;
      if ( v35 > 0 )
      {
        do
        {
          v33 += 2LL;
          --v36;
          dest[0] = *(_BYTE *)(v33 - 1);
          v37 += a1(a2, (unsigned __int64)dest, 1u);
        }
        while ( v36 + 1 > 0 );
      }
      v39 = v202 - 1;
      if ( v202 - 1 >= 0 )
      {
        do
        {
          --v39;
          v37 += a1(a2, (unsigned __int64)" ", 1u);
        }
        while ( v39 != -1 );
      }
      return v37;
    case 'f':
      *a3 = (__int64)(v9 + 3);
      if ( v9[2] != 110 )
        return 0;
      v40 = *(_DWORD *)a4;
      if ( *(_DWORD *)a4 >= 0x30u )
      {
        v41 = *(unsigned __int64 **)(a4 + 8);
        *(_QWORD *)(a4 + 8) = v41 + 1;
      }
      else
      {
        v41 = (unsigned __int64 *)(*(_QWORD *)(a4 + 16) + v40);
        *(_DWORD *)a4 = v40 + 8;
      }
      v42 = *v41;
      if ( *v41 + 0x200000 <= 0x200FFF
        || (v42 & 0xFF00000000000000LL) != 0 && (v42 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
      {
        return a1(v13, (unsigned __int64)"<null>", 6u);
      }
      v43 = *(_BYTE *)v42;
      v44 = *v41;
      v45 = 0;
      while ( 2 )
      {
        if ( !v43 )
          return v12(v13, v42, v44 - v42);
LABEL_61:
        if ( v43 != 40 )
        {
          if ( v43 != 9 && v43 != 32 )
          {
            if ( v43 == 60 )
            {
              v43 = *(_BYTE *)(v44 + 1);
              ++v45;
              ++v44;
            }
            else
            {
              if ( v43 == 62 )
              {
                v43 = *(_BYTE *)(v44 + 1);
                --v45;
              }
              else
              {
                v43 = *(_BYTE *)(v44 + 1);
              }
              ++v44;
            }
            continue;
          }
          v46 = *(_BYTE *)(v44 + 1);
          v47 = (char *)(v44 + 1);
          if ( v46 )
          {
            while ( (v46 & 0xF7) == 0x20 || v46 == 9 )
            {
              v46 = *++v47;
              if ( !*v47 )
                goto LABEL_118;
            }
            v48 = v46 == 0;
            v43 = *v47;
            if ( v48 || v45 )
            {
              v44 = (unsigned __int64)v47;
              continue;
            }
            v45 = 0;
            v42 = (unsigned __int64)v47;
            v44 = (unsigned __int64)v47;
            if ( !v43 )
              return v12(v13, v42, v44 - v42);
            goto LABEL_61;
          }
LABEL_118:
          v44 = (unsigned __int64)v47;
        }
        return v12(v13, v42, v44 - v42);
      }
    case 'h':
      *a3 = (__int64)(v9 + 3);
      v49 = v9[2];
      if ( v49 == 99 )
        goto LABEL_243;
      if ( v49 <= 99 )
      {
        if ( v49 != 88 )
          return 0;
LABEL_75:
        v50 = *(_DWORD *)a4;
        if ( *(_DWORD *)a4 >= 0x30u )
        {
          v51 = *(unsigned __int8 ***)(a4 + 8);
          *(_QWORD *)(a4 + 8) = v51 + 1;
        }
        else
        {
          v51 = (unsigned __int8 **)(*(_QWORD *)(a4 + 16) + v50);
          *(_DWORD *)a4 = v50 + 8;
        }
        v52 = 16;
        v53 = *v51;
        if ( a6 >= 0 )
          v52 = a6;
        v203 = v52;
        if ( v49 == 120 )
        {
          v218 = *v51;
          v212 = 16;
        }
        else
        {
          v54 = *(_DWORD *)a4;
          if ( *(_DWORD *)a4 >= 0x30u )
          {
            v55 = *(__int64 **)(a4 + 8);
            *(_QWORD *)(a4 + 8) = v55 + 1;
          }
          else
          {
            v55 = (__int64 *)(*(_QWORD *)(a4 + 16) + v54);
            *(_DWORD *)a4 = v54 + 8;
          }
          v212 = 16;
          v218 = (unsigned __int8 *)*v55;
          if ( (unsigned __int64)*v55 <= 0xFFFFFFFF )
            v212 = (unsigned __int64)(*v55 + v203) > 0xFFFFFFFF ? 16 : 8;
        }
        if ( !v53 )
          return a1(v13, (unsigned __int64)"<null>", 6u);
        v56 = (char *)(*a3)++;
        v57 = *v56;
        if ( v57 == 100 )
        {
          v144 = 16;
          if ( a5 > 0 )
            v144 = a5;
          if ( !v203 )
            return 0;
          v217 = v144;
          v220 = v144;
          v145 = v144;
          v146 = v218;
          v227 = 0;
          v37 = 0;
          v147 = (const char *)&unk_26D11;
          s1b = (int)v53;
          while ( 1 )
          {
            v196 = v146;
            v148 = 0;
            v198 = v227;
            v194 = v212;
            v150 = VBoxGuest_RTStrFormat((_DWORD)v12, v13, 0, 0, (unsigned int)"%s%0*llx/%04x:", (_DWORD)v147) + v37;
            while ( v203 > (int)v148 + v227 )
            {
              v153 = v53[v148];
              v154 = " %02x";
              if ( (v148 & 7) == 0 && (_DWORD)v148 )
                v154 = "-%02x";
              ++v148;
              v150 += VBoxGuest_RTStrFormat((_DWORD)v12, v13, 0, 0, (_DWORD)v154, v153);
              if ( v145 <= (int)v148 )
                goto LABEL_328;
            }
            for ( ;
                  (int)v148 < v145;
                  v150 += ((__int64 (__fastcall *)(__int64, const char *, __int64, __int64, __int64, __int64, int, unsigned __int8 *, int))v12)(
                            v13,
                            "   ",
                            3,
                            v149,
                            v151,
                            v152,
                            v194,
                            v196,
                            v198) )
            {
              LODWORD(v148) = v148 + 1;
            }
LABEL_328:
            v155 = v53;
            v37 = v12(v13, (unsigned __int64)" ", 1u) + v150;
            do
            {
              if ( v203 <= (int)v155 - s1b )
                break;
              v156 = ".";
              dest[0] = *v155;
              if ( (unsigned __int8)(dest[0] - 32) <= 0x5Eu )
                v156 = dest;
              ++v155;
              v37 += v12(v13, (unsigned __int64)v156, 1u);
            }
            while ( (int)v155 - (int)v53 < v145 );
            v53 += v220;
            v227 += v145;
            if ( v203 <= v217 )
              return v37;
            v147 = (const char *)&unk_26D11;
            v146 = &v218[v227];
            if ( v217 )
              v147 = "\n";
            v217 += v145;
          }
        }
        if ( v57 != 115 )
        {
          if ( v57 != 68 )
            return 0;
          v58 = 16;
          if ( a5 > 0 )
            v58 = a5;
          v228 = v203 - v58;
          if ( !v203 )
            return 0;
          s1a = (int)v53;
          na = v58;
          v59 = 0;
          v226 = 0;
          v60 = 0;
          v61 = v58;
          v224 = &v53[v58];
          v216 = v58;
          while ( v226 > 0 && v228 > v226 && !memcmp(v53, &v53[-na], na) )
          {
            v219 = v216;
            if ( !v59 && (v228 <= v216 || memcmp(v224, v53, na)) )
              goto LABEL_103;
            ++v59;
LABEL_98:
            v226 += v61;
            v216 += v61;
            v224 += na;
            v53 += na;
            if ( v203 <= v219 )
              return v60;
          }
          if ( v59 )
          {
            v193 = "****************";
            v60 += VBoxGuest_RTStrFormat((_DWORD)a1, v13, 0, 0, (unsigned int)"\n%.*s ****  <ditto x %u>", v212);
          }
          v219 = v216;
LABEL_103:
          v62 = (const char *)&unk_26D11;
          v197 = v226;
          v195 = &v218[v226];
          LODWORD(v193) = v212;
          if ( v226 )
            v62 = "\n";
          v63 = 0;
          v67 = VBoxGuest_RTStrFormat((_DWORD)a1, v13, 0, 0, (unsigned int)"%s%0*llx/%04x:", (_DWORD)v62) + v60;
          while ( v203 > (int)v63 + v226 )
          {
            v68 = v53[v63];
            v69 = " %02x";
            if ( (v63 & 7) == 0 && (_DWORD)v63 )
              v69 = "-%02x";
            ++v63;
            v67 += VBoxGuest_RTStrFormat((_DWORD)a1, v13, 0, 0, (_DWORD)v69, v68);
            if ( v61 <= (int)v63 )
              goto LABEL_111;
          }
          for ( ;
                v61 > (int)v63;
                v67 += ((__int64 (__fastcall *)(__int64, const char *, __int64, __int64, __int64, __int64, const char *, unsigned __int8 *, int))a1)(
                         v13,
                         "   ",
                         3,
                         v64,
                         v65,
                         v66,
                         v193,
                         v195,
                         v197) )
          {
            LODWORD(v63) = v63 + 1;
          }
LABEL_111:
          v70 = v53;
          v60 = a1(v13, (unsigned __int64)" ", 1u) + v67;
          do
          {
            if ( v203 <= (int)v70 - s1a )
              break;
            v71 = ".";
            dest[0] = *v70;
            if ( (unsigned __int8)(dest[0] - 32) <= 0x5Eu )
              v71 = dest;
            ++v70;
            v60 += a1(v13, (unsigned __int64)v71, 1u);
          }
          while ( v61 > (int)v70 - (int)v53 );
          v59 = 0;
          goto LABEL_98;
        }
        if ( v203 )
        {
          v48 = v49 == 120;
          v141 = v53 + 1;
          if ( v48 )
            v37 = VBoxGuest_RTStrFormat((_DWORD)a1, a2, 0, 0, (unsigned int)"%02x", *v53);
          else
            v37 = VBoxGuest_RTStrFormat((_DWORD)a1, a2, 0, 0, (unsigned int)"%0*llx: %02x", v212);
          if ( v203 != 1 )
          {
            v142 = (__int64)&v141[v203 - 2 + 1];
            do
            {
              v143 = *v141++;
              v37 += VBoxGuest_RTStrFormat((_DWORD)a1, a2, 0, 0, (unsigned int)" %02x", v143);
            }
            while ( v141 != (unsigned __int8 *)v142 );
          }
          return v37;
        }
        return 0;
      }
      if ( v49 != 117 )
      {
        if ( v49 != 120 )
          return 0;
        goto LABEL_75;
      }
LABEL_243:
      *a3 = (__int64)(v9 + 4);
      v116 = v9[3];
      if ( (v116 & 0xDF) != 0x42 && v116 != 105 )
        return 0;
      v117 = *(_DWORD *)a4;
      if ( *(_DWORD *)a4 >= 0x30u )
      {
        v118 = *(unsigned __int64 **)(a4 + 8);
        *(_QWORD *)(a4 + 8) = v118 + 1;
      }
      else
      {
        v118 = (unsigned __int64 *)(*(_QWORD *)(a4 + 16) + v117);
        *(_DWORD *)a4 = v117 + 8;
      }
      v119 = *v118;
      if ( (a7 & 0x100) != 0 )
      {
        v120 = 0;
        v121 = 3;
        if ( a6 >= 0 )
          v120 = a6;
        if ( v120 <= 3 )
          v121 = v120;
      }
      else
      {
        v121 = 1;
      }
      if ( (v116 & 0xDF) != 0x42 )
      {
        v136 = (unsigned __int64 *)&unk_230E8;
        v137 = 0;
        do
        {
          if ( v119 >= *v136 && (v121 || v119 >= v136[1]) )
          {
            v164 = (&s_aUnits_6868)[3 * v137];
            goto LABEL_362;
          }
          v137 = (unsigned int)(v137 + 1);
          v136 += 3;
        }
        while ( (_DWORD)v137 != 6 );
LABEL_257:
        v124 = VBoxGuest_RTStrFormatU64(dest, 0);
        goto LABEL_258;
      }
      v122 = (unsigned __int64 *)&unk_23190;
      v123 = 0;
      while ( 1 )
      {
        if ( v119 < *v122 )
          goto LABEL_256;
        if ( v121 )
          break;
        if ( v119 >= v122[1] )
        {
          v163 = v123;
          goto LABEL_361;
        }
LABEL_256:
        ++v123;
        v122 += 4;
        if ( v123 == 6 )
          goto LABEL_257;
      }
      v163 = v123;
LABEL_361:
      v164 = (&s_aUnits_6860)[4 * v163];
LABEL_362:
      v213 = v164;
      v206 = v116;
      v165 = VBoxGuest_RTStrFormatU64(dest, 0);
      v166 = v213;
      if ( !v213 )
      {
        v124 = v165;
LABEL_258:
        if ( (a7 & 0x40) != 0 )
          dest[v124++] = 32;
        goto LABEL_260;
      }
      v167 = v206;
      if ( v121 )
      {
        v169 = v165 + 1;
        dest[v165] = 46;
        v214 = v206;
        v207 = v166;
        v170 = VBoxGuest_RTStrFormatU64(&dest[v165 + 1], 132);
        v167 = v214;
        v165 = v169 + v170;
        v166 = v207;
      }
      if ( (a7 & 0x40) != 0 )
        dest[v165++] = 32;
      v124 = v165 + 1;
      dest[v165] = *v166;
      v168 = v166[1];
      if ( v168 && v167 != 66 )
      {
        dest[v124] = v168;
        v124 = v165 + 2;
      }
LABEL_260:
      if ( v49 == 99 )
        dest[v124++] = 66;
      v125 = 0;
      dest[v124] = 0;
      if ( (a7 & 0x82) == 0x80 && v124 < v225 )
      {
        v138 = v225;
        do
        {
          v139 = "0";
          if ( (a7 & 4) == 0 )
            v139 = " ";
          --v138;
          v125 += a1(v13, (unsigned __int64)v139, 1u);
        }
        while ( v124 < v138 );
      }
      return v125 + a1(v13, (unsigned __int64)dest, v124);
    case 'r':
      v14 = *(_DWORD *)a4;
      if ( *(_DWORD *)a4 >= 0x30u )
      {
        v15 = *(_DWORD **)(a4 + 8);
        *(_QWORD *)(a4 + 8) = v15 + 2;
      }
      else
      {
        v15 = (_DWORD *)(*(_QWORD *)(a4 + 16) + v14);
        *(_DWORD *)a4 = v14 + 8;
      }
      v16 = (_BYTE *)*a3;
      LODWORD(v17) = *v15;
      ++*a3;
      if ( (unsigned __int8)(*v16 - 97) > 0x12u || ((1LL << (*v16 - 97)) & 0x40025) == 0 )
        return 0;
      v18 = "%d";
      return VBoxGuest_RTStrFormat((_DWORD)v12, v13, 0, 0, (_DWORD)v18, v17);
    default:
      return 0;
  }
}
