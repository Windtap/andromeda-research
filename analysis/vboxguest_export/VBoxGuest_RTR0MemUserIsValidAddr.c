bool __fastcall VBoxGuest_RTR0MemUserIsValidAddr(unsigned __int64 a1)
{
  return a1 <= *(_QWORD *)(__readgsqword((unsigned int)&cpu_tss + 4) - 16360) - 1LL;
}
