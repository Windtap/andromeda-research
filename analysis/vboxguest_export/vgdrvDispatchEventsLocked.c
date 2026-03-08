__int64 __fastcall vgdrvDispatchEventsLocked(__int64 a1, int a2)
{
  _QWORD *v2; // rbx
  _QWORD *v3; // rbp
  int v4; // r12d
  _QWORD *v5; // rdx
  _QWORD *v6; // rax
  int v7; // r15d
  int v8; // eax
  unsigned int v10; // [rsp+4h] [rbp-3Ch]

  v2 = *(_QWORD **)(a1 + 56);
  v10 = 0;
  v3 = (_QWORD *)*v2;
  v4 = *(_DWORD *)(a1 + 120) | a2;
  if ( v2 != (_QWORD *)(a1 + 56) )
  {
    while ( 1 )
    {
      v7 = v2[2] & v4;
      if ( v7 && !*((_DWORD *)v2 + 5) )
      {
        v8 = v2[2] & v4;
        if ( (v7 & 0x24) != 0 )
        {
          v7 &= vgdrvGetAllowedEventMaskForSession(a1, v2[4]);
          if ( !v7 )
            goto LABEL_4;
          v8 = v4 & v2[2];
        }
        v5 = (_QWORD *)v2[1];
        *((_DWORD *)v2 + 5) = v8 & v7;
        v4 &= ~*((_DWORD *)v2 + 5);
        v6 = (_QWORD *)*v2;
        *v5 = *v2;
        v6[1] = v5;
        *v2 = 0;
        v2[1] = 0;
        **(_QWORD **)(a1 + 96) = v2;
        v2[1] = *(_QWORD *)(a1 + 96);
        *v2 = a1 + 88;
        *(_QWORD *)(a1 + 96) = v2;
        v10 |= VBoxGuest_RTSemEventMultiSignal(v2[3]);
        if ( !v4 )
          break;
      }
LABEL_4:
      if ( (_QWORD *)(a1 + 56) == v3 )
        break;
      v2 = v3;
      v3 = (_QWORD *)*v3;
    }
  }
  _InterlockedExchange((volatile __int32 *)(a1 + 120), v4);
  return v10;
}
