__int64 __fastcall VBoxGuest_RTHeapSimpleGetHeapSize(__int64 a1)
{
  if ( a1
    && (unsigned __int64)(a1 + 0x200000) > 0x200FFF
    && ((a1 & 0xFF00000000000000LL) == 0 || (a1 & 0xFF00000000000000LL) == 0xFF00000000000000LL) )
  {
    return *(_QWORD *)(a1 + 8);
  }
  else
  {
    return 0;
  }
}
