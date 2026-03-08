char __fastcall rtR0MemObjNativeLockUser(_QWORD *a1, __int64 a2, unsigned __int64 a3, char a4, __int64 a5)
{
  char result; // al
  unsigned __int64 v6; // r15
  unsigned __int64 v7; // rbp
  __int64 v8; // rcx
  _DWORD *v9; // rbx
  __int64 v10; // r12
  int user_pages; // eax
  int v12; // r13d
  _DWORD *v13; // rax
  volatile signed __int8 *v14; // rdi
  __int64 v15; // rdi
  char v16; // bp
  int v17; // edx
  __int64 v18; // rax
  _BOOL4 v19; // [rsp+14h] [rbp-44h]

  result = -37;
  v6 = a3 >> 12;
  v7 = __readgsqword((unsigned int)&current_task);
  if ( a5 == *(_DWORD *)(v7 + 1940) )
  {
    v19 = (a4 & 2) != 0;
    if ( v7 )
    {
      result = -54;
      v8 = (__int64)(int)v6 << 12;
      if ( v8 == a3 )
      {
        v9 = rtR0MemObjNew(8LL * (int)v6 + 96, 4, a2, v8);
        if ( v9 )
        {
          v10 = VBoxGuest_RTMemAllocTag(8LL * (int)v6);
          if ( !v10 )
          {
            v16 = -8;
LABEL_13:
            rtR0MemObjDelete((__int64)v9);
            return v16;
          }
          down_read(*(_QWORD *)(v7 + 1768) + 104LL);
          user_pages = get_user_pages(v7, *(_QWORD *)(v7 + 1768), a2, (int)v6, v19, v19, v9 + 24, v10);
          if ( user_pages != (_DWORD)v6 )
          {
            v12 = user_pages - 1;
            if ( user_pages > 0 )
            {
              do
              {
                v13 = &v9[2 * v12];
                v14 = (volatile signed __int8 *)*((_QWORD *)v13 + 12);
                if ( (*(_QWORD *)v14 & 0x400LL) == 0 )
                {
                  _InterlockedOr8(v14, 0x10u);
                  v14 = (volatile signed __int8 *)*((_QWORD *)v13 + 12);
                }
                put_page(v14);
                --v12;
              }
              while ( v12 != -1 );
            }
            v15 = *(_QWORD *)(v7 + 1768);
            v16 = -5;
            up_read(v15 + 104);
            VBoxGuest_RTMemFree(v10);
            goto LABEL_13;
          }
          v17 = user_pages - 1;
          if ( user_pages > 0 )
          {
            do
            {
              v18 = v17--;
              *(_QWORD *)(*(_QWORD *)(v10 + 8 * v18) + 80LL) |= 0x22000uLL;
            }
            while ( v17 != -1 );
          }
          up_read(*(_QWORD *)(v7 + 1768) + 104LL);
          VBoxGuest_RTMemFree(v10);
          *((_QWORD *)v9 + 11) = (int)v6;
          *((_QWORD *)v9 + 6) = a5;
          *a1 = v9;
          return 0;
        }
        else
        {
          return -8;
        }
      }
    }
  }
  return result;
}
