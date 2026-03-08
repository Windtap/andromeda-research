__int64 __fastcall VbglR0PhysHeapFree(__int64 a1, __int64 a2)
{
  __int64 result; // rax
  __int64 v4; // rdx
  __int64 v5; // rdi
  __int64 v6; // rax
  __int64 v7; // rax
  bool v8; // cf
  __int64 v9; // rdi

  result = VBoxGuest_RTSemFastMutexRequest(*(_QWORD *)&algn_10484[36]);
  if ( (int)result >= 0 )
  {
    if ( a1 && a1 != 40 )
    {
      vbglPhysHeapExcludeBlock(a1 - 40);
      a2 = a1 - 40;
      *(_DWORD *)(a1 - 32) &= ~1u;
      vbglPhysHeapInsertBlock(0, a1 - 40);
      --*(_DWORD *)(*(_QWORD *)(a1 - 8) + 12LL);
      v5 = *(_QWORD *)(a1 - 8);
      v4 = *(unsigned int *)(a1 - 36);
      v6 = a1 + v4;
      if ( a1 + v4 >= v5 + (unsigned __int64)*(unsigned int *)(v5 + 4) || (*(_BYTE *)(v6 + 8) & 1) != 0 )
      {
        if ( !*(_DWORD *)(v5 + 12) )
          goto LABEL_7;
      }
      else
      {
        v9 = a1 + *(unsigned int *)(a1 - 36);
        *(_DWORD *)(a1 - 36) = *(_DWORD *)(v6 + 4) + v4 + 40;
        vbglPhysHeapExcludeBlock(v9);
        v5 = *(_QWORD *)(a1 - 8);
        if ( !*(_DWORD *)(v5 + 12) )
        {
LABEL_7:
          v7 = *(_QWORD *)&algn_10484[28];
          if ( *(_QWORD *)&algn_10484[28] )
          {
            LODWORD(v4) = 0;
            do
            {
              v8 = *(_DWORD *)(v7 + 12) == 0;
              v7 = *(_QWORD *)(v7 + 16);
              v4 = v8 + (unsigned int)v4;
            }
            while ( v7 );
            if ( (unsigned int)v4 > 1 )
              vbglPhysHeapChunkDelete(v5);
          }
        }
      }
    }
    return VBoxGuest_RTSemFastMutexRelease(*(_QWORD *)&algn_10484[36], a2, v4);
  }
  return result;
}
