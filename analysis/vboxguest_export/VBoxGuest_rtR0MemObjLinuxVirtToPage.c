__int64 __fastcall VBoxGuest_rtR0MemObjLinuxVirtToPage(unsigned __int64 a1)
{
  unsigned __int64 v1; // rax
  __int64 v3; // rdi
  __int64 v4; // rdi
  __int64 v5; // rax
  __int64 v6; // r8
  __int64 v7; // r9
  __int64 v8; // r10
  __int64 v9; // rdx
  __int64 v10; // rdi
  __int64 v11; // rcx
  __int64 v12; // rax
  __int64 v13; // r8
  __int64 v14; // rdx
  __int64 v15; // rcx
  __int64 v16; // rdx
  __int64 v18; // rax
  __int64 v19; // r8
  __int64 v20; // rdx
  __int64 v21; // rdx
  __int64 v22; // rsi
  __int64 v23; // rax
  __int64 v24; // r8
  __int64 v25; // r9
  __int64 v26; // rdx
  __int64 v27; // rcx
  _QWORD *v28; // rsi
  __int64 v29; // rax
  __int64 v30; // r8

  v1 = __readgsqword((unsigned int)&current_task);
  if ( *(_QWORD *)(v1 + 1776) )
  {
    v3 = *(_QWORD *)(*(_QWORD *)(*(_QWORD *)(v1 + 1776) + 64LL) + 8 * ((a1 >> 39) & 0x1FF));
    if ( v3 )
    {
      v4 = *(_QWORD *)(((a1 >> 27) & 0xFF8)
                     + (((__int64 (__fastcall *)(__int64, unsigned __int64))pv_mmu_ops[31])(v3, a1) & 0x3FFFFFFFF000LL)
                     - 0x780000000000LL);
      if ( v4 )
      {
        if ( (pv_mmu_ops[36]() & 0x81) == 0x81 )
        {
          v18 = pv_mmu_ops[36]();
          v20 = 0x3FFFC0000000LL;
          if ( (v4 & 0x80) == 0 )
            v20 = v19;
          v21 = (v18 & (unsigned __int64)v20) >> 12 << 6;
          if ( v21 != 0x160000000000LL )
            return (((v21 >> 6) + ((a1 >> 12) & 0x3FFFF)) << 6) - 0x160000000000LL;
        }
        else
        {
          v5 = pv_mmu_ops[36]();
          v9 = 0x3FFFC0000000LL;
          if ( (v4 & 0x80) == 0 )
            v9 = v6;
          v10 = *(_QWORD *)(v8 + (v5 & v9) + v7);
          if ( v10 )
          {
            v11 = *(_QWORD *)(v8 + (v5 & v9) + v7) & 0x80LL;
            if ( (v10 & 0x80u) == 0LL )
            {
              v22 = (a1 >> 9) & 0xFF8;
              v23 = ((__int64 (__fastcall *)(__int64, __int64, unsigned __int64, __int64))pv_mmu_ops[34])(
                      v10,
                      v22,
                      0xFFFFC00000000FFFLL,
                      v11);
              v26 = 0x3FFFFFE00000LL;
              if ( !v27 )
                v26 = v24;
              v28 = (_QWORD *)((v23 & v26) + v25 + (unsigned int)v22);
              if ( v28 && (*v28 & 0x101) != 0 )
              {
                v29 = pv_mmu_ops[29]();
                return ((v30 & (unsigned __int64)v29) >> 6) - 0x160000000000LL;
              }
            }
            else
            {
              v12 = ((__int64 (__fastcall *)(__int64, unsigned __int64, unsigned __int64, __int64))pv_mmu_ops[34])(
                      v10,
                      a1,
                      0xFFFFC00000000FFFLL,
                      v11);
              v14 = 0x3FFFFFE00000LL;
              if ( !v15 )
                v14 = v13;
              v16 = (v12 & (unsigned __int64)v14) >> 12 << 6;
              if ( v16 != 0x160000000000LL )
                return (((v16 >> 6) + ((a1 >> 12) & 0x1FF)) << 6) - 0x160000000000LL;
            }
          }
        }
      }
    }
  }
  return 0;
}
