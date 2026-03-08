__int64 __fastcall VBoxGuest_RTTimerCreateEx(__int64 *a1, unsigned __int64 a2, int a3, __int64 a4, __int64 a5)
{
  char *v9; // r10
  __int64 result; // rax
  unsigned __int64 v11; // rdi
  int v12; // r12d
  __int64 v13; // rdi
  __int64 v14; // rcx
  int v15; // eax
  bool v16; // cf
  __int64 v17; // rax
  unsigned int v18; // ebp
  __int64 v19; // rbx
  __int64 v20; // rbx
  __int64 v21; // r14
  __int64 v22; // r15
  _QWORD *v23; // r14
  __int64 v24; // rdx
  int v25; // ebx
  int v26; // [rsp+4h] [rbp-3Ch]
  __int64 v27[7]; // [rsp+8h] [rbp-38h] BYREF

  flush_workqueue(g_prtR0LnxWorkQueue);
  *a1 = 0;
  if ( (a3 & 0x10000) == 0 )
  {
    if ( (a3 & 0xFFFCFFFF) == 0 )
    {
      v11 = 216;
      v12 = 1;
      LODWORD(v9) = a3 & 0x1FFFF;
      if ( (a3 & 0x1FFFF) != (_DWORD)&off_1FFF8 + 7 )
        goto LABEL_14;
LABEL_12:
      v12 = nr_cpu_ids;
      if ( !a2 )
        return 4294967284LL;
      v9 = (char *)&off_1FFF8 + 7;
      v11 = 112LL * nr_cpu_ids + 104;
      goto LABEL_14;
    }
    return 4294967294LL;
  }
  if ( (a3 & 0xFFFC0000) != 0 )
    return 4294967294LL;
  LODWORD(v9) = a3 & 0x1FFFF;
  if ( (a3 & 0x1FFFF) == (_DWORD)&off_1FFF8 + 7 )
    goto LABEL_12;
  result = 4294966495LL;
  if ( (unsigned int)(unsigned __int16)a3 >= nr_cpu_ids || !_bittest64(cpu_possible_mask, (unsigned __int16)a3) )
    return result;
  v11 = 216;
  v12 = 1;
LABEL_14:
  v26 = (int)v9;
  result = VBoxGuest_RTMemAllocExTag(
             v11,
             0,
             9,
             (__int64)"/media/code/p-emulator-vk/system/leidian/vboxguest-6.1.36/vboxguest/r0drv/linux/timer-r0drv-linux.c",
             v27);
  if ( (int)result >= 0 )
  {
    *(_DWORD *)v27[0] = 423037200;
    v14 = v27[0];
    *(_BYTE *)(v27[0] + 19) = (a3 & 0x20000) != 0;
    *(_QWORD *)(v14 + 8) = 0;
    *(_BYTE *)(v14 + 16) = 1;
    if ( (a3 & 0x10000) == 0 || v26 == (_DWORD)&off_1FFF8 + 7 )
    {
      *(_BYTE *)(v14 + 17) = 0;
      v15 = -1;
      *(_BYTE *)(v14 + 18) = v26 == (_DWORD)&off_1FFF8 + 7;
    }
    else
    {
      v15 = -1;
      *(_BYTE *)(v14 + 17) = 1;
      v16 = (unsigned int)(unsigned __int16)a3 < nr_cpu_ids;
      *(_BYTE *)(v14 + 18) = 0;
      if ( v16 )
        v15 = (unsigned __int16)a3;
    }
    *(_DWORD *)(v14 + 20) = v15;
    *(_QWORD *)(v14 + 48) = a2;
    *(_DWORD *)(v14 + 24) = v12;
    *(_QWORD *)(v14 + 32) = a4;
    *(_QWORD *)(v14 + 40) = a5;
    *(_QWORD *)(v14 + 56) = a2 / 0x32DCD5;
    if ( 3333333LL * *(_QWORD *)(v14 + 56) != a2 )
      *(_QWORD *)(v14 + 56) = 0;
    *(_DWORD *)(v14 + 64) = 0;
    v17 = v14;
    if ( !v12 )
      goto LABEL_31;
    v18 = 0;
    do
    {
      v20 = v18;
      v21 = 112LL * v18;
      if ( *(_BYTE *)(v17 + 19) )
      {
        hrtimer_init(v17 + v21 + 104, 1, 0);
        v17 = v27[0];
        *(_QWORD *)(v27[0] + v21 + 144) = rtTimerLinuxHrCallback;
      }
      else
      {
        v22 = v21 + 96;
        init_timer_key(v17 + v21 + 96 + 8, 0, 0, 0);
        v17 = v27[0];
        v23 = (_QWORD *)(v27[0] + v21);
        v23[17] = v27[0] + v22 + 8;
        v24 = jiffies;
        v23[16] = rtTimerLinuxStdCallback;
        v23[19] = 0;
        v23[15] = v24;
      }
      ++v18;
      v19 = v17 + 112 * v20;
      *(_QWORD *)(v19 + 184) = 0;
      *(_QWORD *)(v19 + 200) = v17;
      *(_DWORD *)(v19 + 208) = 0;
    }
    while ( v18 != v12 );
    if ( v18 == 1 )
      goto LABEL_31;
    v25 = VBoxGuest_RTSpinlockCreate((__int64 *)(v17 + 8), 2);
    if ( v25 < 0 )
    {
      v13 = v27[0];
      *(_QWORD *)(v27[0] + 8) = 0;
    }
    else
    {
      v25 = VBoxGuest_RTMpNotificationRegister((__int64)rtTimerLinuxMpEvent, v27[0]);
      if ( v25 >= 0 )
      {
        v17 = v27[0];
LABEL_31:
        *a1 = v17;
        return 0;
      }
      v13 = v27[0];
    }
    VBoxGuest_RTTimerDestroy(v13);
    return (unsigned int)v25;
  }
  return result;
}
