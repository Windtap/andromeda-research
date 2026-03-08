__int64 __fastcall assert_log_func(int a1, const char *a2, const char *a3)
{
  __int64 result; // rax

  result = (__int64)a3;
  if ( !a1 )
  {
    printk("fastpipe: assert!!!!!!!!!!!! [%s] %s\n", a3, a2);
    return dump_stack();
  }
  return result;
}
