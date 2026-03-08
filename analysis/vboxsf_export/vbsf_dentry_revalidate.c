__int64 __fastcall vbsf_dentry_revalidate(_QWORD *a1, __int16 a2)
{
  unsigned int v2; // ebp

  if ( (a2 & 0x40) != 0 )
    return (unsigned int)-10;
  if ( a1[6] )
  {
    v2 = 1;
    if ( jiffies - a1[15] < (unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1[13] + 1120LL) + 52LL) )
      return v2;
    if ( !(unsigned int)vbsf_inode_revalidate_worker((__int64)a1, 1, 0) )
    {
      a1[15] = jiffies;
      return 1;
    }
  }
  else if ( (a2 & 0xA00) == 0 )
  {
    return a1[15] - jiffies < (unsigned __int64)*(unsigned int *)(*(_QWORD *)(a1[13] + 1120LL) + 52LL);
  }
  return 0;
}
