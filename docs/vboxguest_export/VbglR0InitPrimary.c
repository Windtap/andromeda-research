__int64 __fastcall VbglR0InitPrimary(
        __int16 a1,
        __int64 a2,
        _DWORD *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  int v12; // ebx
  double v13; // xmm4_8
  double v14; // xmm5_8
  __int64 DefaultInstance; // rax
  double v17; // xmm4_8
  double v18; // xmm5_8
  __int64 v19[5]; // [rsp+0h] [rbp-28h] BYREF

  memset(&g_vbgldata, 0, 0x58u);
  g_vbgldata = 1;
  v12 = VbglR0PhysHeapInit(a4, a5, a6, a7, a8, a9, a10, a11);
  if ( v12 < 0 )
  {
    DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(0x860010u);
    if ( DefaultInstance )
      VBoxGuest_RTLogLoggerEx(
        DefaultInstance,
        16,
        0x86u,
        "vbglR0InitCommon: VbglR0PhysHeapInit failed: rc=%Rrc\n",
        a4,
        a5,
        a6,
        a7,
        v17,
        v18,
        a10,
        a11,
        (unsigned int)v12);
    g_vbgldata = 0;
    return (unsigned int)v12;
  }
  else
  {
    unk_320A4 = a1;
    unk_320A8 = a2;
    g_vbgldata = 2;
    if ( (int)VbglR0GRAlloc(v19, 0x28u, 4, a4, a5, a6, a7, v13, v14, a10, a11) >= 0 )
    {
      if ( (int)VbglR0GRPerform(v19[0]) >= 0 )
      {
        unk_320D0 = *(_QWORD *)v19[0];
        unk_320D8 = *(_QWORD *)(v19[0] + 8);
        unk_320E0 = *(_QWORD *)(v19[0] + 16);
        unk_320E8 = *(_QWORD *)(v19[0] + 24);
        unk_320F0 = *(_QWORD *)(v19[0] + 32);
      }
      VbglR0GRFree(v19[0]);
    }
    *a3 = unk_320F4;
    return 0;
  }
}
