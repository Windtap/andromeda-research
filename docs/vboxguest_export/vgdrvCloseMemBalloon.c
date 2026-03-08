__int64 __fastcall vgdrvCloseMemBalloon(__int64 a1, __int64 a2)
{
  int v3; // ebp
  int v4; // eax
  unsigned int v5; // ebp
  int v6; // r13d
  __int64 v7; // rax
  __int64 DefaultInstance; // rax
  _DWORD *v9; // [rsp+0h] [rbp-28h] BYREF

  VBoxGuest_RTSemFastMutexRequest(*(_QWORD *)(a1 + 160));
  if ( *(_QWORD *)(a1 + 184) == a2 || !a2 )
  {
    if ( *(_QWORD *)(a1 + 192) )
    {
      v3 = VbglR0GRAlloc(&v9, 2080, 113);
      if ( v3 < 0 )
      {
        DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
        if ( DefaultInstance )
          VBoxGuest_RTLogLoggerEx(
            DefaultInstance,
            16,
            32,
            (unsigned int)"vgdrvCloseMemBalloon: Failed to allocate VMMDev request buffer (rc=%Rrc).  Will leak %u chunks.\n",
            v3,
            *(_DWORD *)(a1 + 168));
      }
      else
      {
        v4 = *(_DWORD *)(a1 + 168);
        v5 = v4 - 1;
        if ( v4 )
        {
          while ( 1 )
          {
            v6 = vgdrvBalloonDeflate((_QWORD *)(*(_QWORD *)(a1 + 192) + 8LL * v5), v9);
            if ( v6 < 0 )
              break;
            *(_QWORD *)(*(_QWORD *)(a1 + 192) + 8LL * v5) = 0;
            --*(_DWORD *)(a1 + 168);
            if ( !v5 )
              goto LABEL_11;
            --v5;
          }
          v7 = VBoxGuest_RTLogRelGetDefaultInstanceEx(2097168);
          if ( v7 )
            VBoxGuest_RTLogLoggerEx(
              v7,
              16,
              32,
              (unsigned int)"vgdrvCloseMemBalloon: Deflate failed with rc=%Rrc.  Will leak %u chunks.\n",
              v6,
              *(_DWORD *)(a1 + 168));
        }
LABEL_11:
        VbglR0GRFree(v9);
      }
      VBoxGuest_RTMemFree(*(_QWORD *)(a1 + 192));
      *(_QWORD *)(a1 + 192) = 0;
    }
    *(_QWORD *)(a1 + 184) = 0;
  }
  return VBoxGuest_RTSemFastMutexRelease(*(_QWORD *)(a1 + 160));
}
