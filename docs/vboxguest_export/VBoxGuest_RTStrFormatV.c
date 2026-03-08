__int64 __fastcall VBoxGuest_RTStrFormatV(
        __int64 (*a1)(__int64, const char *, ...),
        __int64 a2,
        __int64 (__fastcall *a3)(__int64, __int64 (*)(__int64, const char *, ...), __int64, char **, __int64 *, _QWORD, _DWORD, unsigned int, int),
        __int64 a4,
        __int64 a5,
        __int64 *a6)
{
  __int64 v7; // rsi
  __int64 v9; // rbx
  char *v10; // rdx
  char v11; // al
  __int64 v13; // rax
  char *v14; // rdx
  unsigned int v15; // r9d
  char *v16; // rax
  int v17; // edi
  int v18; // esi
  int *v19; // rcx
  int v20; // r15d
  __int64 v21; // r8
  char v22; // al
  int *v23; // rsi
  char v24; // r10
  int v25; // esi
  char v26; // r10
  char *v27; // rax
  char v28; // al
  bool v29; // zf
  __int64 v30; // rax
  unsigned int v31; // eax
  __int64 v32; // rdx
  __int64 v33; // r8
  _QWORD **v34; // rsi
  _QWORD *v35; // rax
  __int64 *v36; // rsi
  const char **v37; // rax
  const char *v38; // r14
  const char *v39; // rax
  int v40; // r13d
  __int64 v41; // rdx
  const char *i; // rsi
  int *v43; // rax
  int v44; // eax
  int v45; // r13d
  char *v46; // rax
  int v47; // edi
  char v48; // r10
  __int64 *v49; // rax
  unsigned __int64 *v50; // rsi
  unsigned __int64 v51; // r13
  _DWORD *v52; // rax
  int v53; // r14d
  int v54; // r15d
  int v55; // r13d
  unsigned int v56; // edx
  unsigned int v57; // esi
  int *v58; // rax
  unsigned __int64 v59; // rsi
  unsigned __int64 *v60; // rsi
  unsigned int *v61; // rax
  unsigned __int64 *v62; // rax
  int v63; // eax
  __int16 **v64; // rsi
  __int16 *v65; // r14
  __int16 *v66; // r13
  int v67; // r13d
  int v68; // r15d
  int v69; // r13d
  int *v70; // rsi
  const char *v71; // rax
  int *v72; // rax
  int *v73; // rax
  __int64 v74; // [rsp+0h] [rbp-D8h]
  __int64 v77; // [rsp+28h] [rbp-B0h]
  int v78; // [rsp+28h] [rbp-B0h]
  int v79; // [rsp+28h] [rbp-B0h]
  char *v80; // [rsp+30h] [rbp-A8h] BYREF
  __int64 v81; // [rsp+38h] [rbp-A0h] BYREF
  int *v82; // [rsp+40h] [rbp-98h]
  __int64 v83; // [rsp+48h] [rbp-90h]
  _QWORD v84[3]; // [rsp+50h] [rbp-88h] BYREF
  char v85[112]; // [rsp+68h] [rbp-70h] BYREF

  v7 = a5;
  v9 = 0;
  v10 = (char *)a5;
  v80 = (char *)a5;
  v81 = *a6;
  v82 = (int *)a6[1];
  v83 = a6[2];
  while ( 1 )
  {
    v11 = *v10;
    if ( !*v10 )
      break;
    while ( v11 != 37 )
    {
      v80 = ++v10;
      v11 = *v10;
      if ( !*v10 )
        goto LABEL_5;
    }
    if ( (char *)v7 != v10 )
    {
      v13 = a1(a2, (const char *)v7, &v10[-v7]);
      v10 = v80;
      v9 += v13;
    }
    v7 = (__int64)(v10 + 1);
    v80 = v10 + 1;
    if ( v10[1] == 37 )
    {
      v10 += 2;
      v80 = v10;
    }
    else
    {
      v14 = v10 + 1;
      v15 = 0;
      while ( 2 )
      {
        v16 = v14 + 1;
        v80 = v14 + 1;
        switch ( *v14 )
        {
          case ' ':
            v15 |= 0x40u;
            goto LABEL_14;
          case '#':
            v15 |= 8u;
            goto LABEL_14;
          case '\'':
            v15 |= 0x200u;
            goto LABEL_14;
          case '+':
            v15 |= 0x20u;
            goto LABEL_14;
          case '-':
            v15 |= 2u;
            goto LABEL_14;
          case '0':
            v15 |= 4u;
LABEL_14:
            ++v14;
            continue;
          default:
            v80 = v14;
            v17 = *v14;
            v18 = v17;
            v19 = (int *)(unsigned int)(v17 - 48);
            if ( (unsigned int)v19 <= 9 )
            {
              v20 = 0;
              do
              {
                v80 = v16;
                v17 = *v16;
                v20 = v18 + 10 * v20 - 48;
                v14 = v16++;
                v18 = (char)v17;
              }
              while ( (unsigned int)((char)v17 - 48) <= 9 );
              LOBYTE(v15) = v15 | 0x80;
LABEL_24:
              v21 = 0xFFFFFFFFLL;
              if ( (_BYTE)v17 != 46 )
                goto LABEL_25;
              goto LABEL_33;
            }
            v20 = -1;
            if ( (_BYTE)v17 != 42 )
              goto LABEL_24;
            v80 = v14 + 1;
            if ( (unsigned int)v81 >= 0x30 )
            {
              v23 = v82;
              v19 = v82 + 2;
              v82 += 2;
            }
            else
            {
              v19 = (int *)(unsigned int)(v81 + 8);
              v23 = (int *)(v83 + (unsigned int)v81);
              LODWORD(v81) = v81 + 8;
            }
            v20 = *v23;
            if ( *v23 < 0 )
            {
              v20 = -v20;
              v15 |= 2u;
            }
            v17 = v14[1];
            LOBYTE(v15) = v15 | 0x80;
            ++v14;
            v21 = 0xFFFFFFFFLL;
            if ( (_BYTE)v17 != 46 )
            {
LABEL_25:
              v22 = v17 - 73;
              goto LABEL_26;
            }
LABEL_33:
            v80 = v14 + 1;
            v24 = v14[1];
            v25 = v24;
            if ( (unsigned int)(v24 - 48) <= 9 )
            {
              v46 = v14 + 2;
              v47 = 0;
              do
              {
                v80 = v46;
                v48 = *v46;
                v47 = v25 + 10 * v47 - 48;
                v14 = v46++;
                v25 = v48;
              }
              while ( (unsigned int)(v48 - 48) <= 9 );
              v21 = 0;
              if ( v47 >= 0 )
                v21 = (unsigned int)v47;
              v17 = v48;
            }
            else if ( v24 == 42 )
            {
              v80 = v14 + 2;
              if ( (unsigned int)v81 >= 0x30 )
              {
                v70 = v82;
                v82 += 2;
              }
              else
              {
                v70 = (int *)(v83 + (unsigned int)v81);
                LODWORD(v81) = v81 + 8;
              }
              v21 = 0;
              v17 = v14[2];
              v14 += 2;
              if ( *v70 >= 0 )
                v21 = (unsigned int)*v70;
            }
            else
            {
              v17 = v24;
              ++v14;
              v21 = 0;
            }
            v22 = v17 - 73;
            v15 |= 0x100u;
            if ( (unsigned __int8)(v17 - 73) > 0x31u )
            {
LABEL_37:
              v17 = 0;
              goto LABEL_40;
            }
LABEL_26:
            switch ( v22 )
            {
              case 0:
                v28 = v14[1];
                if ( v28 == 54 )
                {
                  if ( v14[2] != 52 )
                    goto LABEL_46;
                  v14 += 3;
                  v17 = 76;
                }
                else
                {
                  if ( v28 != 51 || v14[2] != 50 )
                  {
LABEL_46:
                    ++v14;
                    v17 = 106;
                    goto LABEL_40;
                  }
                  v14 += 3;
                  v17 = 0;
                }
                break;
              case 3:
              case 33:
              case 43:
              case 49:
                ++v14;
                goto LABEL_40;
              case 31:
                v27 = v14 + 1;
                v80 = v14 + 1;
                if ( v14[1] != 104 )
                  goto LABEL_42;
                v14 += 2;
                v17 = 72;
                goto LABEL_40;
              case 35:
                v27 = v14 + 1;
                v80 = v14 + 1;
                if ( v14[1] == 108 )
                {
                  v14 += 2;
                  v17 = 76;
                }
                else
                {
LABEL_42:
                  v14 = v27;
                }
                goto LABEL_40;
              case 40:
                ++v14;
                v17 = 76;
                goto LABEL_40;
              default:
                goto LABEL_37;
            }
            break;
        }
        break;
      }
LABEL_40:
      v7 = (__int64)(v14 + 1);
      v80 = v14 + 1;
      v26 = *v14;
      switch ( *v14 )
      {
        case 'M':
          if ( (unsigned int)v81 >= 0x30 )
          {
            v36 = (__int64 *)v82;
            v82 += 2;
          }
          else
          {
            v36 = (__int64 *)(v83 + (unsigned int)v81);
            LODWORD(v81) = v81 + 8;
          }
          v7 = *v36;
          v80 = (char *)v7;
          goto LABEL_51;
        case 'N':
          v31 = v81;
          if ( (unsigned int)v81 >= 0x30 )
          {
            v49 = (__int64 *)v82;
            v34 = (_QWORD **)(v82 + 2);
            v82 += 2;
            v33 = *v49;
          }
          else
          {
            v32 = (unsigned int)(v81 + 8);
            LODWORD(v81) = v32;
            v33 = *(_QWORD *)(v83 + v31);
            if ( (unsigned int)v32 <= 0x2F )
            {
              v34 = (_QWORD **)(v32 + v83);
              LODWORD(v81) = v31 + 16;
              goto LABEL_55;
            }
            v34 = (_QWORD **)v82;
          }
          v82 = (int *)(v34 + 1);
LABEL_55:
          v35 = *v34;
          v84[0] = **v34;
          v84[1] = v35[1];
          v84[2] = v35[2];
          v9 += VBoxGuest_RTStrFormatV(a1, a2, a3, a4, v33, v84);
          v7 = (__int64)v80;
          goto LABEL_51;
        case 'R':
          v29 = v14[1] == 91;
          v80 = v14;
          LODWORD(v74) = v15;
          if ( v29 )
          {
            v9 += rtstrFormatType(a1, a2, &v80, (unsigned int *)&v81, v20, v21, v74);
            v7 = (__int64)v80;
          }
          else
          {
            v30 = rtstrFormatRt(
                    (__int64 (__fastcall *)(__int64, unsigned __int64, unsigned __int64))a1,
                    a2,
                    (__int64 *)&v80,
                    (unsigned __int64)&v81,
                    v20,
                    v21,
                    v15,
                    v17);
            v7 = (__int64)v80;
            v9 += v30;
          }
          goto LABEL_51;
        case 'S':
        case 's':
          if ( (_BYTE)v17 == 108 )
          {
            if ( (unsigned int)v81 >= 0x30 )
            {
              v64 = (__int16 **)v82;
              v82 += 2;
            }
            else
            {
              v64 = (__int16 **)(v83 + (unsigned int)v81);
              LODWORD(v81) = v81 + 8;
            }
            v65 = *v64;
            if ( (unsigned __int64)(*v64 + 0x100000) <= 0x200FFF )
            {
              v65 = s_wszNull_27929;
            }
            else if ( ((unsigned __int64)v65 & 0xFF00000000000000LL) != 0
                   && ((unsigned __int64)v65 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
            {
              v65 = s_wszNull_27929;
            }
            if ( (_DWORD)v21 && *v65 )
            {
              v66 = v65;
              do
                ++v66;
              while ( v66 != &v65[(unsigned int)(v21 - 1) + 1] && *v66 );
              v79 = v66 - v65;
              v67 = v79 - 1;
            }
            else
            {
              v67 = -1;
              v79 = 0;
            }
            if ( (v15 & 2) == 0 )
            {
              while ( --v20 >= v79 )
                v9 += a1(a2, " ", 1);
            }
            v68 = v20 - v79;
            if ( v79 > 0 )
            {
              do
              {
                ++v65;
                --v67;
                LOBYTE(v84[0]) = *(v65 - 1);
                v9 += a1(a2, (const char *)v84, 1);
              }
              while ( v67 + 1 > 0 );
            }
            v69 = v68 - 1;
            if ( v68 - 1 >= 0 )
            {
              do
              {
                --v69;
                v9 += a1(a2, " ", 1);
              }
              while ( v69 != -1 );
            }
          }
          else if ( (_BYTE)v17 == 76 )
          {
            if ( (unsigned int)v81 >= 0x30 )
            {
              v50 = (unsigned __int64 *)v82;
              v82 += 2;
            }
            else
            {
              v50 = (unsigned __int64 *)(v83 + (unsigned int)v81);
              LODWORD(v81) = v81 + 8;
            }
            v51 = *v50;
            if ( *v50 + 0x200000 <= 0x200FFF )
            {
              v51 = (unsigned __int64)&s_uszNull_27942;
            }
            else if ( (v51 & 0xFF00000000000000LL) != 0 && (v51 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
            {
              v51 = (unsigned __int64)&s_uszNull_27942;
            }
            if ( (_DWORD)v21 && *(_DWORD *)v51 )
            {
              v52 = (_DWORD *)v51;
              do
                ++v52;
              while ( v52 != (_DWORD *)(v51 + 4LL * (unsigned int)(v21 - 1) + 4) && *v52 );
              v78 = (__int64)((__int64)v52 - v51) >> 2;
              v53 = v78 - 1;
            }
            else
            {
              v53 = -1;
              v78 = 0;
            }
            if ( (v15 & 2) == 0 )
            {
              while ( --v20 >= v78 )
                v9 += a1(a2, " ", 1);
            }
            v54 = v20 - v78;
            if ( v78 > 0 )
            {
              do
              {
                v51 += 4LL;
                --v53;
                LOBYTE(v84[0]) = *(_DWORD *)(v51 - 4);
                v9 += a1(a2, (const char *)v84, 1);
              }
              while ( v53 + 1 > 0 );
            }
            v55 = v54 - 1;
            if ( v54 - 1 >= 0 )
            {
              do
              {
                --v55;
                v9 += a1(a2, " ", 1);
              }
              while ( v55 != -1 );
            }
          }
          else
          {
            if ( (unsigned int)v81 >= 0x30 )
            {
              v37 = (const char **)v82;
              v82 += 2;
            }
            else
            {
              v37 = (const char **)(v83 + (unsigned int)v81);
              LODWORD(v81) = v81 + 8;
            }
            v38 = *v37;
            if ( (unsigned __int64)(*v37 + 0x200000) <= 0x200FFF )
            {
              v38 = "<NULL>";
            }
            else if ( ((unsigned __int64)v38 & 0xFF00000000000000LL) != 0 )
            {
              v71 = "<NULL>";
              if ( ((unsigned __int64)v38 & 0xFF00000000000000LL) == 0xFF00000000000000LL )
                v71 = v38;
              v38 = v71;
            }
            if ( (_DWORD)v21 && *v38 )
            {
              v39 = v38;
              do
                ++v39;
              while ( v39 != &v38[(unsigned int)(v21 - 1) + 1] && *v39 );
              v40 = (_DWORD)v39 - (_DWORD)v38;
              v77 = (int)v39 - (int)v38;
            }
            else
            {
              v77 = 0;
              v40 = 0;
            }
            if ( (v15 & 2) == 0 )
            {
              while ( --v20 >= v40 )
                v9 += a1(a2, " ", 1);
            }
            v41 = v77;
            for ( i = v38; ; i = " " )
            {
              --v20;
              v9 += a1(a2, i, v41);
              if ( v20 < v40 )
                break;
              v41 = 1;
            }
          }
          goto LABEL_92;
        case 'X':
        case 'd':
        case 'i':
        case 'o':
        case 'p':
        case 'u':
        case 'x':
          switch ( v26 )
          {
            case 'X':
              LOWORD(v15) = v15 | 1;
              v56 = 16;
              goto LABEL_119;
            case 'd':
            case 'i':
              LOWORD(v15) = v15 | 0x10;
              goto LABEL_137;
            case 'o':
              v56 = 8;
              goto LABEL_119;
            case 'p':
              LOWORD(v15) = v15 | 4;
              if ( v20 < 0 )
                v20 = 16;
              v56 = 16;
              goto LABEL_133;
            case 'x':
              v56 = 16;
              goto LABEL_119;
            default:
LABEL_137:
              v56 = 10;
              if ( v26 == 112 )
              {
LABEL_133:
                if ( (unsigned int)v81 >= 0x30 )
                {
                  v60 = (unsigned __int64 *)v82;
                  v82 += 2;
                }
                else
                {
                  v60 = (unsigned __int64 *)(v83 + (unsigned int)v81);
                  LODWORD(v81) = v81 + 8;
                }
                v59 = *v60;
              }
              else
              {
LABEL_119:
                if ( (v15 & 0x10) != 0 )
                {
                  switch ( (_BYTE)v17 )
                  {
                    case 'L':
                    case 'l':
                      goto LABEL_154;
                    case 'h':
                      goto LABEL_202;
                    case 'H':
                      goto LABEL_207;
                  }
                  v57 = v81;
                  if ( (_BYTE)v17 == 106 || (_BYTE)v17 == 122 || (_BYTE)v17 == 116 )
                    goto LABEL_187;
                  if ( (unsigned int)v81 >= 0x30 )
                  {
                    v58 = v82;
                    v82 += 2;
                  }
                  else
                  {
                    v58 = (int *)(v83 + (unsigned int)v81);
                    LODWORD(v81) = v81 + 8;
                  }
                  v59 = *v58;
                  LOWORD(v15) = v15 | 0x2000;
                }
                else
                {
                  switch ( (_BYTE)v17 )
                  {
                    case 'L':
                    case 'l':
LABEL_154:
                      v57 = v81;
                      if ( (unsigned int)v81 >= 0x30 )
                        goto LABEL_155;
LABEL_188:
                      v62 = (unsigned __int64 *)(v83 + v57);
                      LODWORD(v81) = v57 + 8;
LABEL_156:
                      v59 = *v62;
                      LOWORD(v15) = v15 | 0x4000;
                      goto LABEL_157;
                    case 'h':
LABEL_202:
                      if ( (unsigned int)v81 >= 0x30 )
                      {
                        v72 = v82;
                        v82 += 2;
                      }
                      else
                      {
                        v72 = (int *)(v83 + (unsigned int)v81);
                        LODWORD(v81) = v81 + 8;
                      }
                      v59 = *v72;
                      LOWORD(v15) = v15 | 0x1000;
                      goto LABEL_157;
                    case 'H':
LABEL_207:
                      if ( (unsigned int)v81 >= 0x30 )
                      {
                        v73 = v82;
                        v82 += 2;
                      }
                      else
                      {
                        v73 = (int *)(v83 + (unsigned int)v81);
                        LODWORD(v81) = v81 + 8;
                      }
                      v59 = *v73;
                      LOWORD(v15) = v15 | 0x800;
                      goto LABEL_157;
                  }
                  v57 = v81;
                  if ( (_BYTE)v17 == 106 || (_BYTE)v17 == 122 || (_BYTE)v17 == 116 )
                  {
LABEL_187:
                    if ( v57 < 0x30 )
                      goto LABEL_188;
LABEL_155:
                    v62 = (unsigned __int64 *)v82;
                    v82 += 2;
                    goto LABEL_156;
                  }
                  if ( (unsigned int)v81 >= 0x30 )
                  {
                    v61 = (unsigned int *)v82;
                    v82 += 2;
                  }
                  else
                  {
                    v61 = (unsigned int *)(v83 + (unsigned int)v81);
                    LODWORD(v81) = v81 + 8;
                  }
                  v59 = *v61;
                  LOWORD(v15) = v15 | 0x2000;
                }
              }
LABEL_157:
              v63 = VBoxGuest_RTStrFormatNumber(v85, v59, v56, v20, v21, v15);
              v9 += a1(a2, v85, v63);
              v7 = (__int64)v80;
LABEL_51:
              v10 = (char *)v7;
              break;
          }
          break;
        case 'c':
          if ( (v15 & 2) == 0 && --v20 > 0 )
          {
            do
            {
              v9 += a1(a2, " ", 1, v19, v21);
              --v20;
            }
            while ( v20 );
          }
          if ( (unsigned int)v81 >= 0x30 )
          {
            v43 = v82;
            v82 += 2;
          }
          else
          {
            v43 = (int *)(v83 + (unsigned int)v81);
            LODWORD(v81) = v81 + 8;
          }
          v44 = *v43;
          v85[1] = 0;
          v45 = v20 - 1;
          v85[0] = v44;
          v9 += a1(a2, v85, 1, v19, v21);
          if ( v20 - 1 > 0 )
          {
            do
            {
              v9 += a1(a2, " ", 1);
              --v45;
            }
            while ( v45 );
          }
          goto LABEL_92;
        default:
          if ( !a3 )
            goto LABEL_51;
          v80 = v14;
          v9 += a3(a4, a1, a2, &v80, &v81, (unsigned int)v20, v21, v15, v17);
LABEL_92:
          v7 = (__int64)v80;
          goto LABEL_51;
      }
    }
  }
LABEL_5:
  if ( (char *)v7 != v10 )
    v9 += a1(a2, (const char *)v7, &v10[-v7]);
  a1(a2, 0, 0);
  return v9;
}
