__int64 __fastcall VBoxGuest_RTStrFormatR80u2(char *dest, unsigned __int64 a2, unsigned __int8 *a3)
{
  unsigned __int8 v6; // al
  __int64 v7; // rdx
  unsigned __int64 v8; // rsi
  char v9; // al
  int v10; // eax
  unsigned __int8 v11; // dl
  int v12; // esi
  char *v13; // rax
  unsigned __int64 v14; // rax
  __int64 v15; // rbx
  char v16; // r15
  char v17; // r15
  char *v18; // rdx
  __int64 v19; // r14
  __int64 v20; // r11
  __int64 v21; // rdi
  __int64 v22; // r10
  __int64 v23; // r9
  __int64 v24; // r8
  __int64 v25; // rsi
  char *v26; // rax
  unsigned __int8 v28; // [rsp+0h] [rbp-D8h]
  char src; // [rsp+8h] [rbp-D0h] BYREF
  char v30; // [rsp+9h] [rbp-CFh] BYREF
  char v31; // [rsp+Ah] [rbp-CEh] BYREF
  char v32[205]; // [rsp+Bh] [rbp-CDh] BYREF

  v6 = a3[9];
  v7 = a3[8];
  src = (v6 & 0x80u) == 0 ? 43 : 45;
  if ( v7 | ((unsigned __int64)(a3[9] & 0x7F) << 8) )
  {
    v16 = a3[7];
    if ( ((unsigned __int16)v7 | ((a3[9] & 0x7F) << 8)) == 0x7FFF )
    {
      if ( v16 >= 0 )
      {
        v18 = &v30;
      }
      else
      {
        v30 = 80;
        v18 = &v31;
      }
      v19 = a3[1];
      v20 = a3[2];
      v21 = *a3;
      v22 = a3[3];
      v23 = a3[4];
      v24 = a3[5];
      v25 = a3[6];
      v28 = a3[7];
      if ( *(unsigned __int16 *)a3
         | (unsigned __int64)(v20 << 16)
         | (v22 << 24)
         | (v23 << 32)
         | (v24 << 40)
         | (v25 << 48)
         | ((unsigned __int64)(v28 & 0x7F) << 56) )
      {
        *v18 = 78;
        v26 = v18 + 3;
        v18[1] = 97;
        v18[2] = 78;
      }
      else
      {
        *v18 = 73;
        v26 = v18 + 3;
        v18[1] = 110;
        v18[2] = 102;
      }
      if ( v26 != &v30 )
        goto LABEL_16;
      v17 = v16 & 0x80;
      v8 = v21
         | (v19 << 8)
         | (v20 << 16)
         | (v22 << 24)
         | (v23 << 32)
         | (v24 << 40)
         | (v25 << 48)
         | ((unsigned __int64)(v28 & 0x7F) << 56);
    }
    else
    {
      v17 = v16 & 0x80;
      v8 = *(unsigned __int16 *)a3
         | ((unsigned __int64)a3[2] << 16)
         | ((unsigned __int64)a3[3] << 24)
         | ((unsigned __int64)a3[4] << 32)
         | ((unsigned __int64)a3[5] << 40)
         | ((unsigned __int64)a3[6] << 48)
         | ((unsigned __int64)(a3[7] & 0x7F) << 56);
    }
  }
  else
  {
    v8 = *(unsigned __int16 *)a3
       | ((unsigned __int64)a3[2] << 16)
       | ((unsigned __int64)a3[3] << 24)
       | ((unsigned __int64)a3[4] << 32)
       | ((unsigned __int64)a3[5] << 40)
       | ((unsigned __int64)a3[6] << 48)
       | ((unsigned __int64)(a3[7] & 0x7F) << 56);
    if ( !v8 )
    {
      if ( (a3[7] & 0x80u) == 0 )
      {
        v8 = 0;
        v9 = 48;
        goto LABEL_5;
      }
      v30 = 48;
      v26 = &v31;
LABEL_16:
      *v26 = 0;
      v14 = v26 - &src;
      v15 = v14;
      if ( v14 <= a2 )
        goto LABEL_6;
      goto LABEL_17;
    }
    v17 = a3[7] & 0x80;
  }
  v9 = 49 - (v17 == 0);
LABEL_5:
  v30 = v9;
  v31 = 109;
  v10 = VBoxGuest_RTStrFormatNumber(v32, v8, 0x10u, 18, 0, 16396);
  v11 = a3[9];
  v12 = a3[8];
  v13 = &v32[v10];
  *v13 = 101;
  v14 = &v13[(int)VBoxGuest_RTStrFormatNumber(v13 + 1, (v12 | ((v11 & 0x7F) << 8)) - 0x3FFF, 0xAu, 0, 0, 8212) + 1]
      - &src;
  v15 = v14;
  if ( v14 <= a2 )
  {
LABEL_6:
    memcpy(dest, &src, v14 + 1);
    return v15;
  }
LABEL_17:
  v15 = -41;
  if ( a2 )
  {
    memcpy(dest, &src, a2 - 1);
    dest[a2 - 1] = 0;
  }
  return v15;
}
