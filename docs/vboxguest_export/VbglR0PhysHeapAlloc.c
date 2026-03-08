__int64 __fastcall VbglR0PhysHeapAlloc(
        int a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v9; // ebp
  double v10; // xmm4_8
  double v11; // xmm5_8
  __int64 v12; // rdx
  __int64 v13; // rcx
  __int64 v14; // rbx
  unsigned int v15; // eax
  __int64 v16; // r12
  __int64 v17; // rcx
  unsigned int v18; // eax
  __int64 v19; // rcx
  unsigned int v21; // eax
  __int64 v22; // rax
  __int64 v23; // rdx
  __int64 v24; // rsi

  v9 = (a1 + 7) & 0xFFFFFFF8;
  if ( (int)VBoxGuest_RTSemFastMutexRequest(unk_320C8) < 0 )
    return 0;
  v12 = *(_QWORD *)&dword_320B0;
  if ( v9 > 0xC00 )
  {
    if ( !*(_QWORD *)&dword_320B0 )
      goto LABEL_32;
    v14 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        v21 = *(_DWORD *)(v12 + 4);
        if ( v9 <= v21 )
          break;
LABEL_26:
        v12 = *(_QWORD *)(v12 + 16);
        if ( !v12 )
          goto LABEL_31;
      }
      if ( v9 == v21 )
      {
        v17 = v9;
        v18 = (a1 + 7) & 0xFFFFFFF8;
        v14 = v12;
        v16 = v12 + 40;
        goto LABEL_19;
      }
      if ( v14 )
      {
        if ( v21 < *(_DWORD *)(v14 + 4) )
          v14 = v12;
        goto LABEL_26;
      }
      v14 = v12;
      v12 = *(_QWORD *)(v12 + 16);
      if ( !v12 )
        goto LABEL_31;
    }
  }
  if ( !*(_QWORD *)&dword_320B0 )
    goto LABEL_32;
  v13 = 0;
  v14 = 0;
  do
  {
    while ( 1 )
    {
      v15 = *(_DWORD *)(v12 + 4);
      if ( v9 <= v15 )
        break;
LABEL_12:
      v12 = *(_QWORD *)(v12 + 16);
      if ( !v12 )
        goto LABEL_17;
    }
    if ( v9 != v15 )
    {
      if ( v13 )
      {
        if ( v15 < *(_DWORD *)(v13 + 4) )
          v13 = v12;
      }
      else
      {
        v13 = v12;
      }
      if ( 4096 - (unsigned __int64)(((_WORD)v12 + 40) & 0xFFF) >= v9 )
      {
        if ( v14 )
        {
          if ( v15 < *(_DWORD *)(v14 + 4) )
            v14 = v12;
        }
        else
        {
          v14 = v12;
        }
      }
      goto LABEL_12;
    }
    v16 = v12 + 40;
    v17 = v9;
    if ( 4096 - (unsigned __int64)(((_WORD)v12 + 40) & 0xFFF) >= v9 )
    {
      v18 = (a1 + 7) & 0xFFFFFFF8;
      v14 = v12;
      goto LABEL_19;
    }
    v13 = v12;
    v12 = *(_QWORD *)(v12 + 16);
  }
  while ( v12 );
LABEL_17:
  if ( v14 )
    goto LABEL_18;
  v14 = v13;
LABEL_31:
  if ( v14 )
  {
LABEL_18:
    v18 = *(_DWORD *)(v14 + 4);
    v16 = v14 + 40;
    v17 = v9;
  }
  else
  {
LABEL_32:
    v22 = vbglPhysHeapChunkAlloc(v9, a2, a3, a4, a5, v10, v11, a8, a9);
    v14 = v22;
    if ( !v22 )
    {
      VBoxGuest_RTSemFastMutexRelease(unk_320C8);
      return 0;
    }
    v18 = *(_DWORD *)(v22 + 4);
    v16 = v14 + 40;
    v17 = v9;
  }
LABEL_19:
  v19 = v17 + 40;
  if ( v18 > (unsigned __int64)(2 * v19) )
  {
    v23 = *(_QWORD *)(v14 + 32);
    v24 = v14 + v19;
    *(_DWORD *)v24 = -1378108485;
    *(_QWORD *)(v24 + 4) = v18 - v9 - 40;
    *(_QWORD *)(v24 + 16) = 0;
    *(_QWORD *)(v24 + 24) = 0;
    *(_QWORD *)(v24 + 32) = v23;
    *(_DWORD *)(v14 + 4) = v9;
    vbglPhysHeapInsertBlock(v14, v14 + v19);
  }
  vbglPhysHeapExcludeBlock(v14);
  *(_DWORD *)(v14 + 8) |= 1u;
  vbglPhysHeapInsertBlock(0, v14);
  ++*(_DWORD *)(*(_QWORD *)(v14 + 32) + 12LL);
  VBoxGuest_RTSemFastMutexRelease(unk_320C8);
  return v16;
}
