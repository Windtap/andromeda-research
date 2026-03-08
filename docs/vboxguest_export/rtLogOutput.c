__int64 __fastcall rtLogOutput(__int64 a1, char *a2, unsigned __int64 a3)
{
  if ( a3 )
    return rtLogOutput_part_13(a1, a2, a3);
  *(_BYTE *)(a1 + *(unsigned int *)(a1 + 49152)) = 0;
  return 0;
}
