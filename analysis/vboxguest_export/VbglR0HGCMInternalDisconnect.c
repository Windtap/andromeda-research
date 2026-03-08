__int64 __fastcall VbglR0HGCMInternalDisconnect(
        int a1,
        int a2,
        void (__fastcall *a3)(__int64, __int64, _QWORD),
        __int64 a4,
        unsigned int a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13)
{
  __int64 result; // rax
  __int64 v18; // rdi
  int v19; // eax
  __int64 v20; // rdi
  unsigned int v21; // [rsp+4h] [rbp-34h]
  __int64 v22[6]; // [rsp+8h] [rbp-30h] BYREF

  if ( !a1 || !a3 )
    return 4294967294LL;
  v22[0] = 0;
  result = VbglR0GRAlloc(v22, 0x24u, 61, a6, a7, a8, a9, a10, a11, a12, a13);
  if ( (int)result >= 0 )
  {
    v18 = v22[0];
    *(_DWORD *)(v22[0] + 20) = a2;
    *(_DWORD *)(v18 + 24) = 0;
    *(_DWORD *)(v18 + 32) = a1;
    v19 = VbglR0GRPerform(v18);
    if ( v19 < 0 )
    {
      v20 = v22[0];
    }
    else
    {
      if ( v19 == 2903 )
        a3(v22[0], a4, a5);
      v20 = v22[0];
      v19 = *(_DWORD *)(v22[0] + 28);
    }
    v21 = v19;
    VbglR0GRFree(v20);
    return v21;
  }
  return result;
}
