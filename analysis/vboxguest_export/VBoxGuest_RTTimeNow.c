_QWORD *__fastcall VBoxGuest_RTTimeNow(_QWORD *a1)
{
  _QWORD v2[3]; // [rsp+0h] [rbp-18h] BYREF

  getnstimeofday64(v2);
  *a1 = v2[1] + 1000000000LL * v2[0];
  return a1;
}
