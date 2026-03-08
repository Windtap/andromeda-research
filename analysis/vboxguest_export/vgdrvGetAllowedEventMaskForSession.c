__int64 __fastcall vgdrvGetAllowedEventMaskForSession(__int64 a1, __int64 a2)
{
  int v2; // edx
  __int64 result; // rax
  int v4; // ecx

  v2 = *(_DWORD *)(a1 + 492);
  result = 2047;
  if ( v2 )
  {
    v4 = *(_DWORD *)(a2 + 304);
    if ( (v4 & 4) == 0 )
      result = (*(_DWORD *)(a1 + 492) & 4) == 0 ? 2047 : 2043;
    if ( (v4 & 1) == 0 && (v2 & 1) != 0 )
      return (unsigned int)result & 0xFFFFFFDF;
  }
  return result;
}
