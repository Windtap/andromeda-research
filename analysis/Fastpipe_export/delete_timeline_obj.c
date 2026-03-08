__int64 __fastcall delete_timeline_obj(__int64 a1)
{
  sync_timeline_destroy(*(_QWORD *)(a1 - 12));
  *(_QWORD *)(a1 - 12) = 0;
  return kfree(a1 - 12);
}
