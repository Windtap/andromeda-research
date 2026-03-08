__int64 __fastcall vbsf_init_inode(__int64 a1, __int64 a2, __int64 *a3, _DWORD *a4)
{
  int v7; // eax
  int v8; // edx
  __int16 v9; // ax
  bool v10; // zf
  int v11; // edx
  int v12; // ecx
  __int16 v13; // dx
  __int16 v14; // ax
  __int64 v15; // rax
  __int64 v16; // rdx
  __int64 v17; // rax
  __int64 v18; // rdx
  unsigned __int64 v19; // rsi
  unsigned __int64 v20; // rsi
  unsigned __int64 v21; // rsi
  __int64 result; // rax
  int v23; // edx
  __int16 v24; // ax
  int v25; // ecx
  __int16 v26; // dx
  __int16 v27; // ax
  __int16 v28; // dx
  __int16 v29; // ax

  *(_QWORD *)(a2 + 16) = jiffies;
  *(_BYTE *)(a2 + 8) = 0;
  v7 = *((_DWORD *)a3 + 12);
  v8 = v7 & 0xF000;
  if ( v8 == 0x4000 )
  {
    v23 = a4[9];
    v24 = v7 & 0x1FF;
    v25 = a4[7];
    *(_QWORD *)(a1 + 32) = vbsf_dir_iops;
    *(_QWORD *)(a1 + 336) = &vbsf_dir_fops;
    v26 = ~(_WORD)v23;
    if ( v25 != -1 )
      v24 = v25 & 0x1FF;
    v27 = v26 & v24;
    HIBYTE(v27) |= 0x40u;
    *(_WORD *)a1 = v27;
    set_nlink(a1, 1);
  }
  else
  {
    v9 = v7 & 0x1FF;
    v10 = v8 == 40960;
    v11 = a4[10];
    v12 = a4[8];
    if ( v10 )
    {
      v28 = ~(_WORD)v11;
      if ( v12 != -1 )
        v9 = v12 & 0x1FF;
      *(_QWORD *)(a1 + 32) = &vbsf_lnk_iops;
      v29 = v28 & v9;
      HIBYTE(v29) |= 0xA0u;
      *(_WORD *)a1 = v29;
      set_nlink(a1, 1);
    }
    else
    {
      v13 = ~(_WORD)v11;
      if ( v12 != -1 )
        v9 = v12 & 0x1FF;
      *(_QWORD *)(a1 + 32) = &vbsf_reg_iops;
      *(_QWORD *)(a1 + 336) = &vbsf_reg_fops;
      v14 = v13 & v9;
      HIBYTE(v14) |= 0x80u;
      *(_WORD *)a1 = v14;
      *(_QWORD *)(*(_QWORD *)(a1 + 48) + 104LL) = vbsf_reg_aops;
      set_nlink(a1, 1);
    }
  }
  *(_DWORD *)(a1 + 4) = a4[5];
  *(_DWORD *)(a1 + 8) = a4[6];
  v15 = *a3;
  *(_DWORD *)(a1 + 144) = 12;
  *(_QWORD *)(a1 + 80) = v15;
  v16 = a3[1];
  v17 = v16 + 1022;
  v18 = v16 + 511;
  if ( v18 >= 0 )
    v17 = v18;
  *(_QWORD *)(a1 + 152) = v17 >> 9;
  v19 = a3[2];
  *(_QWORD *)(a1 + 88) = v19 / 0x3B9ACA00;
  *(_QWORD *)(a1 + 96) = v19 % 0x3B9ACA00;
  v20 = a3[4];
  *(_QWORD *)(a1 + 120) = v20 / 0x3B9ACA00;
  *(_QWORD *)(a1 + 128) = v20 % 0x3B9ACA00;
  v21 = a3[3];
  *(_QWORD *)(a1 + 104) = v21 / 0x3B9ACA00;
  *(_QWORD *)(a1 + 112) = v21 % 0x3B9ACA00;
  *(_QWORD *)(a2 + 24) = a3[5];
  result = a3[3];
  *(_QWORD *)(a2 + 40) = 0;
  *(_QWORD *)(a2 + 32) = result;
  return result;
}
