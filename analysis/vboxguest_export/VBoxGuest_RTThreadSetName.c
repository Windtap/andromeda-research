__int64 __fastcall VBoxGuest_RTThreadSetName(__int64 a1, const char *a2)
{
  unsigned int v2; // r12d
  size_t v3; // rbp
  __int64 v4; // rax
  __int64 v5; // rbx

  v2 = -2;
  v3 = strlen(a2);
  if ( v3 <= 0xF )
  {
    v4 = rtThreadGet(a1);
    v5 = v4;
    if ( v4 )
    {
      *(_BYTE *)(v4 + v3 + 104) = 0;
      v2 = 0;
      memcpy((void *)(v4 + 104), a2, v3);
      if ( *(_DWORD *)(v5 + 36) )
        rtThreadRelease_part_26(v5);
    }
    else
    {
      return (unsigned int)-4;
    }
  }
  return v2;
}
