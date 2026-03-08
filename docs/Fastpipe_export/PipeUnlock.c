__int64 __fastcall PipeUnlock(volatile __int32 *a1)
{
  if ( *a1 != 1 )
  {
    printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", "PipeUnlock", "pPipe->mainLock == 1");
    dump_stack();
  }
  return (unsigned int)_InterlockedExchange(a1, 0);
}
