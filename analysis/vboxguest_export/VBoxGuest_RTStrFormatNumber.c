signed __int64 __fastcall VBoxGuest_RTStrFormatNumber(
        char *a1,
        unsigned __int64 a2,
        unsigned int a3,
        int a4,
        int a5,
        __int16 a6)
{
  const char *v6; // r12
  unsigned __int64 v7; // rbp
  int v8; // r13d
  int v9; // r14d
  char v10; // r11
  unsigned __int64 v11; // rax
  int v12; // ebx
  int v13; // r10d
  int v14; // eax
  int v15; // ecx
  int v16; // edx
  int v17; // r8d
  int v18; // r11d
  int v19; // ecx
  int v20; // r9d
  int v21; // r8d
  int v22; // r11d
  char *v23; // rbx
  int v24; // r10d
  int j; // eax
  char v26; // dl
  int v27; // ecx
  char *v28; // rax
  int v30; // edx
  char v31; // r15
  int v32; // r11d
  __int64 i; // rdx
  char v34; // dl
  int v35; // r8d
  unsigned int v36; // eax
  unsigned int v37; // eax
  int v38; // r10d
  int k; // edx
  unsigned int v40; // et2
  int v41; // r8d
  unsigned int v42; // et2
  int v43; // eax

  v6 = "0123456789abcdef";
  if ( (a6 & 1) != 0 )
    v6 = "0123456789ABCDEF";
  if ( (a6 & 2) != 0 )
    a6 &= ~4u;
  v7 = a3;
  v8 = a6 & 0x200;
  if ( (a6 & 0x200) != 0 && (a3 != 10 || (a6 & 4) != 0) )
  {
    v8 = 0;
    a6 &= ~0x200u;
  }
  v9 = a6 & 0x4000;
  if ( (a6 & 0x4000) != 0 || (a2 & 0xFFFFFFFF00000000LL) != 0 )
  {
    v10 = 0;
    if ( (a6 & 0x10) != 0 && (a2 & 0x8000000000000000LL) != 0LL )
    {
      v10 = 45;
      if ( a2 != 0x8000000000000000LL )
        a2 = -(__int64)a2;
    }
    v11 = a2;
    v12 = 0;
    do
    {
      ++v12;
      v11 /= a3;
    }
    while ( v11 );
  }
  else
  {
    v10 = 0;
    v36 = a2;
    if ( (a6 & 0x10) != 0 && (a2 & 0x80000000) != 0LL )
    {
      if ( (_DWORD)a2 == 0x80000000 )
      {
        v10 = 45;
        a2 = 0x80000000LL;
      }
      else
      {
        v36 = -(int)a2;
        v10 = 45;
        a2 = -(int)a2;
      }
    }
    v12 = 0;
    do
    {
      ++v12;
      v36 /= a3;
    }
    while ( v36 );
  }
  if ( v8 )
  {
    if ( v12 > 3 )
    {
      v12 += v12 / 3 - (v12 == 3 * (v12 / 3));
    }
    else
    {
      v8 = 0;
      v9 = a6 & 0x4000;
    }
  }
  v13 = 0;
  if ( (a6 & 0x10) != 0 )
  {
    if ( v10 )
    {
      *a1 = v10;
      LOBYTE(v13) = 1;
    }
    else if ( (a6 & 0x60) != 0 )
    {
      v13 = 1;
      *a1 = (a6 & 0x20) == 0 ? 32 : 43;
    }
  }
  if ( (a6 & 8) != 0 && (a3 & 7) == 0 )
  {
    v43 = v13 + 1;
    a1[v13] = 48;
    if ( a3 == 16 )
    {
      v13 += 2;
      a1[v43] = (a6 & 1) == 0 ? 120 : 88;
    }
    else
    {
      ++v13;
    }
  }
  v14 = 63 - (v12 + v13);
  v15 = a4 - (v12 + v13);
  if ( (a6 & 4) != 0 )
  {
    v16 = v15 - 1;
    if ( v15 - 1 < 0 )
    {
      v20 = a6 & 2;
      --v15;
    }
    else
    {
      if ( v13 >= v14 )
      {
LABEL_90:
        v20 = a6 & 2;
        v15 = v16;
        v22 = v13;
        goto LABEL_34;
      }
      v17 = a5 - v15;
      while ( 1 )
      {
        v18 = v17 + v16--;
        v19 = v13 + 1;
        a1[v13] = 48;
        if ( v16 == -1 )
          break;
        ++v13;
        if ( v14 <= v19 )
          goto LABEL_90;
      }
      ++v13;
      v20 = a6 & 2;
      a5 = v18;
      v15 = -1;
    }
  }
  else
  {
    v20 = a6 & 2;
    if ( !v20 && v15 > 0 )
    {
      if ( v14 <= v15 )
        v15 = 62 - (v12 + v13);
      v30 = v13 - 1;
      if ( v13 )
      {
        do
        {
          v31 = a1[v30];
          v32 = v30 + v15;
          --v30;
          a1[v32] = v31;
        }
        while ( v30 != -1 );
      }
      for ( i = 0; v15 > (int)i; ++i )
        a1[i] = 32;
      v13 += v15;
    }
  }
  v21 = a5 - 1;
  if ( v12 <= v21 && v13 < v14 )
  {
    while ( 1 )
    {
      v22 = v13 + 1;
      --v21;
      a1[v13] = 48;
      if ( v12 > v21 || v14 <= v22 )
        break;
      ++v13;
    }
  }
  else
  {
    v22 = v13;
  }
LABEL_34:
  v23 = &a1[v22 + v12];
  if ( v9 || (a2 & 0xFFFFFFFF00000000LL) != 0 )
  {
    v24 = -1;
    if ( v8 )
    {
      while ( 1 )
      {
        v34 = v6[a2 % v7];
        v35 = v24 - 1;
        a2 /= v7;
        v23[v24] = v34;
        if ( !a2 )
          break;
        if ( ~v35 % 4 == 3 )
        {
          v23[v35] = 32;
          v35 = v24 - 2;
        }
        v24 = v35;
      }
    }
    else
    {
      for ( j = -1; ; --j )
      {
        v26 = v6[a2 % v7];
        a2 /= v7;
        v23[j] = v26;
        if ( !a2 )
          break;
      }
    }
  }
  else
  {
    v37 = a2;
    v38 = -1;
    if ( !v8 )
    {
      for ( k = -1; ; --k )
      {
        v40 = v37 % (unsigned int)v7;
        v37 /= (unsigned int)v7;
        v23[k] = v6[v40];
        if ( !v37 )
          break;
      }
      if ( !v20 )
        goto LABEL_74;
      goto LABEL_41;
    }
    while ( 1 )
    {
      v41 = v38 - 1;
      v42 = v37 % (unsigned int)v7;
      v37 /= (unsigned int)v7;
      v23[v38] = v6[v42];
      if ( !v37 )
        break;
      if ( ~v41 % 4 == 3 )
      {
        v23[v41] = 32;
        v41 = v38 - 2;
      }
      v38 = v41;
    }
  }
  if ( !v20 )
  {
LABEL_74:
    v28 = v23;
    goto LABEL_44;
  }
LABEL_41:
  v27 = v15 - 1;
  if ( v27 < 0 )
    goto LABEL_74;
  v28 = &v23[v27 + 1];
  do
    *v23++ = 32;
  while ( v23 != v28 );
LABEL_44:
  *v28 = 0;
  return v28 - a1;
}
