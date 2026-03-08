__int64 __fastcall VbglR0HGCMInternalConnect(
        unsigned __int64 src,
        int a2,
        unsigned __int64 a3,
        unsigned __int64 a4,
        __int64 a5,
        unsigned int a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  unsigned __int64 v19; // rcx
  __int64 result; // rax
  _DWORD *v21; // rdi
  __int64 v22; // rdi
  int v23; // eax
  __int64 v24; // rdi
  unsigned int v25; // [rsp+4h] [rbp-3Ch]
  _DWORD *v26; // [rsp+8h] [rbp-38h] BYREF

  if ( src + 0x200000 <= 0x200FFF
    || (src & 0xFF00000000000000LL) != 0 && (src & 0xFF00000000000000LL) != 0xFF00000000000000LL
    || a3 + 0x200000 <= 0x200FFF
    || (a3 & 0xFF00000000000000LL) != 0 && (a3 & 0xFF00000000000000LL) != 0xFF00000000000000LL
    || a4 + 0x200000 <= 0x200FFF )
  {
    return 4294967294LL;
  }
  v19 = a4 & 0xFF00000000000000LL;
  if ( (a4 & 0xFF00000000000000LL) == 0 || (result = 4294967294LL, v19 == 0xFF00000000000000LL) )
  {
    v26 = 0;
    result = VbglR0GRAlloc(&v26, 0xA8u, 60, a7, a8, a9, a10, a11, a12, a13, a14);
    if ( (int)result >= 0 )
    {
      v21 = v26;
      v26[5] = a2;
      v21 += 8;
      *(v21 - 2) = 0;
      memcpy(v21, (const void *)src, 0x84u);
      v22 = (__int64)v26;
      v26[41] = 0;
      v23 = VbglR0GRPerform(v22);
      if ( v23 < 0 )
      {
        v24 = (__int64)v26;
      }
      else
      {
        if ( v23 == 2903 )
          ((void (__fastcall *)(_DWORD *, __int64, _QWORD))a4)(v26, a5, a6);
        v24 = (__int64)v26;
        v23 = v26[7];
        if ( v23 >= 0 )
          *(_DWORD *)a3 = v26[41];
      }
      v25 = v23;
      VbglR0GRFree(v24);
      return v25;
    }
  }
  return result;
}
