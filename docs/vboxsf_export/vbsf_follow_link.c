_BYTE *__fastcall vbsf_follow_link(__int64 a1, __int64 *a2)
{
  __int64 v2; // r14
  _BYTE *zeroed_page; // rbx
  __int64 v4; // rax
  int *v5; // r13
  __int64 *v6; // rdx
  __int64 v7; // rax
  unsigned __int64 v8; // r12
  __int64 v9; // rsi
  unsigned __int16 v10; // dx
  size_t v11; // rbp
  _WORD *v12; // rax
  _WORD *v13; // r15
  char v14; // al
  int v15; // esi
  unsigned __int64 v16; // rdx
  unsigned int v17; // ebp
  int v18; // esi
  int PhysAddr; // eax
  int v20; // eax
  bool v21; // zf
  int v22; // eax
  int v23; // eax
  int v24; // eax
  int v25; // eax
  int v26; // ebp
  __int64 v27; // rax
  size_t v29; // rax
  size_t v30; // rbp
  _BYTE *v31; // rax
  __int64 v32; // rbp
  int v33; // eax
  int v34; // eax
  int v35; // r12d
  _BYTE *v36; // rax
  _BYTE *v37; // r15
  __int64 DefaultInstance; // rax
  int v40; // [rsp+Ch] [rbp-44h]
  int v41; // [rsp+Ch] [rbp-44h]
  unsigned __int16 v42; // [rsp+18h] [rbp-38h]
  unsigned __int64 v43; // [rsp+18h] [rbp-38h]

  v2 = a1;
  zeroed_page = (_BYTE *)get_zeroed_page(37748928);
  if ( !zeroed_page )
  {
    v32 = -12;
    goto LABEL_32;
  }
  v4 = *(_QWORD *)(a1 + 48);
  v5 = *(int **)(*(_QWORD *)(v4 + 40) + 1120LL);
  v6 = *(__int64 **)(v4 + 552);
  v7 = 0x77FF80000000LL;
  if ( (unsigned __int64)zeroed_page >= 0xFFFFFFFF80000000LL )
    v7 = phys_base;
  v8 = (unsigned __int64)&zeroed_page[v7 + 0x80000000LL];
  v9 = *v6;
  v40 = *v5;
  v10 = *(_WORD *)(*v6 + 2);
  v11 = v10;
  if ( v10 == 0xFFFF )
  {
    v34 = -120;
    goto LABEL_35;
  }
  v42 = v10;
  v12 = (_WORD *)VbglR0PhysHeapAlloc((unsigned int)v10 + 168);
  v13 = v12;
  if ( !v12 )
  {
    v34 = -8;
    goto LABEL_35;
  }
  v12[81] = v42;
  v12[80] = v42 + 1;
  memcpy(v12 + 82, (const void *)(v9 + 4), v11);
  v14 = g_fHostFeatures;
  *((_BYTE *)v13 + v11 + 164) = 0;
  if ( (v14 & 2) != 0 )
  {
    v15 = (unsigned __int16)v13[80];
    v16 = 4096 - (v8 & 0xFFF);
    v17 = v15 + 164;
    v18 = v15 + 112;
  }
  else
  {
    v16 = 4096 - (v8 & 0xFFF);
    if ( v16 <= 0xFFE )
    {
      v33 = v14 & 4;
      v18 = v33 == 0 ? 92 : 112;
      v17 = v33 == 0 ? 144 : 164;
    }
    else
    {
      v18 = 112;
      v17 = 164;
    }
  }
  *(_DWORD *)v13 = v17;
  *((_DWORD *)v13 + 1) = (_DWORD)&unk_10001;
  *((_DWORD *)v13 + 2) = 0;
  *((_DWORD *)v13 + 3) = -225;
  *((_DWORD *)v13 + 4) = v17;
  *((_DWORD *)v13 + 5) = 0;
  v43 = v16;
  PhysAddr = VbglR0PhysHeapGetPhysAddr(v13);
  *((_BYTE *)v13 + 28) = 0;
  *((_DWORD *)v13 + 14) = (_DWORD)&unk_10001;
  *((_DWORD *)v13 + 6) = PhysAddr + 52;
  v20 = g_SfClient;
  v21 = (g_fHostFeatures & 2) == 0;
  *((_DWORD *)v13 + 15) = 63;
  *((_DWORD *)v13 + 16) = -225;
  *((_DWORD *)v13 + 13) = v18;
  *((_DWORD *)v13 + 21) = v20;
  *((_DWORD *)v13 + 17) = 0;
  *((_DWORD *)v13 + 18) = 2;
  *((_DWORD *)v13 + 19) = 0;
  *((_DWORD *)v13 + 20) = -225;
  *((_DWORD *)v13 + 22) = 18;
  *((_DWORD *)v13 + 23) = 3;
  *((_DWORD *)v13 + 24) = 1;
  *((_DWORD *)v13 + 25) = v40;
  v22 = (unsigned __int16)v13[80];
  if ( v21 )
  {
    *((_DWORD *)v13 + 28) = 5;
    *((_DWORD *)v13 + 29) = v22 + 4;
    *((_QWORD *)v13 + 15) = v13 + 80;
  }
  else
  {
    *((_DWORD *)v13 + 28) = 11;
    *((_DWORD *)v13 + 30) = v22 + 4;
    v23 = *((unsigned __int8 *)v13 + 116);
    BYTE1(v23) = 108;
    *((_DWORD *)v13 + 29) = v23;
    *((_BYTE *)v13 + 116) = 1;
  }
  if ( v43 > 0xFFE )
  {
    v24 = 10;
    goto LABEL_12;
  }
  v24 = 12;
  if ( (g_fHostFeatures & 4) != 0 )
  {
LABEL_12:
    *((_DWORD *)v13 + 32) = v24;
    *((_DWORD *)v13 + 33) = 4095;
    v13[74] = v8 & 0xFFF;
    *((_DWORD *)v13 + 34) = 92;
    *((_DWORD *)v13 + 36) = 2;
    *((_QWORD *)v13 + 19) = v8 & 0xFFFFFFFFFFFFF000LL;
    v13[75] = 1;
    goto LABEL_13;
  }
  *((_DWORD *)v13 + 32) = 6;
  *((_DWORD *)v13 + 33) = 4095;
  *((_QWORD *)v13 + 17) = zeroed_page;
LABEL_13:
  v25 = VbglR0HGCMFastCall(*(_QWORD *)&algn_FA24[4], v13, v17);
  if ( v25 < 0 )
  {
    v41 = v25;
    VbglR0PhysHeapFree(v13);
    v34 = v41;
LABEL_45:
    LODWORD(v32) = -22;
    if ( v34 == -127 || v34 == -140 )
    {
LABEL_40:
      v32 = (int)v32;
      goto LABEL_31;
    }
LABEL_35:
    LODWORD(v32) = -22;
    if ( (unsigned int)(v34 + 164) > 3 && v34 != -19 )
    {
      LOBYTE(v32) = -20;
      if ( v34 != -103 )
      {
        LOBYTE(v32) = -2;
        if ( v34 != -102 )
          LODWORD(v32) = -71;
      }
    }
    goto LABEL_40;
  }
  v26 = *((_DWORD *)v13 + 20);
  VbglR0PhysHeapFree(v13);
  if ( v26 < 0 )
  {
    v34 = v26;
    goto LABEL_45;
  }
  zeroed_page[4095] = 0;
  if ( *((_BYTE *)v5 + 16) )
    goto LABEL_16;
  v29 = VBoxGuest_RTStrNLen(zeroed_page, 4096);
  v30 = v29;
  if ( v29 > 0xFFF )
  {
    v32 = -36;
    goto LABEL_31;
  }
  if ( v29 - 1 > 0x200 )
  {
    v35 = v29 + 1;
    v36 = (_BYTE *)_kmalloc(v29 + 1, 37748928);
    v37 = v36;
    if ( !v36 )
    {
      DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
      if ( DefaultInstance )
      {
        v32 = -12;
        if ( (unsigned int)s_LogRelMaxIt_cLogged_44755 <= 0x31 )
        {
          ++s_LogRelMaxIt_cLogged_44755;
          VBoxGuest_RTLogLoggerEx(
            DefaultInstance,
            16,
            337,
            "vbsf_symlink_nls_convert_slow: failed to allocate %u bytes\n",
            v35);
        }
      }
      else
      {
        v32 = -12;
      }
      goto LABEL_31;
    }
    memcpy(v36, zeroed_page, v30);
    v37[v30] = 0;
    v32 = (int)vbsf_nlscpy(v5, zeroed_page, 4096, v37, v30);
    kfree(v37);
  }
  else
  {
    v31 = memcpy(&zeroed_page[-v29 + 4095], zeroed_page, v29);
    v31[v30] = 0;
    v32 = (int)vbsf_nlscpy(v5, zeroed_page, 4097 - v30, v31, v30);
  }
  if ( (_DWORD)v32 )
  {
LABEL_31:
    free_pages(zeroed_page, 0);
LABEL_32:
    *a2 = v32;
    return (_BYTE *)v32;
  }
LABEL_16:
  v27 = jiffies;
  do
  {
    *(_QWORD *)(v2 + 120) = v27;
    v2 = *(_QWORD *)(v2 + 24);
  }
  while ( v2 != *(_QWORD *)(v2 + 24) );
  *a2 = (__int64)zeroed_page;
  return zeroed_page;
}
