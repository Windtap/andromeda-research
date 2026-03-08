__int64 __fastcall VbglGR0Verify(unsigned int *a1, unsigned __int64 a2)
{
  unsigned __int64 v2; // rcx
  unsigned int v3; // edx
  __int64 v4; // rax
  unsigned __int64 v5; // rax
  __int64 result; // rax

  if ( !a1 )
    return 4294967294LL;
  if ( a2 <= 0x17 )
    return 4294967294LL;
  v2 = *a1;
  if ( a2 < v2 )
    return 4294967294LL;
  v3 = a1[2];
  v4 = v3 - 1;
  if ( (unsigned int)v4 <= 0xDD )
  {
    v5 = (unsigned __int16)CSWTCH_652[v4];
    if ( a2 >= v5 )
    {
      if ( a2 == v5 )
        return 2 * (unsigned int)(a2 == v2) - 2;
      goto LABEL_8;
    }
    return 4294967294LL;
  }
LABEL_8:
  if ( (v3 & 0xFFFFFFDF) == 0x51 )
    return a2 >= 0x100001 ? 0xFFFFFFD7 : 0;
  if ( v3 - 62 <= 1 )
    return a2 >= 0x100001 ? 0xFFFFFFD7 : 0;
  switch ( v3 )
  {
    case 0xD4u:
      return a2 >= 0x100001 ? 0xFFFFFFD7 : 0;
    case 0xC8u:
      return a2 >= 0x100001 ? 0xFFFFFFD7 : 0;
    case 3u:
      return a2 >= 0x100001 ? 0xFFFFFFD7 : 0;
  }
  if ( (v3 & 0xFFFFFFFD) == 0x48 )
    return a2 >= 0x100001 ? 0xFFFFFFD7 : 0;
  result = 4294967041LL;
  if ( v3 == 222 )
    return a2 >= 0x100001 ? 0xFFFFFFD7 : 0;
  return result;
}
