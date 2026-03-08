__int64 __fastcall VBoxGuest_RTStrFormatU512(
        char *dest,
        size_t a2,
        unsigned __int64 *a3,
        int a4,
        __int64 a5,
        __int64 a6,
        __int16 a7)
{
  __int16 v8; // bp
  char *v9; // rbx
  __int16 v10; // r9
  __int16 v11; // bp
  __int64 v12; // r14
  __int64 v13; // r15
  __int64 v14; // r14
  __int64 v15; // r15
  __int64 v16; // r14
  __int64 v17; // r15
  __int64 v18; // r14
  __int64 v19; // r14
  __int64 result; // rax
  char v21; // [rsp+8h] [rbp-150h] BYREF

  v8 = a7;
  v9 = &v21;
  if ( a4 != 16 )
    v8 = a7 | 8;
  v10 = v8 & 0x7FF;
  if ( a2 > 0x11F )
    v9 = dest;
  v11 = v8 & 0x7F3 | 0x4004;
  v12 = (int)VBoxGuest_RTStrFormatNumber(v9, a3[7], 0x10u, 0, 0, v10 | 0x4000u);
  v13 = v12 + (int)VBoxGuest_RTStrFormatNumber(&v9[v12], a3[6], 0x10u, 8, 0, v11);
  v14 = v13 + (int)VBoxGuest_RTStrFormatNumber(&v9[v13], a3[5], 0x10u, 8, 0, v11);
  v15 = v14 + (int)VBoxGuest_RTStrFormatNumber(&v9[v14], a3[4], 0x10u, 8, 0, v11);
  v16 = v15 + (int)VBoxGuest_RTStrFormatNumber(&v9[v15], a3[3], 0x10u, 8, 0, v11);
  v17 = v16 + (int)VBoxGuest_RTStrFormatNumber(&v9[v16], a3[2], 0x10u, 8, 0, v11);
  v18 = v17 + (int)VBoxGuest_RTStrFormatNumber(&v9[v17], a3[1], 0x10u, 8, 0, v11);
  v19 = (int)VBoxGuest_RTStrFormatNumber(&v9[v18], *a3, 0x10u, 8, 0, v11) + v18;
  if ( v9 == dest )
    return v19;
  LODWORD(result) = VBoxGuest_RTStrCopy(dest, a2, v9);
  if ( (int)result >= 0 )
    return v19;
  else
    return (int)result;
}
