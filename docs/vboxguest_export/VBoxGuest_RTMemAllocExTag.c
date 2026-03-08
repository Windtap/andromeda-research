__int64 __fastcall VBoxGuest_RTMemAllocExTag(unsigned __int64 a1, unsigned __int64 a2, int a3, __int64 a4, _QWORD *a5)
{
  int v6; // ebx
  __int64 v7; // rsi
  int v8; // r12d
  int v9; // eax
  __int64 v10; // rdx
  void *v11; // rdi
  unsigned int v12; // ebp
  _QWORD v14[4]; // [rsp+0h] [rbp-20h] BYREF

  if ( a2 > 8 )
    return (unsigned int)-97;
  if ( a2 >= a1 )
    a1 = a2;
  if ( (a3 & 0xFFFFFFF0) != 0 )
    return (unsigned int)-2;
  v6 = a3 & 1;
  v7 = 17 - (unsigned int)(v6 == 0);
  v8 = a3 & 2;
  if ( (a3 & 2) != 0 )
    v7 = (17 - (v6 == 0)) | 2u;
  if ( (a3 & 4) != 0 )
    v7 = (unsigned int)v7 | 4;
  if ( (a3 & 8) != 0 )
    v7 = (unsigned int)v7 | 8;
  v9 = rtR0MemAllocEx(a1, v7, v14);
  if ( v9 < 0 )
  {
    v12 = v9;
    if ( v9 == -8 )
      return v8 == 0 ? -8 : -96;
    return v12;
  }
  v10 = v14[0];
  v11 = (void *)(v14[0] + 16LL);
  *a5 = v14[0] + 16LL;
  v12 = v9;
  if ( !v6 )
    return v12;
  memset(v11, 0, *(unsigned int *)(v10 + 8));
  return v12;
}
