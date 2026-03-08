__int64 __fastcall VbglR0IdcClose(unsigned __int64 a1)
{
  __int64 v1; // rax
  __int64 result; // rax
  _DWORD v3[3]; // [rsp+0h] [rbp-28h] BYREF
  int v4; // [rsp+Ch] [rbp-1Ch]
  int v5; // [rsp+10h] [rbp-18h]
  int v6; // [rsp+14h] [rbp-14h]
  __int64 v7; // [rsp+18h] [rbp-10h]

  if ( a1 + 0x200000 <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 4294967290LL;
  }
  v1 = *(_QWORD *)a1;
  if ( !*(_QWORD *)a1
    || (unsigned __int64)(v1 + 0x200000) <= 0x200FFF
    || (v1 & 0xFF00000000000000LL) != 0 && (v1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 4294967292LL;
  }
  v3[0] = 32;
  v3[1] = (_DWORD)&unk_10001;
  v3[2] = 0;
  v4 = -225;
  v5 = 24;
  v6 = 0;
  v7 = v1;
  result = ((__int64 (__fastcall *)(unsigned __int64, _DWORD *))vbglR0IdcNativeClose)(a1, v3);
  if ( (int)result >= 0 )
  {
    result = (unsigned int)v4;
    if ( v4 >= 0 )
      *(_QWORD *)a1 = 0;
  }
  return result;
}
