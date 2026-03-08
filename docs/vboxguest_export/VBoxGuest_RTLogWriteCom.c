__int64 __fastcall VBoxGuest_RTLogWriteCom(unsigned __int8 *a1, __int64 a2)
{
  __int64 i; // r12
  unsigned int v4; // esi
  int v5; // ecx
  unsigned __int8 v6; // al
  __int64 result; // rax

  for ( i = a2; i; --i )
  {
    v4 = *a1;
    if ( (_BYTE)v4 == 10 )
    {
      VBoxGuest_RTLogWriteCom("\r", 1);
      v4 = *a1;
    }
    v5 = -1;
    do
    {
      v6 = __inbyte(0x3FDu);
      if ( (v6 & 0x20) != 0 )
        break;
      --v5;
    }
    while ( v5 );
    result = v4;
    __outbyte(0x3F8u, v4);
    ++a1;
  }
  return result;
}
