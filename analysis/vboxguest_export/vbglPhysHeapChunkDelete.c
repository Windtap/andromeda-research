__int64 __fastcall vbglPhysHeapChunkDelete(__int64 a1)
{
  __int64 v2; // rdx
  unsigned __int64 v3; // rdi
  unsigned __int64 v4; // rbp
  __int64 v5; // rax
  __int64 v6; // rdx

  v2 = *(unsigned int *)(a1 + 4);
  v3 = a1 + 32;
  if ( v3 < a1 + v2 )
  {
    while ( 1 )
    {
      v4 = v3 + *(unsigned int *)(v3 + 4) + 40;
      vbglPhysHeapExcludeBlock(v3);
      if ( v4 >= a1 + (unsigned __int64)*(unsigned int *)(a1 + 4) )
        break;
      v3 = v4;
    }
  }
  v5 = *(_QWORD *)(a1 + 16);
  if ( v5 )
  {
    *(_QWORD *)(v5 + 24) = *(_QWORD *)(a1 + 24);
    v5 = *(_QWORD *)(a1 + 16);
  }
  v6 = *(_QWORD *)(a1 + 24);
  if ( v6 )
    *(_QWORD *)(v6 + 16) = v5;
  else
    unk_320C0 = v5;
  return VBoxGuest_RTMemContFree(a1, *(unsigned int *)(a1 + 4));
}
