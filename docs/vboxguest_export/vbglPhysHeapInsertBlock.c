__int64 __fastcall vbglPhysHeapInsertBlock(__int64 a1, __int64 a2)
{
  __int64 v2; // rax
  __int64 result; // rax
  bool v4; // zf

  if ( a1 )
  {
    v2 = *(_QWORD *)(a1 + 16);
    *(_QWORD *)(a2 + 24) = a1;
    *(_QWORD *)(a2 + 16) = v2;
    result = *(_QWORD *)(a1 + 16);
    if ( result )
      *(_QWORD *)(result + 24) = a2;
    *(_QWORD *)(a1 + 16) = a2;
  }
  else
  {
    v4 = (*(_BYTE *)(a2 + 8) & 1) == 0;
    *(_QWORD *)(a2 + 24) = 0;
    if ( v4 )
    {
      *(_QWORD *)(a2 + 16) = unk_320B0;
      result = unk_320B0;
      if ( unk_320B0 )
        *(_QWORD *)(unk_320B0 + 24LL) = a2;
      unk_320B0 = a2;
    }
    else
    {
      *(_QWORD *)(a2 + 16) = unk_320B8;
      result = unk_320B8;
      if ( unk_320B8 )
        *(_QWORD *)(unk_320B8 + 24LL) = a2;
      unk_320B8 = a2;
    }
  }
  return result;
}
