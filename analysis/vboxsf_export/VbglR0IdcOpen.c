__int64 __fastcall VbglR0IdcOpen(
        unsigned __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned __int64 a4,
        unsigned __int64 a5,
        unsigned __int64 a6)
{
  unsigned int v6; // r14d
  __int64 result; // rax
  __int64 v11; // rdx
  unsigned __int64 v12; // rdx
  int v13; // edx
  int v14; // eax
  int v15; // eax
  _DWORD v16[3]; // [rsp+0h] [rbp-60h] BYREF
  int v17; // [rsp+Ch] [rbp-54h]
  int v18; // [rsp+10h] [rbp-50h]
  int v19; // [rsp+14h] [rbp-4Ch]
  __int64 v20; // [rsp+18h] [rbp-48h]
  unsigned int v21; // [rsp+20h] [rbp-40h]
  int v22; // [rsp+24h] [rbp-3Ch]
  int v23; // [rsp+28h] [rbp-38h]

  if ( a1 + 0x200000 <= 0x200FFF )
    return 4294967290LL;
  v6 = a3;
  if ( (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
    return 4294967290LL;
  *(_QWORD *)a1 = 0;
  if ( a4 + 0x200000 > 0x200FFF
    && ((a4 & 0xFF00000000000000LL) == 0 || (a4 & 0xFF00000000000000LL) == 0xFF00000000000000LL) )
  {
    if ( a4 )
      *(_DWORD *)a4 = 0;
  }
  else if ( a4 )
  {
    return 4294967290LL;
  }
  if ( a5 + 0x200000 > 0x200FFF
    && ((a5 & 0xFF00000000000000LL) == 0 || (a5 & 0xFF00000000000000LL) == 0xFF00000000000000LL) )
  {
    if ( a5 )
      *(_DWORD *)a5 = 0;
  }
  else if ( a5 )
  {
    return 4294967290LL;
  }
  if ( a6 + 0x200000 > 0x200FFF
    && ((a6 & 0xFF00000000000000LL) == 0 || (a6 & 0xFF00000000000000LL) == 0xFF00000000000000LL) )
  {
    if ( a6 )
      *(_DWORD *)a6 = 0;
  }
  else if ( a6 )
  {
    return 4294967290LL;
  }
  if ( a3 )
  {
    HIWORD(v14) = HIWORD(a3);
    LOWORD(v14) = 0;
    if ( v14 != (_DWORD)&unk_10000 )
      return 4294967294LL;
  }
  if ( a2 )
  {
    HIWORD(v15) = HIWORD(a2);
    LOWORD(v15) = 0;
    if ( v15 != (_DWORD)&unk_10000 )
      return 4294967294LL;
  }
  if ( a3 <= 0xFFFF )
    v6 = (unsigned int)&unk_10000;
  v16[0] = 40;
  if ( a2 <= 0xFFFF )
    a2 = (unsigned int)&unk_10000;
  v16[1] = (_DWORD)&unk_10001;
  v16[2] = 0;
  HIDWORD(v20) = a2;
  v17 = -225;
  v18 = 56;
  v19 = 0;
  LODWORD(v20) = 1437224282;
  v21 = v6;
  v22 = 0;
  result = ((__int64 (__fastcall *)(unsigned __int64, _DWORD *))vbglR0IdcNativeOpen)(a1, v16);
  if ( (int)result >= 0 )
  {
    result = (unsigned int)v17;
    if ( v17 >= 0 )
    {
      v11 = v20;
      *(_QWORD *)a1 = v20;
      if ( a4 )
        *(_DWORD *)a4 = v21;
      if ( a5 )
        *(_DWORD *)a5 = v22;
      if ( a6 )
        *(_DWORD *)a6 = v23;
      if ( (unsigned __int64)(v11 + 0x200000) <= 0x200FFF )
        goto LABEL_33;
      v12 = v11 & 0xFF00000000000000LL;
      if ( v12 && v12 != 0xFF00000000000000LL )
      {
        VbglR0IdcClose(a1);
        return 4294967285LL;
      }
      HIWORD(v13) = HIWORD(v21);
      if ( v6 > v21 || (LOWORD(v13) = 0, v13 != (_DWORD)&unk_10000) )
      {
LABEL_33:
        VbglR0IdcClose(a1);
        return 4294967285LL;
      }
    }
  }
  return result;
}
