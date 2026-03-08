bool __fastcall checkValid(int a1)
{
  if ( (unsigned int)(a1 - 1) > 0x3FE )
  {
    printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", "checkValid", "nPipeId > 0 && nPipeId < MAX_PIPE_COUNT");
    dump_stack();
  }
  return (unsigned int)(a1 - 1) <= 0x3FE;
}
