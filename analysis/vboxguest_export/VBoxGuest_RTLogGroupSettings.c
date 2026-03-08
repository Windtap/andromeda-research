__int64 __fastcall VBoxGuest_RTLogGroupSettings(__int64 a1, _BYTE *a2)
{
  _BYTE *v2; // r15
  char v3; // al
  int v4; // eax
  char v5; // dl
  unsigned __int64 v6; // rdx
  char v7; // al
  char *v8; // r12
  char v9; // di
  char v10; // si
  _BYTE *v11; // rcx
  unsigned __int64 v12; // r14
  int v13; // eax
  unsigned int v14; // r8d
  int v15; // edi
  int v16; // eax
  char v17; // bl
  _BYTE *v18; // rbp
  char v19; // al
  int v20; // eax
  int v22; // esi
  char *v23; // rax
  int v24; // esi
  char *v25; // rax
  int v26; // eax
  int v27; // ecx
  __int64 v28; // rdx
  bool v29; // [rsp+3h] [rbp-55h]
  unsigned int i; // [rsp+4h] [rbp-54h]
  __int64 v31; // [rsp+8h] [rbp-50h]
  _BYTE *v32; // [rsp+10h] [rbp-48h]
  unsigned __int64 v33; // [rsp+20h] [rbp-38h]

  v2 = a2;
  v31 = a1;
  if ( !a1 )
  {
    v31 = VBoxGuest_RTLogDefaultInstance();
    if ( !v31 )
      return 0;
  }
  v3 = *a2;
  if ( !*a2 )
    return 0;
  do
  {
    v29 = 1;
    while ( 1 )
    {
      if ( v3 == 43 )
        goto LABEL_7;
      if ( v3 != 45 && v3 != 32 && (unsigned __int8)(v3 - 9) > 1u )
        break;
      if ( (v3 & 0xEF) == 0x2B || v3 == 45 )
        goto LABEL_7;
LABEL_8:
      v3 = *++v2;
    }
    if ( v3 == 59 )
    {
LABEL_7:
      v29 = v3 != 45;
      goto LABEL_8;
    }
    if ( !v3 )
      break;
    v4 = v3 & 0xDF;
    v32 = v2;
    if ( v4 )
    {
      do
      {
        v5 = *++v32;
        if ( (*v32 & 0xDF) == 0 )
        {
          v6 = v32 - v2;
          goto LABEL_22;
        }
      }
      while ( v5 != 45 && v5 != 43 && v5 != 9 );
      v6 = v32 - v2;
LABEL_22:
      if ( v6 <= 2 || (_BYTE)v4 != 65 || (v2[1] & 0xDF) != 0x4C || (v2[2] & 0xDF) != 0x4C )
      {
        v33 = v6;
        goto LABEL_29;
      }
      if ( v6 == 3 )
      {
        v26 = 17;
      }
      else
      {
        v7 = v2[3];
        if ( v7 != 46 )
        {
          v33 = v6;
          if ( v7 != 61 )
            goto LABEL_29;
        }
        v26 = rtlogGroupFlags(v2 + 3);
      }
      v27 = *(_DWORD *)(v31 + 49184);
      v28 = v31;
      if ( v27 )
      {
        do
        {
          if ( v29 )
            *(_DWORD *)(v28 + 49188) |= v26;
          else
            *(_DWORD *)(v28 + 49188) &= ~v26;
          v28 += 4;
        }
        while ( v28 != v31 + 4LL * (unsigned int)(v27 - 1) + 4 );
      }
    }
    else
    {
      v33 = 0;
LABEL_29:
      for ( i = 0; *(_DWORD *)(v31 + 49184) > i; ++i )
      {
        v8 = *(char **)(*(_QWORD *)(*(_QWORD *)(v31 + 49168) + 48LL) + 8LL * i);
        if ( v8 )
        {
          v9 = *v8;
          if ( *v8 )
          {
            v10 = *v2;
            v11 = v2;
            v12 = v33;
            while ( 1 )
            {
              while ( 1 )
              {
                v13 = v9;
                v14 = v9 - 65;
                v15 = v9 + 32;
                if ( v14 > 0x19 )
                  v15 = v13;
                v16 = v10;
                if ( (unsigned int)(v10 - 65) <= 0x19 )
                  v16 = v10 + 32;
                if ( v15 == v16 )
                  break;
                if ( v10 != 42 )
                  goto LABEL_48;
                while ( 1 )
                {
                  v18 = v11 + 1;
                  if ( !--v12 )
                  {
                    v19 = v11[1];
                    goto LABEL_44;
                  }
                  v17 = v11[1];
                  if ( v17 != 42 )
                    break;
                  ++v11;
                }
                if ( v17 == 46 || v17 == 61 )
                  goto LABEL_65;
                v22 = v17 + 32;
                if ( (unsigned int)(v17 - 65) > 0x19 )
                  v22 = v17;
                v23 = strchr(v8, v22);
                if ( v23 )
                {
                  v9 = *v23;
                  v10 = v17;
                  v11 = v18;
                  v8 = v23;
                }
                else
                {
                  v24 = v17 - 32;
                  if ( (unsigned int)(v17 - 97) > 0x19 )
                    v24 = v17;
                  v25 = strchr(v8, v24);
                  v8 = v25;
                  if ( !v25 )
                    goto LABEL_48;
                  v9 = *v25;
                  v10 = v17;
                  v11 = v18;
                }
              }
              v9 = v8[1];
              if ( !v9 )
                break;
              if ( !--v12 )
                goto LABEL_48;
              v10 = v11[1];
              ++v8;
              ++v11;
            }
            while ( 1 )
            {
              v18 = v11 + 1;
              --v12;
              v19 = v11[1];
              if ( !v12 )
              {
LABEL_44:
                if ( v19 == 61 || v19 == 46 )
                  goto LABEL_65;
                v20 = 17;
                if ( !v29 )
                  goto LABEL_66;
                goto LABEL_47;
              }
              if ( v19 != 42 )
                break;
              ++v11;
            }
            if ( v19 != 46 && v19 != 61 )
              continue;
LABEL_65:
            v20 = rtlogGroupFlags(v18);
            if ( v29 )
LABEL_47:
              *(_DWORD *)(v31 + 4LL * i + 49188) |= v20;
            else
LABEL_66:
              *(_DWORD *)(v31 + 4LL * i + 49188) &= ~v20;
          }
        }
LABEL_48:
        ;
      }
    }
    v2 = v32;
    v3 = *v32;
  }
  while ( *v32 );
  return 0;
}
