__int64 __fastcall VBoxGuest_RTStrFormatR80(char *a1, unsigned __int64 a2, __int64 *a3)
{
  __int64 v4; // [rsp+0h] [rbp-10h] BYREF
  __int64 v5; // [rsp+8h] [rbp-8h]

  v5 = 0;
  BYTE1(v5) = *((_BYTE *)a3 + 9) & 0x80;
  LOWORD(v5) = ((*((_BYTE *)a3 + 9) & 0x7F) << 8) | *((unsigned __int8 *)a3 + 8) | v5 & 0x8000;
  v4 = *a3;
  return VBoxGuest_RTStrFormatR80u2(a1, a2, (unsigned __int8 *)&v4);
}
