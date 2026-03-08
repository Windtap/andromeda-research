__int64 __fastcall VBoxGuest_RTStrFormatU128(
        char *dest,
        size_t a2,
        unsigned __int64 *a3,
        int a4,
        __int64 a5,
        __int64 a6,
        __int16 a7)
{
  __int16 v8; // bx
  __int16 v9; // r9
  __int64 v10; // r14
  __int64 v11; // r14
  __int64 result; // rax
  __int64 v13; // r13
  char v14[200]; // [rsp+0h] [rbp-C8h] BYREF

  v8 = a7;
  if ( a4 != 16 )
    v8 = a7 | 8;
  v9 = v8 & 0x7FF;
  if ( a2 > 0x9F )
  {
    v13 = (int)VBoxGuest_RTStrFormatNumber(dest, a3[1], 0x10u, 0, 0, v9 | 0x4000u);
    return v13 + (int)VBoxGuest_RTStrFormatNumber(&dest[v13], *a3, 0x10u, 8, 0, v8 & 0x7F3 | 0x4004u);
  }
  else
  {
    v10 = (int)VBoxGuest_RTStrFormatNumber(v14, a3[1], 0x10u, 0, 0, v9 | 0x4000u);
    v11 = (int)VBoxGuest_RTStrFormatNumber(&v14[v10], *a3, 0x10u, 8, 0, v8 & 0x7F3 | 0x4004u) + v10;
    LODWORD(result) = VBoxGuest_RTStrCopy(dest, a2, v14);
    if ( (int)result < 0 )
      return (int)result;
    else
      return v11;
  }
}
