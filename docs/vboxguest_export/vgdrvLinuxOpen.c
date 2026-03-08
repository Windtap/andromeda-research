char __fastcall vgdrvLinuxOpen(__int64 a1, __int64 a2)
{
  int v2; // ebx
  __int64 current_tty; // rax
  int v4; // r13d
  __int64 v5; // rbp
  _BYTE *v6; // rax
  int UserSession; // edi
  int v8; // eax
  int v9; // ebp
  unsigned int v10; // edx
  unsigned int v11; // ecx
  _QWORD v13[5]; // [rsp+0h] [rbp-28h] BYREF

  v2 = *(_DWORD *)(*(_QWORD *)(__readgsqword((unsigned int)&current_task) + 2360) + 4LL) == 0 ? 11 : 14;
  if ( (*(_DWORD *)(a1 + 76) & 0xFFFFF) == g_MiscDeviceUser )
  {
    v9 = v2 | 0x8000;
    if ( *(_DWORD *)(a1 + 8) )
    {
      v2 |= 0x8000u;
    }
    else
    {
      v2 |= 0x8080u;
      if ( !(unsigned int)in_egroup_p(0) )
        v2 = v9;
    }
  }
  current_tty = get_current_tty();
  v4 = 0;
  v5 = current_tty;
  if ( current_tty )
  {
    v6 = (_BYTE *)tty_name(current_tty);
    if ( v6 )
    {
      if ( *v6 == 116 && v6[1] == 116 && v6[2] == 121 )
      {
        v10 = (char)v6[3] - 48;
        if ( v10 <= 9 )
        {
          LOBYTE(v4) = 32;
          if ( v6[4] )
          {
            v11 = (char)v6[4] - 48;
            LOBYTE(v4) = 0;
            if ( v11 <= 9 && !v6[5] && (int)(10 * v10 + v11) < 64 )
              v4 = 32;
          }
        }
      }
    }
    tty_kref_put(v5);
  }
  UserSession = VGDrvCommonCreateUserSession(&g_DevExt, v2 | (unsigned int)v4, v13);
  if ( UserSession >= 0 )
    *(_QWORD *)(a2 + 208) = v13[0];
  if ( (unsigned int)(UserSession + 999) <= 0x7CE )
  {
    return -(int)VBoxGuest_RTErrConvertToErrno();
  }
  else
  {
    LOBYTE(v8) = -3;
    if ( UserSession != -2900 )
    {
      if ( UserSession <= -2900 )
      {
        LOBYTE(v8) = -71;
        if ( UserSession != -2904 )
        {
          LOBYTE(v8) = -14;
          if ( UserSession != -2902 )
          {
            LOBYTE(v8) = -22;
            if ( UserSession != -2905 )
              goto LABEL_14;
          }
        }
      }
      else
      {
        if ( UserSession != 2903 && UserSession != 2906 && UserSession != 2901 )
        {
LABEL_14:
          LOBYTE(v8) = -71;
          return v8;
        }
        LOBYTE(v8) = 0;
      }
    }
  }
  return v8;
}
