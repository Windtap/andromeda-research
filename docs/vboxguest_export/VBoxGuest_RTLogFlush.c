void __fastcall VBoxGuest_RTLogFlush(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // rbx
  __int64 v10; // rax
  __int64 v11; // rdi
  double v12; // xmm4_8
  double v13; // xmm5_8
  __int64 v14; // rax
  __int64 v15; // rcx
  __int64 v16; // rdx
  unsigned __int64 v17; // r12
  unsigned __int8 *v18; // r13
  unsigned __int64 v19; // rdx
  unsigned __int64 v20; // rbp
  unsigned __int64 v21; // rsi
  int v22; // eax
  unsigned __int8 *v23; // r14
  __int64 v24; // r15
  int v25; // eax
  int v26; // eax
  __int64 v27; // rdi
  unsigned __int8 *v28; // [rsp+0h] [rbp-38h]

  v9 = a1;
  if ( (a1 || (v9 = g_pLogger) != 0) && (*(_DWORD *)(v9 + 49152) || (*(_BYTE *)(v9 + 49164) & 0x20) != 0) )
  {
    v10 = *(_QWORD *)(v9 + 49168);
    if ( *(_DWORD *)v10 == 11 && *(_DWORD *)(v10 + 4) == 120 )
    {
      v11 = *(_QWORD *)(v10 + 8);
      if ( !v11 || (int)VBoxGuest_RTSemSpinMutexRequest(v11) >= 0 )
      {
        rtlogFlush_isra_12(v9);
        if ( (*(_BYTE *)(v9 + 49164) & 0x20) == 0 )
          goto LABEL_43;
        v14 = *(_QWORD *)(v9 + 49168);
        v15 = *(_QWORD *)(v14 + 80);
        v16 = v14;
        if ( !v15 )
          goto LABEL_44;
        v17 = *(_QWORD *)(v14 + 72);
        v18 = (unsigned __int8 *)(v15 + 16);
        v19 = *(unsigned int *)(v14 + 68) - 32LL;
        v20 = *(_QWORD *)(v14 + 88) - (v15 + 16);
        v21 = v19;
        if ( v19 <= v20 )
          v20 = 0;
        else
          v21 = v19 - v20;
        *(_QWORD *)(v14 + 72) = 0;
        if ( !v17 )
          goto LABEL_43;
        *(_BYTE *)(v15 + v20 + 16) = 0;
        if ( v17 < v19 )
        {
          if ( v17 <= v20 )
          {
            v23 = &v18[v20 - v17];
            v20 = 0;
            v18 = (unsigned __int8 *)&unk_27081;
          }
          else
          {
            v17 -= v20;
            v23 = &v18[v19 - v17];
          }
          v25 = *(_DWORD *)(v9 + 49164);
          if ( (v25 & 0x40000000) == 0 )
          {
            if ( (v25 & 8) == 0 )
            {
              if ( (v25 & 0x10) != 0 )
                goto LABEL_39;
              goto LABEL_43;
            }
            v24 = 0;
            v28 = (unsigned __int8 *)&unk_27081;
            goto LABEL_32;
          }
          v28 = (unsigned __int8 *)&unk_27081;
          v24 = 0;
        }
        else
        {
          v17 = 0;
          if ( v21 )
            v17 = v21 - 1;
          v22 = *(_DWORD *)(v9 + 49164);
          v23 = &v18[v20 + 1];
          if ( (v22 & 0x40000000) == 0 )
          {
            if ( (v22 & 8) == 0 )
            {
              if ( (v22 & 0x10) != 0 )
              {
                v24 = 18;
                v28 = "\n*FLUSH RING BUF*\n";
                goto LABEL_52;
              }
LABEL_43:
              v16 = *(_QWORD *)(v9 + 49168);
LABEL_44:
              v27 = *(_QWORD *)(v16 + 8);
              if ( v27 )
                VBoxGuest_RTSemSpinMutexRelease(v27, a2, a3, a4, a5, v12, v13, a8, a9);
              return;
            }
            v24 = 18;
            v28 = "\n*FLUSH RING BUF*\n";
            goto LABEL_19;
          }
          __outbytestring(0x504u, "\n*FLUSH RING BUF*\n", 0x12u);
          v28 = "\n*FLUSH RING BUF*\n";
          v24 = 18;
        }
        if ( v17 )
        {
          if ( v17 <= 1 )
            VBoxGuest_RTLogWriteUser_part_6(v23, 1);
          else
            __outbytestring(0x504u, v23, v17);
        }
        if ( v20 )
        {
          if ( v20 == 1 )
            VBoxGuest_RTLogWriteUser_part_6(v18, 1);
          else
            __outbytestring(0x504u, v18, v20);
        }
        v26 = *(_DWORD *)(v9 + 49164);
        if ( (v26 & 8) == 0 )
        {
LABEL_37:
          if ( (v26 & 0x10) != 0 )
          {
            if ( !v24 )
            {
LABEL_39:
              if ( v17 )
                VBoxGuest_RTLogWriteCom(v23, v17);
              if ( v20 )
                VBoxGuest_RTLogWriteCom(v18, v20);
              goto LABEL_43;
            }
LABEL_52:
            VBoxGuest_RTLogWriteCom(v28, v24);
            goto LABEL_39;
          }
          goto LABEL_43;
        }
        if ( !v24 )
        {
LABEL_32:
          if ( v17 )
            VBoxGuest_RTLogWriteDebugger(v23, v17);
          if ( v20 )
            VBoxGuest_RTLogWriteDebugger(v18, v20);
          v26 = *(_DWORD *)(v9 + 49164);
          goto LABEL_37;
        }
LABEL_19:
        VBoxGuest_RTLogWriteDebugger(v28, v24);
        goto LABEL_32;
      }
    }
  }
}
