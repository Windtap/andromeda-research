__int64 __fastcall VbglR0HGCMConnect(__int64 *a1, __int64 a2, _DWORD *a3)
{
  int v4; // ebx
  int *v7; // rax
  __int64 v8; // r14
  int *v9; // r15
  __int64 v10; // rsi
  _DWORD v11[51]; // [rsp+Ch] [rbp-CCh] BYREF

  if ( a1 && a2 )
  {
    v4 = -2;
    if ( a3 )
    {
      v7 = vbglR0HGCMHandleAlloc((__int64)a1, a2);
      LOBYTE(v4) = -8;
      v8 = (__int64)v7;
      if ( v7 )
      {
        v9 = v7 + 2;
        v10 = (__int64)&unk_10000;
        v4 = VbglR0IdcOpen(v7 + 2, &unk_10000, &unk_10000, 0, 0, 0);
        if ( v4 >= 0 )
        {
          v10 = 128;
          memset(v11, 0, 156);
          v11[0] = 156;
          v11[1] = (_DWORD)&unk_10001;
          v11[3] = -225;
          v11[4] = 28;
          v11[6] = 2;
          v4 = VBoxGuest_RTStrCopy(&v11[7], 128, a2);
          if ( v4 >= 0 )
          {
            v10 = 3231471108LL;
            v4 = VbglR0IdcCall(v9, 3231471108LL, v11, 156);
            if ( v4 >= 0 )
            {
              *a3 = v11[6];
              *a1 = v8;
              return (unsigned int)v4;
            }
          }
          VbglR0IdcClose(v9);
        }
        vbglR0HGCMHandleFree(v8, v10);
      }
    }
  }
  else
  {
    return (unsigned int)-2;
  }
  return (unsigned int)v4;
}
