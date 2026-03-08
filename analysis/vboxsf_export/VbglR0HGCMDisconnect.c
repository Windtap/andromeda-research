__int64 __fastcall VbglR0HGCMDisconnect(__int64 a1, int a2)
{
  unsigned int v2; // r12d
  _DWORD v4[2]; // [rsp+4h] [rbp-34h] BYREF
  unsigned __int64 v5; // [rsp+Ch] [rbp-2Ch]
  __int64 v6; // [rsp+14h] [rbp-24h]
  int v7; // [rsp+1Ch] [rbp-1Ch]

  v7 = a2;
  v5 = 0xFFFFFF1F00000000LL;
  v6 = 24;
  v4[0] = 28;
  v4[1] = (_DWORD)&unk_10001;
  v2 = VbglR0IdcCall(a1 + 8, 3223082501LL, v4, 28);
  VbglR0IdcClose(a1 + 8);
  vbglR0HGCMHandleFree(a1, 3223082501LL);
  return v2;
}
