__int64 __fastcall VbglR0GRAlloc(_QWORD *a1, unsigned __int64 a2, int a3)
{
  __int64 result; // rax
  void *v5; // rax
  _DWORD *v6; // rax

  result = vbglR0Enter();
  if ( (int)result >= 0 )
  {
    if ( a1 && a2 > 0x17 )
    {
      result = 4294967294LL;
      if ( (unsigned int)a2 == a2 )
      {
        v5 = (void *)VbglR0PhysHeapAlloc((unsigned int)a2);
        if ( v5 )
        {
          v6 = memset(v5, 170, (unsigned int)a2);
          *v6 = a2;
          v6[1] = (_DWORD)&unk_10001;
          v6[2] = a3;
          v6[3] = -1;
          v6[4] = 0;
          v6[5] = 2;
          *a1 = v6;
          return 0;
        }
        else
        {
          return 4294967288LL;
        }
      }
    }
    else
    {
      return 4294967294LL;
    }
  }
  return result;
}
