__int64 __fastcall VBoxGuest_RTR0MemObjMapKernelExTag(
        unsigned __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        int a5,
        unsigned __int64 a6,
        unsigned __int64 a7)
{
  __int64 v9; // rsi
  unsigned __int64 v10; // rdi
  int v11; // edi
  __int64 result; // rax
  unsigned __int64 v13; // rax
  int v14; // ebx
  _DWORD *v15; // rdi
  _DWORD *v16; // [rsp+8h] [rbp-18h] BYREF

  v9 = a7;
  if ( a1 + 0x200000 <= 0x200FFF )
    return 4294967290LL;
  v10 = a1 & 0xFF00000000000000LL;
  if ( v10 )
  {
    if ( v10 != 0xFF00000000000000LL )
      return 4294967290LL;
  }
  *(_QWORD *)a1 = 0;
  if ( (unsigned __int64)(a2 + 0x200000) <= 0x200FFF
    || (a2 & 0xFF00000000000000LL) != 0 && (a2 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 4294967292LL;
  }
  if ( *(_DWORD *)a2 != 425792016 )
    return 4294967292LL;
  v11 = *(_DWORD *)(a2 + 8);
  if ( (unsigned int)(v11 - 1) > 7 )
    return 4294967292LL;
  result = 4294967294LL;
  if ( v11 != 8 && v11 != 7 )
  {
    if ( a4 )
    {
      if ( a4 != 4096 && a4 != 0x200000 && a4 != 0x400000 )
        return result;
    }
    else
    {
      a4 = 4096;
    }
    if ( a3 == -1 || ((a4 - 1) & a3) == 0 )
    {
      if ( a5 )
      {
        if ( (a5 & 0xFFFFFFF8) == 0 && (a6 & 0xFFF) == 0 )
        {
          v13 = *(_QWORD *)(a2 + 16);
          if ( a6 < v13 && (a7 & 0xFFF) == 0 && v13 >= a7 )
          {
            if ( !(a7 | a6) )
              goto LABEL_20;
            if ( v13 >= a6 + a7 )
            {
              if ( a6 )
              {
LABEL_22:
                result = rtR0MemObjNativeMapKernel((unsigned int)&v16, a2, a3, a4, a5, a6, v9);
                if ( (int)result >= 0 )
                {
                  v14 = rtR0MemObjLink(a2, (__int64)v16);
                  if ( v14 < 0 )
                  {
                    rtR0MemObjNativeFree(v16);
                    ++*v16;
                    v15 = v16;
                    v16[2] = 9;
                    VBoxGuest_RTMemFree((__int64)v15);
                    return (unsigned int)v14;
                  }
                  else
                  {
                    *(_QWORD *)a1 = v16;
                    return (unsigned int)v14;
                  }
                }
                return result;
              }
LABEL_20:
              if ( v13 == a7 )
                v9 = 0;
              goto LABEL_22;
            }
          }
        }
      }
    }
    return 4294967294LL;
  }
  return result;
}
