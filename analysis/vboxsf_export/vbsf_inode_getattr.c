__int64 __fastcall vbsf_inode_getattr(__int64 a1, __int64 a2, __int64 a3)
{
  __int64 result; // rax
  __int16 v5; // dx

  result = vbsf_inode_revalidate_worker(a2, 0, 0);
  if ( !(_DWORD)result )
  {
    generic_fillattr(*(_QWORD *)(a2 + 48), a3);
    result = 0;
    v5 = *(_WORD *)(a3 + 12) & 0xF000;
    if ( v5 == (__int16)0x8000 )
    {
      *(_QWORD *)(a3 + 88) = 0x100000;
    }
    else if ( v5 == 0x4000 )
    {
      *(_QWORD *)(a3 + 88) = 0x4000;
    }
  }
  return result;
}
