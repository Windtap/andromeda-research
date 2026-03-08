void __fastcall rtlogFlush_isra_12(__int64 a1)
{
  unsigned int v2; // ebp
  int v3; // eax
  void (__fastcall *v4)(__int64); // rax
  __int64 v5; // rdi

  v2 = *(_DWORD *)(a1 + 49152);
  if ( v2 )
  {
    v3 = *(_DWORD *)(a1 + 49164);
    if ( (v3 & 0x20) != 0 && (v5 = *(_QWORD *)(a1 + 49168)) != 0 && *(_QWORD *)(v5 + 80) )
    {
      rtLogRingBufWrite(v5, (char *)a1, v2);
      *(_DWORD *)(a1 + 49152) = 0;
    }
    else
    {
      if ( v2 <= 0xBFFF )
        *(_BYTE *)(a1 + v2) = 0;
      if ( (v3 & 0x40000000) != 0 )
      {
        if ( v2 == 1 )
        {
          VBoxGuest_RTLogWriteUser_part_6((unsigned __int8 *)a1, 1);
          v3 = *(_DWORD *)(a1 + 49164);
        }
        else
        {
          __outbytestring(0x504u, (unsigned __int8 *)a1, v2);
        }
      }
      if ( (v3 & 8) != 0 )
      {
        VBoxGuest_RTLogWriteDebugger(a1, v2);
        v3 = *(_DWORD *)(a1 + 49164);
      }
      if ( (v3 & 0x10) != 0 )
        VBoxGuest_RTLogWriteCom((unsigned __int8 *)a1, v2);
      v4 = *(void (__fastcall **)(__int64))(*(_QWORD *)(a1 + 49168) + 16LL);
      if ( v4 )
        v4(a1);
      *(_DWORD *)(a1 + 49152) = 0;
    }
  }
}
