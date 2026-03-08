__int64 __fastcall VbglR0PhysHeapFree(__int64 a1)
{
  __int64 result; // rax
  __int64 v3; // rdi
  unsigned __int64 v4; // rax
  __int64 v5; // rax
  unsigned int v6; // edx
  bool v7; // cf
  __int64 v8; // rdi

  result = VBoxGuest_RTSemFastMutexRequest(unk_320C8);
  if ( (int)result >= 0 )
  {
    if ( a1 && a1 != 40 )
    {
      vbglPhysHeapExcludeBlock(a1 - 40);
      *(_DWORD *)(a1 - 32) &= ~1u;
      vbglPhysHeapInsertBlock(0, a1 - 40);
      --*(_DWORD *)(*(_QWORD *)(a1 - 8) + 12LL);
      v3 = *(_QWORD *)(a1 - 8);
      v4 = a1 + *(unsigned int *)(a1 - 36);
      if ( v4 >= v3 + (unsigned __int64)*(unsigned int *)(v3 + 4) || (*(_BYTE *)(v4 + 8) & 1) != 0 )
      {
        if ( !*(_DWORD *)(v3 + 12) )
          goto LABEL_7;
      }
      else
      {
        v8 = a1 + *(unsigned int *)(a1 - 36);
        *(_DWORD *)(a1 - 36) += *(_DWORD *)(v4 + 4) + 40;
        vbglPhysHeapExcludeBlock(v8);
        v3 = *(_QWORD *)(a1 - 8);
        if ( !*(_DWORD *)(v3 + 12) )
        {
LABEL_7:
          v5 = unk_320C0;
          if ( unk_320C0 )
          {
            v6 = 0;
            do
            {
              v7 = *(_DWORD *)(v5 + 12) == 0;
              v5 = *(_QWORD *)(v5 + 16);
              v6 += v7;
            }
            while ( v5 );
            if ( v6 > 1 )
              vbglPhysHeapChunkDelete(v3);
          }
        }
      }
    }
    return VBoxGuest_RTSemFastMutexRelease(unk_320C8);
  }
  return result;
}
