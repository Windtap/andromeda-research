int __fastcall VBoxGuest_RTLogDestinations(
        __int64 a1,
        char *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  char *v10; // r15
  char v11; // al
  const char **v12; // rbp
  int v13; // ebx
  size_t v14; // r13
  double v15; // xmm4_8
  double v16; // xmm5_8
  int result; // eax
  int v18; // eax
  char v19; // al
  __int64 v20; // rax
  char v21; // al
  size_t i; // rdx
  size_t v23; // r14
  const char *v24; // r12
  char v25; // al
  size_t *v26; // r13
  size_t v27; // rbp
  char v28; // al
  double v29; // xmm4_8
  double v30; // xmm5_8
  unsigned int v31; // eax
  void *v32; // rsi
  char *v33; // [rsp+0h] [rbp-88h]
  char v34; // [rsp+Fh] [rbp-79h]
  size_t v35; // [rsp+10h] [rbp-78h]
  __int64 v36; // [rsp+28h] [rbp-60h]
  unsigned int v37; // [rsp+34h] [rbp-54h] BYREF
  unsigned __int8 dest[80]; // [rsp+38h] [rbp-50h] BYREF

  v10 = a2;
  v36 = a1;
  if ( !a1 )
  {
    v36 = VBoxGuest_RTLogDefaultInstance();
    if ( !v36 )
      return 0;
  }
  v11 = *a2;
  while ( v11 )
  {
    if ( (unsigned int)(v11 - 9) <= 4 || v11 == 32 )
    {
      do
      {
        do
          v11 = *++v10;
        while ( (unsigned int)(*v10 - 9) <= 4 );
      }
      while ( v11 == 32 );
      if ( !v11 )
        break;
    }
    v34 = 0;
    if ( v11 == 110 && v10[1] == 111 && (v10[2] != 100 || v10[3] != 101 || v10[4] != 110 || v10[5] != 121) )
    {
      v10 += 2;
      v34 = 1;
    }
    v12 = (const char **)&g_aLogDst;
    v13 = 0;
    while ( 1 )
    {
      v14 = strlen(*v12);
      if ( !strncmp(v10, *v12, v14) )
        break;
      ++v13;
      v12 += 3;
      if ( v13 == 12 )
        return -2;
    }
    v18 = dword_24FF0[6 * v13];
    if ( v34 )
      *(_DWORD *)(v36 + 49164) &= ~v18;
    else
      *(_DWORD *)(v36 + 49164) |= v18;
    for ( v10 += v14; ; ++v10 )
    {
      v19 = *v10;
      if ( (unsigned int)(*v10 - 9) > 4 && v19 != 32 )
        break;
    }
    if ( v19 == 58 || v19 == 61 )
    {
      v35 = 0;
      v33 = v10 + 1;
LABEL_36:
      while ( 1 )
      {
        v21 = v33[v35];
        if ( !v21 || v21 == 59 )
          break;
        if ( (unsigned int)(v21 - 9) <= 4 || v21 == 32 )
        {
          for ( i = v35; ; ++i )
          {
            v23 = i + 1;
            v24 = &v33[i + 1];
            v25 = v10[i + 2];
            if ( !v25 )
              break;
            if ( (unsigned int)(v25 - 9) > 4 && v25 != 32 )
            {
              if ( v25 == 59 )
                goto LABEL_60;
              if ( v25 == 110 && v33[i + 2] == 111 )
              {
                v23 = i + 3;
                v24 = &v33[i + 3];
              }
              break;
            }
          }
          v26 = (size_t *)&unk_24FE8;
          while ( 1 )
          {
            v27 = *v26;
            if ( !strncmp(v24, (const char *)*(v26 - 1), *v26) )
            {
              v28 = v33[v23 + v27];
              if ( (v28 & 0xDF) == 0 || (unsigned int)(v28 - 9) <= 4 || (unsigned __int8)(v28 - 58) <= 1u || v28 == 61 )
                goto LABEL_60;
            }
            v26 += 3;
            if ( v26 == (size_t *)&unk_25108 )
            {
              v35 = v23;
              goto LABEL_36;
            }
          }
        }
        ++v35;
      }
LABEL_60:
      if ( v13 != 5 || v34 )
        return -2;
      result = VBoxGuest_RTStrCopyEx((char *)dest, 0x20u, v33, v35);
      v37 = 0;
      if ( result < 0 )
        return result;
      result = VBoxGuest_RTStrToUInt32Full(dest, 0, &v37);
      if ( result < 0 )
        return result;
      v31 = v37;
      if ( v37 )
      {
        if ( v37 > 0x3FF )
        {
          if ( v37 <= 0x400000 )
          {
            v37 = (v37 + 63) & 0xFFFFFFC0;
            LODWORD(v32) = (v31 + 63) & 0xFFFFFFC0;
          }
          else
          {
            v37 = 0x400000;
            LODWORD(v32) = 0x400000;
          }
        }
        else
        {
          v37 = 1024;
          LODWORD(v32) = 1024;
        }
      }
      else
      {
        v37 = (unsigned int)&loc_10000;
        v32 = &loc_10000;
      }
      result = rtLogRingBufAdjust(v36, (unsigned int)v32, 0, a3, a4, a5, a6, v29, v30, a9, a10);
      if ( result < 0 )
        return result;
      v10 = &v33[v35 + (v33[v35] != 0)];
    }
    else if ( v13 == 5 && !v34 )
    {
      v20 = *(_QWORD *)(v36 + 49168);
      if ( !*(_QWORD *)(v20 + 80) )
      {
        result = rtLogRingBufAdjust(v36, *(_DWORD *)(v20 + 68), 0, a3, a4, a5, a6, v15, v16, a9, a10);
        if ( result < 0 )
          return result;
      }
    }
    while ( 1 )
    {
      v11 = *v10;
      if ( *v10 != 32 && (unsigned int)(v11 - 9) > 4 && v11 != 59 )
        break;
      ++v10;
    }
  }
  return 0;
}
