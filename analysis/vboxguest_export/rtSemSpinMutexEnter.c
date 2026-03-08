__int64 __fastcall rtSemSpinMutexEnter(__int64 a1, __int64 a2)
{
  unsigned int v2; // ebp
  int v3; // eax
  bool v4; // zf
  unsigned __int64 v6; // kr00_8
  unsigned __int64 v7; // [rsp-8h] [rbp-20h]

  v2 = 0;
  *(_BYTE *)(a1 + 16) = VBoxGuest_RTThreadPreemptIsEnabled(0) ^ 1;
  if ( (unsigned __int8)VBoxGuest_RTThreadIsInInterrupt(0) )
  {
    v3 = *(_DWORD *)(a2 + 4);
    *(_BYTE *)(a1 + 16) = 1;
    v2 = (v3 & 1) == 0 ? 0x16F : 0;
  }
  *(_DWORD *)(a1 + 8) = -1;
  *(_DWORD *)(a1 + 12) = 0;
  VBoxGuest_RTThreadPreemptDisable(a1 + 8);
  v4 = (*(_BYTE *)(a2 + 4) & 1) == 0;
  *(_BYTE *)(a1 + 17) = *(_BYTE *)(a2 + 4) & 1;
  if ( v4 )
  {
    *(_QWORD *)a1 = 0;
  }
  else
  {
    v6 = __readeflags();
    v7 = v6;
    _disable();
    *(_QWORD *)a1 = v7;
  }
  return v2;
}
