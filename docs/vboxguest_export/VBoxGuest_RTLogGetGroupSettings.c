__int64 __fastcall VBoxGuest_RTLogGetGroupSettings(__int64 a1, _BYTE *a2, unsigned __int64 a3)
{
  __int64 v3; // rbp
  unsigned int v4; // r12d
  unsigned int v5; // esi
  int v6; // eax
  __int64 v7; // rdx
  __int64 result; // rax
  __int64 i; // rbx
  const char *v10; // rdi
  unsigned __int64 v11; // [rsp+0h] [rbp-30h] BYREF
  _BYTE *v12; // [rsp+8h] [rbp-28h] BYREF
  _BYTE v13[25]; // [rsp+17h] [rbp-19h] BYREF

  v3 = a1;
  v12 = a2;
  v11 = a3;
  v13[0] = 0;
  if ( a1 || (v3 = VBoxGuest_RTLogDefaultInstance()) != 0 )
  {
    v4 = *(_DWORD *)(v3 + 49184);
    v5 = *(_DWORD *)(v3 + 49188);
    if ( v4 > 1 )
    {
      v6 = *(_DWORD *)(v3 + 49192);
      if ( v6 != v5 )
      {
LABEL_9:
        for ( i = 0; ; v5 = *(_DWORD *)(v3 + 4 * i + 49188) )
        {
          if ( v5 )
          {
            v10 = *(const char **)(*(_QWORD *)(*(_QWORD *)(v3 + 49168) + 48LL) + 8 * i);
            if ( v10 )
            {
              result = rtLogGetGroupSettingsAddOne(v10, v5, (void **)&v12, &v11, v13);
              if ( (_DWORD)result )
                break;
            }
          }
          if ( v4 <= (unsigned int)++i )
          {
            result = 0;
            goto LABEL_8;
          }
        }
        goto LABEL_8;
      }
      v7 = v3;
      while ( v7 != v3 + 4LL * (v4 - 2) )
      {
        v7 += 4;
        if ( v6 != *(_DWORD *)(v7 + 49192) )
          goto LABEL_9;
      }
    }
    result = rtLogGetGroupSettingsAddOne("all", v5, (void **)&v12, &v11, v13);
LABEL_8:
    *v12 = 0;
    return result;
  }
  *v12 = 0;
  return 0;
}
