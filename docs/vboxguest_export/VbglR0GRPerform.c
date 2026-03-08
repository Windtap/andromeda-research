__int64 __fastcall VbglR0GRPerform(__int64 a1)
{
  __int64 result; // rax

  if ( g_vbgldata != 2 )
    return 4294963996LL;
  if ( !a1 )
    return 4294967294LL;
  result = 4294963995LL;
  if ( a1 != 40
    && (*(_BYTE *)(a1 - 32) & 1) != 0
    && (unsigned __int64)(*(_DWORD *)(*(_QWORD *)(a1 - 8) + 8LL) + (unsigned int)a1 - (unsigned int)*(_QWORD *)(a1 - 8))
     - 1 <= 0xFFFFFFFE )
  {
    __outdword(unk_320A4, *(_DWORD *)(*(_QWORD *)(a1 - 8) + 8LL) + a1 - *(_QWORD *)(a1 - 8));
    return *(unsigned int *)(a1 + 12);
  }
  return result;
}
