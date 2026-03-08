__int64 __fastcall vbsf_inode_mkdir(__int64 a1, __int64 a2, __int16 a3)
{
  __int16 v3; // dx

  v3 = a3 & 0xFFF;
  HIBYTE(v3) |= 0x40u;
  return vbsf_create_worker(a1, a2, v3, 12308, 0, 0, 0, 0);
}
