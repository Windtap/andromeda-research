__int64 __fastcall vbsf_evict_inode(__int64 a1)
{
  __int64 result; // rax
  _QWORD *v2; // rbp

  truncate_inode_pages(a1 + 352, 0);
  result = clear_inode(a1);
  v2 = *(_QWORD **)(a1 + 552);
  if ( v2 )
  {
    *(_QWORD *)(a1 + 552) = 0;
    if ( !*v2 )
      BUG();
    kfree(*v2);
    vbsf_handle_drop_chain(v2);
    return kfree(v2);
  }
  return result;
}
