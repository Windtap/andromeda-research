__int64 __fastcall vbsf_reg_llseek(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 result; // rax

  if ( a3 - 2 <= 2
    && (LODWORD(result) = vbsf_inode_revalidate_with_handle(
                            *(_QWORD *)(a1 + 24),
                            *(_QWORD *)(*(_QWORD *)(a1 + 208) + 16LL),
                            1,
                            0),
        (_DWORD)result) )
  {
    return (int)result;
  }
  else
  {
    return generic_file_llseek(a1, a2, a3);
  }
}
