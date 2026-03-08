__int64 __fastcall vgdrvLinuxIOCtl(__int64 a1, unsigned int a2, __int64 a3)
{
  __int64 v4; // r14
  unsigned int v5; // ebp
  int v6; // eax
  __int64 v7; // rax
  __int64 v8; // rbx
  int v9; // r14d
  unsigned int v10; // r15d
  __int64 v12; // rax
  __int64 v13; // rax
  __int64 DefaultInstance; // rax
  unsigned int v15; // r8d
  _DWORD v16[4]; // [rsp+8h] [rbp-48h] BYREF
  unsigned int v17; // [rsp+18h] [rbp-38h]

  v4 = *(_QWORD *)(a1 + 208);
  if ( (int)VBoxGuest_RTR0MemUserCopyFrom(v16, a3, 24) < 0 )
    return -14;
  if ( v16[1] != (_DWORD)&loc_10001 )
    return -22;
  v5 = v16[0];
  if ( v17 >= v16[0] )
    v5 = v17;
  if ( v5 > 0x1000000 )
    return -7;
  if ( v16[0] > 0x17u && ((v6 = HIWORD(a2) & 0x3FFF, v5 == v6) || !v6) )
  {
    v7 = VBoxGuest_RTMemAllocTag(
           v5,
           "/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/VBoxGuest-linux.c");
    v8 = v7;
    if ( v7 )
    {
      if ( (int)VBoxGuest_RTR0MemUserCopyFrom(v7, a3, v16[0]) < 0 )
      {
        v9 = -14;
        VBoxGuest_RTMemFree(v8);
      }
      else
      {
        if ( v5 > v16[0] )
          memset((void *)(v8 + v16[0]), 0, v5 - v16[0]);
        v9 = VGDrvCommonIoCtl(a2, &g_DevExt, v4, v8, v5);
        if ( v9 < 0 )
        {
          v9 = -22;
        }
        else
        {
          v10 = *(_DWORD *)(v8 + 16);
          if ( v5 < v10 )
          {
            DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(22478864);
            if ( DefaultInstance )
            {
              v15 = v10;
              v10 = v5;
              VBoxGuest_RTLogLoggerEx(
                DefaultInstance,
                16,
                343,
                (unsigned int)"vgdrvLinuxIOCtlSlow: too much output! %#x > %#x; uCmd=%#x!\n",
                v15,
                v5);
            }
            else
            {
              v10 = v5;
            }
          }
          if ( (int)VBoxGuest_RTR0MemUserCopyTo(a3, v8, v10) < 0 )
          {
            v9 = -14;
            v13 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22478864);
            if ( v13 )
              VBoxGuest_RTLogLoggerEx(
                v13,
                16,
                343,
                (unsigned int)"vgdrvLinuxIOCtlSlow: copy_to_user(%#lx,,%#x); uCmd=%#x!\n",
                a3,
                v10);
          }
        }
        VBoxGuest_RTMemFree(v8);
      }
    }
    else
    {
      v9 = -12;
      v12 = VBoxGuest_RTLogRelGetDefaultInstanceEx(22478864);
      if ( v12 )
        VBoxGuest_RTLogLoggerEx(
          v12,
          16,
          343,
          (unsigned int)"vgdrvLinuxIOCtlSlow: failed to allocate buffer of %d bytes for uCmd=%#x\n",
          v5,
          a2);
    }
  }
  else
  {
    return -22;
  }
  return v9;
}
