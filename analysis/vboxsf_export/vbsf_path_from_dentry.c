__int64 __fastcall vbsf_path_from_dentry(__int64 a1, __int64 *a2, __int64 a3, _QWORD *a4, __int64 a5)
{
  char *v5; // rbp
  size_t v6; // rbx
  __int64 v7; // rax
  _BYTE *v8; // r12
  unsigned int v9; // r13d
  size_t v10; // r14
  int v11; // eax
  int v12; // eax
  unsigned int v13; // ebx
  char *v14; // rdi
  __int64 v16; // r14
  int v17; // r13d
  unsigned __int64 v18; // r12
  int v19; // ebx
  _WORD *v20; // rbp
  void *v21; // rdi
  __int64 v22; // rbx
  __int64 DefaultInstance; // rax
  size_t n; // [rsp+8h] [rbp-70h]
  unsigned __int64 v25; // [rsp+10h] [rbp-68h]
  char *src; // [rsp+18h] [rbp-60h]
  char *v27; // [rsp+20h] [rbp-58h]
  unsigned __int16 v30[25]; // [rsp+46h] [rbp-32h] BYREF

  v5 = *(char **)(a3 + 40);
  v27 = v5;
  v6 = *(unsigned int *)(a3 + 36);
  n = v6;
  if ( *(_QWORD *)(a1 + 8) )
  {
    v7 = kmem_cache_alloc_trace(kmalloc_caches[12], 37748928, 4096);
    src = (char *)v7;
    if ( v6 )
    {
      v8 = (_BYTE *)v7;
      v9 = 4096;
      v10 = 0;
      v25 = 0;
      while ( 1 )
      {
        v12 = (*(__int64 (__fastcall **)(char *, _QWORD, unsigned __int16 *))(*(_QWORD *)(a1 + 8) + 24LL))(
                v5,
                (unsigned int)v6,
                v30);
        if ( v12 < 0 )
          break;
        LODWORD(v6) = v6 - v12;
        v5 += v12;
        v11 = utf32_to_utf8(v30[0], v8, v9);
        if ( v11 < 0 )
          break;
        ++v10;
        v25 += v11;
        v9 -= v11;
        v8 += v11;
        if ( n <= v10 )
        {
          v13 = -36;
          if ( v25 <= 0xFFE )
            goto LABEL_12;
LABEL_8:
          v14 = src;
          goto LABEL_9;
        }
      }
      v13 = -22;
      goto LABEL_8;
    }
    v25 = 0;
    v8 = (_BYTE *)v7;
LABEL_12:
    *v8 = 0;
    n = v25;
  }
  else
  {
    src = *(char **)(a3 + 40);
  }
  v16 = *a2;
  v17 = *(unsigned __int16 *)(*a2 + 2);
  if ( (_WORD)v17 == 1 && *(_BYTE *)(v16 + 4) == 47 )
  {
    v19 = 1;
    v18 = n + 1;
  }
  else
  {
    v18 = n + (unsigned __int16)v17 + 2;
    if ( v18 > 0xFFFF )
    {
      v13 = -36;
      goto LABEL_20;
    }
    v19 = 0;
  }
  v20 = (_WORD *)_kmalloc(v18 + 4, 37748928);
  if ( v20 )
  {
    *v20 = v18;
    v20[1] = v18 - 1;
    v21 = v20 + 2;
    if ( v19 )
    {
      memcpy(v21, src, n + 1);
    }
    else
    {
      memcpy(v21, (const void *)(v16 + 4), (unsigned __int16)v17);
      v22 = v17 + 1;
      *((_BYTE *)v20 + v17 + 4) = 47;
      memcpy((char *)v20 + v22 + 4, src, n);
      *((_BYTE *)v20 + n + v22 + 4) = 0;
    }
    v13 = 0;
    *a4 = v20;
  }
  else
  {
    v13 = -12;
    DefaultInstance = VBoxGuest_RTLogRelGetDefaultInstanceEx(22085648);
    if ( DefaultInstance )
      VBoxGuest_RTLogLoggerEx(DefaultInstance, 16, 337, "%Rfn: %M", "vbsf_make_path", "kmalloc failed, caller=%s\n", a5);
  }
LABEL_20:
  v14 = src;
  if ( src != v27 )
LABEL_9:
    kfree(v14);
  return v13;
}
