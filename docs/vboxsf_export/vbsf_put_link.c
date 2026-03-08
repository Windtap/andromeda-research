__int64 __fastcall vbsf_put_link(__int64 a1, unsigned __int64 a2)
{
  __int64 result; // rax

  if ( a2 <= 0xFFFFFFFFFFFFF000LL )
    return free_pages(a2, 0);
  return result;
}
