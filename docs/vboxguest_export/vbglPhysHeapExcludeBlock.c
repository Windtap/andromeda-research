__int64 __fastcall vbglPhysHeapExcludeBlock(__int64 a1)
{
  __int64 result; // rax
  __int64 v2; // rdx

  result = *(_QWORD *)(a1 + 16);
  if ( result )
  {
    *(_QWORD *)(result + 24) = *(_QWORD *)(a1 + 24);
    result = *(_QWORD *)(a1 + 16);
  }
  v2 = *(_QWORD *)(a1 + 24);
  if ( v2 )
  {
    *(_QWORD *)(v2 + 16) = result;
  }
  else if ( (*(_BYTE *)(a1 + 8) & 1) != 0 )
  {
    unk_320B8 = result;
  }
  else
  {
    unk_320B0 = result;
  }
  *(_QWORD *)(a1 + 16) = 0;
  *(_QWORD *)(a1 + 24) = 0;
  return result;
}
