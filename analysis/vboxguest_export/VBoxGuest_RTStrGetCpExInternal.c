__int64 __fastcall VBoxGuest_RTStrGetCpExInternal(unsigned __int8 **a1, int *a2)
{
  _BYTE *v2; // rax
  __int16 v3; // dx
  __int64 v5; // r8
  char v6; // r9
  int v7; // ecx

  v2 = *a1;
  v3 = **a1;
  if ( (v3 & 0x80u) == 0 )
  {
    *a2 = (unsigned __int8)v3;
    *a1 = v2 + 1;
    return 0;
  }
  if ( (v3 & 0x40) == 0 )
    goto LABEL_20;
  if ( (v3 & 0x20) != 0 )
  {
    if ( (v3 & 0x10) != 0 )
    {
      if ( (v3 & 8) != 0 )
      {
        if ( (v3 & 4) != 0 )
        {
          if ( (v3 & 2) != 0 || (v2[5] & 0xC0) != 0x80 )
            goto LABEL_20;
          v5 = 6;
        }
        else
        {
          v5 = 5;
        }
        if ( (v2[4] & 0xC0) != 0x80 )
        {
LABEL_20:
          *a1 = v2 + 1;
          *a2 = -2;
          return 4294967235LL;
        }
      }
      else
      {
        v5 = 4;
      }
      if ( (v2[3] & 0xC0) != 0x80 )
        goto LABEL_20;
    }
    else
    {
      v5 = 3;
    }
    if ( (v2[2] & 0xC0) != 0x80 )
      goto LABEL_20;
  }
  else
  {
    v5 = 2;
  }
  v6 = v2[1];
  if ( (v6 & 0xC0) != 0x80 )
    goto LABEL_20;
  if ( (_DWORD)v5 == 4 )
  {
    v7 = ((v3 & 7) << 18) | v2[3] & 0x3F | ((v6 & 0x3F) << 12) | ((v2[2] & 0x3F) << 6);
    if ( (unsigned int)(v7 - 0x10000) <= 0x1EFFFF )
      goto LABEL_11;
    goto LABEL_20;
  }
  if ( (unsigned int)v5 > 4 )
  {
    if ( (_DWORD)v5 == 5 )
    {
      v7 = ((v3 & 3) << 24) | ((v6 & 0x3F) << 18) | v2[4] & 0x3F | ((v2[2] & 0x3F) << 12) | ((v2[3] & 0x3F) << 6);
      if ( (unsigned int)(v7 - 0x200000) <= 0x3DFFFFF )
        goto LABEL_11;
    }
    else
    {
      v7 = ((v3 & 1) << 30)
         | ((v6 & 0x3F) << 24)
         | ((v2[2] & 0x3F) << 18)
         | v2[5] & 0x3F
         | ((v2[3] & 0x3F) << 12)
         | ((v2[4] & 0x3F) << 6);
      if ( (unsigned int)(v7 - 0x4000000) <= 0x7BFFFFFF )
      {
LABEL_11:
        *a2 = v7;
        *a1 = &v2[v5];
        return 0;
      }
    }
    goto LABEL_20;
  }
  if ( (_DWORD)v5 != 3 )
  {
    v7 = v6 & 0x3F | ((v3 & 0x1F) << 6);
    if ( (unsigned int)(v7 - 128) <= 0x77F )
      goto LABEL_11;
    goto LABEL_20;
  }
  v7 = v2[2] & 0x3F | (unsigned __int16)(v3 << 12) | ((v6 & 0x3F) << 6);
  if ( (unsigned int)(v7 - 2048) <= 0xF7FD )
  {
    if ( (unsigned int)(v7 - 55296) > 0x7FF )
      goto LABEL_11;
    *a1 = v2 + 1;
    *a2 = -2;
    return 4294967236LL;
  }
  else
  {
    *a1 = v2 + 1;
    *a2 = -2;
    return (unsigned int)(v7 - 65534) < 2 ? -59 : -61;
  }
}
