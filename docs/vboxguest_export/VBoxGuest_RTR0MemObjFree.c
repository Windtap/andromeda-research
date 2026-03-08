__int64 __fastcall VBoxGuest_RTR0MemObjFree(
        __int64 a1,
        char a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  int v11; // eax
  int v12; // eax
  __int64 v13; // rdx
  __int64 v14; // rax
  _DWORD **v15; // rax
  _DWORD *v16; // rbx
  int v17; // eax
  double v18; // xmm4_8
  double v19; // xmm5_8
  unsigned int v20; // ebx
  __int64 v21; // rax
  int v22; // edx
  int v23; // edi
  unsigned int v24; // edi
  __int64 v25; // rsi
  unsigned int i; // edx
  _QWORD *v27; // rcx
  __int64 v28; // rdi
  __int64 result; // rax
  __int64 v30; // rdx
  __int64 v31; // rcx

  if ( !a1 )
    return 0;
  if ( (unsigned __int64)(a1 + 0x200000) <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 4294967292LL;
  }
  if ( *(_DWORD *)a1 != 425792016 )
    return 4294967292LL;
  v11 = *(_DWORD *)(a1 + 8);
  if ( (unsigned int)(v11 - 1) > 7 )
    return 4294967292LL;
  if ( v11 == 8 || (v12 = *(_DWORD *)(a1 + 36)) == 0 )
  {
LABEL_16:
    result = rtR0MemObjNativeFree(a1);
    v20 = result;
    if ( (int)result >= 0 )
    {
      if ( *(_DWORD *)(a1 + 8) == 8 )
      {
        v21 = *(_QWORD *)(a1 + 32);
        if ( *(_DWORD *)v21 != 425792016 )
        {
          while ( 1 )
          {
            VBoxGuest_RTAssertMsg1(
              (__int64)"pParent->u32Magic == RTR0MEMOBJ_MAGIC",
              0x180u,
              (__int64)"/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/r0drv/memobj-r0drv.c",
              (__int64)"VBoxGuest_RTR0MemObjFree",
              a3,
              a4,
              a5,
              a6,
              v18,
              v19,
              a9,
              a10);
            __debugbreak();
          }
        }
        v22 = *(_DWORD *)(v21 + 8);
        if ( (unsigned int)(v22 - 1) > 7 )
        {
          while ( 1 )
          {
            VBoxGuest_RTAssertMsg1(
              (__int64)"pParent->enmType > RTR0MEMOBJTYPE_INVALID && pParent->enmType < RTR0MEMOBJTYPE_END",
              0x181u,
              (__int64)"/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/r0drv/memobj-r0drv.c",
              (__int64)"VBoxGuest_RTR0MemObjFree",
              a3,
              a4,
              a5,
              a6,
              v18,
              v19,
              a9,
              a10);
            __debugbreak();
          }
        }
        if ( v22 == 8 )
        {
          while ( 1 )
          {
            VBoxGuest_RTAssertMsg1(
              (__int64)"!rtR0MemObjIsMapping(pParent)",
              0x182u,
              (__int64)"/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/r0drv/memobj-r0drv.c",
              (__int64)"VBoxGuest_RTR0MemObjFree",
              a3,
              a4,
              a5,
              a6,
              v18,
              v19,
              a9,
              a10);
            __debugbreak();
          }
        }
        v23 = *(_DWORD *)(v21 + 36);
        if ( !v23 )
        {
          while ( 1 )
          {
            VBoxGuest_RTAssertMsg1(
              (__int64)"pParent->uRel.Parent.cMappings > 0",
              0x183u,
              (__int64)"/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/r0drv/memobj-r0drv.c",
              (__int64)"VBoxGuest_RTR0MemObjFree",
              a3,
              a4,
              a5,
              a6,
              v18,
              v19,
              a9,
              a10);
            __debugbreak();
          }
        }
        v24 = v23 - 1;
        v25 = *(_QWORD *)(v21 + 40);
        for ( i = v24; ; --i )
        {
          v27 = (_QWORD *)(v25 + 8LL * i);
          if ( a1 == *v27 )
            break;
          if ( !i )
            goto LABEL_26;
        }
        *(_DWORD *)(v21 + 36) = v24;
        *v27 = *(_QWORD *)(v25 + 8LL * v24);
      }
LABEL_26:
      v28 = *(_QWORD *)(a1 + 40);
      *(_DWORD *)(a1 + 8) = 9;
      ++*(_DWORD *)a1;
      VBoxGuest_RTMemFree(v28);
      VBoxGuest_RTMemFree(a1);
      return v20;
    }
  }
  else if ( a2 )
  {
    while ( 1 )
    {
      v13 = *(_QWORD *)(a1 + 40);
      v14 = (unsigned int)(v12 - 1);
      *(_DWORD *)(a1 + 36) = v14;
      v15 = (_DWORD **)(v13 + 8 * v14);
      v16 = *v15;
      *v15 = 0;
      if ( *v16 != 425792016 )
      {
        while ( 1 )
        {
          VBoxGuest_RTAssertMsg1(
            (__int64)"pChild->u32Magic == RTR0MEMOBJ_MAGIC",
            0x15Du,
            (__int64)"/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/r0drv/memobj-r0drv.c",
            (__int64)"VBoxGuest_RTR0MemObjFree",
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10);
          __debugbreak();
        }
      }
      v17 = v16[2];
      if ( (unsigned int)(v17 - 1) > 7 )
      {
        while ( 1 )
        {
          VBoxGuest_RTAssertMsg1(
            (__int64)"pChild->enmType > RTR0MEMOBJTYPE_INVALID && pChild->enmType < RTR0MEMOBJTYPE_END",
            0x15Eu,
            (__int64)"/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/r0drv/memobj-r0drv.c",
            (__int64)"VBoxGuest_RTR0MemObjFree",
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10);
          __debugbreak();
        }
      }
      if ( v17 != 8 )
      {
        while ( 1 )
        {
          VBoxGuest_RTAssertMsg1(
            (__int64)"rtR0MemObjIsMapping(pChild)",
            0x15Fu,
            (__int64)"/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/r0drv/memobj-r0drv.c",
            (__int64)"VBoxGuest_RTR0MemObjFree",
            a3,
            a4,
            a5,
            a6,
            a7,
            a8,
            a9,
            a10);
          __debugbreak();
        }
      }
      result = rtR0MemObjNativeFree(v16);
      if ( (int)result < 0 )
        break;
      ++*v16;
      v16[2] = 9;
      VBoxGuest_RTMemFree((__int64)v16);
      v12 = *(_DWORD *)(a1 + 36);
      if ( !v12 )
        goto LABEL_16;
    }
    v30 = *(unsigned int *)(a1 + 36);
    v31 = *(_QWORD *)(a1 + 40);
    *(_DWORD *)(a1 + 36) = v30 + 1;
    *(_QWORD *)(v31 + 8 * v30) = v16;
  }
  else
  {
    return 4294967229LL;
  }
  return result;
}
