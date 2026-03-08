__int64 __fastcall rtR0LnxWorkqueuePush(_QWORD *a1, __int64 a2)
{
  __int64 v2; // rsi

  a1[3] = a2;
  v2 = g_prtR0LnxWorkQueue;
  *a1 = 0xFFFFFFFE0LL;
  a1[1] = a1 + 1;
  a1[2] = a1 + 1;
  return queue_work_on(0x2000, v2, a1);
}
