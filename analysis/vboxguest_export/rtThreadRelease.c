__int64 __fastcall rtThreadRelease(__int64 a1)
{
  if ( *(_DWORD *)(a1 + 36) )
    return rtThreadRelease_part_26(a1);
  else
    return 0;
}
