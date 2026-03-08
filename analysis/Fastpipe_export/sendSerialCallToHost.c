__int64 __fastcall sendSerialCallToHost(int a1, const void *a2, int a3, void *a4, int a5, _DWORD *a6)
{
  _DWORD *v10; // r14
  __int64 v11; // rbx
  _DWORD v13[6]; // [rsp+8h] [rbp-58h] BYREF
  _QWORD v14[8]; // [rsp+20h] [rbp-40h] BYREF

  if ( a3 > (unsigned int)&unk_10000 )
  {
    printk(
      "fastpipe: assert!!!!!!!!!!!! [%s] %s\n",
      "sendSerialCallToHost",
      "len <= sizeof(g_pPipeMem->serialToHost.buf)");
    dump_stack();
  }
  mutex_lock(&g_lockSendSerialCall);
  v10 = (_DWORD *)g_pPipeMem;
  *(_DWORD *)(g_pPipeMem + 115036) = 0;
  v10[28758] = a1;
  memcpy(v10 + 28761, a2, (int)a3);
  v10[28760] = a3;
  __outdword(g_IOPortBase, 7u);
  if ( !v10[28759] )
  {
    v13[0] = 0;
    v14[0] = v14;
    v14[1] = v14;
    while ( 1 )
    {
      prepare_to_wait_event(&g_waitSerialCallQueue, v13, 2);
      if ( *(_DWORD *)(g_pPipeMem + 115036) )
        break;
      schedule();
    }
    finish_wait(&g_waitSerialCallQueue, v13);
  }
  if ( a6 )
    *a6 = 0;
  if ( a4 )
  {
    v11 = g_pPipeMem;
    if ( *(_DWORD *)(g_pPipeMem + 115040) > a5 )
    {
      printk(
        "fastpipe: assert!!!!!!!!!!!! [%s] %s\n",
        "sendSerialCallToHost",
        "sizeReplyBuf >= g_pPipeMem->serialToHost.len");
      dump_stack();
      v11 = g_pPipeMem;
    }
    if ( a5 >= *(_DWORD *)(v11 + 115040) )
    {
      memcpy(a4, (const void *)(v11 + 115044), *(int *)(v11 + 115040));
      if ( a6 )
        *a6 = *(_DWORD *)(v11 + 115040);
    }
  }
  return mutex_unlock(&g_lockSendSerialCall);
}
