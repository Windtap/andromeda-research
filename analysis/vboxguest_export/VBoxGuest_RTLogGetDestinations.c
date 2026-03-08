__int64 __fastcall VBoxGuest_RTLogGetDestinations(
        __int64 a1,
        _BYTE *a2,
        size_t a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11)
{
  __int64 v11; // r12
  int v12; // ebp
  int *v13; // rbx
  char v14; // si
  __int64 result; // rax
  const char *v16; // rdx
  int v17; // edx
  const char *v18; // rdx
  size_t v19; // [rsp+0h] [rbp-48h] BYREF
  void *v20; // [rsp+8h] [rbp-40h] BYREF
  char v21[56]; // [rsp+10h] [rbp-38h] BYREF

  v20 = a2;
  v19 = a3;
  if ( !a3 )
    return 4294967294LL;
  v11 = a1;
  *a2 = 0;
  if ( !a1 )
  {
    v11 = VBoxGuest_RTLogDefaultInstance();
    if ( !v11 )
      return 0;
  }
  v12 = *(_DWORD *)(v11 + 49164);
  v13 = (int *)&unk_25080;
  v14 = 0;
  do
  {
    if ( (v12 & *v13) != 0 )
    {
      if ( v14 )
      {
        result = VBoxGuest_RTStrCopyP(&v20, &v19, " ");
        if ( (int)result < 0 )
          return result;
      }
      result = VBoxGuest_RTStrCopyP(&v20, &v19, *((const char **)v13 - 2));
      if ( (int)result < 0 )
        return result;
      v14 = 1;
    }
    v13 += 6;
  }
  while ( v13 != dword_25110 );
  if ( (v12 & 0x20) == 0 )
    return 0;
  if ( *(_DWORD *)(*(_QWORD *)(v11 + 49168) + 68LL) == (_DWORD)&loc_10000 )
  {
    v18 = " ringbuf";
    if ( !v14 )
      v18 = "ringbuf";
    v17 = VBoxGuest_RTStrCopyP(&v20, &v19, v18);
  }
  else
  {
    v16 = " ringbuf=%#x";
    if ( !v14 )
      v16 = "ringbuf=%#x";
    VBoxGuest_RTStrPrintf((__int64)v21, 32, (__int64)v16, a4, a5, a6, a7, a8, a9, a10, a11, v19, v20);
    v17 = VBoxGuest_RTStrCopyP(&v20, &v19, v21);
  }
  result = 0;
  if ( v17 <= 0 )
    return (unsigned int)v17;
  return result;
}
