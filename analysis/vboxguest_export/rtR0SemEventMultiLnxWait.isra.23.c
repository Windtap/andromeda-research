__int64 __fastcall rtR0SemEventMultiLnxWait_isra_23(__int64 a1, unsigned int a2, unsigned __int64 a3)
{
  int v3; // eax
  int v5; // r12d
  unsigned int v6; // r13d
  __int64 v8; // r13
  unsigned __int64 v9; // rbp
  unsigned __int64 v10; // rax
  unsigned __int64 v11; // rax
  unsigned __int64 v12; // [rsp+0h] [rbp-90h]
  unsigned __int64 v13; // [rsp+0h] [rbp-90h]
  __int64 v14; // [rsp+10h] [rbp-80h] BYREF
  unsigned __int64 v15; // [rsp+18h] [rbp-78h]
  void *v16; // [rsp+20h] [rbp-70h]
  _QWORD v17[2]; // [rsp+28h] [rbp-68h] BYREF
  __int64 v18; // [rsp+38h] [rbp-58h]
  unsigned __int64 v19; // [rsp+40h] [rbp-50h]
  __int64 v20; // [rsp+48h] [rbp-48h] BYREF
  char v21; // [rsp+50h] [rbp-40h]
  char v22; // [rsp+51h] [rbp-3Fh]
  char v23; // [rsp+52h] [rbp-3Eh]
  unsigned int v24; // [rsp+54h] [rbp-3Ch]
  __int64 i; // [rsp+58h] [rbp-38h]

  if ( (unsigned __int64)(a1 + 0x200000) <= 0x200FFF
    || (a1 & 0xFF00000000000000LL) != 0 && (a1 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 4294967294LL;
  }
  if ( *(_DWORD *)a1 != 421527810 || (a2 & 0xFFFFFF80) != 0 )
    return 4294967294LL;
  v3 = a2 ^ (a2 >> 1);
  if ( !((a2 & 0x10) != 0 ? (v3 & 0x20) != 0 : (v3 & 0x25) == 37) )
    return 4294967294LL;
  _InterlockedExchangeAdd((volatile signed __int32 *)(a1 + 8), 1u);
  v5 = *(_DWORD *)(a1 + 4);
  v6 = 0;
  if ( (v5 & 1) != 0 )
    goto LABEL_9;
  v8 = a1 + 16;
  if ( (a2 & 0x10) != 0 )
    goto LABEL_14;
  if ( (a2 & 8) != 0 )
  {
    if ( a3 > 0xFFFFFFFFFFF7953FLL )
      goto LABEL_32;
    a3 *= 1000000LL;
  }
  if ( a3 == -1 )
    goto LABEL_32;
  if ( (a2 & 1) == 0 )
  {
    v13 = a3;
    v14 = 0;
    v15 = 0;
    ktime_get_ts64(&v14);
    v11 = v15 + 1000000000 * v14;
    if ( v13 > v11 )
    {
      v18 = v13;
      v19 = v13 - v11;
LABEL_35:
      v22 = 0;
      if ( (a2 & 6) != 0 || v19 <= 0xCB7353 )
      {
        v21 = 1;
        v20 = v18;
        goto LABEL_15;
      }
      if ( (unsigned __int64)(0x12C * (unsigned __int128)v19 / 0x3B9ACA00) <= 0x3FFFFFFFFFFFFFFDLL )
      {
        v20 = 0x12C * (unsigned __int128)v19 / 0x3B9ACA00;
        v21 = 0;
        goto LABEL_15;
      }
      goto LABEL_32;
    }
LABEL_46:
    v6 = -40;
    goto LABEL_9;
  }
  v12 = a3;
  if ( !a3 )
    goto LABEL_46;
  v14 = 0;
  v15 = 0;
  ktime_get_ts64(&v14);
  v19 = v12;
  v10 = v15 + 1000000000 * v14;
  v18 = v10 + v12;
  if ( v10 + v12 >= v10 )
    goto LABEL_35;
LABEL_32:
  a2 |= 0x10u;
LABEL_14:
  v22 = 1;
  v21 = 0;
  v18 = -1;
  v19 = -1;
  v20 = 0x7FFFFFFFFFFFFFFFLL;
LABEL_15:
  v23 = 0;
  v16 = &autoremove_wake_function;
  v17[0] = v17;
  v17[1] = v17;
  v24 = ((int)(a2 << 26) >> 31) + 2;
  v9 = __readgsqword((unsigned int)&current_task);
  v15 = v9;
  LODWORD(v14) = 0;
  for ( i = a1 + 16; *(_DWORD *)a1 == 421527810; v8 = i )
  {
    prepare_to_wait(v8, &v14, v24);
    if ( *(_DWORD *)a1 != 421527810 )
      break;
    if ( v5 != *(_DWORD *)(a1 + 4) )
    {
      v6 = 0;
      goto LABEL_48;
    }
    if ( v23 )
    {
      v6 = -40;
      goto LABEL_48;
    }
    if ( v24 == 1 && (*(_QWORD *)(*(_QWORD *)(v9 + 8) + 8LL) & 4) != 0 )
    {
      v6 = -39;
      goto LABEL_48;
    }
    if ( v22 )
    {
      schedule();
    }
    else
    {
      if ( v21 )
      {
        if ( (unsigned int)schedule_hrtimeout_range(&v20, 0, 50000) )
          continue;
LABEL_24:
        v23 = 1;
        continue;
      }
      v20 = schedule_timeout(v20);
      if ( v20 <= 0 )
        goto LABEL_24;
    }
  }
  v6 = -363;
LABEL_48:
  finish_wait(i, &v14);
LABEL_9:
  if ( _InterlockedExchangeAdd((volatile signed __int32 *)(a1 + 8), 0xFFFFFFFF) == 1 )
    VBoxGuest_RTMemFree(a1);
  return v6;
}
