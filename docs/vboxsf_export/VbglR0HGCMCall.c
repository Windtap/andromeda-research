__int64 __fastcall VbglR0HGCMCall(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 result; // rax

  result = VbglR0HGCMCallRaw(a1, a2, a3);
  if ( (int)result >= 0 )
    return *(unsigned int *)(a2 + 12);
  return result;
}
