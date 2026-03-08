__int64 __fastcall VbglR0HGCMInternalCall32(
        __int64 a1,
        unsigned int a2,
        int a3,
        int a4,
        __int64 (__fastcall *a5)(unsigned int *, __int64, _QWORD),
        __int64 a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14,
        unsigned int a15)
{
  __int64 v16; // rdi
  _QWORD *v17; // rax
  double v18; // xmm4_8
  double v19; // xmm5_8
  _QWORD *v20; // r12
  unsigned int *v21; // rbp
  _QWORD *v22; // rbx
  _QWORD *v23; // rcx
  __int64 i; // rax
  unsigned int v25; // r14d
  int v26; // r14d
  __int64 v27; // r13
  unsigned int v28; // edx
  __int64 v29; // rax
  double v30; // xmm4_8
  double v31; // xmm5_8
  __int64 v32; // r8
  __int64 DefaultInstance; // rax
  double v35; // xmm4_8
  double v36; // xmm5_8
  bool v37; // cc
  __int64 v38; // rax
  double v39; // xmm4_8
  double v40; // xmm5_8
  __int64 v41; // r8
  char *v42; // rcx

  if ( a1 && a5 && *(_WORD *)(a1 + 38) <= 0x20u && (a3 & 0xFFFFFFFE) != 0
    || a2 <= 0x27 && a2 < 12 * (unsigned __int64)*(unsigned __int16 *)(a1 + 38) )
  {
    return 4294967294LL;
  }
  if ( (a3 & 1) == 0 )
    return 4294967274LL;
  v16 = *(unsigned __int16 *)(a1 + 38);
  v17 = VBoxGuest_RTMemAllocZTag(16 * v16 + 40);
  v20 = v17;
  if ( !v17 )
    return 4294967276LL;
  v21 = (unsigned int *)(a1 + 40);
  v22 = v17 + 5;
  *v17 = *(_QWORD *)a1;
  v17[1] = *(_QWORD *)(a1 + 8);
  v17[2] = *(_QWORD *)(a1 + 16);
  v17[3] = *(_QWORD *)(a1 + 24);
  v17[4] = *(_QWORD *)(a1 + 32);
  if ( (_WORD)v16 )
  {
    v23 = v17 + 5;
    for ( i = a1 + 40; i != a1 + 12LL * ((unsigned int)(unsigned __int16)v16 - 1) + 52; i += 12 )
    {
      v25 = *(_DWORD *)i;
      if ( *(_DWORD *)i == 2 )
      {
        *(_DWORD *)v23 = 2;
        *(_QWORD *)((char *)v23 + 4) = *(_QWORD *)(i + 4);
      }
      else if ( v25 > 2 )
      {
        if ( v25 - 4 > 2 )
        {
LABEL_26:
          DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(0x860010u);
          if ( DefaultInstance )
            VBoxGuest_RTLogLoggerEx(
              DefaultInstance,
              16,
              0x86u,
              "VbglR0HGCMInternalCall32: pParm32 type %#x invalid.\n",
              a7,
              a8,
              a9,
              a10,
              v35,
              v36,
              a13,
              a14,
              v25);
          v26 = -2;
          v37 = (unsigned int)s_cErrors_22267++ <= 0x1F;
          if ( v37 )
          {
            v26 = -2;
            v38 = VBoxGuest_RTLogRelGetDefaultInstanceEx(0x860010u);
            if ( v38 )
            {
              v41 = 4294967294LL;
              v42 = "VbglR0HGCMInternalCall32: failed. rc=%Rrc\n";
              goto LABEL_31;
            }
          }
          goto LABEL_23;
        }
        *(_DWORD *)v23 = v25;
        *((_DWORD *)v23 + 1) = *(_DWORD *)(i + 4);
        v23[1] = *(unsigned int *)(i + 8);
      }
      else
      {
        if ( v25 != 1 )
          goto LABEL_26;
        *(_DWORD *)v23 = 1;
        *((_DWORD *)v23 + 1) = *(_DWORD *)(i + 4);
      }
      v23 += 2;
    }
  }
  v26 = VbglR0HGCMInternalCall(
          (__int64)v20,
          16 * (unsigned int)(unsigned __int16)v16 + 40,
          a3,
          a4,
          a5,
          a6,
          a7,
          a8,
          a9,
          a10,
          v18,
          v19,
          a13,
          a14,
          a15);
  if ( v26 >= 0 )
  {
    *(_QWORD *)a1 = *v20;
    *(_QWORD *)(a1 + 8) = v20[1];
    *(_QWORD *)(a1 + 16) = v20[2];
    *(_QWORD *)(a1 + 24) = v20[3];
    *(_QWORD *)(a1 + 32) = v20[4];
    if ( !(_WORD)v16 )
      goto LABEL_23;
    v27 = (__int64)&v20[2 * (unsigned int)(unsigned __int16)v16 + 5];
    while ( 1 )
    {
      while ( 1 )
      {
        v28 = *(_DWORD *)v22;
        if ( *(_DWORD *)v22 == 2 )
        {
          *(_QWORD *)(v21 + 1) = *(_QWORD *)((char *)v22 + 4);
          goto LABEL_17;
        }
        if ( v28 > 2 )
          break;
        if ( v28 != 1 )
          goto LABEL_21;
LABEL_16:
        v21[1] = *((_DWORD *)v22 + 1);
LABEL_17:
        v22 += 2;
        v21 += 3;
        if ( v22 == (_QWORD *)v27 )
          goto LABEL_23;
      }
      if ( v28 - 4 <= 2 )
        goto LABEL_16;
LABEL_21:
      v26 = -227;
      v29 = VBoxGuest_RTLogRelGetDefaultInstanceEx(0x860010u);
      if ( !v29 )
        goto LABEL_17;
      v32 = *v21;
      v22 += 2;
      v21 += 3;
      VBoxGuest_RTLogLoggerEx(
        v29,
        16,
        0x86u,
        "VbglR0HGCMInternalCall32: failed invalid pParm32 type %d\n",
        a7,
        a8,
        a9,
        a10,
        v30,
        v31,
        a13,
        a14,
        v32);
      if ( v22 == (_QWORD *)v27 )
        goto LABEL_23;
    }
  }
  v37 = (unsigned int)s_cErrors_22265++ <= 0x1F;
  if ( v37 )
  {
    v38 = VBoxGuest_RTLogRelGetDefaultInstanceEx(0x860010u);
    if ( v38 )
    {
      v41 = (unsigned int)v26;
      v42 = "VbglR0HGCMInternalCall32: VbglR0HGCMInternalCall failed. rc=%Rrc\n";
LABEL_31:
      VBoxGuest_RTLogLoggerEx(v38, 16, 0x86u, v42, a7, a8, a9, a10, v39, v40, a13, a14, v41);
    }
  }
LABEL_23:
  VBoxGuest_RTMemFree((__int64)v20);
  return (unsigned int)v26;
}
