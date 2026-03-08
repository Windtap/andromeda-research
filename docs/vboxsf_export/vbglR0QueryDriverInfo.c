__int64 vbglR0QueryDriverInfo()
{
  int v0; // ebx
  _QWORD *v2; // [rsp+0h] [rbp-38h] BYREF
  _DWORD v3[2]; // [rsp+8h] [rbp-30h] BYREF
  unsigned __int64 v4; // [rsp+10h] [rbp-28h]
  __int64 v5; // [rsp+18h] [rbp-20h]
  __int64 v6; // [rsp+20h] [rbp-18h]
  __int64 v7; // [rsp+28h] [rbp-10h]

  v0 = VBoxGuest_RTSemMutexRequest(*(_QWORD *)&algn_10484[116], 0xFFFFFFFFLL);
  if ( v0 >= 0 )
  {
    if ( g_vbgldata != 2 )
    {
      v0 = VbglR0IdcOpen((unsigned __int64)&algn_10484[84], (unsigned int)&unk_10000, (unsigned int)&unk_10000, 0, 0, 0);
      if ( v0 >= 0 )
      {
        v4 = 0xFFFFFF1F00000000LL;
        v5 = 40;
        v6 = 0;
        v7 = 0;
        v3[0] = 24;
        v3[1] = (_DWORD)&unk_10001;
        v0 = VbglR0IdcCall((__int64)&algn_10484[84], 3223868929LL, (__int64)v3, 40);
        if ( v0 >= 0 )
        {
          g_vbgldata = 2;
          *(_WORD *)algn_10484 = v7;
          *(_QWORD *)&algn_10484[4] = v6;
          if ( (int)VbglR0GRAlloc(&v2, 0x28u, 4) >= 0 )
          {
            if ( (int)VbglR0GRPerform((__int64)v2) >= 0 )
            {
              *(_QWORD *)&algn_10484[44] = *v2;
              *(_QWORD *)&algn_10484[52] = v2[1];
              *(_QWORD *)&algn_10484[60] = v2[2];
              *(_QWORD *)&algn_10484[68] = v2[3];
              *(_QWORD *)&algn_10484[76] = v2[4];
            }
            VbglR0GRFree((__int64)v2);
          }
        }
      }
    }
    VBoxGuest_RTSemMutexRelease(*(_QWORD *)&algn_10484[116]);
  }
  return (unsigned int)v0;
}
