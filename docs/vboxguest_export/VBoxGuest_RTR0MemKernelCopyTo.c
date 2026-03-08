__int64 __fastcall VBoxGuest_RTR0MemKernelCopyTo(void *a1, const void *a2, unsigned __int64 a3)
{
  if ( a3 )
    return rtR0MemKernelCopyLnxWorker_part_7(a1, a2, a3);
  else
    return 0;
}
