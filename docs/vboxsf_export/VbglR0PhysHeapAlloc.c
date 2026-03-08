__int64 __fastcall VbglR0PhysHeapAlloc(int a1, unsigned __int64 a2)
{
  unsigned int v2; // ebp
  __int64 v3; // rdx
  __int64 v4; // rcx
  __int64 v5; // rbx
  unsigned int v6; // eax
  __int64 v7; // r12
  __int64 v8; // rcx
  unsigned int v9; // eax
  __int64 v10; // rcx
  __int64 v11; // rdx
  unsigned int v13; // eax
  __int64 v14; // rax
  __int64 v15; // rdx
  __int64 v16; // rdx
  __int64 v17; // rsi

  v2 = (a1 + 7) & 0xFFFFFFF8;
  if ( (int)VBoxGuest_RTSemFastMutexRequest(*(_QWORD *)&algn_10484[36]) < 0 )
    return 0;
  v3 = *(_QWORD *)&algn_10484[12];
  if ( v2 > 0xC00 )
  {
    if ( !*(_QWORD *)&algn_10484[12] )
      goto LABEL_32;
    v5 = 0;
    while ( 1 )
    {
      while ( 1 )
      {
        v13 = *(_DWORD *)(v3 + 4);
        if ( v2 <= v13 )
          break;
LABEL_26:
        v3 = *(_QWORD *)(v3 + 16);
        if ( !v3 )
          goto LABEL_31;
      }
      if ( v2 == v13 )
      {
        v8 = v2;
        v9 = (a1 + 7) & 0xFFFFFFF8;
        v5 = v3;
        v7 = v3 + 40;
        goto LABEL_19;
      }
      if ( v5 )
      {
        if ( v13 < *(_DWORD *)(v5 + 4) )
          v5 = v3;
        goto LABEL_26;
      }
      v5 = v3;
      v3 = *(_QWORD *)(v3 + 16);
      if ( !v3 )
        goto LABEL_31;
    }
  }
  if ( !*(_QWORD *)&algn_10484[12] )
    goto LABEL_32;
  v4 = 0;
  v5 = 0;
  do
  {
    while ( 1 )
    {
      v6 = *(_DWORD *)(v3 + 4);
      if ( v2 <= v6 )
        break;
LABEL_12:
      v3 = *(_QWORD *)(v3 + 16);
      if ( !v3 )
        goto LABEL_17;
    }
    if ( v2 != v6 )
    {
      if ( v4 )
      {
        if ( v6 < *(_DWORD *)(v4 + 4) )
          v4 = v3;
      }
      else
      {
        v4 = v3;
      }
      a2 = ((_WORD)v3 + 40) & 0xFFF;
      if ( 4096 - a2 >= v2 )
      {
        if ( v5 )
        {
          if ( v6 < *(_DWORD *)(v5 + 4) )
            v5 = v3;
        }
        else
        {
          v5 = v3;
        }
      }
      goto LABEL_12;
    }
    v7 = v3 + 40;
    v8 = v2;
    a2 = 4096LL - (((_WORD)v3 + 40) & 0xFFF);
    if ( a2 >= v2 )
    {
      v9 = (a1 + 7) & 0xFFFFFFF8;
      v5 = v3;
      goto LABEL_19;
    }
    v4 = v3;
    v3 = *(_QWORD *)(v3 + 16);
  }
  while ( v3 );
LABEL_17:
  if ( v5 )
    goto LABEL_18;
  v5 = v4;
LABEL_31:
  if ( v5 )
  {
LABEL_18:
    v9 = *(_DWORD *)(v5 + 4);
    v7 = v5 + 40;
    v8 = v2;
  }
  else
  {
LABEL_32:
    v14 = vbglPhysHeapChunkAlloc(v2);
    v5 = v14;
    if ( !v14 )
    {
      VBoxGuest_RTSemFastMutexRelease(*(_QWORD *)&algn_10484[36], a2, v15);
      return 0;
    }
    v9 = *(_DWORD *)(v14 + 4);
    v7 = v5 + 40;
    v8 = v2;
  }
LABEL_19:
  v10 = v8 + 40;
  if ( v9 > (unsigned __int64)(2 * v10) )
  {
    v16 = *(_QWORD *)(v5 + 32);
    v17 = v5 + v10;
    *(_DWORD *)v17 = -1378108485;
    *(_QWORD *)(v17 + 4) = v9 - v2 - 40;
    *(_QWORD *)(v17 + 16) = 0;
    *(_QWORD *)(v17 + 24) = 0;
    *(_QWORD *)(v17 + 32) = v16;
    *(_DWORD *)(v5 + 4) = v2;
    vbglPhysHeapInsertBlock(v5, v5 + v10);
  }
  vbglPhysHeapExcludeBlock(v5);
  *(_DWORD *)(v5 + 8) |= 1u;
  vbglPhysHeapInsertBlock(0, v5);
  ++*(_DWORD *)(*(_QWORD *)(v5 + 32) + 12LL);
  VBoxGuest_RTSemFastMutexRelease(*(_QWORD *)&algn_10484[36], v5, v11);
  return v7;
}
