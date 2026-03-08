__int64 __fastcall VBoxGuest_RTStrCopyP(void **a1, size_t *a2, const char *a3)
{
  size_t v4; // rax
  size_t v5; // rdx
  size_t v6; // rbx
  unsigned int v7; // ebx
  size_t v9; // r14
  _BYTE *v10; // rax

  v4 = strlen(a3);
  v5 = *a2;
  v6 = v4;
  if ( v4 >= *a2 )
  {
    v7 = -41;
    if ( v5 )
    {
      v9 = v5 - 1;
      v10 = memcpy(*a1, a3, v5 - 1);
      *a1 = &v10[v9];
      v10[v9] = 0;
      *a2 = 1;
    }
  }
  else
  {
    *a1 = (char *)memcpy(*a1, a3, v4 + 1) + v4;
    *a2 -= v6;
    return 0;
  }
  return v7;
}
