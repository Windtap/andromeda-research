__int64 __fastcall rtThreadNativeCreate(__int64 a1, unsigned __int64 *a2)
{
  unsigned __int64 v2; // rax
  unsigned __int64 v3; // rbx

  v2 = kthread_create_on_node(rtThreadNativeMain, a1, 0xFFFFFFFFLL, "iprt-%s", (const char *)(a1 + 104));
  v3 = v2;
  if ( v2 > 0xFFFFFFFFFFFFF000LL )
    return 0xFFFFFFFFLL;
  wake_up_process(v2);
  *a2 = v3;
  return 0;
}
