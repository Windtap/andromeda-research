__int64 __fastcall vbsf_inode_revalidate_with_handle(__int64 a1, __int64 a2, char a3, unsigned __int8 a4)
{
  __int64 result; // rax
  __int64 v5; // r14
  __int64 v6; // r12
  unsigned int *v7; // r13
  unsigned int *v8; // rbx
  char v9; // al
  unsigned int v10; // ecx
  int v11; // eax
  unsigned int v12; // ebp
  int PhysAddr; // eax
  int v14; // eax
  bool v15; // zf
  unsigned int v16; // eax
  int v17; // ebp
  int v19; // [rsp+8h] [rbp-38h]
  unsigned int v20; // [rsp+Ch] [rbp-34h]

  result = 4294967274LL;
  if ( a1 )
  {
    v5 = *(_QWORD *)(a1 + 48);
    if ( v5 )
    {
      v6 = *(_QWORD *)(v5 + 552);
      v7 = *(unsigned int **)(*(_QWORD *)(v5 + 40) + 1120LL);
      if ( v6 )
      {
        if ( v7 )
        {
          if ( a3 || *(_BYTE *)(v6 + 8) || (result = 0, jiffies - *(_QWORD *)(v6 + 16) >= (unsigned __int64)v7[14]) )
          {
            v8 = (unsigned int *)VbglR0PhysHeapAlloc(268);
            result = 4294967284LL;
            if ( v8 )
            {
              memset(v8, 0, 0x108u);
              v9 = g_fHostFeatures;
              v8[66] = 0;
              v10 = *v7;
              v8[1] = (unsigned int)&unk_10001;
              v8[2] = 0;
              v8[3] = -225;
              v11 = v9 & 2;
              v8[5] = 0;
              v20 = v10;
              v19 = v11 == 0 ? 124 : 216;
              v12 = v11 == 0 ? 176 : 268;
              *v8 = v12;
              v8[4] = v12;
              PhysAddr = VbglR0PhysHeapGetPhysAddr(v8);
              *((_BYTE *)v8 + 28) = 0;
              v8[14] = (unsigned int)&unk_10001;
              v8[6] = PhysAddr + 52;
              v14 = g_SfClient;
              v8[15] = 63;
              v15 = (g_fHostFeatures & 2) == 0;
              v8[16] = -225;
              v8[13] = v19;
              v8[17] = 0;
              v8[18] = 2;
              v8[19] = 0;
              v8[20] = -225;
              v8[21] = v14;
              v8[22] = 9;
              v8[23] = 5;
              v8[24] = 1;
              v8[25] = v20;
              v8[28] = 2;
              *(_QWORD *)(v8 + 29) = a2;
              v8[32] = 1;
              v8[33] = 8;
              v8[36] = 1;
              v8[37] = 92;
              if ( v15 )
              {
                v8[40] = 6;
                v8[41] = 92;
                *((_QWORD *)v8 + 21) = v8 + 44;
              }
              else
              {
                v16 = *((unsigned __int8 *)v8 + 164);
                v8[40] = 11;
                v8[42] = 92;
                BYTE1(v16) |= 0x7Cu;
                v8[41] = v16;
                *((_BYTE *)v8 + 164) = 2;
              }
              v17 = VbglR0HGCMFastCall(*(_QWORD *)&algn_FA24[4], v8, v12);
              if ( v17 < 0 || (v17 = v8[20], v17 < 0) )
                v17 = -(int)VBoxGuest_RTErrConvertToErrno((unsigned int)v17);
              else
                vbsf_update_inode((unsigned __int16 *)v5, v6, (__int64)(v8 + 44), v7, a4, 0);
              VbglR0PhysHeapFree(v8);
              return (unsigned int)v17;
            }
          }
        }
      }
    }
  }
  return result;
}
