__int64 __fastcall rtUtf8RecodeAsLatin1(unsigned __int8 *a1, unsigned __int64 a2, _BYTE *a3, __int64 a4)
{
  unsigned __int64 v6; // rax
  unsigned int v7; // esi
  __int64 result; // rax
  unsigned __int64 v9; // [rsp+0h] [rbp-28h] BYREF
  unsigned __int8 *v10; // [rsp+8h] [rbp-20h] BYREF
  unsigned int v11[5]; // [rsp+14h] [rbp-14h] BYREF

  v10 = a1;
  v9 = a2;
LABEL_2:
  v6 = v9;
  if ( v9 )
  {
LABEL_3:
    v7 = *v10;
    if ( (v7 & 0x80u) != 0 )
      goto LABEL_7;
    ++v10;
    v9 = v6 - 1;
    v11[0] = v7;
    if ( v7 )
      goto LABEL_5;
    result = 0;
LABEL_12:
    *a3 = 0;
  }
  else
  {
LABEL_7:
    while ( 1 )
    {
      result = VBoxGuest_RTStrGetCpNExInternal(&v10, &v9, (int *)v11);
      LOBYTE(v7) = v11[0];
      if ( !v11[0] || (int)result < 0 )
        break;
      if ( v11[0] > 0xFF )
      {
        a3 = 0;
        goto LABEL_2;
      }
LABEL_5:
      if ( !a4 )
      {
        result = 4294967255LL;
        goto LABEL_12;
      }
      v6 = v9;
      *a3 = v7;
      --a4;
      ++a3;
      if ( v6 )
        goto LABEL_3;
    }
    *a3 = 0;
    if ( (_DWORD)result == -83 )
      return 0;
  }
  return result;
}
