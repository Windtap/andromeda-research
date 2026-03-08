__int64 __fastcall VBoxGuest_RTHeapSimpleInit(unsigned __int64 *a1, unsigned __int64 a2, unsigned __int64 a3)
{
  unsigned __int64 v3; // rcx
  unsigned __int64 v4; // rdx
  char *v5; // rax

  if ( a3 <= 0xFFF )
    return 4294967294LL;
  if ( a2 + 0x200000 <= 0x200FFF
    || (a2 & 0xFF00000000000000LL) != 0 && (a2 & 0xFF00000000000000LL) != 0xFF00000000000000LL )
  {
    return 4294967290LL;
  }
  if ( a3 >= a2 + a3 - 1 )
    return 4294967294LL;
  v3 = a2 & 0x1F;
  if ( (a2 & 0x1F) != 0 )
  {
    a3 -= 32 - v3;
    a2 += 32 - v3;
  }
  v4 = a3 & 0xFFFFFFFFFFFFFFE0LL;
  *(_QWORD *)a2 = 425263365;
  v5 = (char *)(a2 + v4);
  *(_QWORD *)(a2 + 8) = v4;
  v4 -= 96LL;
  *(_QWORD *)(a2 + 16) = v5;
  *(_QWORD *)(a2 + 32) = a2 + 64;
  *(_QWORD *)(a2 + 40) = a2 + 64;
  *(_QWORD *)(a2 + 88) = 2882400001LL;
  *(_QWORD *)(a2 + 24) = v4;
  *(_QWORD *)(a2 + 48) = -1;
  *(_QWORD *)(a2 + 56) = -1;
  *(_QWORD *)(a2 + 64) = 0;
  *(_QWORD *)(a2 + 72) = 0;
  *(_QWORD *)(a2 + 80) = a2;
  *(_QWORD *)(a2 + 96) = 0;
  *(_QWORD *)(a2 + 104) = 0;
  *(_QWORD *)(a2 + 112) = v4;
  *a1 = a2;
  return 0;
}
