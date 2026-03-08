__int64 __fastcall VBoxGuest_RTStrGetCpNExInternal(unsigned __int8 **a1, unsigned __int64 *a2, int *a3)
{
  unsigned __int64 v3; // r9
  _BYTE *v4; // rax
  __int16 v5; // cx
  int v6; // r8d
  unsigned __int8 *v7; // rax
  unsigned __int64 v8; // r9
  __int64 v10; // rbx
  unsigned int v11; // r11d
  char v12; // r10

  v3 = *a2;
  v4 = *a1;
  v5 = **a1;
  if ( !*a2 )
  {
    *a3 = -2;
    return 4294967213LL;
  }
  if ( (v5 & 0x80u) == 0 )
  {
    v6 = (unsigned __int8)v5;
    v7 = v4 + 1;
    v8 = v3 - 1;
LABEL_4:
    *a3 = v6;
    *a1 = v7;
    *a2 = v8;
    return 0;
  }
  if ( (v5 & 0x40) == 0 )
    goto LABEL_25;
  if ( (v5 & 0x20) == 0 )
  {
    if ( v3 > 1 )
    {
      v10 = 2;
      v11 = 2;
      goto LABEL_9;
    }
LABEL_25:
    *a1 = v4 + 1;
    --*a2;
    *a3 = -2;
    return 4294967235LL;
  }
  if ( (v5 & 0x10) != 0 )
  {
    if ( (v5 & 8) != 0 )
    {
      if ( (v5 & 4) != 0 )
      {
        if ( (v5 & 2) != 0 )
          goto LABEL_25;
        if ( v3 <= 5 )
          goto LABEL_25;
        v10 = 6;
        v11 = 6;
        if ( (v4[5] & 0xC0) != 0x80 )
          goto LABEL_25;
      }
      else
      {
        if ( v3 <= 4 )
          goto LABEL_25;
        v10 = 5;
        v11 = 5;
      }
      if ( (v4[4] & 0xC0) != 0x80 )
        goto LABEL_25;
    }
    else
    {
      if ( v3 <= 3 )
        goto LABEL_25;
      v10 = 4;
      v11 = 4;
    }
    if ( (v4[3] & 0xC0) != 0x80 )
      goto LABEL_25;
  }
  else
  {
    if ( v3 <= 2 )
      goto LABEL_25;
    v10 = 3;
    v11 = 3;
  }
  if ( (v4[2] & 0xC0) != 0x80 )
    goto LABEL_25;
LABEL_9:
  v12 = v4[1];
  if ( (v12 & 0xC0) != 0x80 )
    goto LABEL_25;
  if ( v11 == 4 )
  {
    v6 = ((v5 & 7) << 18) | v4[3] & 0x3F | ((v12 & 0x3F) << 12) | ((v4[2] & 0x3F) << 6);
    if ( (unsigned int)(v6 - 0x10000) <= 0x1EFFFF )
      goto LABEL_14;
    goto LABEL_25;
  }
  if ( v11 > 4 )
  {
    if ( v11 == 5 )
    {
      v6 = ((v5 & 3) << 24) | ((v12 & 0x3F) << 18) | v4[4] & 0x3F | ((v4[2] & 0x3F) << 12) | ((v4[3] & 0x3F) << 6);
      if ( (unsigned int)(v6 - 0x200000) <= 0x3DFFFFF )
        goto LABEL_14;
    }
    else
    {
      v6 = ((v5 & 1) << 30)
         | ((v12 & 0x3F) << 24)
         | ((v4[2] & 0x3F) << 18)
         | v4[5] & 0x3F
         | ((v4[3] & 0x3F) << 12)
         | ((v4[4] & 0x3F) << 6);
      if ( (unsigned int)(v6 - 0x4000000) <= 0x7BFFFFFF )
      {
LABEL_14:
        v7 = &v4[v10];
        v8 = v3 - v10;
        goto LABEL_4;
      }
    }
    goto LABEL_25;
  }
  if ( v11 != 3 )
  {
    v6 = v12 & 0x3F | ((v5 & 0x1F) << 6);
    if ( (unsigned int)(v6 - 128) <= 0x77F )
      goto LABEL_14;
    goto LABEL_25;
  }
  v6 = v4[2] & 0x3F | (unsigned __int16)(v5 << 12) | ((v12 & 0x3F) << 6);
  if ( (unsigned int)(v6 - 2048) <= 0xF7FD )
  {
    if ( (unsigned int)(v6 - 55296) > 0x7FF )
      goto LABEL_14;
    *a1 = v4 + 1;
    --*a2;
    *a3 = -2;
    return 4294967236LL;
  }
  else
  {
    *a1 = v4 + 1;
    --*a2;
    *a3 = -2;
    return (unsigned int)(v6 - 65534) < 2 ? -59 : -61;
  }
}
