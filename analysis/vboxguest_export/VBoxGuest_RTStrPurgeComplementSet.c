__int64 __fastcall VBoxGuest_RTStrPurgeComplementSet(unsigned __int8 *a1, unsigned int *a2, char a3)
{
  unsigned int v4; // eax
  int v5; // r13d
  __int64 v6; // rdx
  unsigned __int8 *v7; // rbx
  __int64 v8; // r15
  unsigned int v9; // ecx
  unsigned int *v10; // rdx
  unsigned __int8 *v12; // [rsp+0h] [rbp-40h] BYREF
  unsigned int v13[13]; // [rsp+Ch] [rbp-34h] BYREF

  v12 = a1;
  if ( a3 > 0 )
  {
    if ( !*a2 )
    {
      v5 = 0;
      goto LABEL_7;
    }
    if ( a2[1] )
    {
      v4 = 3;
      v5 = 0;
      while ( 1 )
      {
        ++v5;
        if ( !a2[2 * v5] )
          break;
        v6 = v4;
        v4 += 2;
        if ( !a2[v6] )
          return -1;
      }
LABEL_7:
      v7 = v12;
      v8 = 0;
      while ( 1 )
      {
        v9 = *v7;
        if ( (v9 & 0x80u) == 0 )
          break;
        while ( 1 )
        {
          if ( (int)VBoxGuest_RTStrGetCpExInternal(&v12, (int *)v13) < 0 )
            return -1;
          v9 = v13[0];
          if ( !v13[0] )
            return v8;
LABEL_10:
          if ( v5 )
            break;
          while ( v12 != v7 )
LABEL_16:
            *v7++ = a3;
LABEL_18:
          v9 = *v7;
          ++v8;
          if ( (v9 & 0x80u) == 0 )
            goto LABEL_9;
        }
        v10 = a2;
        while ( v9 < *v10 || v9 > v10[1] )
        {
          v10 += 2;
          if ( v10 == &a2[2 * (v5 - 1) + 2] )
          {
            if ( v12 != v7 )
              goto LABEL_16;
            goto LABEL_18;
          }
        }
        v7 = v12;
      }
LABEL_9:
      v13[0] = v9;
      v12 = v7 + 1;
      if ( !v9 )
        return v8;
      goto LABEL_10;
    }
  }
  return -1;
}
