__int64 __fastcall VbglR0GRFree(__int64 a1)
{
  __int64 result; // rax

  result = vbglR0Enter();
  if ( (int)result >= 0 )
    return VbglR0PhysHeapFree(a1);
  return result;
}
