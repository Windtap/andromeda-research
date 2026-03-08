bool __fastcall PipeTryLock(volatile __int32 *a1)
{
  return _InterlockedExchange(a1, 1) == 0;
}
