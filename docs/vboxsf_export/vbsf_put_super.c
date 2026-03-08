__int64 __fastcall vbsf_put_super(__int64 a1)
{
  int *v1; // rbx

  v1 = *(int **)(a1 + 1120);
  if ( !v1 )
    BUG();
  bdi_destroy(v1 + 24);
  *(_QWORD *)(a1 + 216) = &noop_backing_dev_info;
  return vbsf_super_info_free(v1);
}
