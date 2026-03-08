__int64 onSerialRecvWorkFunc()
{
  size_t v0; // rdx
  __int64 v1; // rdi
  bool v2; // cc
  int v4; // [rsp+4h] [rbp-4h] BYREF

  v4 = 0;
  if ( *(int *)(g_pPipeMem + 49484) > 999 )
  {
    printk(
      "fastpipe: assert!!!!!!!!!!!! [%s] %s\n",
      "onSerialRecvWorkFunc",
      "! \"onSerialRecvWorkFunc: unknown callCode\"");
    dump_stack();
  }
  else
  {
    ld_onRecvSerialCallGLES(
      *(unsigned int *)(g_pPipeMem + 49484),
      g_pPipeMem + 49496,
      *(unsigned int *)(g_pPipeMem + 49492),
      &g_replyToHost,
      &unk_10000,
      &v4);
  }
  v0 = v4;
  v1 = g_pPipeMem;
  v2 = v4 <= 0;
  *(_DWORD *)(g_pPipeMem + 49492) = v4;
  if ( !v2 )
    memcpy((void *)(v1 + 49496), &g_replyToHost, v0);
  __outdword(g_IOPortBase, 8u);
  return 8;
}
