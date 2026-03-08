__int64 __fastcall rtThreadMain(
        __int64 a1,
        unsigned __int64 a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v10; // ebp

  rtThreadInsert(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
  rtThreadNativeSetPriority(a1, *(unsigned int *)(a1 + 64));
  _InterlockedExchange((volatile __int32 *)(a1 + 40), 3);
  v10 = (*(__int64 (__fastcall **)(__int64, _QWORD))(a1 + 80))(a1, *(_QWORD *)(a1 + 88));
  rtThreadTerminate(a1, v10);
  return v10;
}
