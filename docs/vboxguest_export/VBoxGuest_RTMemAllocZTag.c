void *__fastcall VBoxGuest_RTMemAllocZTag(__int64 a1)
{
  __int64 v2; // [rsp+0h] [rbp-8h] BYREF

  if ( (int)rtR0MemAllocEx(a1, 1, &v2) >= 0 && v2 )
    return memset((void *)(v2 + 16), 0, *(unsigned int *)(v2 + 8));
  else
    return 0;
}
