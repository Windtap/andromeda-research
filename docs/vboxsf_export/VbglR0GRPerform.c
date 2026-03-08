__int64 __fastcall VbglR0GRPerform(__int64 a1)
{
  __int64 result; // rax
  unsigned int PhysAddr; // eax

  result = vbglR0Enter();
  if ( (int)result >= 0 )
  {
    if ( a1 )
    {
      PhysAddr = VbglR0PhysHeapGetPhysAddr(a1);
      if ( (unsigned __int64)PhysAddr - 1 > 0xFFFFFFFE )
      {
        return 4294963995LL;
      }
      else
      {
        __outdword(*(unsigned __int16 *)algn_10484, PhysAddr);
        return *(unsigned int *)(a1 + 12);
      }
    }
    else
    {
      return 4294967294LL;
    }
  }
  return result;
}
