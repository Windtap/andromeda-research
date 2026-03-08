__int64 __fastcall fileOpOpen(__int64 a1, const void **a2)
{
  unsigned __int64 v2; // rax

  v2 = __readgsqword((unsigned int)&current_task);
  printk(
    "fastpipe: fileOpOpen: pFilp=%p pSession=%p pid=%d %s\n",
    a2,
    a2[26],
    *(_DWORD *)(v2 + 1936),
    (const char *)(v2 + 2368));
  a2[26] = 0;
  return 0;
}
