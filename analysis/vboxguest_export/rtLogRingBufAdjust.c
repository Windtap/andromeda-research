__int64 __fastcall rtLogRingBufAdjust(
        __int64 a1,
        unsigned int a2,
        char a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  unsigned int v12; // ebx
  __int64 v13; // rcx
  unsigned int v14; // r12d
  __int64 v15; // rdi
  int v16; // eax
  void *v17; // rdi
  unsigned __int64 v18; // r12
  char *v19; // rax
  char *v20; // rax
  __int64 v21; // rdi

  v12 = a2;
  v13 = *(_QWORD *)(a1 + 49168);
  if ( !*(_BYTE *)(v13 + 43) )
  {
    v14 = 0;
    if ( !a3 )
      return v14;
  }
  if ( *(_DWORD *)v13 != 11 || *(_DWORD *)(v13 + 4) != 120 )
    return (unsigned int)-22300;
  v15 = *(_QWORD *)(v13 + 8);
  if ( v15 )
  {
    v16 = VBoxGuest_RTSemSpinMutexRequest(v15);
    if ( v16 < 0 )
      return (unsigned int)v16;
    v13 = *(_QWORD *)(a1 + 49168);
  }
  if ( !a2 )
    v12 = (unsigned int)&loc_10000;
  if ( *(_DWORD *)(v13 + 68) != v12 || (v14 = 0, !*(_QWORD *)(v13 + 88)) )
  {
    v17 = *(void **)(v13 + 80);
    v18 = *(_QWORD *)(v13 + 88) - (_QWORD)v17;
    if ( v18 > 0xF )
    {
      if ( v18 < v12 )
      {
LABEL_13:
        v19 = (char *)VBoxGuest_RTMemReallocTag(*(_DWORD **)(v13 + 88), v12);
        if ( v19 )
        {
          *(_QWORD *)(*(_QWORD *)(a1 + 49168) + 80LL) = v19;
          *(_QWORD *)(*(_QWORD *)(a1 + 49168) + 88LL) = &v19[v18];
          v14 = 0;
          *(_DWORD *)(*(_QWORD *)(a1 + 49168) + 68LL) = v12;
          strcpy(v19, "START RING BUF");
          v19[15] = 0;
          v20 = &v19[v12 - 16];
          *(_QWORD *)v20 = 0x5220444E45000000LL;
          *((_QWORD *)v20 + 1) = 0x46554220474E49LL;
          v13 = *(_QWORD *)(a1 + 49168);
        }
        else
        {
          v13 = *(_QWORD *)(a1 + 49168);
          v14 = -8;
        }
        goto LABEL_15;
      }
      memmove(v17, (const void *)(*(_QWORD *)(v13 + 88) - v12), v12);
      v13 = *(_QWORD *)(a1 + 49168);
    }
    v18 = 16;
    goto LABEL_13;
  }
LABEL_15:
  v21 = *(_QWORD *)(v13 + 8);
  if ( v21 )
    VBoxGuest_RTSemSpinMutexRelease(v21, a4, a5, a6, a7, a8, a9, a10, a11);
  return v14;
}
