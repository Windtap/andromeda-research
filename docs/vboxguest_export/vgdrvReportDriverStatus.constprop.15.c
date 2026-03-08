__int64 vgdrvReportDriverStatus_constprop_15()
{
  __int64 result; // rax
  __int64 v1; // rdi
  unsigned int v2; // eax
  unsigned int v3; // [rsp+4h] [rbp-Ch]
  __int64 v4; // [rsp+8h] [rbp-8h] BYREF

  v4 = 0;
  result = VbglR0GRAlloc(&v4, 36, 59);
  if ( (int)result >= 0 )
  {
    v1 = v4;
    *(_DWORD *)(v4 + 24) = 20;
    *(_DWORD *)(v1 + 28) = 50;
    *(_DWORD *)(v1 + 32) = 0;
    v2 = VbglR0GRPerform(v1);
    if ( v2 == -12 )
      v2 = 0;
    v3 = v2;
    VbglR0GRFree(v4);
    return v3;
  }
  return result;
}
