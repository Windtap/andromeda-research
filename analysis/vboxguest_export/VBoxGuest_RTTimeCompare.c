__int64 __fastcall VBoxGuest_RTTimeCompare(__int64 a1, __int64 a2)
{
  __int64 v2; // rbp
  __int64 v3; // rbx
  __int64 v4; // rax
  __int64 v5; // rax
  unsigned __int16 v7; // ax
  bool v8; // cf
  unsigned __int8 v9; // al
  unsigned __int8 v10; // al
  unsigned __int8 v11; // al
  unsigned int v12; // eax
  _QWORD v13[3]; // [rsp+0h] [rbp-40h] BYREF
  _QWORD v14[5]; // [rsp+18h] [rbp-28h] BYREF

  v2 = a2;
  v3 = a1;
  if ( !a1 )
    return (unsigned int)-(a2 != 0);
  if ( !a2 )
    return 1;
  if ( *(_DWORD *)(a1 + 20)
    || (unsigned __int16)(*(_WORD *)(a1 + 6) - 1) > 0x16Du
    || *(_BYTE *)(a1 + 9) > 0x3Bu
    || *(_BYTE *)(a1 + 10) > 0x3Bu
    || *(_BYTE *)(a1 + 11) > 0x3Bu )
  {
    v13[0] = *(_QWORD *)a1;
    v13[1] = *(_QWORD *)(a1 + 8);
    v13[2] = *(_QWORD *)(a1 + 16);
    v4 = rtTimeNormalizeInternal((__int64)v13);
    v3 = rtTimeConvertToZulu(v4);
  }
  if ( *(_DWORD *)(a2 + 20)
    || (unsigned __int16)(*(_WORD *)(a2 + 6) - 1) > 0x16Du
    || *(_BYTE *)(a2 + 9) > 0x3Bu
    || *(_BYTE *)(a2 + 10) > 0x3Bu
    || *(_BYTE *)(a2 + 11) > 0x3Bu )
  {
    v14[0] = *(_QWORD *)a2;
    v14[1] = *(_QWORD *)(a2 + 8);
    v14[2] = *(_QWORD *)(a2 + 16);
    v5 = rtTimeNormalizeInternal((__int64)v14);
    v2 = rtTimeConvertToZulu(v5);
  }
  if ( *(_DWORD *)v3 != *(_DWORD *)v2 )
    return 2 * (unsigned int)(*(_DWORD *)v3 >= *(_DWORD *)v2) - 1;
  v7 = *(_WORD *)(v2 + 6);
  v8 = *(_WORD *)(v3 + 6) < v7;
  if ( *(_WORD *)(v3 + 6) != v7 )
    return v8 ? -1 : 1;
  v9 = *(_BYTE *)(v2 + 9);
  v8 = *(_BYTE *)(v3 + 9) < v9;
  if ( *(_BYTE *)(v3 + 9) != v9 )
    return v8 ? -1 : 1;
  v10 = *(_BYTE *)(v2 + 10);
  v8 = *(_BYTE *)(v3 + 10) < v10;
  if ( *(_BYTE *)(v3 + 10) == v10
    && (v11 = *(_BYTE *)(v2 + 11), v8 = *(_BYTE *)(v3 + 11) < v11, *(_BYTE *)(v3 + 11) == v11)
    && (v12 = *(_DWORD *)(v2 + 12), v8 = *(_DWORD *)(v3 + 12) < v12, *(_DWORD *)(v3 + 12) == v12) )
  {
    return 0;
  }
  else
  {
    return v8 ? -1 : 1;
  }
}
