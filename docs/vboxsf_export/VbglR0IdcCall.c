__int64 __fastcall VbglR0IdcCall(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  __int64 result; // rax

  result = VbglR0IdcCallRaw(a1, a2, a3, a4);
  if ( (int)result >= 0 )
    return *(unsigned int *)(a3 + 12);
  return result;
}
