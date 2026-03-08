__int64 __fastcall VBoxGuest_RTR0MemObjMapUserExTag(
        unsigned __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        int a5,
        __int64 a6,
        __int128 a7)
{
  __int64 v8; // r12
  int v9; // edi
  __int64 result; // rax
  unsigned __int64 v11; // rax
  int v12; // ebx
  _DWORD *v13; // rdi
  int v14; // [rsp+10h] [rbp-40h]
  int v15; // [rsp+18h] [rbp-38h]
  int v16; // [rsp+24h] [rbp-2Ch]
  _DWORD *v17; // [rsp+28h] [rbp-28h] BYREF

  v8 = *((_QWORD *)&a7 + 1);
  if ( a1 + 0x200000 <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
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
  v9 = *(_DWORD *)(a2 + 8);
  if ( (unsigned int)(v9 - 1) > 7 )
    return 4294967292LL;
  result = 4294967294LL;
  if ( v9 != 8 && v9 != 7 )
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
    if ( a3 != -1 && (a3 & (a4 - 1)) != 0 )
      return 4294967294LL;
    if ( !a5 )
      return 4294967294LL;
    if ( (a5 & 0xFFFFFFF8) != 0 )
      return 4294967294LL;
    if ( (a7 & 0xFFF) != 0 )
      return 4294967294LL;
    v11 = *(_QWORD *)(a2 + 16);
    if ( (unsigned __int64)a7 >= v11
      || (WORD4(a7) & 0xFFF) != 0
      || v11 < *((_QWORD *)&a7 + 1)
      || a7 != 0 && v11 < (_QWORD)a7 + *((_QWORD *)&a7 + 1) )
    {
      return 4294967294LL;
    }
    else
    {
      if ( a6 == -1 )
      {
        v16 = a5;
        v15 = a4;
        v14 = a3;
        LODWORD(a6) = VBoxGuest_RTR0ProcHandleSelf();
        a5 = v16;
        LODWORD(a4) = v15;
        LODWORD(a3) = v14;
      }
      if ( __PAIR128__(*(_QWORD *)(a2 + 16), 0) == a7 )
        v8 = 0;
      result = rtR0MemObjNativeMapUser((unsigned int)&v17, a2, a3, a4, a5, a6, a7, v8);
      if ( (int)result >= 0 )
      {
        v12 = rtR0MemObjLink(a2, (__int64)v17);
        if ( v12 < 0 )
        {
          rtR0MemObjNativeFree(v17);
          ++*v17;
          v13 = v17;
          v17[2] = 9;
          VBoxGuest_RTMemFree((__int64)v13);
          return (unsigned int)v12;
        }
        else
        {
          *(_QWORD *)a1 = v17;
          return (unsigned int)v12;
        }
      }
    }
  }
  return result;
}
