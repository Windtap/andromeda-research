__int64 __fastcall VBoxGuest_RTLogWriteDebugger(const char *a1, int a2)
{
  return printk("%.*s", a2, a1);
}
