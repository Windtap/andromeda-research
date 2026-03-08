__int64 __fastcall vgdrvHgcmAsyncWaitCallbackInterruptible(__int64 a1, __int64 a2, unsigned int a3)
{
  return vgdrvHgcmAsyncWaitCallbackWorker(a1, a2, 1, a3);
}
