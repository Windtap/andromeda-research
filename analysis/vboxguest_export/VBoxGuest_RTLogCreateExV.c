__int64 __fastcall VBoxGuest_RTLogCreateExV(
        unsigned __int64 a1,
        int a2,
        _BYTE *a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        __int64 a12,
        unsigned int a13,
        __int64 a14,
        int a15,
        int a16,
        int a17,
        unsigned int a18,
        int a19,
        int a20,
        __int64 a21)
{
  __int64 v24; // rax
  unsigned __int64 v25; // r12
  unsigned __int64 v26; // rdi
  unsigned __int64 v27; // rax
  _DWORD *v28; // rbx
  double v29; // xmm4_8
  double v30; // xmm5_8
  __int64 result; // rax
  _DWORD *v32; // r12
  __int64 v33; // rax
  __int64 v34; // rax
  int v35; // eax
  int v36; // eax
  signed int v37; // eax
  int v38; // r12d
  __int64 v39; // rax

  if ( a13 && !a14
    || a1 + 0x200000 <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 4294967294LL;
  }
  *(_QWORD *)a1 = 0;
  if ( a18 > 0xFFFFF )
    return 4294967242LL;
  v24 = 4LL * a13;
  v25 = (v24 + 49195) & 0xFFFFFFFFFFFFFFF8LL;
  v26 = v25 + 120;
  v27 = v25 + 120 + v24;
  if ( (a2 & 0x400) != 0 )
    v26 = v27;
  v28 = VBoxGuest_RTMemAllocZVarTag(v26);
  result = 4294967288LL;
  if ( v28 )
  {
    v32 = (_DWORD *)((char *)v28 + v25);
    v28[12290] = a2;
    *((_QWORD *)v28 + 6146) = v32;
    v28[12289] = 422056455;
    v28[12296] = a13;
    v28[12291] = a16;
    *v32 = 11;
    *(_DWORD *)(*((_QWORD *)v28 + 6146) + 4LL) = 120;
    *(_QWORD *)(*((_QWORD *)v28 + 6146) + 8LL) = 0;
    *(_QWORD *)(*((_QWORD *)v28 + 6146) + 16LL) = 0;
    *(_QWORD *)(*((_QWORD *)v28 + 6146) + 24LL) = 0;
    *(_QWORD *)(*((_QWORD *)v28 + 6146) + 32LL) = 0;
    *(_BYTE *)(*((_QWORD *)v28 + 6146) + 40LL) = 1;
    *(_BYTE *)(*((_QWORD *)v28 + 6146) + 43LL) = 0;
    *(_QWORD *)(*((_QWORD *)v28 + 6146) + 96LL) = 0;
    v33 = *((_QWORD *)v28 + 6146);
    *(_QWORD *)(v33 + 104) = 0;
    *(_QWORD *)(v33 + 112) = 0;
    *(_DWORD *)(*((_QWORD *)v28 + 6146) + 44LL) = a13;
    *(_QWORD *)(*((_QWORD *)v28 + 6146) + 48LL) = a14;
    v34 = *((_QWORD *)v28 + 6146);
    if ( (a2 & 0x400) != 0 )
      *(_QWORD *)(v34 + 56) = v34 + 120;
    else
      *(_QWORD *)(v34 + 56) = 0;
    v35 = -1;
    if ( a15 )
      v35 = a15;
    *(_DWORD *)(*((_QWORD *)v28 + 6146) + 64LL) = v35;
    if ( a3 )
      VBoxGuest_RTLogGroupSettings((__int64)v28, a3);
    v36 = v28[12291];
    if ( (v36 & 0x20001) == (_DWORD)&_ksymtab_VBoxGuest_RTR0MemObjAllocContTag )
    {
      v36 &= ~0x20000u;
      v28[12291] = v36;
    }
    if ( (v36 & 0x20) == 0
      || (v38 = rtLogRingBufAdjust(
                  (__int64)v28,
                  *(_DWORD *)(*((_QWORD *)v28 + 6146) + 68LL),
                  1,
                  a4,
                  a5,
                  a6,
                  a7,
                  v29,
                  v30,
                  a10,
                  a11),
          v38 >= 0) )
    {
      v37 = VBoxGuest_RTSemSpinMutexCreate((__int64 *)(*((_QWORD *)v28 + 6146) + 8LL), 1);
      v38 = v37;
      if ( v37 >= 0 )
      {
        *(_BYTE *)(*((_QWORD *)v28 + 6146) + 43LL) = 1;
        result = 0;
        *(_QWORD *)a1 = v28;
        return result;
      }
      VBoxGuest_RTErrInfoSet(a21, v37, "failed to create semaphore");
    }
    v39 = *((_QWORD *)v28 + 6147);
    if ( v39 )
    {
      if ( *(_DWORD *)(v39 - 16) == 403243289 )
        rtR0MemFree(v39 - 16);
    }
    VBoxGuest_RTMemFree((__int64)v28);
    return (unsigned int)v38;
  }
  return result;
}
