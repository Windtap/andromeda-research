__int64 __fastcall VBoxGuest_RTMpCurSetIndexAndId(_DWORD *a1)
{
  __int64 result; // rax

  result = debug_smp_processor_id();
  *a1 = result;
  return result;
}
