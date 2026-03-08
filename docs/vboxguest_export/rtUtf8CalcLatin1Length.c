__int64 __fastcall rtUtf8CalcLatin1Length(unsigned __int8 *a1, unsigned __int64 a2, _QWORD *a3)
{
  __int64 v3; // rbp
  unsigned __int64 v5; // rax
  unsigned int v6; // ecx
  __int64 result; // rax
  unsigned __int64 v8; // [rsp+0h] [rbp-28h] BYREF
  unsigned __int8 *v9; // [rsp+8h] [rbp-20h] BYREF
  unsigned int v10[5]; // [rsp+14h] [rbp-14h] BYREF

  v3 = 0;
  v8 = a2;
  v5 = a2;
  v9 = a1;
  if ( !a2 )
    goto LABEL_5;
LABEL_2:
  v6 = *v9;
  if ( (v6 & 0x80u) != 0 )
  {
LABEL_5:
    while ( 1 )
    {
      result = VBoxGuest_RTStrGetCpNExInternal(&v9, &v8, (int *)v10);
      if ( !v10[0] || (_DWORD)result == -83 )
        break;
      if ( (int)result < 0 )
        return result;
      if ( v10[0] > 0xFF )
        return 4294967238LL;
LABEL_4:
      v5 = v8;
      ++v3;
      if ( v8 )
        goto LABEL_2;
    }
  }
  else
  {
    ++v9;
    v8 = v5 - 1;
    v10[0] = v6;
    if ( v6 )
      goto LABEL_4;
  }
  *a3 = v3;
  return 0;
}
