__int64 __fastcall goldfish_sync_timeline_inc(__int64 a1, int a2)
{
  __int64 result; // rax

  if ( a1 )
  {
    result = sw_sync_timeline_inc(*(_QWORD *)a1);
    *(_DWORD *)(a1 + 8) += a2;
    if ( !_InterlockedSub((volatile signed __int32 *)(a1 + 12), 1u) )
      return delete_timeline_obj(a1 + 12);
  }
  return result;
}
