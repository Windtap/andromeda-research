__int64 __fastcall VbglR0GRFree(__int64 a1)
{
  __int64 result; // rax

  if ( g_vbgldata == 2 )
    return VbglR0PhysHeapFree(a1);
  return result;
}
