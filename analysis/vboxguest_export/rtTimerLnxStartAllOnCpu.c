__int64 __fastcall rtTimerLnxStartAllOnCpu(unsigned int a1, __int64 a2, __int64 a3)
{
  return rtTimerLnxStartSubTimer(a2 + 112LL * a1 + 104, *(_QWORD *)a3, *(_QWORD *)(a3 + 8), 1, *(_BYTE *)(a2 + 19));
}
