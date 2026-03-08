__int64 __fastcall vbsf_update_inode(unsigned __int16 *a1, __int64 a2, __int64 a3, _DWORD *a4, __int64 a5, char a6)
{
  int v6; // eax
  int v8; // edx
  int v9; // r10d
  int v10; // eax
  bool v11; // zf
  int v12; // edx
  int v13; // edx
  int v14; // eax
  int v15; // edx
  __int64 v16; // rdx
  __int64 v17; // rax
  __int64 v18; // rdx
  unsigned __int64 v19; // r11
  unsigned __int64 v20; // r11
  unsigned __int64 v21; // r11
  __int64 v22; // rax
  __int64 v23; // rdx
  __int64 result; // rax
  __int64 v25; // rdi
  int v26; // eax
  int v27; // edx

  v6 = *(_DWORD *)(a3 + 48);
  v8 = v6 & 0xF000;
  if ( v8 == 0x4000 )
  {
    v26 = v6 & 0x1FF;
    if ( a4[7] != -1 )
      v26 = a4[7] & 0x1FF;
    v14 = ~a4[9] & v26;
    BYTE1(v14) |= 0x40u;
  }
  else
  {
    v9 = a4[8];
    v10 = v6 & 0x1FF;
    v11 = v8 == 40960;
    v12 = a4[10];
    if ( v11 )
    {
      v27 = ~v12;
      if ( v9 != -1 )
        v10 = v9 & 0x1FF;
      v14 = v27 & v10;
      BYTE1(v14) |= 0xA0u;
    }
    else
    {
      v13 = ~v12;
      if ( v9 != -1 )
        v10 = v9 & 0x1FF;
      v14 = v13 & v10;
      BYTE1(v14) |= 0x80u;
    }
  }
  v15 = *a1;
  if ( v15 != v14 )
  {
    if ( (((unsigned __int16)v14 ^ (unsigned __int16)v15) & 0xF000) != 0 )
      return vbsf_init_inode((__int64)a1, a2, (__int64 *)a3, a4);
    *a1 = v14;
  }
  v16 = *(_QWORD *)(a3 + 8);
  v17 = v16 + 1022;
  v18 = v16 + 511;
  if ( v18 >= 0 )
    v17 = v18;
  *((_QWORD *)a1 + 19) = v17 >> 9;
  *((_QWORD *)a1 + 10) = *(_QWORD *)a3;
  v19 = *(_QWORD *)(a3 + 16);
  *((_QWORD *)a1 + 11) = v19 / 0x3B9ACA00;
  *((_QWORD *)a1 + 12) = v19 % 0x3B9ACA00;
  v20 = *(_QWORD *)(a3 + 32);
  *((_QWORD *)a1 + 15) = v20 / 0x3B9ACA00;
  *((_QWORD *)a1 + 16) = v20 % 0x3B9ACA00;
  v21 = *(_QWORD *)(a3 + 24);
  *((_QWORD *)a1 + 13) = v21 / 0x3B9ACA00;
  *((_QWORD *)a1 + 14) = v21 % 0x3B9ACA00;
  v22 = *(_QWORD *)(a3 + 40);
  *(_BYTE *)(a2 + 8) = 0;
  v23 = *(_QWORD *)(a2 + 32);
  *(_QWORD *)(a2 + 24) = v22;
  result = jiffies;
  *(_QWORD *)(a2 + 16) = jiffies;
  if ( v23 != *(_QWORD *)(a3 + 24) )
  {
    if ( (*(_DWORD *)(a3 + 48) & 0xF000) == 0x8000 )
    {
      if ( (a6 & 0x28) != 0 || a4[15] != 1 && v23 == *(_QWORD *)(a2 + 40) )
      {
        *(_QWORD *)(a2 + 40) = 0;
        result = *(_QWORD *)(a3 + 24);
        *(_QWORD *)(a2 + 32) = result;
      }
      else
      {
        result = *(_QWORD *)(a3 + 24);
        *(_QWORD *)(a2 + 32) = result;
        v25 = *((_QWORD *)a1 + 6);
        if ( v25 )
        {
          if ( *(_QWORD *)(v25 + 80) )
            return invalidate_mapping_pages(v25, 0, -1);
        }
      }
    }
    else
    {
      result = *(_QWORD *)(a3 + 24);
      *(_QWORD *)(a2 + 32) = result;
    }
  }
  return result;
}
