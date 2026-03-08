__int64 __fastcall VBoxGuest_RTLogFlags(__int64 a1, char *a2)
{
  __int64 v2; // r13
  char *v3; // rbx
  char v4; // dl
  int v5; // r14d
  size_t *v6; // rbp
  __int64 v7; // r12
  size_t v8; // r15
  __int64 v9; // r12
  int v10; // eax

  v2 = a1;
  v3 = a2;
  if ( a1 || (v2 = VBoxGuest_RTLogDefaultInstance()) != 0 )
  {
    v4 = *a2;
    while ( v4 )
    {
      if ( (unsigned int)(v4 - 9) <= 4 || v4 == 32 )
      {
        do
        {
          do
            v4 = *++v3;
          while ( (unsigned int)(*v3 - 9) <= 4 );
        }
        while ( v4 == 32 );
        if ( !v4 )
          break;
      }
      v5 = 0;
      while ( v4 )
      {
        switch ( v4 )
        {
          case 'n':
            if ( v3[1] != 111 )
              goto LABEL_17;
            v3 += 2;
            v5 ^= 1u;
            break;
          case '+':
            ++v3;
            v5 = 1;
            break;
          case '-':
          case '!':
          case '~':
            ++v3;
            v5 ^= 1u;
            break;
          default:
            goto LABEL_17;
        }
        v4 = *v3;
      }
LABEL_17:
      v6 = (size_t *)&unk_25108;
      v7 = 0;
      do
      {
        v8 = *v6;
        if ( !strncmp(v3, (const char *)*(v6 - 1), *v6) )
        {
          v9 = 8 * v7;
          if ( (*(_DWORD *)(v2 + 49164) & dword_25118[v9]) == 0 )
          {
            v10 = dword_25110[v9];
            if ( (_BYTE)v5 == byte_25114[v9 * 4] )
              *(_DWORD *)(v2 + 49160) |= v10;
            else
              *(_DWORD *)(v2 + 49160) &= ~v10;
          }
          v3 += v8;
          goto LABEL_25;
        }
        v7 = (unsigned int)(v7 + 1);
        v6 += 4;
      }
      while ( (_DWORD)v7 != 30 );
      do
      {
        ++v3;
LABEL_25:
        v4 = *v3;
      }
      while ( *v3 == 32 || (unsigned int)(v4 - 9) <= 4 || v4 == 59 );
    }
  }
  return 0;
}
