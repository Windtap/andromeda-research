__int64 __fastcall VbglR0QueryVMMDevMemory(_QWORD *a1)
{
  if ( g_vbgldata != 2 )
    return 4294963996LL;
  if ( !unk_320A8 )
    return 4294967259LL;
  *a1 = unk_320A8;
  return 0;
}
