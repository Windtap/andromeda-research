__int64 __fastcall vgdrvHeartbeatHostConfigure(__int64 a1, char a2)
{
  __int64 result; // rax
  __int64 v4; // rdi
  unsigned int v5; // eax
  __int64 v6; // rdi
  unsigned int v7; // [rsp+4h] [rbp-1Ch]
  _QWORD v8[3]; // [rsp+8h] [rbp-18h] BYREF

  result = VbglR0GRAlloc(v8, 36, 220);
  if ( (int)result >= 0 )
  {
    v4 = v8[0];
    *(_BYTE *)(v8[0] + 32LL) = a2;
    *(_QWORD *)(v4 + 24) = 0;
    v5 = VbglR0GRPerform(v4);
    v6 = v8[0];
    v7 = v5;
    *(_QWORD *)(a1 + 648) = *(_QWORD *)(v8[0] + 24LL);
    VbglR0GRFree(v6);
    return v7;
  }
  return result;
}
