__int64 __fastcall vbsf_super_info_copy_remount_options(__int64 a1, __int64 a2)
{
  __int64 v4; // rsi
  int v5; // eax
  unsigned int v6; // eax
  int v7; // edi
  __int64 result; // rax
  unsigned int v9; // ecx

  *(_DWORD *)(a1 + 20) = *(_DWORD *)(a2 + 296);
  *(_DWORD *)(a1 + 24) = *(_DWORD *)(a2 + 300);
  if ( *(_DWORD *)(a2 + 4) <= 0x143u )
  {
    *(_DWORD *)(a1 + 28) = -1;
    *(_DWORD *)(a1 + 32) = -1;
    if ( *(_DWORD *)(a2 + 4) <= 0x163u )
      goto LABEL_3;
LABEL_29:
    *(_QWORD *)(a1 + 64) = *(_QWORD *)(a2 + 324);
    *(_QWORD *)(a1 + 72) = *(_QWORD *)(a2 + 332);
    *(_QWORD *)(a1 + 80) = *(_QWORD *)(a2 + 340);
    *(_QWORD *)(a1 + 88) = *(_QWORD *)(a2 + 348);
    *(_BYTE *)(a1 + 95) = 0;
    goto LABEL_4;
  }
  *(_DWORD *)(a1 + 28) = *(_DWORD *)(a2 + 308);
  *(_DWORD *)(a1 + 32) = *(_DWORD *)(a2 + 312);
  *(_DWORD *)(a1 + 36) = *(_DWORD *)(a2 + 316);
  *(_DWORD *)(a1 + 40) = *(_DWORD *)(a2 + 320);
  if ( *(_DWORD *)(a2 + 4) > 0x163u )
    goto LABEL_29;
LABEL_3:
  *(_BYTE *)(a1 + 64) = 0;
LABEL_4:
  *(_DWORD *)(a1 + 44) = 2048;
  if ( *(_DWORD *)(a2 + 4) > 0x177u )
  {
    v4 = *(unsigned int *)(a2 + 356);
    if ( (_DWORD)v4 )
    {
      if ( (unsigned int)v4 > 0x8000 )
      {
        printk(&unk_C460, v4);
      }
      else
      {
        v5 = 2;
        if ( (unsigned int)v4 >= 2 )
          v5 = v4;
        *(_DWORD *)(a1 + 44) = v5;
      }
    }
  }
  *(_DWORD *)(a1 + 48) = (_DWORD)&unk_10000;
  if ( *(_DWORD *)(a2 + 4) > 0x167u )
  {
    v6 = *(_DWORD *)(a2 + 360);
    if ( v6 )
    {
      if ( v6 > 0x1000000 )
        printk(&unk_C4B8, *(unsigned int *)(a2 + 356));
      else
        *(_DWORD *)(a1 + 48) = (v6 + 4095) & 0xFFFFF000;
    }
  }
  *(_DWORD *)(a1 + 808) = *(_DWORD *)(a2 + 304);
  v7 = *(_DWORD *)(a2 + 304);
  if ( v7 <= 0 )
  {
    if ( v7 == -1 )
    {
      *(_DWORD *)(a1 + 52) = 60;
      result = 60;
    }
    else
    {
      *(_DWORD *)(a1 + 808) = 0;
      result = 0;
      *(_DWORD *)(a1 + 52) = 0;
    }
  }
  else
  {
    result = ((__int64 (*)(void))_msecs_to_jiffies)();
    *(_DWORD *)(a1 + 52) = result;
  }
  *(_DWORD *)(a1 + 56) = result;
  *(_DWORD *)(a1 + 812) = -1;
  if ( *(_DWORD *)(a2 + 4) > 0x16Bu )
  {
    result = *(unsigned int *)(a2 + 364);
    if ( (int)result >= 0 )
    {
      if ( (_DWORD)result )
      {
        *(_DWORD *)(a1 + 812) = result;
        result = _msecs_to_jiffies(*(unsigned int *)(a2 + 364));
        *(_DWORD *)(a1 + 52) = result;
      }
      else
      {
        *(_DWORD *)(a1 + 812) = 0;
        *(_DWORD *)(a1 + 52) = 0;
      }
    }
  }
  *(_DWORD *)(a1 + 816) = -1;
  if ( *(_DWORD *)(a2 + 4) > 0x16Fu )
  {
    result = *(unsigned int *)(a2 + 368);
    if ( (int)result >= 0 )
    {
      if ( (_DWORD)result )
      {
        *(_DWORD *)(a1 + 816) = result;
        result = _msecs_to_jiffies(*(unsigned int *)(a2 + 368));
        *(_DWORD *)(a1 + 56) = result;
      }
      else
      {
        *(_DWORD *)(a1 + 816) = 0;
        *(_DWORD *)(a1 + 56) = 0;
      }
    }
  }
  *(_DWORD *)(a1 + 60) = 2;
  if ( *(_DWORD *)(a2 + 4) > 0x173u )
  {
    v9 = *(_DWORD *)(a2 + 372);
    if ( v9 > 4 )
      return printk(&unk_C518, v9);
    result = 1LL << v9;
    if ( ((1LL << v9) & 5) != 0 )
      return result;
    if ( (result & 0x1A) == 0 )
      return printk(&unk_C518, v9);
    *(_DWORD *)(a1 + 60) = v9;
  }
  return result;
}
