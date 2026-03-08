unsigned __int64 __fastcall rtR0MemObjLinuxConvertProt(int a1, char a2)
{
  unsigned __int64 result; // rax

  switch ( a1 )
  {
    case 1:
      result = 0x8000000000000161LL;
      if ( !a2 )
        result = 0x8000000000000025LL;
      break;
    case 2:
    case 3:
      result = 0x8000000000000163LL;
      if ( !a2 )
        result = 0x8000000000000027LL;
      break;
    case 4:
    case 5:
      result = (-(__int64)(a2 == 0) & 0xFFFFFFFFFFFFFEC4LL) + 353;
      break;
    case 6:
    case 7:
      result = (-(__int64)(a2 == 0) & 0xFFFFFFFFFFFFFEC4LL) + 355;
      break;
    default:
      result = 288;
      break;
  }
  return result;
}
