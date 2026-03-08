__int64 __fastcall vbsf_linux_oflags_to_vbox(int a1, _DWORD *a2)
{
  __int64 result; // rax
  int v3; // edx
  bool v4; // cf

  if ( (a1 & 0x40) != 0 )
  {
    result = 16;
    if ( (a1 & 0x80u) == 0 )
      result = (a1 << 22 >> 31) & 0x30;
    v3 = a1 & 3;
    v4 = v3 == 0;
    if ( v3 != 1 )
      goto LABEL_5;
LABEL_14:
    *a2 |= 2u;
    BYTE1(result) |= 0x20u;
    goto LABEL_8;
  }
  v3 = a1 & 3;
  result = (a1 & 0x200) == 0 ? 256 : 304;
  v4 = v3 == 0;
  if ( v3 == 1 )
    goto LABEL_14;
LABEL_5:
  if ( v4 )
  {
    *a2 |= 1u;
    BYTE1(result) |= 0x10u;
  }
  else
  {
    if ( v3 != 2 )
      BUG();
    *a2 |= 3u;
    BYTE1(result) |= 0x30u;
  }
LABEL_8:
  if ( (a1 & 0x400) != 0 )
  {
    *a2 |= 4u;
    result = (unsigned int)result | 0x40000;
  }
  if ( (a1 & 0x10000) != 0 )
    return (unsigned int)result | 4;
  return result;
}
