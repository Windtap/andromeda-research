void __fastcall rtR0LogLoggerExFallbackFlush(unsigned int *a1)
{
  __int64 v2; // rcx
  unsigned int v3; // eax
  __int64 v4; // rdi
  unsigned __int8 *v5; // rdi

  v2 = *a1;
  if ( (_DWORD)v2 )
  {
    v3 = a1[1];
    if ( (v3 & 0x20) != 0 && (v4 = *((_QWORD *)a1 + 1)) != 0 && *(_QWORD *)(v4 + 80) )
    {
      rtLogRingBufWrite(v4, (char *)a1 + 16, (unsigned int)v2);
      *a1 = 0;
    }
    else
    {
      if ( (v3 & 0x40000000) != 0 )
      {
        v5 = (unsigned __int8 *)(a1 + 4);
        if ( v2 == 1 )
        {
          VBoxGuest_RTLogWriteUser_part_6(v5, 1);
          v3 = a1[1];
        }
        else
        {
          __outbytestring(0x504u, v5, v2);
        }
      }
      if ( (v3 & 8) != 0 )
      {
        VBoxGuest_RTLogWriteDebugger(a1 + 4, *a1);
        v3 = a1[1];
      }
      if ( (v3 & 0x10) != 0 )
        VBoxGuest_RTLogWriteCom((unsigned __int8 *)a1 + 16, *a1);
      *a1 = 0;
    }
  }
}
