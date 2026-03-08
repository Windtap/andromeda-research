__int64 __fastcall rtTimerLnxStartOnSpecificCpu(__int64 a1, __int64 a2, __int64 a3)
{
  return rtTimerLnxStartSubTimer(a2 + 104, *(_QWORD *)a3, *(_QWORD *)(a3 + 8), 1, *(_BYTE *)(a2 + 19));
}
