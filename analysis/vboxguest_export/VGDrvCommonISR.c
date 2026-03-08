__int64 __fastcall VGDrvCommonISR(__int64 a1)
{
  __int64 v2; // rbp
  __int64 v3; // rax
  unsigned int v4; // r14d
  char v5; // r12
  void (__fastcall *v6)(_QWORD); // rax
  __int64 *v7; // rcx
  __int64 *v8; // r15
  __int64 v9; // r13
  __int64 *v10; // rbp
  __int64 *v11; // rdi
  _QWORD *v12; // rax
  _QWORD *v13; // rdx
  __int64 v14; // rax
  __int64 result; // rax
  unsigned int v16; // ebp
  unsigned __int32 v17; // eax

  if ( *(int *)(a1 + 32) >= 0 )
  {
    v2 = *(_QWORD *)(a1 + 40);
    if ( !v2 )
      return 0;
  }
  else
  {
    v2 = 0;
  }
  VBoxGuest_RTSpinlockAcquire(*(_QWORD *)(a1 + 24));
  v3 = *(_QWORD *)(a1 + 8);
  if ( !v3 || !*(_BYTE *)(v3 + 8) )
  {
    v16 = 0;
LABEL_21:
    VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 24));
    return v16;
  }
  if ( v2 )
  {
    *(_DWORD *)(v2 + 12) = -225;
    *(_DWORD *)(v2 + 24) = 0;
    __outdword(*(_WORD *)(a1 + 4), *(_QWORD *)(a1 + 48));
    v4 = *(_DWORD *)(v2 + 24);
    if ( *(int *)(v2 + 12) >= 0 )
      goto LABEL_7;
    goto LABEL_24;
  }
  v17 = __indword(*(_WORD *)(a1 + 4) + 8);
  v4 = v17;
  if ( v17 == -1 )
  {
LABEL_24:
    v16 = 1;
    goto LABEL_21;
  }
LABEL_7:
  v5 = 0;
  if ( (v4 & 0x200) != 0 )
  {
    v6 = *(void (__fastcall **)(_QWORD))(a1 + 200);
    v4 &= ~0x200u;
    v5 = 1;
    if ( v6 )
      v6(*(_QWORD *)(a1 + 208));
  }
  if ( (v4 & 2) != 0 )
  {
    v7 = *(__int64 **)(a1 + 72);
    v8 = (__int64 *)(a1 + 72);
    v9 = a1 + 88;
    v10 = (__int64 *)*v7;
    if ( (__int64 *)(a1 + 72) != v7 )
    {
      while ( 1 )
      {
        if ( (*(_DWORD *)(v7[5] + 24) & 1) != 0 )
        {
          v12 = (_QWORD *)*v7;
          *((_DWORD *)v7 + 5) = 2;
          v13 = (_QWORD *)v7[1];
          *v13 = v12;
          v12[1] = v13;
          *v7 = 0;
          v7[1] = 0;
          **(_QWORD **)(a1 + 96) = v7;
          v14 = *(_QWORD *)(a1 + 96);
          *v7 = v9;
          v7[1] = v14;
          *(_QWORD *)(a1 + 96) = v7;
          VBoxGuest_RTSemEventMultiSignal(v7[3]);
          v11 = (__int64 *)*v10;
          if ( v8 == v10 )
            break;
        }
        else
        {
          v11 = (__int64 *)*v10;
          if ( v8 == v10 )
            break;
        }
        v7 = v10;
        v10 = v11;
      }
    }
    v4 &= ~2u;
  }
  vgdrvDispatchEventsLocked(a1, v4);
  VBoxGuest_RTSpinlockRelease(*(_QWORD *)(a1 + 24));
  result = 1;
  if ( v5 )
  {
    VGDrvNativeISRMousePollEvent(
      a1,
      v4,
      (unsigned int)_InterlockedExchangeAdd((volatile signed __int32 *)(a1 + 124), 1u));
    return 1;
  }
  return result;
}
