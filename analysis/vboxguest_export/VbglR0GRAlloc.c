__int64 __fastcall VbglR0GRAlloc(
        _QWORD *a1,
        unsigned __int64 a2,
        int a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 result; // rax
  void *v13; // rax
  _DWORD *v14; // rax

  if ( g_vbgldata != 2 )
    return 4294963996LL;
  if ( !a1 || a2 <= 0x17 )
    return 4294967294LL;
  result = 4294967294LL;
  if ( (unsigned int)a2 == a2 )
  {
    v13 = (void *)VbglR0PhysHeapAlloc(a2, a4, a5, a6, a7, a8, a9, a10, a11);
    if ( v13 )
    {
      v14 = memset(v13, 170, (unsigned int)a2);
      *v14 = a2;
      v14[1] = (_DWORD)&loc_10001;
      v14[2] = a3;
      v14[3] = -1;
      v14[4] = 0;
      v14[5] = 1;
      *a1 = v14;
      return 0;
    }
    else
    {
      return 4294967288LL;
    }
  }
  return result;
}
