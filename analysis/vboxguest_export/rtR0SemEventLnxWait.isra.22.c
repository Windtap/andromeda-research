__int64 __fastcall rtR0SemEventLnxWait_isra_22(__int64 a1, unsigned int a2, unsigned __int64 a3)
{
  unsigned int v3; // ebp
  int v4; // eax
  int v5; // esi
  unsigned int v7; // r13d
  __int64 v9; // r8
  unsigned __int64 v10; // r14
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // rax
  unsigned __int64 v13; // [rsp+0h] [rbp-90h]
  unsigned __int64 v14; // [rsp+0h] [rbp-90h]
  __int64 v15; // [rsp+10h] [rbp-80h] BYREF
  unsigned __int64 v16; // [rsp+18h] [rbp-78h]
  void *v17; // [rsp+20h] [rbp-70h]
  _QWORD v18[2]; // [rsp+28h] [rbp-68h] BYREF
  __int64 v19; // [rsp+38h] [rbp-58h]
  unsigned __int64 v20; // [rsp+40h] [rbp-50h]
  __int64 v21; // [rsp+48h] [rbp-48h] BYREF
  char v22; // [rsp+50h] [rbp-40h]
  char v23; // [rsp+51h] [rbp-3Fh]
  char v24; // [rsp+52h] [rbp-3Eh]
  unsigned int v25; // [rsp+54h] [rbp-3Ch]
  __int64 i; // [rsp+58h] [rbp-38h]

  if ( (unsigned __int64)(a1 + 0x200000) <= 0x200FFF )
    return 4294967294LL;
  v3 = a2;
  if ( (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
    return 4294967294LL;
  if ( *(_DWORD *)a1 != 425726224 || (a2 & 0xFFFFFF80) != 0 )
    return 4294967294LL;
  v4 = a2 ^ (a2 >> 1);
  v5 = a2 & 0x10;
  if ( !((v3 & 0x10) != 0 ? (v4 & 0x20) != 0 : (v4 & 0x25) == 37) )
    return 4294967294LL;
  _InterlockedExchangeAdd((volatile signed __int32 *)(a1 + 8), 1u);
  v7 = 0;
  if ( _InterlockedCompareExchange((volatile signed __int32 *)(a1 + 4), 0, 1) == 1 )
    goto LABEL_9;
  v9 = a1 + 16;
  if ( v5 )
    goto LABEL_14;
  if ( (v3 & 8) != 0 )
  {
    if ( a3 > 0xFFFFFFFFFFF7953FLL )
      goto LABEL_32;
    a3 *= 1000000LL;
  }
  if ( a3 == -1 )
    goto LABEL_32;
  if ( (v3 & 1) == 0 )
  {
    v14 = a3;
    v15 = 0;
    v16 = 0;
    ktime_get_ts64(&v15);
    v12 = v16 + 1000000000 * v15;
    if ( v14 > v12 )
    {
      v9 = a1 + 16;
      v19 = v14;
      v20 = v14 - v12;
LABEL_35:
      v23 = 0;
      if ( (v3 & 6) != 0 || v20 <= 0xCB7353 )
      {
        v22 = 1;
        v21 = v19;
        goto LABEL_15;
      }
      if ( (unsigned __int64)(0x12C * (unsigned __int128)v20 / 0x3B9ACA00) <= 0x3FFFFFFFFFFFFFFDLL )
      {
        v21 = 0x12C * (unsigned __int128)v20 / 0x3B9ACA00;
        v22 = 0;
        goto LABEL_15;
      }
      goto LABEL_32;
    }
LABEL_46:
    v7 = -40;
    goto LABEL_9;
  }
  v13 = a3;
  if ( !a3 )
    goto LABEL_46;
  v15 = 0;
  v16 = 0;
  ktime_get_ts64(&v15);
  v9 = a1 + 16;
  v20 = v13;
  v11 = v16 + 1000000000 * v15;
  v19 = v11 + v13;
  if ( v11 + v13 >= v11 )
    goto LABEL_35;
LABEL_32:
  v3 |= 0x10u;
LABEL_14:
  v23 = 1;
  v22 = 0;
  v19 = -1;
  v20 = -1;
  v21 = 0x7FFFFFFFFFFFFFFFLL;
LABEL_15:
  v24 = 0;
  LODWORD(v15) = 0;
  v18[0] = v18;
  v18[1] = v18;
  v10 = __readgsqword((unsigned int)&current_task);
  v25 = ((int)(v3 << 26) >> 31) + 2;
  v16 = v10;
  v17 = &autoremove_wake_function;
  for ( i = v9; *(_DWORD *)a1 == 425726224; v9 = i )
  {
    prepare_to_wait(v9, &v15, v25);
    if ( *(_DWORD *)a1 != 425726224 )
      break;
    if ( _InterlockedCompareExchange((volatile signed __int32 *)(a1 + 4), 0, 1) == 1 )
    {
      v7 = 0;
      goto LABEL_48;
    }
    if ( v24 )
    {
      v7 = -40;
      goto LABEL_48;
    }
    if ( v25 == 1 && (*(_QWORD *)(*(_QWORD *)(v10 + 8) + 8LL) & 4) != 0 )
    {
      v7 = -39;
      goto LABEL_48;
    }
    if ( v23 )
    {
      schedule();
    }
    else
    {
      if ( v22 )
      {
        if ( (unsigned int)schedule_hrtimeout_range(&v21, 0, 50000) )
          continue;
LABEL_24:
        v24 = 1;
        continue;
      }
      v21 = schedule_timeout(v21);
      if ( v21 <= 0 )
        goto LABEL_24;
    }
  }
  v7 = -363;
LABEL_48:
  finish_wait(i, &v15);
LABEL_9:
  if ( _InterlockedExchangeAdd((volatile signed __int32 *)(a1 + 8), 0xFFFFFFFF) == 1 )
    VBoxGuest_RTMemFree(a1);
  return v7;
}
