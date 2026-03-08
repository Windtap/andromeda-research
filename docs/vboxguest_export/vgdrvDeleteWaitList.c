__int64 __fastcall vgdrvDeleteWaitList(__int64 **a1)
{
  __int64 *v2; // rbx
  _QWORD *v3; // rdx
  __int64 v4; // rax
  __int64 v5; // rdi
  __int64 result; // rax

  for ( ; a1[1] != (__int64 *)a1; result = VBoxGuest_RTMemFree(v2) )
  {
    v2 = *a1;
    v3 = (_QWORD *)(*a1)[1];
    v4 = **a1;
    *v3 = v4;
    *(_QWORD *)(v4 + 8) = v3;
    v5 = v2[3];
    *v2 = 0;
    v2[1] = 0;
    VBoxGuest_RTSemEventMultiDestroy(v5);
    v2[3] = 0;
    v2[4] = 0;
  }
  return result;
}
