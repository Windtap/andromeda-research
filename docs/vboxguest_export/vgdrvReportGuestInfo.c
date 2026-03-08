__int64 __fastcall vgdrvReportGuestInfo(int a1)
{
  int v2; // ebx
  __int64 v3; // rax
  __int64 v4; // rax
  __int64 v5; // rdi
  int v6; // eax
  __int64 v8; // [rsp+0h] [rbp-20h] BYREF
  _QWORD v9[3]; // [rsp+8h] [rbp-18h] BYREF

  v8 = 0;
  v9[0] = 0;
  v2 = VbglR0GRAlloc(&v8, 168, 58);
  if ( v2 >= 0 )
  {
    v3 = v8;
    *(_WORD *)(v8 + 24) = 6;
    *(_WORD *)(v3 + 26) = 1;
    *(_DWORD *)(v3 + 28) = 36;
    *(_DWORD *)(v3 + 32) = (_DWORD)&unk_25373;
    *(_DWORD *)(v3 + 36) = 1;
    VBoxGuest_RTStrCopy((void *)(v3 + 40));
    v2 = VbglR0GRAlloc(v9, 32, 50);
    if ( v2 >= 0 )
    {
      v4 = v9[0];
      v5 = v8;
      *(_DWORD *)(v9[0] + 24LL) = 65540;
      *(_DWORD *)(v4 + 28) = a1;
      v6 = VbglR0GRPerform(v5);
      v2 = v6;
      if ( v6 < 0 )
      {
        if ( v6 == -12 || v6 == -37 )
        {
          v2 = VbglR0GRPerform(v9[0]);
          if ( v2 >= 0 )
          {
            v2 = VbglR0GRPerform(v8);
            if ( v2 == -12 )
              v2 = 0;
          }
        }
      }
      else
      {
        v2 = VbglR0GRPerform(v9[0]);
      }
      VbglR0GRFree(v9[0]);
    }
    VbglR0GRFree(v8);
  }
  return (unsigned int)v2;
}
