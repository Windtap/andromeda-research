__int64 VBoxGuest_RTTimeNanoTS()
{
  __int64 v1; // [rsp+0h] [rbp-10h] BYREF
  __int64 v2; // [rsp+8h] [rbp-8h]

  v1 = 0;
  v2 = 0;
  ktime_get_ts64(&v1);
  return v2 + 1000000000 * v1;
}
