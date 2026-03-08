__int64 __fastcall rtLatin1CalcUtf8Length(unsigned __int8 *a1, __int64 a2, __int64 *a3)
{
  unsigned __int8 *v3; // rsi
  __int64 i; // rcx
  unsigned int v5; // eax

  v3 = &a1[a2];
  for ( i = 0; a1 != v3; i = i - (v5 < 0x80) + 2 )
  {
    v5 = *a1++;
    if ( !v5 )
      break;
  }
  *a3 = i;
  return 0;
}
