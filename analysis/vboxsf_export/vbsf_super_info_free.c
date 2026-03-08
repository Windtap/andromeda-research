__int64 __fastcall vbsf_super_info_free(int *a1)
{
  int v2; // r12d
  _DWORD *v3; // rax
  _DWORD *v4; // rbx
  int PhysAddr; // eax
  __int64 v6; // rdi
  int v7; // eax

  v2 = *a1;
  v3 = (_DWORD *)VbglR0PhysHeapAlloc(112);
  v4 = v3;
  if ( v3 )
  {
    v3[24] = 1;
    v3[25] = v2;
    *v3 = 112;
    v3[1] = (_DWORD)&unk_10001;
    v3[2] = 0;
    v3[3] = -225;
    v3[4] = 112;
    v3[5] = 0;
    PhysAddr = VbglR0PhysHeapGetPhysAddr(v3);
    v6 = *(_QWORD *)&algn_FA24[4];
    *((_BYTE *)v4 + 28) = 0;
    v4[13] = 60;
    v4[6] = PhysAddr + 52;
    v7 = g_SfClient;
    v4[14] = (_DWORD)&unk_10001;
    v4[15] = 63;
    v4[16] = -225;
    v4[17] = 0;
    v4[18] = 2;
    v4[19] = 0;
    v4[20] = -225;
    v4[21] = v7;
    v4[22] = 13;
    v4[23] = 1;
    VbglR0HGCMFastCall(v6, v4, 112);
    VbglR0PhysHeapFree(v4);
  }
  if ( *((_QWORD *)a1 + 1) )
    unload_nls();
  return kfree(a1);
}
